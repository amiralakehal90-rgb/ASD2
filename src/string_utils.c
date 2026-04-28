 
#include <string.h>

 // fun 14 : remove Spaces
 void removeSpaces(char* s) {
    char* i = s; // مؤشر القراءة
    char* j = s; // مؤشر الكتابة

    while (*i != '\0') {
        if (*i != ' ' && *i != '\t') {
            *j = *i; 
            j++;     
        }
        i++; 
    }
    *j = '\0'; // إغلاق السلسلة النصية في النهاية 
 }

 // fun 15 :   substring
void substring(const char* src, int start, int len, char* dest) {
    // التحقق من صحة الحدود
    if (start + len > strlen(src)) {
        printf("Error!\n");
        return; 
    }
    // نسخ  
    for (int i = 0; i < len; i++) {
        dest[i] = src[start + i];
    }
    // نهاية النص
    dest[len] = '\0';
}

// fun 16 : compare Ignore Case



