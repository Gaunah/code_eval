#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>


int main(int argc, char* argv[]) {
	
	if(argc != 2){
		std::cerr << "usage: ./fizzbuzz <filename>" << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream file(argv[1]); // get filename and open
	if(file.is_open()){
		std::string line;
		while(std::getline(file, line)){
			std::cout << line << std::endl;	
		}
		file.close();
	} else {
		std::cerr << "could not open file: " << argv[1] << std::endl;
	}

	return EXIT_SUCCESS;
}
