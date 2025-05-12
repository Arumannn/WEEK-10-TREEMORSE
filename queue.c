#include "queue.h"
#include <stdio.h>

void initQueue(Queue *Q) {
    Front(Q) = -1;
    Rear(Q) = -1;
}

boolean isQueueEmpty(Queue *Q) {
    return (Front(Q) == -1 || Rear(Q) == -1);
}

boolean isQueuefull(Queue *Q) {
    return (Front(Q) == (Rear(Q) + 1) % jml_maks);
}

void endQueue(Queue *Q, address X) {
    if (!isQueuefull(Q)) {
        if (isQueueEmpty(Q)) {
            Front(Q) = 0;
            Rear(Q) = 0;
        } else {
            Rear(Q) = (Rear(Q) + 1) % jml_maks;
        }
        Items(Q)[Rear(Q)] = X;
    } else {
        printf("Sudah penuh\n");
    }
}

address deQueue(Queue *Q) {
    if (!isQueueEmpty(Q)) {
        address X = Items(Q)[Front(Q)];
        if (Front(Q) == Rear(Q)) {
            Front(Q) = -1;
            Rear(Q) = -1;
        } else {
            Front(Q) = (Front(Q) + 1) % jml_maks;
        }
        return X;
    } else {
        printf("Queue Kosong\n");
        return NULL;
    }
}

void display(Queue *Q) {
    if (!isQueueEmpty(Q)) {
        int i = Front(Q);
        while (1) {
            printf(" -> %p", (void *)Items(Q)[i]);  // tampilkan pointer
            if (i == Rear(Q)) break;
            i = (i + 1) % jml_maks;
        }
        printf("\n");
    } else {
        printf("Queue Kosong\n");
    }
}

address peek(Queue *Q) {
    if (!isQueueEmpty(Q)) {
        return Items(Q)[Rear(Q)];
    } else {
        printf("List masih kosong\n");
        return NULL;
    }
}
