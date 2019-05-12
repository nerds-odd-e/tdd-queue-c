#include "queue.h"
#include <stdlib.h>

queue * queue_init() {
    queue* q = (queue *)malloc(sizeof(queue));
    if (q) {
        q->size = 0;
        q->cursor = 0;
    }
    return q;
}

int queue_push(queue *q, int value) {
    q->values[q->size++] = value;
    return 0;
}

int queue_pop(queue *q, int *value) {
    if (q->size == 0) {
        return QUEUE_EMPTY;
    }

    q->size--;
    *value = q->values[q->cursor++];
    return 0;
}
