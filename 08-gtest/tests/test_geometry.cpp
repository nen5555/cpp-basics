#include <gtest/gtest.h>
#include "geometry.h"


// calcu area
TEST(geometrytest, calcu) {
    for(int i=0;i<200;i++){
        for(int j=0;j<200;j++){
            Rect r{{0, 0}, i, j};
            EXPECT_EQ(area(r), i*j);
        }
    }

}

// TEST(测试组名, 测试名)：每个 TEST 是一个独立的测试用例（test case）
TEST(geometrytest, containstest) {
    for(int i=0;i<200;i++){
        for(int j=0;j<200;j++){
            Rect r{{0, 0}, i, j};
            Point p1{0, 0};
            Point p2{i, j};
            Point p3{i/2, j/2};
            Point p4{i+1, j+1};
            EXPECT_TRUE(contains(r,p1));
            EXPECT_TRUE(contains(r,p2));
            EXPECT_TRUE(contains(r,p3));
            EXPECT_FALSE(contains(r,p4));
        }
    }

}

TEST(geometrytest   , intersectAreatest) {
    Rect r1{{0, 0}, 10, 5};
    Rect r2{{1, 1}, 2, 2};
    Rect r3{{5, 3}, 10, 5};
    Rect r4{{-1, -1}, 2, 2};
    Rect r5{{11, 6}, 2, 2};

    EXPECT_EQ(intersectArea(r1,r2),4);
    EXPECT_EQ(intersectArea(r1,r3),10);
    EXPECT_EQ(intersectArea(r1,r4),1);
    EXPECT_EQ(intersectArea(r1,r5),0);

}

