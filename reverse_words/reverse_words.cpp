#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>


void print_backwards(std::vector<std::string> words){
	if(words.size() == 0){ return; }
	std::string str;
	std::vector<std::string>::reverse_iterator rit = words.rbegin();
	for(; rit != words.rend(); rit++){
		str += *rit + " ";
	}	
	std::cout << str.erase(str.find_last_not_of(" ")+1) << std::endl;
}

int main(int argc, char* argv[]){
	if(argc != 2){
		std::cerr << "usage: ./reverse_words <filename>" << std::endl;
		return EXIT_FAILURE;
	}	

	std::fstream file(argv[1]); // get filename and open it
	if(file.is_open()){
		std::string line;
		while(std::getline(file, line)){ //read line by line
			std::stringstream ss(line);
			std::vector<std::string> words;
			for(std::string word; ss >> word;){
				words.push_back(word); //split by whitespace and push into vector
			}
			print_backwards(words);
		}
	}else {
		std::cerr << "could not open file: " << argv[1] << std::endl;
	}
	return EXIT_SUCCESS;
}
