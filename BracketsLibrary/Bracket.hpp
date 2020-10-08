/** @author yaishenka
    @date 08.10.2020 */
#pragma once

#include <memory>
#include "BracketParser.hpp"

namespace Brackets {
  template <typename T>
  class Bracket {
   public:
    using BracketType = typename BracketParser<T>::BracketType;

    Bracket() = default;

    explicit Bracket(const T& bracket,
                     std::shared_ptr<BracketParser<T>> bracket_parser = nullptr);

    Bracket(const Bracket& bracket) = default;

    bool operator==(const T& other_bracket) const {
      return bracket_ == other_bracket.bracket_;
    }

    [[nodiscard]] BracketType GetType() const;

    [[nodiscard]] bool IsMatching(const Bracket<T>& other_bracket) const;

   private:
    T bracket_;

    std::shared_ptr<BracketParser<T>> bracket_parser_;
  };
}