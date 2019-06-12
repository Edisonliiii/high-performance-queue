#include <queue>
#include <mutex>
#ifndef NONBLOCKINGQUEUE_H
#define NONBLOCKINGQUEUE_H

template<typename T>
class nonBlockingQueue {
private:
	int limit;
	std::mutex mtx;
	std::condition_variable empty_checker;
	std::condition_variable full_checker;
	std::queue<T> _queue;
public:
	nonBlockingQueue(int maxLen) : limit(maxLen){}

	void push_in(T val);
	void pop_off();
	T get_front() const;
	size_t get_size() const;
};
#endif