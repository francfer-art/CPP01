#include <iostream>

int main(int args, char **argv)
{
  if (args != 4)
  {
    std::cout << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
    return 1;
  }
  else 
  {
    std::cout << "Keep the process" << std::endl;
  }
}