#include <iostream>
#include <fstream>
#include <string>

void close_files(std::fstream &fs, std::fstream &fs1)
{
  fs.close();
  fs1.close();
}

int open_create_file(std::string filename, std::fstream &fs, std::fstream &fs1)
{
  // Intentamos abrir el archivo dado por argumento
  fs.open (filename, std::fstream::in | std::fstream::out);
  if (!fs.is_open())
  {
    std::cout << "Error while opening the file" << std::endl;
    return 0;
  }

  // Si todo va bien creamos y abrimos el archivo de salida
  std::string outputFile;
  outputFile = outputFile + filename + ".replace";
  std::ofstream outfile (outputFile);
  fs1.open (outputFile, std::fstream::in | std::fstream::out);
  if (!fs1.is_open())
  {
    std::cout << "Error while opening the file" << std::endl;
    fs.close();
    return 0;
  }
  return 1;
}

int replaceStrings(std::string filename, std::string string1, std::string string2)
{
  std::fstream fs;
  std::fstream fs1;
  // Abrimos los archivos
  if (!open_create_file(filename, fs, fs1))
    return 0;

  // Lógica para copiar el archivo y sustituir cada ocurrencia de s1 por s2
  std::string line;
  while (std::getline(fs, line))
  {
    std::string newLine;
    size_t pos = 0;
    while ((pos = line.find(string1)) != std::string::npos)
    {
      newLine += line.substr(0, pos) + string2;
      line = line.substr(pos + string1.length());
    }
    newLine += line;
    fs1 << newLine << std::endl;
  }
  // Cerramos los archivos
  close_files(fs, fs1);
  return 1;
}

int main(int args, char **argv)
{
  if (args != 4)
  {
    std::cout << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
    return 1;
  }
  else 
  {
    if (!replaceStrings(argv[1], argv[2], argv[3]))
    {
      std::cout << "Error while replacing the words" << std::endl;
      return 1;
    } else
    {
      std::cout << "The words were replaced successfully" << std::endl;
      return 0;
    }
  }
}
