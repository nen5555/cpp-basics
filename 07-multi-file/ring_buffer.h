#pragma once

class RingBuffer{
    public:
    RingBuffer();
    bool empty() const;
    bool full() const;
    int size() const;
    bool push(int a);
    bool pop(int &a);

    private:
    static const int Kcapacity=4;
    int data_[Kcapacity];
    int head_;
    int tail_;
    int counter_;
};