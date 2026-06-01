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

// fun :
int deleteByValue(List* L, int value) {
    // 1. Handle edge case: List pointer is NULL or list is empty
    if (L == NULL || L->head == NULL) {
        return 0; 
    }

    Node* temp = L->head;

    // 2. Handle head case separately
    if (temp->data == value) {
        L->head = temp->next; // Redirect head to the second node
        free(temp);           // Free the old head
        return 1;             // Return success
    }

    // 3. Search for the value in the rest of the list
    Node* prev = L->head;
    Node* curr = L->head->next;

    while (curr != NULL && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    // 4. If the value was found, unlink and free the node
    if (curr != NULL) {
        prev->next = curr->next; // Bypass the current node
        free(curr);              // Free memory
        return 1;                // Return success
    }

    // Value not found in the list
    return 0;
}

// fun : 
Node* searchByValue(List* L, int value) {
    // 1. Handle edge case: List pointer is NULL or list is empty
    if (L == NULL || L->head == NULL) {
        return NULL;
    }

    // 2. Start traversal from the head node
    Node* curr = L->head;

    // 3. Loop through the list until the end (NULL) is reached
    while (curr != NULL) {
        if (curr->data == value) {
            return curr; // Value found, return the pointer to this node
        }
        curr = curr->next; // Move to the next node
    }

    // 4. Value was not found in the entire list
    return NULL;
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
