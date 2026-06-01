#ifndef COMMON_H
#define COMMON_H

typedef struct {
    int   id;
    char  name[50];
    float score;
    char  category[20];
} Record;

/* Node for singly linked list */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    int size;
} List;

/* Node for doubly linked list */
typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

// --- 2. تعريف هيكل الـ Bonus (الذي كان ينقصك) ---

typedef struct {
    int id;
    char name[50];
    char category[20]; // تأكدي من إضافة هذا السطر بالتحديد
} Record;

// --- 3. تصريحات الدوال (Prototypes) ---
int countRecords(const char* filename);
int appendRecord(const char* filename, Record* r);
#ifndef RECORDS_H
#define RECORDS_H

typedef struct {
    int id;
    char name[50];
    float score;
} Record;

int searchRecordById(const char* filename, int id, Record* result);
int updateRecord(const char* filename, int index, Record* newData);


#endif
