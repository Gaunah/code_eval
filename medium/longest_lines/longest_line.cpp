#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

void PrintLongestLines(std::vector<std::string> &lines, int const &count){
	using namespace std;
	for(int i = 0; i < count; i++){
		cout << lines[i] << endl;
	}
}

int main(int argc, char* argv[]){
	if(argc != 2){
		std::cerr << "usage: ./longest_line <filename>" << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream file(argv[1]); //get filename and open
	if(file.is_open()){
		std::string line, n;
		std::getline(file, n);
		int count = std::stoi(n); //how many lines to print
		std::vector<std::string> lines;
		while(std::getline(file, line)){ //read line by line
			lines.push_back(line);
		}
		PrintLongestLines(lines, count);
	} else {
		std::cerr << "could not open file: " << argv[1] << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
