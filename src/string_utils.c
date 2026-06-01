 
#include <string.h>
#include <ctype.h> 
#include "../include/string_utils.h"     

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

int compareIgnoreCase(const char* a, const char* b) {
    while (*a != '\0' && *b != '\0') {
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) {

            return tolower((unsigned char)*a) - tolower((unsigned char)*b);
        }
        a++;
        b++;
    }
    return tolower((unsigned char)*a) - tolower((unsigned char)*b);
}
 // fun :
int countWords(const char* s)
{
    int count = 0;
    int inWord = 0; 

    while (*s)         //Keep looping while the current character is not the end of the string
    {
        if (isspace(*s))        // If the current character is a space that means we are outside a word
            inWord = 0;       
        else if (inWord==0)    // We are not currently inside a word
        {
            inWord = 1;
            count++;   // We found a new word so we increase word count
        }

        s++;    //Move to the next character in the string
    }

    return count;
}

int isPalindrome(const char* s)
{
    int i = 0;
    int j = 0;

    while (s[j] != '\0')
        j++;

    j = j - 1;    // so we are not in the last position '\0 '

    while (i < j)
    {
        if (s[i] != s[j])
            return 0;

        i++;
        j--;
    }

    return 1;
}

void removeChar(char* s, char c)
{
    int i = 0;
    int j = 0;

    while (s[i] != '\0')
    {
        if (s[i] != c)
        {
            s[j] = s[i];        //Copy the character at position i into position j of the string.
            j++;
        }

        i++;
    }

    s[j] = '\0';
}
void toUpperCase(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32; // الفرق في جدول ASCII
        }
    }
}

// 2. تحويل الحروف إلى صغيرة
void toLowerCase(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
    }
}

// 3. عكس النص (طريقة المؤشرين Two-pointer)
void reverseString(char* s) {
    int i = 0;
    int j = strlen(s) - 1;
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}
