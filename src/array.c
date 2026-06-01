
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

int deleteAt(int arr[], int *size, int pos) {
    // Shift elements from the right to the left to fill the gap
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    // Decrement the size of the array
    (*size)--;
    return 0;
}
// . Function to find an element's index
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Target found
        }
    }
    return -1; // Target not found
}
// . Binary Search (Optimized search for sorted arrays)
int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
int isSymmetric(int m[][MAX_COLS], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) { // نختبر فقط العناصر تحت القطر الرئيسي
            if (m[i][j] != m[j][i]) {
                return 0; // بمجرد وجود اختلاف، المصفوفة غير متناظرة
            }
        }
    }
    return 1; // إذا انتهى التكرار دون اختلاف، فهي متناظرة
}
void sortRows(int m[][MAX_COLS], int rows, int cols) {
    int i, j, k, temp;
    
    // نمر على كل صف على حدة
    for (i = 0; i < rows; i++) {
        
        // داخل كل صف (i)، نقوم بعملية الترتيب الفقاعي للعناصر
        for (j = 0; j < cols - 1; j++) {
            for (k = 0; k < cols - j - 1; k++) {
                
                // إذا كان العنصر الحالي أكبر من الذي يليه، نقوم بالتبديل
                if (m[i][k] > m[i][k + 1]) {
                    temp = m[i][k];
                    m[i][k] = m[i][k + 1];
                    m[i][k + 1] = temp;
                }
            }
        }
    }
}

#include "matrix.h"

void multiplyMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r[i][j] = 0;
            for (int k = 0; k < n; k++) {
                r[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int sumDiagonal(int m[][MAX_COLS], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += m[i][i];
    }
    return sum;
}

int sumAntiDiagonal(int m[][MAX_COLS], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += m[i][n - 1 - i];
    }
    return sum;
}

void bubbleSort(int arr[], int size) {
    int i, j, temp, swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }
}

void selectionSort(int arr[], int size) {
    int i, j, min_idx, temp;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int deleteAt(int arr[], int* size, int index) {
    if (index < 0 || index >= *size) return -1;
    int deletedValue = arr[index];
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    return deletedValue;
}

int linearSearch(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

int binarySearch(int arr[], int size, int value) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value) return mid;
        if (arr[mid] < value) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
// fun 13
int sumArray(int arr[], int size) {
    // إذا كان الحجم صفر أو سالب نرجع 0
    if (size <= 0) {
        return 0;
    }

    int total = 0; // متغير لتخزين المجموع

    // حلقة تمر على جميع عناصر المصفوفة
    for (int i = 0; i < size; i++) {
        total = total + arr[i]; // جمع العناصر
    }

    return total; // إرجاع المجموع النهائي
}
// fun 14
double AveragArray(int arr[],int size){

   if(size==0){
     return 0;
   }
 
 int Sum=0;
 
 for(int i = 0; i< size ; i++){
    Sum = Sum + arr[i];
 }
 
 return (double)Sum / size;
}
// fun 01
void initMatrix(int m[][MAX_COLS], int* rows, int* cols) {
    int i, j;
    int r, c;

    //طلب عدد الصفوف و الاعمدة من المستخدم
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    //التحقق ان القيم المدخلة لا تتجاوز الحد الاقصى
    if(r > 0 && r <= MAX_ROWS && c > 0 && c <= MAX_COLS){
        *rows=r;
        *cols=c;

        // حلقة لادخال عناصر المصفوفة
        for(i = 0; i < *rows; i++){
            for(j = 0; j < *cols; j++){
                printf("mat[%d][%d]= ", i, j);
                scanf("%d", &m[i][j]);
            }
        }
    }else{
        //في حالة تجاوز الحجم المسموح
        printf("Error, size exceeds MAX\n");
    }
}
// fun 02
#define MAX_ROWS 10
#define MAX_COLS 10

// دالة طباعة المصفوفة
void printMatrix(int m[][MAX_COLS], int rows, int cols)
{
    // المرور على الصفوف
    for (int i = 0; i < rows; i++)
    {
        // المرور على الأعمدة
        for (int j = 0; j < cols; j++)
        {
            // طباعة عنصر مع تنسيق ثابت
            printf("%4d", m[i][j]);
        }

        // الانتقال إلى سطر جديد بعد كل صف
        printf("\n");
    }
}