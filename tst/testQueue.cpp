#include "CppUTest/TestHarness.h"

extern "C" {
#include "queue.h"
#include "fff.h"
}

DEFINE_FFF_GLOBALS
FAKE_VALUE_FUNC(queue*, queue_malloc)

TEST_GROUP(Queue) {
    queue *q;
    int value;
    int code;
    queue malloc_q;

    void setup() {
        queue_malloc_fake.return_val = &malloc_q;
        q = queue_init();
        value = 0;
        code = -1;
        RESET_FAKE(queue_malloc)
    }

    void teardown() {
    }

    void pushToMaxLen() {
        for (int i = 0; i < MAX_LEN; ++i) {
            queue_push(q, 10);
        }
    }

    void popToMaxLen() {
        for (int i = 0; i < MAX_LEN; ++i) {
            queue_pop(q, &value);
        }
    }

};

TEST(Queue, init) {
    CHECK_EQUAL(0, q->size)
}

TEST(Queue, push) {
    code = queue_push(q, 10);

    CHECK_TRUE(!code)
    CHECK_EQUAL(1, q->size)
}

TEST(Queue, popAfterPush) {
    queue_push(q, 10);

    code = queue_pop(q, &value);

    CHECK_EQUAL(10, value)
    CHECK_TRUE(!code)
    CHECK_EQUAL(0, q->size)
}

TEST(Queue, popRightAfterInit) {
    value = 5;

    code = queue_pop(q, &value);

    CHECK_EQUAL(QUEUE_EMPTY, code);
    CHECK_EQUAL(5, value);
}

TEST(Queue, pushPushAndPop) {
    queue_push(q, 10);
    queue_push(q, 15);

    code = queue_pop(q, &value);

    CHECK_EQUAL(10, value)
    CHECK_TRUE(!code)
    CHECK_EQUAL(1, q->size)
}

TEST(Queue, pushPushPopAndPop) {
    queue_push(q, 10);
    queue_push(q, 15);
    queue_pop(q, &value);

    code = queue_pop(q, &value);

    CHECK_EQUAL(15, value)
    CHECK_TRUE(!code)
    CHECK_EQUAL(0, q->size)
}

TEST(Queue, pushPopPushAndPop) {
    queue_push(q, 10);
    queue_pop(q, &value);
    queue_push(q, 20);

    queue_pop(q, &value);

    CHECK_EQUAL(20, value)
}

TEST(Queue, pushToMaxSize) {
    pushToMaxLen();

    code = queue_push(q, 15);

    CHECK_EQUAL(QUEUE_FULL, code)
}

TEST(Queue, canStillPushIfPopAfterPushToMaxSize) {
    pushToMaxLen();
    queue_pop(q, &value);

    code = queue_push(q, 15);

    CHECK_TRUE(!code)
    CHECK_EQUAL(15, q->values[0])
}

TEST(Queue, canStillPopAfterPopToMaxSize) {
    pushToMaxLen();
    popToMaxLen();
    queue_push(q, 15);

    code = queue_pop(q, &value);

    CHECK_TRUE(!code)
    CHECK_EQUAL(15, value)
}

TEST(Queue, initShouldMalloc) {
    queue malloc_q;
    queue_malloc_fake.return_val = &malloc_q;

    q = queue_init();

    CHECK_EQUAL(1, queue_malloc_fake.call_count)
    CHECK_EQUAL(&malloc_q, q)
}
