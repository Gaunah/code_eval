#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stdlib.h>
#include <string>

void printList(std::list<int> const &l){
	std::string str;
	for(int val : l){
		str += std::to_string(val) + ",";
	}
	std::cout << str.substr(0, str.size()-1) <<std::endl;
}

int main(int argc, char* argv[]){
	if(argc != 2){
		std::cerr << "usage: ./unique_elements <filename>" << std::endl;
		return 1;
	}

	std::ifstream file(argv[1]); // get filename and open
	if(file.is_open()){
		std::string line, number;
		while(std::getline(file, line)){ //read line by line
			std::stringstream ss(line);
			std::list<int> numberList;
			while(std::getline(ss, number, ',')){ //push the numbers in a vector
				numberList.push_back(atoi(number.c_str()));
			}
			numberList.unique();
			printList(numberList);
		}
		file.close();
	} else {
		std::cerr << "could not open file: " << argv[1] << std::endl;
	}
	return 0;
}
