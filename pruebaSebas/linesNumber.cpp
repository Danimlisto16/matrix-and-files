#include <iostream>
#include <fstream>
#include <string.h>

int main() { 
    int number_of_lines = 0;
    std::string line;
    std::ifstream myfile("datos.txt");

    while (std::getline(myfile, line))
        ++number_of_lines;
    std::cout << "Number of lines in text file: " << number_of_lines;
    return 0;
}
