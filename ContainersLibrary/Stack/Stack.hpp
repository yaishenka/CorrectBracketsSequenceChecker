/** @author yaishenka
    @date 08.10.2020 */
#pragma once

#include <memory>
#include <string>

#include "../Utils/Utils.hpp"

namespace Containers {
  class EmptyStack : public std::exception {
    [[nodiscard]] const char* what() const noexcept override {
      return "Call top on empty stack";
    }
  };

  template <typename T>
  class Stack {
   public:
    template <bool condition, typename U>
    using ResolvedType = typename std::enable_if<condition, U>::type;

    Stack();

    [[nodiscard]] size_t GetSize() const { return size_; }
    [[nodiscard]] bool IsEmpty() const { return size_ == 0; }

    [[nodiscard]] T& GetTop();
    [[nodiscard]] const T& GetTop() const;

    void Push(const T& value);
    void Push(T&& value);

    template <class... Args>
    void Emplace(Args&&... args);

    void Pop();

    template <typename U = T>
    ResolvedType<Utils::HasOstreamOperator<U>::value, std::string>
    GetStringRepresentation() const {
      auto current_node = head_;

      std::string string_representation;

      string_representation += "Stack contains:\n";
      while (current_node != nullptr) {
        string_representation += current_node->value + "\n";

        current_node = current_node->next_node;
      }

      return string_representation;
    }

    template <typename U = T>
    ResolvedType<!Utils::HasOstreamOperator<U>::value, std::string>
    GetStringRepresentation() const {
      std::string string_representation = "Can't print type ";
      string_representation += typeid(T).name();
      string_representation += "\n";

      return string_representation;
    }

   private:
    struct StackNode;

    std::shared_ptr<StackNode> head_;

    size_t size_;
  };

  template <typename T>
  struct Stack<T>::StackNode {
   public:
    StackNode() : next_node{nullptr} {}

    explicit StackNode(const T& value,
                       const std::shared_ptr<StackNode>& next_node)
        : next_node{next_node}, value{value} {}

    explicit StackNode(T&& value,
                       const std::shared_ptr<StackNode>& next_node = nullptr)
        : value{std::forward<T>(value)}, next_node{next_node} {}

    explicit StackNode(const T& value,
                       std::shared_ptr<StackNode>&& next_node = nullptr)
        : value{value},
          next_node{std::forward<std::shared_ptr<StackNode>>(next_node)} {}

    explicit StackNode(T&& value,
                       std::shared_ptr<StackNode>&& next_node = nullptr)
        : value{std::forward<T>(value)},
          next_node{std::forward<std::shared_ptr<StackNode>>(next_node)} {}

    template <class... Args>
    explicit StackNode(Args&&... args)
        : value{std::forward<Args>(args)...}, next_node{nullptr} {}

    T value;

    std::shared_ptr<StackNode> next_node;
  };


}