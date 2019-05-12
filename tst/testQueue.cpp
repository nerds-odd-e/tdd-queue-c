#include "CppUTest/TestHarness.h"

extern "C" {
#include "queue.h"
}

TEST_GROUP(Queue) {
    queue * q;

    void setup() {
        q = queue_init();
    }

    void teardown() {
    }
};

TEST(Queue, init) {
    CHECK_EQUAL(0, q->size)
}

TEST(Queue, push) {
    int code = queue_push(q, 10);

    CHECK_TRUE(!code)
    CHECK_EQUAL(1, q->size)
}


