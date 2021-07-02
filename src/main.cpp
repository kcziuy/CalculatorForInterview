#include <Calculator.hpp>

#include <iostream>

int main()
{
  setlocale(LC_ALL, "Russian");

  Calcutalor calc;

  try
  {
    std::cout << calc.calculate("0 - 10 + (8 * 2.5) - (3 / 1,5)") << std::endl;
  }
  catch (std::exception e)
  {
    std::cout << "Unable to parse expression!" << std::endl;
  }


  return 0;
}
