#include "BracketParser.hpp"

using namespace Brackets;

template <typename T>
BracketParser<T>::BracketParser(const BracketsVector& brackets_vector) {
  for (const auto& bracket_pair : brackets_vector) {
    auto [first_bracket, second_bracket] = bracket_pair;

    open_bracket_to_matching_close_[first_bracket] = second_bracket;

    bracket_to_type_[first_bracket] = BracketType::OpenBracket;
    bracket_to_type_[second_bracket] = BracketType::CloseBracket;
  }
};

template <typename T>
typename BracketParser<T>::BracketType BracketParser<T>::GetType(const T& bracket) {
  auto iterator = bracket_to_type_.find(bracket);

  if (iterator == bracket_to_type_.end()) {
    return BracketType::UndefinedBracket;
  }

  return iterator->second;
}

template <typename T>
bool BracketParser<T>::IsMatching(const T& first_bracket,
                              const T& second_bracket) {
  if (GetType(first_bracket) == BracketType::UndefinedBracket ||
      GetType(second_bracket) == BracketType::UndefinedBracket) {
    throw UndefinedBracket();
  }

  if (GetType(first_bracket) == BracketType::OpenBracket) {
    return open_bracket_to_matching_close_[first_bracket] == second_bracket;
  }

  if (GetType(second_bracket) == BracketType::OpenBracket) {
    return open_bracket_to_matching_close_[second_bracket] == first_bracket;
  }

  return false;
}