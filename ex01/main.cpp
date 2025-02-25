#include "Zombie.hpp"

int main()
{
  std::cout << "Creating a zombie using the constructor: " << std::endl;
  std::cout << "Type the name for every Zombie in the Horde!" << std::endl;
  std::string name;
  std::cin >> name;
  std::cout << "How many zombies do you want in the horde?" << std::endl;
  int N;
  std::cin >> N;
  Zombie* horde = zombieHorde(N, name);
  for (int i = 0; i < N; i++)
    horde[i].announce();
  delete[] horde;
  return 0;
}