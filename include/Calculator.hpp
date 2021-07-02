#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <vector>
#include <string>

class Calcutalor
{
public:
  Calcutalor() = default;

  double calculate(const std::string& mathExpression);

private:
  int priority(const char& c);
  std::vector<std::string> infixToSplittedPostfix(std::string);

  bool isOperator(const char& c);
  double calculatePotfix(const std::vector<std::string>& postfix);

};


#endif // CALCULATOR_HPP
