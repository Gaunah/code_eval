#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>


void intersect(std::vector<int> &v1, std::vector<int> &v2){
	for(unsigned int i = 0; i < v1.size(); i++){
		std::cout << v1[i] << " ";
	}
	std::cout << "| ";
	for(unsigned int i = 0; i < v2.size(); i++){
		std::cout << v2[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[]){
	if(argc != 2){
		std::cerr << "usage: ./bitpos <filename>" << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream file(argv[1]); //get filename and open
	if(file.is_open()){
		std::string line, set1, set2;
		while(std::getline(file, line)){ //read line by line
			std::vector<int> v1, v2;
			std::stringstream ss(line);
			std::getline(ss, set1, ';'); //get token
			std::getline(ss, set2, ';');
			std::stringstream s1(set1);
			std::stringstream s2(set2);
			std::string tmp;
			while(std::getline(s1, tmp, ',')){
				v1.push_back(atoi(tmp.c_str()));
			}
			while(std::getline(s2, tmp, ',')){
				v2.push_back(atoi(tmp.c_str()));
			}
			intersect(v1, v2);
		}
	} else {
		std::cerr << "could not open file: " << argv[1] << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
