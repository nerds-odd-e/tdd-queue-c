#include "queue.h"
#include <stdlib.h>

queue * queue_init() {
    queue* q = (queue *)malloc(sizeof(queue));
    if (q) {
        q->size = 0;
        q->readCursor = 0;
        q->writeCursor = 0;
    }
    return q;
}

int queue_push(queue *q, int value) {
    if(q->size == MAX_LEN) {
        return QUEUE_FULL;
    }
    q->values[q->writeCursor] = value;
    q->writeCursor = (q->writeCursor + 1) % MAX_LEN;
    q->size++;
    return 0;
}

int queue_pop(queue *q, int *value) {
    if (q->size == 0) {
        return QUEUE_EMPTY;
    }

    *value = q->values[q->readCursor];
    q->readCursor = (q->readCursor + 1) % MAX_LEN;
    q->size--;
    return 0;
}
