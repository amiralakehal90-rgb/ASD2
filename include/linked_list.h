#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

/* Define the Node structure here so both linked lists and stacks can use it */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Your Singly Linked List structure */
typedef struct List {
    Node* head;
} List;

/* Your Doubly Linked List node (used in choice4_LinkedList) */
typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

/* Your Doubly Linked List structure */
typedef struct DLL {
    DNode* head;
    DNode* tail;
} DLL;

// --- LINKED LIST FUNCTION PROTOTYPES ---
void insertBeginning(List* L, int val);
void insertEnd(List* L, int val);
void insertBeginningDLL(DLL* dL, int val);

#endif /* LINKED_LIST_H */

#include "common.h"


// (Prototypes)
void initList(List* L);
int insertAtPosition(List* L, int pos, int value);
int deleteBeginning(List* L);
void displayList(List* L);
int deleteByValueDLL(List* L, int value);
void displayBackward(List* L);


int deleteBeginning(List* L);
int deleteEnd(List* L);

void initListDLL(DLL* L);
void displayList(List* L);
void reverseList(List* L);
void sortListBubble(List* L);
void mergeSortedLists(List* A, List* B, List* result);


#endif

