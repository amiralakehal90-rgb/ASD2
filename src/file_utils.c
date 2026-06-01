
//fun 01 : createBinaryFile
int createBinaryFile(const char* filename) {
    FILE *file = fopen(filename, "wb");

    // التحقق مما إذا كان الملف قد فُتح بنجاح
    if (file == NULL) {
        return -1; // فشل في إنشاء الملف
    }
    // إغلاق الملف فوراً
    fclose(file);
    return 0;
}

// fun 02
/*write a single record into a position in a binary file*/ 
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

// fun 03
/*read a single record from a binary file at a position*/ 
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

// fun 08 :  copy Binary File
int copyBinaryFile(const char* src, const char* dest) {
    FILE *f = fopen(src, "rb");
    if (f == NULL) 
       return -1; // تأكد أن الملف موجود وقابل للفتح 

    FILE *p = fopen(dest, "wb");
    if (p == NULL){
      fclose(f);
      return -1;
    } 
   //  عملية النسخ

   char temp[1024]; // مخزن 1 كيلوبايت
    size_t n;

    while ((n = fread(temp, 1, sizeof(temp), f)) > 0) {
        fwrite(temp, 1, n, p);
    } 

    fclose(f);
    fclose(p);
    return 0 ;
}

// fun:
int createBinaryFile(const char* filename)
{
    FILE *f = fopen(filename, "wb");

    if (f == NULL) {
        return -1;   
    }

    fclose(f);
    return 0;        
}

int countRecords(const char* filename) {
    FILE *fp = fopen(filename, "rb"); // فتح الملف للقراءة الثنائية
    if (fp == NULL) return 0;

    fseek(fp, 0, SEEK_END); // الذهاب لآخر الملف
    long size = ftell(fp);  // معرفة حجم الملف الكلي
    fclose(fp);

    return (int)(size / sizeof(Record)); // تقسيم حجم الملف على حجم السجل الواحد
}

// 2. إضافة سجل جديد لنهاية الملف
int appendRecord(const char* filename, Record* r) {
    FILE *fp = fopen(filename, "ab"); // الفتح بنمط append binary
    if (fp == NULL) return 0;

    fwrite(r, sizeof(Record), 1, fp); // كتابة السجل في النهاية
    fclose(fp);
    return 1;
}
