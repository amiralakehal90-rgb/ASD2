#include "../include/queue.h"      // It represent the path towards my header (library)
#include <stdio.h>
#include <stdlib.h>

// fun 01
 
void initQueue(Queue* Q){
    Q->front = NULL;
    Q->rear = NULL;
}

// fun 02
 
int enqueue(Queue* Q, int value){

    /* Allocate memory for the new node */
    Node* node = malloc(sizeof(Node));
    if (node == NULL)
        return -1;  /* Allocation failed */

    node->data = value; 
    node->next = NULL;   

    /* If queue is empty, both front and rear point to the new node */
    if (Q->front == NULL)
    {
        Q->front = node;
        Q->rear  = node;
    }
    else
    {
        Q->rear->next = node;  /* Link new node after current rear */
        Q->rear = node;  /* Update rear to the new node */
    }

    return 1;
}

// fun 03

int dequeue(Queue* Q){
   int value;
    Node* temp;

    if (Q->front == NULL)
        return -1;  

    value = Q->front->data;  /* Save the front value to return */
    temp  = Q->front;        /* Save pointer to free it later */

    Q->front = Q->front->next;  /* Move front to the next node */

    if (Q->front == NULL)
        Q->rear = NULL;

    free(temp);  /* Free the old front node */

    return value;
}

// fun 04 

#define MAX 5
int front(Queue* Q)
{
    if (Q->size == 0)
    {
        printf("Queue is empty\n");
        return -1;
    }

    return Q->data[Q->front];

    return Q->data[(Q->rear - 1 + MAX) % MAX];
}