#ifndef TEST_H
#define TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../nonblockingQueue.h"
#include "../nonblockingQueue.cpp"	

template <typename T>
class MockNonBlockingQueue : public nonBlockingQueue {
    MOCK_
};

#endif
