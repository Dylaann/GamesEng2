/*
* Dylan Murphy: Tie-Breaker Algorithm
*/
#include <thread>
#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

bool flags[2] = { false, false };
int last = 1;

int cs1() {

	while (true) {
		flags[0] = true;
		last = 1;

		while (flags[1] && last == 1) {
			continue;
		}

		//Critical section
		cout << "CS1" << endl;
		flags[0] = false;
		//Non Critical section
	}

	return 1;
}

int cs2() {

	while (true) {
		flags[1] = true;
		last = 2;

		while (flags[0] && last == 2) {
			continue;
		}

		//Critical section
		cout << "CS2" << endl;
		flags[1] = false;
		//Non Critical section
	}

	return 1;
}


int main() {

	std::thread thread1(cs1);
	std::thread thread2(cs2);

	thread1.join();
	thread2.join();

	system("PAUSE");
	return 0;
}