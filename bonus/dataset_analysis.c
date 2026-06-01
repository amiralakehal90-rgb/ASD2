#include <stdio.h>
#include <stdlib.h>
#include "include/common.h"
#include "include/file_utils.h"
// 1. Define the struct exactly how you need it
typedef struct {
    int id;
    char name[50];
    double balance;
} Record;

// 2. The function logic
int saveBinaryReport(const char* filename, Record arr[], int count) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    for (int i = 0; i < count; i++) {
        size_t written = fwrite(&arr[i], sizeof(Record), 1, file);
        if (written != 1) {
            perror("Error writing record");
            fclose(file);
            return -2;
        }
    }

    fclose(file);
    return 0;
}
//average By Field
float averageByField(Record arr[], int count) {
    // Return 0.0 if count is 0 to prevent division by zero
    if (count <= 0) {
        return 0.0f;
    }

    int sum = 0;
    
    // Sum all score fields
    for (int i = 0; i < count; i++) {
        sum += arr[i].score;
    }

    // Cast to float and divide by count
    return (float)sum / count;
}


// filter By Condition
int filterByCondition(Record arr[], int count, float threshold, Record out[]) {
    int matchCount = 0;

    for (int i = 0; i < count; i++) {
        if (arr[i].score > threshold) {
            out[matchCount] = arr[i]; // Copies the entire struct
            matchCount++;
        }
    }

    return matchCount;
}

int loadDataset(const char* filename, Record arr[], int* count) {
    FILE* file = fopen(filename, "rb"); 
    if (file == NULL) {
        return -1; 
    }

    *count = 0;
    
    while (fread(&arr[*count], sizeof(Record), 1, file)) {
        (*count)++;
    }

    fclose(file);
    return *count;
}


void displayDataset(Record arr[], int count) {
    if (count == 0) {
        printf("\n[!] No records found in the dataset.\n");
        return;
    }

    
    printf("\n%-10s %-25s %-15s\n", "ID", "Record Name", "Category");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        // ????? ??? ????? ?????? (Category) ?????? ???
        printf("%-10d %-25s %-15s\n", i + 1, "Data Entry", arr[i].category);
    }
    printf("----------------------------------------------------------\n");
    printf("Total records displayed: %d\n", count);
}
void createSampleFile() {
    FILE* file = fopen("data.bin", "wb");
    if (file == NULL) return;

    Record samples[2] = {
        {1, "Student_A", "Information_System"},
        {2, "Student_B", "Computer_Science"}
    };

    fwrite(samples, sizeof(Record), 2, file);
    fclose(file);
    printf("\n[v] Sample 'data.bin' created successfully!\n");
}
