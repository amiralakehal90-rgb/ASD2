
//fun 01 : createBinaryFile
int createBinaryFile(const char* filename) {

    FILE *file = fopen(filename, "wb");

    // التحقق مما إذا كان الملف قد فُتح بنجاح
    if (file == NULL) {
        return -1; // فشل في إنشاء الملف
    }
    // إغلاق الملف فوراً
    fclose(file);
    return 0; // نجاح
}