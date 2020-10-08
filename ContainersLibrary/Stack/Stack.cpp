#include "Stack.hpp"

using namespace Containers;

template <typename T>
using StackNode = typename Stack<T>::StackNode;

template <typename T>
Stack<T>::Stack() : head_{nullptr}, size_{0} {}

template <typename T>
T& Stack<T>::GetTop() {
  if (IsEmpty()) {
    throw EmptyStack();
  }

  return head_->value;
}

template <typename T>
const T& Stack<T>::GetTop() const {
  if (IsEmpty()) {
    throw EmptyStack();
  }

  return head_->value;
}

template <typename T>
void Stack<T>::Push(const T& value) {
  head_ = std::make_shared<StackNode>(value, std::move(head_));

  ++size_;
}

template <typename T>
void Stack<T>::Push(T&& value) {
  head_ = std::make_shared<StackNode>(value, std::move(head_));

  ++size_;
}

template <typename T>
template <class... Args>
void Stack<T>::Emplace(Args&&... args) {
  auto new_node = std::make_shared<StackNode>(std::forward<Args>(args)...);
  new_node->next_node = std::move(head_);
  head_ = new_node;

  ++size_;
}

template <typename T>
void Stack<T>::Pop() {
  if (IsEmpty()) {
    return;
  }

  head_ = head_->next_node;
  --size_;
}