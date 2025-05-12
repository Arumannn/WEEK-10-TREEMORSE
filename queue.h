#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "treeman.h"  // untuk tipe 'address'

#define jml_maks 20
#define Front(Q) (Q)->Front 
#define Rear(Q) (Q)->Rear
#define Items(Q) (Q)->Items

typedef struct {
    int Front;
    address Items[jml_maks + 1];  // dari int jadi address
    int Rear;
} Queue;

void initQueue(Queue *Q);

boolean isQueueEmpty(Queue *Q);

boolean isQueuefull(Queue *Q);

void endQueue(Queue *Q, address X);  // dari int X jadi address X

address deQueue(Queue *Q);  // dari int ke address

void display(Queue *Q);

address peek(Queue *Q);

#endif
