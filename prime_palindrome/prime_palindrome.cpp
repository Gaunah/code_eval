#include <iostream>
#include <string>

int main(){
	int max = 1;
	for(int i = 1; i <= 1000; i++){
		//prime check
		int count = 0;
		for(int k = 2; k < i; k++){
			if(i % k == 0){ count++; }
		}
		if(count != 0){ continue; }
		//palindrom check
		std::string str = std::to_string(i);
		if(str == std::string(str.rbegin(), str.rend())){
			max = i;	
		}
	}
	std::cout << max << std::endl;
	return 0;
}
