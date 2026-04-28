
    // fun 15: reverse an array
 void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        // (Swap)
        arr[i] = arr[i] + arr[size - 1 - i];
        arr[size - 1 - i] = arr[i] - arr[size - 1 - i];
        arr[i] = arr[i] - arr[size - 1 - i];
    }
}

   // fun 16: rotateLeft
 void rotateLeft(int arr[], int size, int k) {
    k = k % size;
    int temp[size];

    for (int i = 0; i < size; i++) {
        // تحريك العناصر
        temp[i] = arr[(i + k) % size];
    }
        // نسخ العناصر من temp إلى arr الأصلي
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

   // fun 17: mergeSortedArrays
   void mergeSortedArrays(int a[], int na, int b[], int nb, int out[]) {
    int i = 0, j = 0,k = 0; 
    //المقارنة والدمج
    while (i < na && j < nb) {
        if (a[i] < b[j]) {
            out[k] = a[i];
            i++;
        } else {
            out[k] = b[j];
            j++;
        }
        k++;
    }
    // نسخ ما تبقى من a
    while (i < na) {
        out[k++] = a[i++];
    }
    // نسخ ما تبقى من b
    while (j < nb) {
        out[k++] = b[j++];
    }
}

    // fun 01 : createDynamicArray
  int* createDynamicArray(int capacity) {
          //حجز مساحة من الذاكرة
    int* arr = malloc(capacity * sizeof(int));
    // التحقق مما إذا كان الحجز قد نجح
    if (arr == NULL) {
        printf("Error: Memory allocation failed!\n");
        return NULL;
    }
    return arr;
}

  // fun 02 : fillArray
  void fillArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]); 
    }
}

   // fun 03 :  resizeArray
    int* resizeArray(int* arr, int newCapacity) {
    // تغيير حجم المصفوفة
    int* temp = realloc(arr, newCapacity * sizeof(int));

    // التحقق من نجاح العملية
    if (temp == NULL) {
          printf("Error: Resizing failed!\n");
        return NULL;
    }
    //  إذا نجح
    return temp;
}

   // fun 04 : freeArray
    void freeArray(int* arr) {
    free(arr); // تحرير الذاكرة
}

