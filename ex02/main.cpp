#include <iostream>

int main()
{
  std::string test = "HI THIS IS BRAIN";
  std::string *stringPTR = &test;
  std::string &stringREF = test;
  std::cout << "Memory address of the string: " << &test << std::endl;
  std::cout << "Memory address of the stringPTR: " << stringPTR << std::endl;
  std::cout << "Memory address of the stringREF: " << &stringREF << std::endl;
  std::cout << "Value of the string: " << test << std::endl;
  std::cout << "Value of the stringPTR: " << *stringPTR << std::endl;
  std::cout << "Value of the stringREF: " << stringREF << std::endl;
  return 0;
}