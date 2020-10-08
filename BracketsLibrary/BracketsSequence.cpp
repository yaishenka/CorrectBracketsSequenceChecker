#include "BracketsSequence.hpp"

using namespace Brackets;

template <typename T>
template <typename Container>
BracketSequence<T>::BracketSequence(const Container& bracket_sequence,
                const BracketsVector& brackets_vector) {
  bracket_parser_ = std::make_shared<BracketParser<T>>(brackets_vector);

  bracket_sequence_.reserve(bracket_sequence.size());
  for (const auto& bracket : bracket_sequence) {
    bracket_sequence_.emplace_back(bracket, bracket_parser_);
  }
}

template <typename T>
bool BracketSequence<T>::IsCorrectBracketSequence() const {
  Containers::Stack<Bracket<T>> brackets_stack;

  for (const auto& bracket : bracket_sequence_) {
    switch (bracket.GetType()) {
      case Bracket<T>::BracketType::OpenBracket:
        brackets_stack.Push(bracket);
        break;
      case Bracket<T>::BracketType::CloseBracket:
        if (brackets_stack.IsEmpty()) {
          return false;
        }

        if (brackets_stack.GetTop().IsMatching(bracket)) {
          brackets_stack.Pop();
          break;
        }

        return false;
      default:
        throw UndefinedBracket();
    }
  }

  return brackets_stack.IsEmpty();
}