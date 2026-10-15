#include <gtest/gtest.h>
#include "ring_buffer.h"



// TEST(测试组名, 测试名)：每个 TEST 是一个独立的测试用例（test case）
TEST(RingBufferTest, NewBufferIsEmpty) {
    RingBuffer rb;
    EXPECT_TRUE(rb.empty());
    EXPECT_EQ(rb.size(), 0);

    for(int i = 0; i < 4; ++i) {
        rb.push(i);
    }
    EXPECT_TRUE(rb.full());

    int value;
    EXPECT_TRUE(rb.pop(value));
    EXPECT_EQ(value, 0);

    int vlaue;
    EXPECT_TRUE(rb.pop(vlaue));
    EXPECT_EQ(vlaue, 1);

    EXPECT_TRUE(rb.push(5));
    EXPECT_TRUE(rb.push(6));

    while(!rb.empty()) {
        int value;
        EXPECT_TRUE(rb.pop(value));
    }
    int value2;
    EXPECT_FALSE(rb.pop(value2));
}

// TEST(测试组名, 测试名)：每个 TEST 是一个独立的测试用例（test case）
TEST(RingBufferTest, PushUntilFull) {
    RingBuffer rb;
    for(int i = 0; i < 4; ++i) {
        EXPECT_TRUE(rb.push(i));
    }
    EXPECT_TRUE(rb.full());
    EXPECT_FALSE(rb.push(4)); // Should not be able to push when full

}

TEST(RingBufferTest, FifoOrder) {
    RingBuffer rb;
    for(int i = 0; i < 4; ++i) {
        EXPECT_TRUE(rb.push(i));
    }
    int value,value1,value2,value3;
    EXPECT_TRUE(rb.pop(value));
    EXPECT_EQ(value, 0);
    EXPECT_TRUE(rb.pop(value1));
    EXPECT_EQ(value1, 1);   
    EXPECT_TRUE(rb.pop(value2));
    EXPECT_EQ(value2, 2);
    EXPECT_TRUE(rb.pop(value3));
    EXPECT_EQ(value3, 3);

}


TEST(RingBufferTest, WrapAround) {
    RingBuffer rb;
    for(int i = 0; i < 4; ++i) {
        EXPECT_TRUE(rb.push(i));
    }
    int value,value1,value2,value3;
    EXPECT_TRUE(rb.pop(value));
    EXPECT_EQ(value, 0);
    EXPECT_TRUE(rb.pop(value1));
    EXPECT_EQ(value1, 1);   
    EXPECT_TRUE(rb.pop(value2));
    EXPECT_EQ(value2, 2);
    EXPECT_TRUE(rb.pop(value3));
    EXPECT_EQ(value3, 3);

    

    EXPECT_TRUE(rb.push(5));
    EXPECT_TRUE(rb.push(6));

    int value5,value6;

    ASSERT_TRUE(rb.pop(value5));
    EXPECT_EQ(value5, 5);
    ASSERT_TRUE(rb.pop(value6));
    EXPECT_EQ(value6, 6);

}

TEST(RingBufferTest, PopFromEmptyFails) {
    RingBuffer rb;
    EXPECT_TRUE(rb.empty());

    int value;
    ASSERT_FALSE(rb.pop(value));

    

}

