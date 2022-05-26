#include <iostream>

using namespace std;

int main(void){
	int myArrayNumber[3] = {10, 20, 30};

	cout << "Array number: " << endl;
	cout << "[" ;
	for (int i = 0; i < 3 - 1; i++){
		cout << myArrayNumber[i] << ", ";
	}
	cout << myArrayNumber[2] << "]";

	return 0;
}
