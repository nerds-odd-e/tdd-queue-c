#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

typedef struct {
    int size;
    int values[100];
} queue;

queue* queue_init();

int queue_push(queue* q, int value);

int queue_pop(queue* q, int* value);

#endif //QUEUE_QUEUE_H
