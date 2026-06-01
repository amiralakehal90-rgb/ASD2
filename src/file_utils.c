#include "../include/file_utils.h"
#include <stdio.h>
#include <stdlib.h>

// fun 01
 
int createBinaryFile(const char* filename)
{
    /* Open file in write-binary mode, creating or overwriting it */
    FILE* f = fopen(filename, "wb");
    if (f == NULL)
        return -1;  /* Failed to open/create file */

    fclose(f);  /* Close immediately, we just need to create it */

    return 0;  /* Success */
}


// fun 02
 
int readRecord(const char* filename, int index, Record* r)
{
    // فتح الملف بوضع القراءة الثنائية
    FILE* fp = fopen(filename, "rb");

    // التحقق من نجاح فتح الملف
    if (fp == NULL)
        return -1;

    // الذهاب إلى نهاية الملف لمعرفة حجمه
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp); // حجم الملف بالبايت
    rewind(fp); // الرجوع إلى بداية الملف

    // حساب عدد السجلات في الملف
    long totalRecords = size / sizeof(Record);

    // التحقق من صحة الفهرس
    if (index < 0 || index >= totalRecords)
    {
        fclose(fp);
        return -1;
    }

    // الانتقال إلى موقع السجل المطلوب
    fseek(fp, index * sizeof(Record), SEEK_SET);

    // قراءة السجل من الملف
    fread(r, sizeof(Record), 1, fp);

    fclose(fp); // غلق الملف
    return 0;   // نجاح العملية
}

// fun 03 
int writeRecord(const char* filename, Record* r)
{
    // فتح الملف بوضع الإضافة الثنائية
    FILE* fp = fopen(filename, "ab");

    // التحقق من نجاح فتح الملف
    if (fp == NULL)
        return -1;

    // كتابة السجل في الملف
    if (fwrite(r, sizeof(Record), 1, fp) != 1)
    {
        fclose(fp);
        return -1;
    }

    fclose(fp); // غلق الملف
    return 0;   // نجاح العملية
}

// fun 04
 
int countRecords(const char* filename)
{
    long size;

    /* Open file in read-binary mode */
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL)
        return -1;  /* Failed to open file */

    fseek(fp, 0, SEEK_END);  /* Seek to the end of the file */
    size = ftell(fp);         /* Get the total size in bytes */

    fclose(fp);  /* Close the file */

    /* Divide total size by the size of one record to get the count */
    return size / sizeof(Record);
}

// fun 05

int appendRecord(const char* filename, Record* r)
{
    /* Open file in append-binary mode, writes always go to the end */
    FILE* fp = fopen(filename, "ab");
    if (fp == NULL)
        return -1;  /* Failed to open file */

    fwrite(r, sizeof(Record), 1, fp);  /* Write one record at the end */

    fclose(fp);  /* Close the file */

    return 0;  /* Success */
}

// fun 06
 
int searchRecordById(const char* filename, int id, Record* result)
{
    Record current;
    int index = 0;

    /* Open file in read-binary mode */
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL)
        return -1;  /* Failed to open file */

   while (fread(&current, sizeof(Record), 1, fp) == 1)
   {
        if (current.id == id)  /* Check if current record matches the id */
        {
            *result = current;  /* Copy found record into result */
            fclose(fp);
            return index;       /* Return the index of the found record */
        }
        index++;
   }

    fclose(fp);  /* Close the file */

    return -1;  /* Record not found */
}

// fun 07
 
int updateRecord(const char* filename, int index, Record* newData)
{
    /* Open file in read/write binary mode without truncating */
    FILE* fp = fopen(filename, "r+b");
    if (fp == NULL)
        return -1;  /* Failed to open file */

    /* Seek to the exact byte offset of the target record */
    if (fseek(fp, index * sizeof(Record), SEEK_SET) != 0)
    {
        fclose(fp);
        return -1;  /* Seek failed, index may be out of range */
    }fwrite(newData, sizeof(Record), 1, fp);  /* Overwrite old record with new data */

    fclose(fp);  /* Close the file */

    return 0;  /* Success */
}

// fun 08

int copyBinaryFile(const char* src, const char* dest)
{
    Record current;

    /* Open source file in read-binary mode */
    FILE* fSrc = fopen(src, "rb");
    if (fSrc == NULL)
        return -1;  /* Failed to open source file */

    /* Open destination file in write-binary mode */
    FILE* fDest = fopen(dest, "wb");
    if (fDest == NULL)
    {
        fclose(fSrc);  /* Close source before returning */
        return -1;     /* Failed to open destination file */
    }

    /* Read each record from src and write it to dest */
    while (fread(&current, sizeof(Record), 1, fSrc) == 1)
        fwrite(&current, sizeof(Record), 1, fDest);  /* Write record to dest */

    fclose(fSrc);   /* Close source file */
    fclose(fDest);  /* Close destination file */

    return 0;  /* Success */
}