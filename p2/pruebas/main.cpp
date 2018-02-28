#include <fstream>
#include <iostream>

#define BI2UNI(i, j, n) i*n + j

void foo(std::istream &is){
	while (!is.eof()){
		int x;
		is >> x;
		std::cout << x << std::endl;
	}
}

int main(void){
	//std::ifstream ifs("x.txt", std::fstream::in);
	//foo(ifs);
	//std::cout << BI2UNI(3, 4, 5) << std::endl;
	for(int i = 0; i > -23; i--)
		std::cout << i % 4  << std::endl;
}
