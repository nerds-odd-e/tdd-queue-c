#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

typedef struct {
    int size;
} queue;

queue* queue_init();

int queue_push(queue* q, int value);

#endif //QUEUE_QUEUE_H
