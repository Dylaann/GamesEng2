/*
* Dylan Murphy: Producer Consumer Lab
*/
#include <thread>
#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mx;
condition_variable cv;
deque<int> q;

int thread_size = 0;
const int max_thread_size = 2;

int produced = 0;
int consumed = 0;

/*
* Producer
* .
*/
void producer(int n) {
	int count = n;

	while (count > 0) {
		unique_lock<mutex> lck(mx);
		q.push_front(count);
		produced++;
		cout << "Produced: " << produced << endl;
		lck.unlock();
		cv.notify_one();
		count--;
	}
}

/*
* Consumer
*/
void consumer() {
	int count = 0;

	while (count != 1) {
		unique_lock<mutex> lck(mx);
		cv.wait(lck, []() { return !q.empty(); });
		count = q.back();
		q.pop_back();
		consumed++;
		cout << "Consumed: " << count << endl;
		lck.unlock();
	}
}

int main() {
	
	thread m_producers[max_thread_size];
	thread m_consumers[max_thread_size];

	/* Initialize customers and cheifs */
	for (int i = 0; i < max_thread_size; i++) {
		m_producers[i] = thread(producer, 100);
		m_consumers[i] = thread(consumer);
	}

	/* Join the threads to the main threads */
	for (int i = 0; i < max_thread_size; i++) {
		m_producers[i].join();
		m_consumers[i].join();
	}

	system("PAUSE");
	return 0;
}