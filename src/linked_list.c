#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- 1. SINGLY LINKED LIST ---
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

int insertBeginning(List* L, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return -1; 

    newNode->data = value;
    newNode->next = L->head;
    L->head = newNode;
    return 0; 
}

int insertEnd(List* L, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return -1;

    newNode->data = value;
    newNode->next = NULL;

    if (L->head == NULL) {
        L->head = newNode;
        return 0;
    }

    Node* temp = L->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return 0;
}

// --- 2. DOUBLY LINKED LIST ---
// RENAMED to DNode to avoid conflict with Node
typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

typedef struct DLL {
    DNode* head;
    DNode* tail;
} DLL;

int insertBeginningDLL(DLL* L, int value) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (newNode == NULL) return 0;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = L->head;

    if (L->head == NULL) {
        L->tail = newNode;
    } else {
        L->head->prev = newNode;
    }

    L->head = newNode;
    return 1;
}
