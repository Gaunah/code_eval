#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>


void const sum(std::string const &str)
{
    int sum = 0;
    for (char const c : str) {
        sum += (c - '0');
    }
    std::cout << sum << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "usage: ./sod <filename>" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream file(argv[1]); //get filename and open
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) { //read line by line
            sum(line);
        }
    } else {
        std::cerr << "could not open file: " << argv[1] << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
