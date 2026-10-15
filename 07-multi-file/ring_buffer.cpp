#include "ring_buffer.h"

RingBuffer::RingBuffer(): head_(0), tail_(0), counter_(0) {};

bool RingBuffer::empty() {
    return counter_ == 0;
};


bool RingBuffer::full() {
    return counter_ == Kcapacity;
};


int RingBuffer::size() {
    return counter_;
};

bool RingBuffer::push(int a) {
    if (full()) {
        return false;
    }
    data_[head_] = a;
    head_ = (head_ + 1) % Kcapacity;
    counter_++;
    return true;
};

bool RingBuffer::pop(int &a) {
    if (empty()) {
        return false;
    }
    a = data_[tail_];
    tail_ = (tail_ + 1) % Kcapacity;
    counter_--;
    return true;
};
