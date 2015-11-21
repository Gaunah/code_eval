#include <fstream>
#include <iostream>
#include <string>
#include <vector>


void DetectingCycles(std::vector<int> const &line){
	//TODO	
}

int main(int argc, char* argv[]){
	if(argc != 2){
		std::cerr << "usage: ./detecting_cycles <filename>" << std::endl;
		return -1;
	}

	std::ifstream file(argv[1]); //get filename and open
	if(file.is_open()){
		std::string line;
		while(std::getline(file, line)){ //read line by line
			//TODO token -> convert -> pushback
		}
	} else {
		std::cerr << "could not open file: " << argv[1] << std::endl;
		return -1;
	}
	return 0;
}
