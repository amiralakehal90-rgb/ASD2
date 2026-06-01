#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

// --- INCLUDE YOUR MODULE HEADERS ---
#include "include/common.h"
#include "include/array.h"
#include "include/string_utils.h"
#include "include/file_utils.h"
#include "include/linked_list.h"
#include "include/stack.h"
#include "include/queue.h"

// --- FUNCTION PROTOTYPES ---
// Keeps demo.c informed about functions compiled in your other source files
int saveBinaryReport(const char* filename, Record arr[], int count);
int createBinaryFile(const char* filename); 

// --- MENUS ---

void choice1_ArrayMatrix() {
    int choice, arr[MAX_1D], size = 0, idx, val, r, c;
    int matA[MAX_COLS][MAX_COLS], matB[MAX_COLS][MAX_COLS], res[MAX_COLS][MAX_COLS];
    do {
        printf("\n=== CHOICE 1: ARRAY & MATRIX ===\n1. Insert\n2. Display\n3. QuickSort\n5. Add Matrices\n6. Transpose\n0. Back\nSelection: ");
        if (scanf("%d", &choice) != 1) { int ch; while ((ch = getchar()) != '\n' && ch != EOF); choice = -1; continue; }
        if(choice == 1) { printf("Idx Val: "); scanf("%d %d", &idx, &val); insertAt(arr, &size, idx, val); }
        else if(choice == 2) printArray(arr, size);
        else if(choice == 3) { if(size > 0) quickSort(arr, 0, size-1); }
        else if(choice == 5 || choice == 6) {
            printf("Rows Cols: "); scanf("%d %d", &r, &c);
            printf("Enter elements for Matrix A:\n");
            for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &matA[i][j]);
            if(choice == 5) {
                printf("Enter elements for Matrix B:\n");
                for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &matB[i][j]);
                addMatrices(matA, matB, res, r, c);
            } else transposeMatrix(matA, r, c, res);
            for(int i=0; i<(choice==5?r:c); i++) { for(int j=0; j<(choice==5?c:r); j++) printf("%d ", res[i][j]); printf("\n"); }
        }
    } while (choice != 0);
}

void choice2_Strings() {
    int choice; char str[200], ch;
    do {
        printf("\n=== CHOICE 2: STRINGS ===\n1. Word Count\n2. Palindrome\n3. Remove Char\n0. Back\nSelection: ");
        if (scanf("%d", &choice) != 1) { int ch; while ((ch = getchar()) != '\n' && ch != EOF); choice = -1; continue; }
        getchar(); // Clear newline
        if(choice == 0) break;
        printf("String: "); fgets(str, 200, stdin); str[strcspn(str, "\n")] = 0;
        if(choice == 1) printf("Count: %d\n", countWords(str));
        else if(choice == 2) printf(isPalindrome(str) ? "Palindrome!\n" : "Not palindrome\n");
        else if(choice == 3) { printf("Char: "); scanf(" %c", &ch); removeChar(str, ch); printf("Result: %s\n", str); } 
    } while (choice != 0);
}

void choice3_File() {
    int choice;
    char name[100];
    
    do {
        printf("\n=== CHOICE 3: FILE MENU ===\n");
        printf("1. Create Binary File (Legacy)\n");
        printf("2. Save Binary Report (New Function)\n");
        printf("0. Back\n");
        printf("Selection: ");
        
        if (scanf("%d", &choice) != 1) { 
            int ch; while ((ch = getchar()) != '\n' && ch != EOF); 
            choice = -1; 
            continue; 
        }
        
        if (choice == 1) {
            printf("Enter filename: ");
            scanf("%99s", name);
            if(createBinaryFile(name) == 0) printf("File Created.\n");
        } 
        else if (choice == 2) {
            printf("Enter destination binary filename (e.g., report.bin): ");
            scanf("%99s", name);
            
            // Mocking a sample static array of records to pass to your save function
            Record sampleRecords[3] = {
                {101, "System Admin", 5500.25},
                {102, "Database Eng", 6200.50},
                {103, "Network Tech", 4100.00}
            };
            
            printf("Writing 3 sample records to %s via loop module...\n", name);
            int status = saveBinaryReport(name, sampleRecords, 3);
            if (status == 0) {
                printf("Success! Report written cleanly.\n");
            } else {
                printf("Error writing binary report. Status code: %d\n", status);
            }
        }
    } while (choice != 0);
}

