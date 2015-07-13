#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>


void const fibo(std::string const &str) {
	
}

int main(int argc, char* argv[]){
	if(argc != 2){
		std::cerr << "usage: ./fibonacci <filename>" << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream file(argv[1]); //get filename and open
	if(file.is_open()){
		std::string line;
		while(std::getline(file, line)){ //read line by line
			fibo(line);
		}
	} else {
		std::cerr << "could not open file: " << argv[1] << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
