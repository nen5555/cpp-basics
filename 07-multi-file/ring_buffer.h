#pragma once

class ringBuffer{
    ringBuffer();
    bool empty();
    bool full();
    int size();
    bool push(int a);
    bool pop(int &a);

    private:
    const int Kcapacity;
};