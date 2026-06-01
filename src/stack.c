#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>

// fun 01
 
void initStack(Stack* S)
{
    S->top = NULL;  /* No nodes yet, stack is empty */
}

// fun 02
 
int push(Stack* S, int value)
{
    /* Allocate memory for the new node */
    Node* node = malloc(sizeof(Node));
    if (node == NULL)
        return -1;  /* Allocation failed */

    node->data = value;   /* Set node value */
    node->next = S->top;  /* New node points to current top */
    S->top     = node;    /* Update top to the new node */

    return 1;  /* Push successful */
}

// fun 03
 
int pop(Stack* S)
{
    int value;
    Node* temp;

    /* Check if the stack is empty */
    if (S->top == NULL)
        return -1;  /* Nothing to pop, return sentinel */

    value  = S->top->data;  /* Save the top value to return */
    temp   = S->top;        /* Save pointer to free it later */

    S->top = S->top->next;  /* Move top to the next node */

    free(temp);  /* Free the old top node */

    return value;  /* Return the popped value */
}

// fun 04
 
int peek(Stack* S)
{
    if (S->top == NULL)
        return -1;         /* Stack is empty, return sentinel */

    return S->top->data;  /* Return top element without modifying stack */
}

// fun 05
 
int isEmpty(Stack* S)
{
    return (S->top == NULL);
}