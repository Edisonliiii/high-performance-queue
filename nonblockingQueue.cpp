#include "nonblockingQueue.h"
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <chrono>

template<typename T>
size_t nonBlockingQueue<T>::get_size() {
	return _queue.size();
}

template<typename T>
T nonBlockingQueue<T>::get_front() {
	return _queue.front();
}

template<typename T>
void nonBlockingQueue<T>::push_in(T val) {
	std::unique_lock<std::mutex> lock(mtx);
	while (_queue.size()==limit && full_checker.wait_for(lock, std::chrono::seconds(1))!=std::cv_status::timeout){std::cout<<"!"<<std::endl;};
	//std::cout<<"***Pushing: "<<val<<" Size: "<<_queue.size()<<std::endl;
	if (_queue.size()!=limit) {_queue.push(val);empty_checker.notify_one();}
}

template<typename T>
void nonBlockingQueue<T>::pop_off() {
	std::unique_lock<std::mutex> lock(mtx);
	while (_queue.empty() && empty_checker.wait_for(lock, std::chrono::seconds(1))!=std::cv_status::timeout){std::cout<<"!"<<std::endl;};
	std::cout<<"---Popping: "<<_queue.front()<<std::endl;
	if (!_queue.empty()){_queue.pop(); full_checker.notify_one();}
}