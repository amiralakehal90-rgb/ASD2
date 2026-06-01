
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

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}


    void merge(int arr[], int left, int mid, int right) {
    int temp[right - left + 1];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
    
    
void quickSort(int arr[], int low, int high) {
  // Base condition: only sort if there are 2 or more elements
    if (low < high) {
      // Choose the last element as the pivot
        int pivot = arr[high];
         // i tracks the position for smaller elements
        int i = low - 1;
        // Loop through the array from low to high-1
        for (int j = low; j < high; j++) {
          // If current element is smaller than pivot
            if (arr[j] < pivot) {
                i++;
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
           // Place pivot in its correct sorted position
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
       // pi is the final position of pivot

        int pi = i + 1;
       // Recursively sort elements before pivot
        quickSort(arr, low, pi - 1);
        
        // Recursively sort elements after pivot
        quickSort(arr, pi + 1, high);
    }
}

void transposeMatrix(int m[][MAX_COLS], int rows, int cols, int out[][MAX_COLS]) {
  for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            out[j][i] = m[i][j];
        }
    }
  
  
  
}






void addMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            r[i][j] = a[i][j] + b[i][j];
        }
    }
}
