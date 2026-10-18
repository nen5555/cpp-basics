#include "ring_buffer.h"

RingBuffer::RingBuffer(): head_(0), tail_(0), counter_(0) {};

bool RingBuffer::empty() const {
    return counter_ == 0;
};


ool RingBuffer::full() const {
    return counter_ == Kcapacity;
};


int RingBuffer::size() const {
    return counter_;
};

bool RingBuffer::push(int a) {
    if(full()) {
        return false;
    }else{
        data_[head_]=a;
        head_ = (head_+1) % Kcapacity;
        counter_++;
        return true;
    }
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
