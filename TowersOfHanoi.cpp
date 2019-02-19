//============================================================================
// Name        : cppClasswk4.cpp
// Author      : R. Bruce Tuckey    SP19-CS2363-TS02S
// Version     :
// Copyright   : Dr. Goulden         Mon 5:30-8:00
// Description : Towers of Hanoi
//============================================================================



//move n -1 to spare 
//move

#include <iostream>
#include <string>

void toh(int n, int start, int stop) {
	if(n==1){
		std::cout << " Move the disk from " << start << " to " << stop << std::endl;
	}
	else {
		//int spare = (6 - start) - stop;
		int spare = start ^ stop;
		toh(n - 1, start, spare);
		toh(1, start, stop);
		toh(n - 1, spare, stop);
		// && and      & - bitwise and
	}

}


using namespace std;


int main() {
	int n;
	cout << "Enter depth ";
	cin >> n;
	int start = 1;
	int stop = 2;
	
	toh(n, start, stop);


	return 0;
}