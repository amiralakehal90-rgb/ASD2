#include "../include/string_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// fun 01

int my_strlen(const char* s){

    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

// fun 02

char* my_strcpy(char* dest, const char* src){

    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];  /* Copy current character to dest */
        i++;
    }

    dest[i] = '\0';  /* Copy the null terminator to terminate dest */

    return dest;  /* Return pointer to destination string */
}

// fun 03

char* my_strncpy(char* dest, const char* src, int n){
    int i = 0;

    while (i < n && src[i] != '\0')
    {
        dest[i] = src[i];  /* Copy current character to dest */
        i++;
    }

    while (i < n)
    {
        dest[i] = '\0';  /* Fill rest of dest with null terminators */
        i++;
    }

    return dest;  /* Return pointer to destination string */

}

// fun 04

char* my_strcat(char* dest, const char* src){
    int i = 0, j = 0;

    // الخطوة 1: الذهاب إلى نهاية السلسلة dest
    while(dest[i] != '\0') {
        i++;
    }

    // الخطوة 2: نسخ محتوى src إلى نهاية dest
    while (src[j] != '\0') {
        dest[i] = src[j]; // نسخ الحرف
        i++;
        j++;
    }

    // الخطوة 3: إضافة نهاية السلسلة '\0'
    dest[i] = '\0';

    return dest;
}

// fun 05
 
int my_strcmp(const char* a, const char* b){
    int i = 0;

    // مقارنة الحروف واحد بواحد حتى نهاية إحدى السلسلتين
    while (a[i] != '\0' && b[i] != '\0')
    {
        // إذا كان هناك اختلاف نرجع الفرق بين الحرفين
        if (a[i] != b[i])
            return a[i] - b[i];
        i++;
    }

    // في حالة نهاية إحدى السلسلتين نرجع الفرق
    return a[i] - b[i];
}

// fun 06
 
int my_strncmp(const char* a, const char* b, int n){
    int i = 0;

    // مقارنة الحروف حتى n أو حتى نهاية إحدى السلسلتين
    while (i < n && a[i] != '\0' && b[i] != '\0')
    {
        // إذا كان هناك اختلاف نرجع الفرق
        if (a[i] != b[i]){
            return a[i] - b[i];
        }
        i++;
    }

    // إذا وصلنا لعدد n من الأحرف بدون اختلاف
    if (i == n){
        return 0;
    }

    // في حالة انتهاء إحدى السلسلتين قبل n
    return a[i] - b[i];
}

// fun 07

void toUpperCase(char* s){
    int i = 0;
    while (s[i] != '\0'){
        if (s[i] >= 'a' && s[i] <= 'z'){
            s[i] = s[i] - 32;
        }
        i++;
    }
}

// fun 08
 
void toLowerCase(char* s){
    int i = 0;
    while (s[i] != '\0'){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] + 32;
        }
        i++;
    }
}

// fun 09
 
void reverseString(char* s){

    int i = 0;
    int j = my_strlen(s) - 1;  /* Start j at the last character */
    char temp;

    /* Swap characters from both ends moving inward until pointers meet */
    while (i < j)
    {
        temp = s[i];   /* Save left character */
        s[i] = s[j];  /* Copy right character to left */
        s[j] = temp;  /* Copy saved character to right */
        i++;           /* Move left pointer forward */
        j--;           /* Move right pointer backward */
    }
}

// fun 10
 
int countVowels(const char* s){
    int count = 0; // عداد حروف العلة
    int i = 0;
    char c;

    // المرور على كل أحرف السلسلة
    while (s[i] != '\0')
    {
        char c = tolower(s[i]); // تحويل الحرف إلى صغير

        // التحقق إذا كان الحرف من حروف العلة
        if (c == 'a'  c == 'e'  c == 'i'  c == 'o'  c == 'u'){
            count++;
        }
       i++;
    } 
    return count;

    while (s[i] != '\0') {
        c = tolower(s[i]);

        if (isalpha(c) && !(c == 'a'  c =='e'  c == 'i'  c == 'o'  c == 'u'))
            count++;
        
        i++;
    }
    return count;

}

// fun 11
 
int countWords(const char* s) {
  int count = 0;
  bool inWord = false;
  while (*s) {
    if (!isspace(*s) && !inWord) {
        count++; inWord = true; // transition espace?mot
   } else if (isspace(*s)) {
        inWord = false; // fin de mot
   }
   s++;
  }
   return count;
}

// fun 12

int isPalindrome(const char* s) {
    if (s == NULL) return 0;
    int i = 0;
    int j = strlen(s) - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return 0; 
        }
        i++;
        j--;
    }
    return 1;
}


// fun 13
 
void removeChar(char* s, char c){
    int j = 0;
    int i;
    for (i=0; s[i]!='\0'; i++){
        if (s[i] != c){
            s[j] = s[i];  //keep character if it's not c
            j++;
        }
    }
    s[j] = '\0';   //terminate the modified string
}

// fun 14
 
void removeSpaces(char* s) {
  int r = 0, w = 0; // read & write pointers

  while (s[r] != '\0') {
    if (s[r] != ' ' && s[r] != '\t') {

        s[w] = s[r]; // copier le caractère
        w++;

    } // sinon : espace ignoré, r avance seul
    r++;
  }
  s[w] = '\0'; // terminer la chaîne
}

// fun 15

void substring(const char* src, int start, int len, char* dest){
    if (start + len > (int)my_strlen(src)){  //check if start+len doesn't exceed src string length
        dest[0] = '\0';
        return;
    }

    for (int i = 0; i < len; i++){
        dest[i] = src[start + i];    //copy len characters 
    }

    dest[len] = '\0';   //terminate the destination string

}

// fun 16
 
int compareIgnoreCase(const char* a, const char* b){
    while (*a != '\0' && *b != '\0'){    //walk both strings until one of them reaches the end
        if (tolower(*a) - tolower(*b)){   //compare current characters in lowercase
            return tolower(*a) - tolower(*b);

        }
        a++;
        b++;
    }
    return tolower(*a) - tolower(*b);

}