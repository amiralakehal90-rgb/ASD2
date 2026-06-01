#ifndef SORT_H
#define SORT_H

void sortDatasetByField(Record arr[], int count, char* field);



void toUpperCase(char* s);
void toLowerCase(char* s);
void reverseString(char* s);

int my_strlen(const char* s);
char* my_strcpy(char* dest, const char* src);
char* my_strncpy(char* dest, const char* src, int n);

#endif
