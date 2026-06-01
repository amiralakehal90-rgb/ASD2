#include "../include/linked_list.h"      // It represent the path towards my header (library)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// fun 01

Node* create(int value)
{
    Node* n = (Node*)malloc(sizeof(Node));

    if(n == NULL)
        return NULL;

    n->data = value;
    n->next = NULL;

    return n;
}

// fun 02

int insertBeginning(Node* L, int value){
    Node *n =create(value);  //allocate
    n->next = L;               // 2. point to current head
    L = n;
}

// fun 03

int insertEnd(Node* L, int value){
    Node *p = L;
    while (p->next != NULL)
    p=p->next;
    Node *n =create(value);
    p->next = n;
    L = n;
}

// fun 04
int insertAtPosition(Node* L, int pos, int value){
    if(pos == 0){
     return insertAtBeginning(L, value); 
    }
    Node* n = create(value); 
    Node* p = L; 
    for(int i = 0; i < pos - 1 && p != NULL; i++) { 
        p = p->next;
    } 

    if(p == NULL) {
     return L; 
    }
    n->next = p->next; 
    p->next = n; 
    return L;
}

// fun 05
int deleteBeginning(Node* L){
    if(L == NULL){
      return NULL;
    }
    Node* temp = L;
    L = L->next;
    free(temp); 
    return L; 
}

// fun 06

int deleteEnd(Node* L){
    // empty list
    if(L == NULL)
        return NULL;

    // only one node
    if(L->next == NULL)
    {
        free(L);
        return NULL;
    }

    Node* p = L;

    // stop at node before the last
    while(p->next->next != NULL)
    {
        p = p->next;
    }

    // delete last node
    free(p->next);

    // make new last node point to NULL
    p->next = NULL;

    return L;
}

// fun 07

int deleteByValue(Node* L, int value){
    if(L == NULL) {
      return NULL; 
    }   
    if(L->data == value) {
      return deleteFirst(L);
    } 
    Node* p = L;
    while(p->next != NULL && p->next->data != value) { 
        p = p->next;
    }
    if(p->next == NULL){
       return L; 
    }
    Node* temp = p->next;
    p->next = temp->next;
    free(temp); 
    return L; 
}


// fun 08

Node* searchValue(Node* L, int value){
    Node* current = L; // بداية البحث من الرأس

    // المرور على جميع العقد
    while (current != NULL)
    {
        // إذا وجدنا القيمة نرجع عنوان العقدة
        if (current->data == value)
            return current;

        // الانتقال للعقدة التالية
        current = current->next;
    }

    // إذا لم يتم العثور على القيمة
    return NULL;
}

// fun 09

void displayList(Node* L){
    Node* q = L;
    while(q != NULL){
        printf("%d", q->data);
        q = q->next;
    }
    printf("\n");

}

// fun 10

void reverseList(Node* L){
    if (L == NULL  L == NULL) return;

    Node* prev = NULL;
    Node* current = L;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Sauvegarde le reste de la liste
        current->next = prev;  // Inverse le lien du nœud actuel
        prev = current;        // Déplace prev d'un cran vers l'avant
        current = next;        // Déplace current d'un cran vers l'avant
    }

    L = prev; 
    return prev;
}

// fun 11

void sortListBubble(List* L) {
    if (L == NULL  L->head == NULL || L->head->next == NULL) return;

    bool swapped;
    Node* current;
    Node* lastPtr = NULL; 

    do {
        swapped = false;
        current = L->head;

        while (current->next != lastPtr) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                
                swapped = true;
            }
            current = current->next;
        }
        lastPtr = current;
    } while (swapped);
}

// fun 12

void mergeSortedLists(List* A, List* B, List* result){
    Node* p1 = A->head;
    Node* p2 = B->head;
    result->head = NULL;

    while (p1 != NULL && p2 != NULL){
        if (p1->data < p2->data){
            insertEnd(result, p1->data);
            p1 = p1->next;
        }else{
            insertEnd(result, p2->data);
            p2 = p2->next;
        }
    }
    while (p1 != NULL){
        insertEnd(result, p1->data);
        p1 = p1->next;
    }
    while (p2 != NULL){
        insertEnd(result, p2->data);
        p2 = p2->next;
    }

}

//Doubly linked lists
// fun 01

void initListDLL(DLL* L){
    L->head = NULL;
    L->tail = NULL;
    L->size = 0;

}

// fun 02
int insertBeginningDLL(DLL* L, int value){
    DNode* n = create(value);
    n->next = L->head;
    if(L->head != NULL) {
      L->head->prev = n; // old head points back to new node return n
    } 
}

// fun 03

int insertEndDLL(DLL* L, int value){
    DNode* n = create(value);
    if(L->head == NULL) {
       return n;
    }
    DNode* p = L->head; 
    while(p->next != NULL) {
       p = p->next;
       p->next = n;
       n->prev = p; // link back to previous last node return head;
    }
}

// fun 04
int deleteByValueDLL(DLL* L, int value){
    DNode* p = L->head;
    while(p != NULL && p->data != value){
      p = p->next;
    }
       
    if(p == NULL){
         return; }
    if(p->prev != NULL) {
         p->prev->next = p->next; 
    }else{
         L->head = p->next; } // removing head
    if(p->next != NULL) {
         p->next->prev = p->prev;
    }else{
        L->tail = p->prev;
    }
    free(p); 
    L->size--;
}

// fun 05
void displayForward(DLL* L){

    DNode* current = L->head; // البداية من الرأس

    // المرور على جميع العقد
    while (current != NULL)
    {
        printf("%d ", current->data); // طباعة قيمة العقدة
        current = current->next;      // الانتقال للعقدة التالية
    }

    printf("\n"); // سطر جديد بعد الانتهاء
}

// fun 06

void displayBackward(DLL* L){

    DNode* current = L->tail; // البداية من الرأس

    // المرور على جميع العقد
    while (current != NULL)
    {
        printf("%d ", current->data); // طباعة قيمة العقدة
        current = current->prev;      // الانتقال للعقدة التالية
    }

    printf("\n"); // سطر جديد بعد الانتهاء

}