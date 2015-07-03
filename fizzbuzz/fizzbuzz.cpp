#include <boost/algorithm/string.hpp>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>


void print(int x, int y, int count){
	for(int i = 1; i <= count; i++){
		if(i % x == 0) { std::cout << "F"; }
		if(i % y == 0) { std::cout << "B"; }
		if(i % x != 0 && i % y != 0) {std::cout << i; }
		if(i != count) { std::cout << " "; }
		else { std::cout << std::endl;}
	}	
}

int main(int argc, char* argv[]) {
	if(argc != 2){
		std::cerr << "usage: ./fizzbuzz <filename>" << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream file(argv[1]); // get filename and open
	if(file.is_open()){
		std::string line;
		while(std::getline(file, line)){ //read line by line
			std::vector<std::string> fields;
			boost::split(fields, line, boost::is_any_of(" ")); //slpit by " "
			print(atoi(fields[0].c_str()), atoi(fields[1].c_str()), atoi(fields[2].c_str()));
		}
		file.close();
	} else {
		std::cerr << "could not open file: " << argv[1] << std::endl;
	}

	return EXIT_SUCCESS;
}
