#include "../include/stack.h" 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* * Adds a new element to the top of the stack.
 * Logic: Create node -> point new node to current top -> update top to new node.
 */
void push(Stack* S, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Stack Overflow: Failed to allocate memory.\n");
        return;
    }
    newNode->data = val;
    newNode->next = S->top;
    S->top = newNode;
}

/* * Removes the top element and returns its value.
 */
int pop(Stack* S) {
    // 1. Check if the stack is empty
    if (isEmpty(S)) {
        printf("Stack Underflow\n");
        return INT_MIN; 
    }

    // 2. Store the data to return later
    int poppedValue = S->top->data;

    // 3. Save current top to a temp pointer so we don't lose it
    Node* temp = S->top;

    // 4. Move top pointer to the next node in the list
    S->top = S->top->next;

    // 5. Free the memory of the removed node
    free(temp);

    // 6. Return the value
    return poppedValue;
}

/*
 * Returns the top value without removing it.
 */
int peek(Stack* S) {
    if (isEmpty(S)) {
        printf("Stack is empty.\n");
        return INT_MIN;
    }
    return S->top->data;
}

/*
 * Checks if the stack is empty (returns 1 if empty, 0 otherwise)
 */
int isEmpty(Stack* S) {
    return S->top == NULL;
}

/*
 * Frees all memory in the stack to prevent memory leaks
 */
void freeStack(Stack* S) {
    Node* current = S->top;
    Node* nextNode;
    
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    S->top = NULL;
}
