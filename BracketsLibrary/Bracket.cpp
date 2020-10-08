#include "Bracket.hpp"

using namespace Brackets;

template <typename T>
Bracket<T>::Bracket(const T& bracket,
                 std::shared_ptr<BracketParser<T>> bracket_parser)
    : bracket_{bracket}, bracket_parser_{std::move(bracket_parser)} {
  if (bracket_parser_ != nullptr &&
      bracket_parser_->GetType(bracket_) == BracketType::UndefinedBracket) {
    throw UndefinedBracket();
  }
}

template <typename T>
typename Bracket<T>::BracketType Bracket<T>::GetType() const {
  if (bracket_parser_ == nullptr) {
    throw DontHaveParser();
  }

  return bracket_parser_->GetType(bracket_);
}

template <typename T>
bool Bracket<T>::IsMatching(const Bracket<T>& other_bracket) const {
  if (!bracket_parser_) {
    throw DontHaveParser();
  }

  return bracket_parser_->IsMatching(bracket_, other_bracket.bracket_);
}
