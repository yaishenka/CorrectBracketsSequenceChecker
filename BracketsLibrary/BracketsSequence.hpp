/** @author yaishenka
    @date 08.10.2020 */
#pragma once

#include "Bracket.cpp"
#include "BracketParser.cpp"
#include "../ContainersLibrary/Stack/Stack.cpp"

namespace Brackets {
  template <typename T>
  class BracketSequence {
   public:
    using BracketsVector = typename BracketParser<T>::BracketsVector;

    BracketSequence() = delete;

    template <typename Container = std::vector<T>>
    BracketSequence(const Container& bracket_sequence,
                    const BracketsVector& brackets_vector);

    [[nodiscard]] bool IsCorrectBracketSequence() const;

   private:
    std::shared_ptr<BracketParser<T>> bracket_parser_;

    std::vector<Bracket<T>> bracket_sequence_;
  };
}