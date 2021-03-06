#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool takeSix(vector<int> &i) {
	if (i.size() != 6) {
		return false;
	}
	else
	{
		return true;
	}
}

bool noDups(vector<int> &i) {
	std::sort(i.begin(), i.end());
	if (std::unique(i.begin(), i.end()) == i.end()) {
		return false;
	}
	else {
		return true;
	}
}

bool withinBounds(int i) {
	return !(i < 1 || i > 46);
}


/// <summary>
/// Lotto Game for unit testing
/// </summary>
void main()
{
	vector<int> myNumbers = { 1, 2, 3, 4, 5, 6};
	cout << "Please enter 6 numbers between 1-46: " << endl;

	int num = 0;

	while (!takeSix(myNumbers)) {
		cin >> num;
		myNumbers.push_back(num);
	}

	if (takeSix(myNumbers) && noDups(myNumbers)) {
		cout << "Your Numbers: ";
		for (int i = 0; i < myNumbers.size(); i++) {
			if (withinBounds(myNumbers[i])) {
				if (i != myNumbers.size() - 1)
					cout << myNumbers[i] << ", ";
				else
					cout << myNumbers[i] << endl;
			}
		}
	}

	system("PAUSE");
}

