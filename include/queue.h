#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    char username[10];
    char ip[15];
    int status;
} Request;

typedef struct {
    Request q[100];
    int front, rear;
} Queue;

void init_queue(Queue *);
void enqueue(Queue *, Request);
Request dequeue(Queue *);
int is_empty(Queue *);

#endif
