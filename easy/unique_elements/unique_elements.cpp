#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>

std::vector<int> clean(std::vector<int> const &v){
	std::vector<int>::iterator it;
	//it = std::unique(v.begin(), v.end());
	//v.resize(std::distance(v.begin(), it));
	return v;
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
			std::vector<int> v;
			while(std::getline(ss, number, ',')){ //push the numbers in a vector
				v.push_back(atoi(number.c_str()));
			}
			//TODO
		}
		file.close();
	} else {
		std::cerr << "could not open file: " << argv[1] << std::endl;
	}
	return 0;
}
