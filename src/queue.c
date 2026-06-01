#include <stdio.h>
#include <stdlib.h>

// This looks backward one directory, enters the include folder, and grabs queue.h
#include "../include/queue.h" 

int enqueue(Queue* Q, int value) {
    // 1. Allocate memory for a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return 0; // Allocation failed
    }

    newNode->data = value;
    newNode->next = NULL;

    // 2. If the queue is empty, the new node is both front and rear
    if (Q->rear == NULL) {
        Q->front = Q->rear = newNode;
    } else {
        // 3. Link the new node to the end and update rear
        Q->rear->next = newNode;
        Q->rear = newNode;
    }

    // Return 1 for success
    return 1; 
}
