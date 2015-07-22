#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>


void intersect(std::vector<int> &v1, std::vector<int> &v2){
	using namespace std;
	vector<int> intersect_v;
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(intersect_v));
	sort(intersect_v.begin(), intersect_v.end());
	for(unsigned int i = 0; i < intersect_v.size(); i++){
		cout << intersect_v[i];
		if(i != intersect_v.size()-1){ cout << ','; }
	}
	cout << endl;
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
