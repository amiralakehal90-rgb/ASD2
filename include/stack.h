#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Borrow the Node definition from linked_list.h */
#include "linked_list.h"

/* Pointer-based Stack (linked list) */
typedef struct Stack {
    Node* top;    // top element
} Stack;

/* --- STACK FUNCTION PROTOTYPES --- */
void push(Stack* S, int val);
int pop(Stack* S);
int peek(Stack* S);
int isEmpty(Stack* S);
void freeStack(Stack* S);

#endif /* STACK_H */
#ifndef STACK_H
#define STACK_H

#include "common.h" 

int push(Stack* S, int value);

void initStack(Stack* S);
#endif

