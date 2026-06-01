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
