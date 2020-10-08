#include <iostream>
#include "BracketsLibrary/BracketsSequence.cpp"

using namespace Brackets;

class Solver {
 public:
  void operator()() {
    BracketParser<char>::BracketsVector brackets_vector = {
        {'(', ')'}, {'[', ']'}, {'{', '}'}};

    std::string string_bracket_sequence;

    std::cin >> string_bracket_sequence;

    BracketSequence<char> bracket_sequence(string_bracket_sequence,
                                           brackets_vector);

    std::cout << (bracket_sequence.IsCorrectBracketSequence() ? "YES" : "NO");
  }
};

int main() {
  Solver solver;
  solver();
}
