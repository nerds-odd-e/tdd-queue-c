#include <stdlib.h>
#include <queue.h>

queue * queue_malloc(){
    return (queue *) malloc(sizeof(queue));
}
