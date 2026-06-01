#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

// Borrow the Node structure from linked_list.h
#include "linked_list.h"

/* * The Queue structure tracks the 'front' and 'rear' nodes.
 * It uses the 'Node' type defined inside linked_list.h
 */
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

/* --- FUNCTION PROTOTYPES --- */
int enqueue(Queue* Q, int val);
int dequeue(Queue* Q);
int isEmptyQueue(Queue* Q);

#endif /* QUEUE_H */