void choice4_LinkedList() {
    int type; printf("\n1. Singly\n2. Doubly\nSelection: "); 
    if (scanf("%d", &type) != 1) { int ch; while ((ch = getchar()) != '\n' && ch != EOF); return; }
    
    if(type == 1) {
        List L = {NULL}; int c, v;
        do {
            printf("\n--- SINGLY ---\n1. Start\n2. End\n3. Show\n0. Back\nChoice: "); 
            if (scanf("%d", &c) != 1) { int ch; while ((ch = getchar()) != '\n' && ch != EOF); c = -1; continue; }
            if(c==1 || c==2) { printf("Val: "); scanf("%d", &v); if(c==1) insertBeginning(&L, v); else insertEnd(&L, v); }
            else if(c==3) { Node* curr = L.head; while(curr) { printf("%d -> ", curr->data); curr = curr->next; } printf("NULL\n"); }
        } while(c != 0);
        while(L.head) { Node* t = L.head; L.head = L.head->next; free(t); } // Cleanup
    } else {
        DLL dL = {NULL, NULL}; int c, v;
        do {
            printf("\n--- DOUBLY ---\n1. Start\n2. Show\n0. Back\nChoice: "); 
            if (scanf("%d", &c) != 1) { int ch; while ((ch = getchar()) != '\n' && ch != EOF); c = -1; continue; }
             
            if(c==1) { printf("Val: "); scanf("%d", &v); insertBeginningDLL(&dL, v); }
            else if(c==2) { DNode* curr = dL.head; while(curr) { printf("%d <-> ", curr->data); curr = curr->next; } printf("NULL\n"); }
        } while(c != 0);
        while(dL.head) { DNode* t = dL.head; dL.head = dL.head->next; free(t); } // Cleanup
    }
}

void choice5_Stacks() {
    Stack S = {NULL}; int c, v;
    do {
        printf("\n=== CHOICE 5: STACKS ===\n1. Push\n2. Pop\n0. Back\nSelection: ");
        if (scanf("%d", &c) != 1) { int ch; while ((ch = getchar()) != '\n' && ch != EOF); c = -1; continue; }
        if(c == 1) { printf("Val: "); scanf("%d", &v); push(&S, v); }
        else if(c == 2) { v = pop(&S); if(v != INT_MIN) printf("Popped: %d\n", v); }
    } while(c != 0);
    freeStack(&S); 
}

void choice6_Queues() {
    Queue Q;
    Q.front = NULL;
    Q.rear = NULL;
    int c, v;
    
    do {
        printf("\n=== CHOICE 6: QUEUES ===\n1. Enqueue (Insert)\n2. Show Queue Elements\n0. Back\nSelection: ");
        if (scanf("%d", &c) != 1) { int ch; while ((ch = getchar()) != '\n' && ch != EOF); c = -1; continue; }
        
        if(c == 1) { 
            printf("Val: "); 
            scanf("%d", &v); 
            if(enqueue(&Q, v)) {
                printf("Successfully enqueued %d\n", v);
            } else {
                printf("Enqueue operation failed.\n");
            }
        }
        else if(c == 2) {
            Node* curr = Q.front; 
            if(!curr) {
                printf("Queue is currently empty.\n");
            } else {
                printf("Front -> ");
                while(curr) { 
                    printf("[%d] -> ", curr->data); 
                    curr = curr->next; 
                } 
                printf("Rear\n"); 
            }
        }
        
    } while(c != 0);

    Node* curr = Q.front;
    while(curr) {
        Node* t = curr;
        curr = curr->next;
        free(t);
    }
}

int main() {
    int mainChoice;
    do {
        printf("\n=== ADS2 PROJECT MAIN MENU ===\n");
        printf("CHOICE 1: Array & Matrix\n");
        printf("CHOICE 2: String Utilities\n");
        printf("CHOICE 3: File Operations\n");
        printf("CHOICE 4: Linked List\n");
        printf("CHOICE 5: Stacks\n");
        printf("CHOICE 6: Queues\n"); 
        printf("0: Exit\nSelection: ");
        if (scanf("%d", &mainChoice) != 1) { int ch; while ((ch = getchar()) != '\n' && ch != EOF); continue; }
        switch(mainChoice) {
            case 1: choice1_ArrayMatrix(); break;
            case 2: choice2_Strings(); break;
            case 3: choice3_File(); break;
            case 4: choice4_LinkedList(); break;
            case 5: choice5_Stacks(); break;
            case 6: choice6_Queues(); break; 
        }
    } while (mainChoice != 0);
    return 0;
}
