#include "CppUTest/TestHarness.h"

extern "C" {
#include "queue.h"
}

TEST_GROUP(Queue) {
    queue *q;

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

TEST(Queue, popAfterPush) {
    queue_push(q, 10);
    int value = 0;

    int code = queue_pop(q, &value);

    CHECK_EQUAL(10, value)
    CHECK_TRUE(!code)
    CHECK_EQUAL(0, q->size)
}

TEST(Queue, popRightAfterInit) {
    int value = 5;

    int code = queue_pop(q, &value);

    CHECK_EQUAL(QUEUE_EMPTY, code);
    CHECK_EQUAL(5, value);
}

TEST(Queue, pushPushAndPop) {
    queue_push(q, 10);
    queue_push(q, 15);
    int value = 0;

    int code = queue_pop(q, &value);

    CHECK_EQUAL(10, value)
    CHECK_TRUE(!code)
    CHECK_EQUAL(1, q->size)
}

TEST(Queue, pushPushPopAndPop) {
    queue_push(q, 10);
    queue_push(q, 15);
    int value = 0;
    queue_pop(q, &value);

    int code = queue_pop(q, &value);

    CHECK_EQUAL(15, value)
    CHECK_TRUE(!code)
    CHECK_EQUAL(0, q->size)
}

