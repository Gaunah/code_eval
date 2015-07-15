#include <iostream>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
	if(argc != 2){
		std::cerr << "usage: ./file_size <filename>";
		return EXIT_FAILURE;
	}

	struct stat fs;
	stat(argv[1], &fs);
	std::cout << fs.st_size << std::endl;

	return EXIT_SUCCESS;
}
