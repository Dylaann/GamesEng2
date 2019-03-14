/*
* Dylan Murphy: Tie-Breaker Algorithm
*/
#include <thread>
#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;

bool flags[2] = { false, false };
int last = 1;

int const n = 3;
int nFlags[n] { 0 };
int nLast[n] { 0 };

int cs(int i) {

	while (true) {
		for (int j = 0; j < n; j++) {

			nFlags[i] = j;
			nLast[j] = i;

			for (int k = 0; k < n; k++) {
				if (i != k) {
					while (nFlags[k] >= nFlags[i] && nLast[j] == i) {
						continue;
					}
				}
			}
		}

		//Critical section
		std::cout << i << std::endl;
		nFlags[i] = -1;
		//Non Critical section
	}

	return 1;
}

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

	vector<std::thread> m_nThreads;

	// Pertersons Algorithm
	//std::thread thread1(cs1);
	//std::thread thread2(cs2);

	//thread1.join();
	//thread2.join();

	// N Proccesses Algorithm
	for (int i = 0; i < n; i++) {
		m_nThreads.push_back(std::thread(cs, i));
	}

	for (int i = 0; i < (int)m_nThreads.size(); i++) {
		m_nThreads.at(i).join();
	}

	system("PAUSE");
	return 0;
}