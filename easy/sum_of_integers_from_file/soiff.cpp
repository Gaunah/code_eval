#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>


int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "usage: ./soiff <filename>" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream file(argv[1]); //get filename and open
    if (file.is_open()) {
        std::string line;
        int sum = 0;
        while (std::getline(file, line)) { //read line by line
            sum += atoi(line.c_str());
        }
        std::cout << sum << std::endl;
    } else {
        std::cerr << "could not open file: " << argv[1] << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
