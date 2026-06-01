
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


int createBinaryFile(const char* filename)
{
    FILE *f = fopen(filename, "wb");

    if (f == NULL) {
        return -1;   
    }

    fclose(f);
    return 0;        
}
