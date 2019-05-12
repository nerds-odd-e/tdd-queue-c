#include "CppUTest/TestHarness.h"

extern "C" {
#include "queue.h"
}

TEST_GROUP(Queue){

    void setup() {
    }

    void teardown() {
    }
};

TEST(Queue, init) {
    queue* q = queue_init();
    CHECK_EQUAL(0, q->size);
}


