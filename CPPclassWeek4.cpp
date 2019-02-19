//============================================================================
// Name        : cppClasswk4.cpp
// Author      : R. Bruce Tuckey    SP19-CS2363-TS02S
// Version     :
// Copyright   : Dr. Goulden         Mon 5:30-8:00
// Description : Week 4 in class
//============================================================================

#include <iostream>
#include <ctime>

using namespace std;

unsigned __int64 * theMemo;


unsigned __int64 fac_loop(int n) {
	unsigned __int64 result = 1;

	if (n > 0) {
		for (int x = 1; x <= n; x++) {
			result *= x;
		}
	}

	return result;
}


unsigned __int64 fac_rec(int n) {
	unsigned __int64 result = 1;
	if (n > 0) {
		result = n * fac_rec(n - 1);
	}
	return result;
}


unsigned __int64 fib_loop(int n) {
	int temp;
	unsigned __int64 num1 = 1;
	unsigned __int64 num2 = 1;
	int counter = 2;
	unsigned __int64 result = 1;
	bool exit = false;

	if (n > num1) {

		while (!exit) {

			result = num1 + num2;
			num1 = num2;
			num2 = result;
			counter++;
			//cout << result << " res" << endl;
			if (counter == n) {
				exit = true;
			}
		}
	}
	return result;
}

unsigned __int64 fib_rec(int n) {
	unsigned __int64 result = 1;
	if (n > 2) {
		if (theMemo[n] != 0) {
			result = theMemo[n];
		}
		else {
			result = fib_rec(n - 1) + fib_rec(n - 2);
			theMemo[n] = result;
		}
	}
	return result;
}

int main() {
	int n;
	cout << "Please enter an integer : "; // prints Week 4 in class
	cin >> n;

	cout << n << "!= " << fac_loop(n) << endl;
	clock_t start, stop;

	cout << n << "!= " << fac_rec(n) << endl;

	start = clock();
	theMemo = new unsigned __int64[n + 1];
	for (int i = 0; i < (n + 1); i++) {
		theMemo[i] = 0;
	}
	cout << "fib(" << n << ") = " << fib_loop(n) << endl;
	stop = clock();
	double elapsedTime = (stop - start) / CLOCKS_PER_SEC;
	cout << "took about " << elapsedTime << " seconds." << endl;

	start = clock();
	cout << "fibrec(" << n << ") = " << fib_rec(n) << endl;
	stop = clock();
	elapsedTime = (stop - start) / CLOCKS_PER_SEC;
	cout << "took about " << elapsedTime << " seconds." << endl;


	return 0;
}
