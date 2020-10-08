/** @author yaishenka
    @date 08.10.2020 */
#pragma once

#include <vector>
#include <unordered_map>

namespace Brackets {
  class UndefinedBracket : public std::exception {
    [[nodiscard]] const char* what() const noexcept override {
      return "Can't find bracket in this bracket parser";
    }
  };

  class DontHaveParser : public std::exception {
    [[nodiscard]] const char* what() const noexcept override {
      return "Don't have pointer to bracket parser";
    }
  };

  template <typename T>
  class Bracket;

  template <typename T>
  class BracketParser {
   public:
    using BracketsVector = std::vector<std::pair<T, T>>;

    enum class BracketType { OpenBracket, CloseBracket, UndefinedBracket };

    BracketParser() = delete;
    explicit BracketParser(const BracketsVector& brackets_vector);

    [[nodiscard]] BracketType GetType(const T& bracket);

    [[nodiscard]] bool IsMatching(const T& first_bracket,
                                  const T& second_bracket);

   private:
    std::unordered_map<T, T> open_bracket_to_matching_close_;
    std::unordered_map<T, BracketType> bracket_to_type_;
  };
}