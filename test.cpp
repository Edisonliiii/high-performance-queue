#include "nonblockingQueue.h"
#include "nonblockingQueue.cpp"			// necessary; or link error
#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char const *argv[])
{
	// -- test_1: functionality
	//nonBlockingQueue<int> container(10);
	//container.push_in(1);
	//container.push_in(100);
	//std::cout<<container.get_front()<<std::endl;
	//std::cout<<container.get_size()<<std::endl;

	//  -- test_2: concurreny
	// randomization
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1,10);

	nonBlockingQueue<int> container(200000);
	std::vector<std::thread> arr(100000);
	for (int i=0; i<arr.size(); ++i) {
		//int tmp = dist6(rng);
		//if (tmp%2==0) 
		arr[i] = std::thread(&nonBlockingQueue<int>::push_in, &container, i);
		//else arr[i] = std::thread(&nonBlockingQueue<int>::pop_off, &container);
	}

	for (auto& thr : arr) thr.join();
	return 0;
}