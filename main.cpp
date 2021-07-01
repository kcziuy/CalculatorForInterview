#include <iostream>
#include <stack>
#include <algorithm>
#include <exception>
#include <vector>

int priority(char symbol)
{
  if(symbol == '^')
    return 4;
  else if(symbol == '/')
    return 3;
  else if(symbol=='*')
    return 2;
  else if(symbol == '+' || symbol == '-')
    return 1;
  else
    return 0;
}

std::vector<std::string> infixToSplittedPostfix(std::string infix)
{
  infix.erase(std::remove_if(infix.begin(), infix.end(), ::isspace), infix.end());

  std::stack<char> stack;
  std::vector<std::string> postfixVector;

  size_t instringCounter = 0;
  while(instringCounter < infix.length())
  {
    char symbol = infix[instringCounter];
    if(!((symbol >= '0' && symbol <= '9') ||
          symbol == '.'              ||
          symbol == ','              ||
          symbol == '+'              ||
          symbol == '-'              ||
          symbol == '*'              ||
          symbol == '/'              ||
          symbol == '('              ||
          symbol == ')'              ))
      throw std::exception();

    if(symbol >= '0' && symbol <= '9')
    {
      bool hasdot = false;
      std::string number;
      while((symbol >= '0' && symbol <= '9') ||
            (symbol == '.' || symbol == ','))
      {
        if((symbol == '.' || symbol == ',') && hasdot)
          throw std::exception();

        if((symbol == '.' || symbol == ',') && !hasdot)
          hasdot = true;

        number += symbol;
        symbol = infix[++instringCounter];
      }
      postfixVector.push_back(number);
      symbol = infix[--instringCounter];
    }
    else if(symbol == '(')
      stack.push('(');
    else if(symbol == ')')
    {
      while(stack.top() != '(')
      {
        postfixVector.push_back(std::string(1, stack.top()));
        stack.pop();
      }
      stack.pop();
    }
    else
    {
      while(!stack.empty() && priority(symbol) <= priority(stack.top()))
      {
        postfixVector.push_back(std::string(1, stack.top()));
        stack.pop();
      }
      stack.push(symbol);
    }

    instringCounter++;
  }

  while(!stack.empty())
  {
    postfixVector.push_back(std::string(1, stack.top()));
    stack.pop();
  }

  return postfixVector;
}

int main()
{
  std::string exp = "1 + (2 * (2.5 + 2.52 + (3 - 2))) - (3 / 1.5)";
  auto vectorizedPostfix = infixToSplittedPostfix(exp);
  for(const auto &part : vectorizedPostfix)
    std::cout << part << std::endl;
  return 0;
}
