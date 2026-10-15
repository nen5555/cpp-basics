#include <gtest/gtest.h>
#include "ring_buffer.h"



// TEST(测试组名, 测试名)：每个 TEST 是一个独立的测试用例（test case）
TEST(RingBufferTest, NewBufferIsEmpty) {
    RingBuffer rb;
    EXPECT_TRUE(rb.empty());
    EXPECT_EQ(rb.size(), 0);
}