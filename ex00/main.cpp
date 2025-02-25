#include "Zombie.hpp"

int main()
{
  std::cout << "Creating a zombie using the constructor: " << std::endl;
  std::cout << "Insert the name of the Zombie1: ";
  std::string name;
  std::cin >> name;
  Zombie zombie = Zombie(name);
  zombie.announce();

  std::cout << "Creating a zombie using the newZombie(): " << std::endl;
  Zombie* zombie2 = newZombie("Zombie2");
  zombie2->announce();
  delete zombie2;

  std::cout << "Creating a zombie using the randomChump(): " << std::endl;
  randomChump("Zombie3");
  return 0;
}