#include <stdio.h>

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
