#include "queue.h"
#include <string.h>

void init_queue(Queue *q) {
    q->front = q->rear = 0;
}

void enqueue(Queue *q, Request r) {
    q->q[q->rear++] = r;
}

Request dequeue(Queue *q) {
    return q->q[q->front++];
}

int is_empty(Queue *q) {
    return q->front == q->rear;
}
