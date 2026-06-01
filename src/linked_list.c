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

void initList(List* L) {
    L->head = NULL;
    L->size = 0;
}

// الإضافة في موقع محدد
int insertAtPosition(List* L, int pos, int value) {
    if (pos < 0 || pos > L->size) return -1;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return -1;
    newNode->data = value;

    if (pos == 0) {
        newNode->next = L->head;
        L->head = newNode;
    } else {
        Node* temp = L->head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    L->size++;
    return 1;
}

// الحذف من البداية
int deleteBeginning(List* L) {
    if (L->head == NULL) return -1;

    Node* temp = L->head;
    int val = temp->data;
    L->head = L->head->next;
    free(temp);
    L->size--;
    return val;
}
void displayList(List* L) {
    if (L == NULL || L->head == NULL) {
        printf("\n[ القائمة فارغة حالياً ]\n");
        return;
    }
    
    Node* temp = L->head;
    printf("\nالعناصر الموجودة: ");
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int deleteByValueDLL(List* L, int value) {
    DNode* current =(DNode*) L->head;

    while (current != NULL) {
        if (current->data == value) {

            // إذا كانت أول عقدة
            if (current->prev == NULL) {
                L->head =(DNode*) current->next;
                if (L->head != NULL)
                    ((DNode*)L->head)->prev = NULL;
            }
            else {
                ((DNode*)current->prev)->next = current->next;
                if (current->next != NULL)
                    ((DNode*)current->next)->prev = current->prev;
            }

            free(current);
            return 1; // تم الحذف
        }

        current = (DNode*)current->next;
    }

    return 0; // لم يجد القيمة
}
void displayBackward(List* L) {
    // 1. تغيير النوع إلى DNode* واستخدام Casting
    DNode* current = (DNode*)L->head; 

    // الوصول لآخر عقدة
    while (current != NULL && current->next != NULL) {
        current = (DNode*)current->next;
    }

    // الطباعة من الخلف إلى الأمام
    while (current != NULL) {
        printf("%d ", current->data);
        // 2. استخدام prev الآن سيعمل لأن current نوعه DNode*
        current = (DNode*)current->prev; 
    }

    printf("\n");
}


int deleteBeginning(List* L) {
    if (L->head == NULL) return -1;
    Node* temp = L->head;
    int val = temp->data;
    L->head = L->head->next;
    free(temp);
    return val;
}

int deleteEnd(List* L) {
    if (L->head == NULL) return -1;
    if (L->head->next == NULL) {
        int val = L->head->data;
        free(L->head);
        L->head = NULL;
        return val;
    }
    Node* current = L->head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    Node* temp = current->next;
    int val = temp->data;
    current->next = NULL;
    free(temp);
    return val;
}
