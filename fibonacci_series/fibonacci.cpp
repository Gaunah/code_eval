#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>


int const fibo(int const &n) {
	if(n == 0){ return 0; }
	else if(n == 1){ return 1; }
	else{ return fibo(n-1) + fibo(n-2); }
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
			std::cout << fibo(atoi(line.c_str())) << std::endl;
		}
	} else {
		std::cerr << "could not open file: " << argv[1] << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
