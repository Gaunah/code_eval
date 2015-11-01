#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>


void const bitpos(int n, int p1, int p2) {
	bool b1 = (n & (1 << (p1-1)));
	bool b2 = (n & (1 << (p2-1)));
	std::cout << (b1 == b2 ? "true" : "false") << std::endl;
}

int main(int argc, char* argv[]){
	if(argc != 2){
		std::cerr << "usage: ./bitpos <filename>" << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream file(argv[1]); //get filename and open
	if(file.is_open()){
		std::string line, n, p1, p2;
		while(std::getline(file, line)){ //read line by line
			std::stringstream ss(line);
			std::getline(ss, n, ','); //get token
			std::getline(ss, p1, ',');
			std::getline(ss, p2, ',');
			bitpos(atoi(n.c_str()), atoi(p1.c_str()), atoi(p2.c_str()));
		}
	} else {
		std::cerr << "could not open file: " << argv[1] << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
