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

void initQueue(Queue* Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

// إضافة عنصر للنهاية (Enqueue)
int enqueue(Queue* Q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return -1;
    
    newNode->data = value;
    newNode->next = NULL;

    if (Q->rear == NULL) { // إذا كان الطابور فارغاً
        Q->front = Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
    return 1;
}

// حذف عنصر من البداية (Dequeue)
int dequeue(Queue* Q) {
    if (Q->front == NULL) return -1;

    int value = Q->front->data;
    Node* temp = Q->front;
    
    Q->front = Q->front->next;
    
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    
    free(temp);
    return value;
}
