#include "queue.h"
#include <stdlib.h>

queue * queue_init() {
    queue* q = (queue *)malloc(sizeof(queue));
    if (q) {
        q->size = 0;
    }
    return q;
}
