#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>


void find_smallest_mulltiple(int x, int n){
	std::cout << "x: " << x << " n: " << n << std::endl;	
}

int main(int argc, char* argv[]){
	if(argc != 2){
		std::cerr << "usage: ./moan <filename>" << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream file(argv[1]); //get filename and open
	if(file.is_open()){
		std::string line, x, n;
		while(std::getline(file, line)){
			std::stringstream ss(line);
			std::getline(ss, x, ',');
			std::getline(ss, n, ',');
			find_smallest_mulltiple(atoi(x.c_str()), atoi(n.c_str()));
		}
	} else {
		std::cerr << "could not open file: " << argv[1] << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
