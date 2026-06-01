 ----------------- array -A- ---------------------------

  ### fun 15 Reverse Array
Input: arr[]: An array . size: Number of elements in the array.
Output: The same array arr[] with elements in reversed order.
Algorithm:
.Iterate from index [0] up to [size / 2].
.In each step, swap the element at index [i] with the element at index [size - 1 - i]
.Continue until the middle of the array is reached.

  ### fun 16 Rotate Left
Input: arr[] array. size.k: Number of positions to shift.
Output: The modified array arr[] where elements are shifted left.
Algorithm: 
.Normalize k using (k % size) to handle cases where (k >= size).
.Fill temp by placing arr[(i + k) % size] into temp[i].
.Copy all elements from temp[] back to the original array arr[].


  ### fun 17 Merge Sorted Arrays
Input: a[], b[]. na, nb :Sizes of arrays a and b. out[]: A destination array with size (na + nb).
Output: out[] filled with all elements from a and b .
Algorithm:
.Compare a[i] and b[j]; copy the smaller value to out[] and increment its pointer.
.Repeat until one array is fully processed.
.Copy any remaining elements from the other array into out[].


 -------------------- array -C-  -------------


### fun 01 create Dynamic Array
Input : The number of elements needed 
Output : Pointer to the first element
Algorithm:
.using malloc to reserve memory
.Check if memory was allocated successfully (arr != NULL)
.If it fails, print an error and return NULL

   ### fun 02 fillArray
Input: size, int* arr
Output : The array is modified in memory
Algorithm:
.read an integer from the user

   ### fun 03 resizeArray
Input: int* arr , int newCapacity (New size)
Output :
Algorithm:
.Call realloc with the old pointer and the new size.
.Store the result in a temporary pointer.
.If realloc fails, keep the original pointer alive and return NULL.


   ### fun 04  free Array
Input: int* arr 
Output : 
Algorithm:
. Call free(arr) to release memory back to the system.



------------------------- FILE ------------------------------------
### fun 01 
Input:  filename
Output : An integer: 0 for success, -1 for failure 
Algorithm:
.Open file in "wb" mode with Call fopen()
.If failed, Return -1
.Else, Close file using fclose() and Return 0

### fun 08 Binary File Copy 
Input: src , dest
Output : '0' if the coping of file succesfully , '-1' if not 
Algorithm:
.Open src in "rb" and dest in "wb"
.If any file fails to open, exit with an error
.Read data from 'src' into a 'temp' using 'fread'
.using 'fwrite' to read into 'dest'
.Close both file pointers to save data


------------------------ STRING ----------------------------------
### fun 14 : remove Spaces
Input:   array of characters
Output :  same string but without any whitespace
Algorithm:
.two pointers (i for reading, j for writing) starting at the beginning of the string
.Copy the character from i to j only if it's a valid character, then move j forward
.Always move i until the end (\0)
.Terminate the new string by placing a null character \0 at the final position of j

### FUN 15 : substring
Input:  Source , Index where the extraction begins , Number of characters to extract , where store the result
Output : dest
Algorithm:
.Check if (start + len) is within the bounds of strlen(src). If not, exit
.from i = 0 to len - 1 : Copying dest[i] = src[start + i]
.dest[len] = '\0' to mark the end of the string


### FUN 15 : compare Ignore Case
Input:  Two strings
Output : .0: If the strings are identical (ignoring case)
         . integer: If the strings are different
Algorithm:
.Convert the current character of both strings to lowercase using tolower()
.If the lowercase characters are not equal, stop
.If the loop ends, return the difference between the final characters (to ensure both strings ended at the same time)

## Function: insertAt

### Problem Understanding (An Example)

* Input:  arr\[] — the array, \*size — current element count,
index — position to insert at, value — element to insert
* Output: returns 0 on success, -1 on error; modifies arr\[] and \*size
* Edge cases: index out of bounds, array full (size >= MAX\_1D)

### Algorithm (Simple steps only)

1. Check that index is within \[0, \*size] and size < MAX\_1D
2. Shift all elements from position index rightward by one slot
3. Place value at arr\[index] and increment \*size



## Function: printArray

### Problem Understanding

* Input:arr[] - array of integers , size - number of elements in the array
* Output: returns the maximum or minimum value in the array


### Algorithm ( simple steps )

1. Set max = arr[0]
2. if arr[i] > max, update max = arr[i] or if arr[i] < min , update min = arr[i]

## function mergesort
### problem understanding

* input : arr[] - array of integers , left - starting index , right - ending index 
* output : no value returned ( void ) , the array is sorted in ascending order in-place

 ### Algorithm ( simple steps )
1. Check if (left < right)
2. Find middle index.
3.Recursively call mergeSort on left half 
4.Recursively call mergeSort on right half 
5.Call merge to combine the two sorted halves

### Function merge 
### Probleme solvig
* input :arr[]- array of integers , left - starting index , mid -middle index , right - ending index
*output :No return value (void) , Merges two sorted parts of the array into one sorted section inside arr[]

### Algorithm ( simple steps)
1. create a temporary array
2.set pointers:
i = left (start of left half)
j = mid + 1 (start of right half)
3.compare elements from both halves:
copy the smaller element into temp array
move the corresponding pointer
4.repeat until one half is finished
5.copy remaining elements from the other half
6.copy all elements from temp array back to original array

### Function quickSort
### Problem understanding

* input : arr[] - array of integers , low - starting index of the array (or subarray) , high - ending index of the array (or subarray)
* output : No return value (void) ,The array arr[] is sorted in ascending order in-place

### Algorithm ( simple steps )
Check if low < high , Choose pivot (last element: arr[high]) , Initialize i = low - 1If arr[j] < pivot, increment i and swap arr[i] with arr[j]
Place pivot in correct position by swapping arr[i+1] with arr[high] , Get partition index pi = i + 1 , Recursively apply quickSort on left part (low → pi-1) ,
Recursively apply quickSort on right part (pi+1 → high)


### Function transposeMatrix
### probleme solving
* innput : matrix(m)
* output : matrix(out)

### Algorithm ( simple steps )

This is done by going through the entire matrix one item at a time
The value that you find at (i,j) should simply be entered into the new matrix at (j,i).


### Function addMatrices
### Probleme solving
*input : 2 matrix of the same size
*output : a matrix ( contains the sum of the 2 matrix)

### Algorithm ( simple steps )

Go through the matrix row by row
In each row, move column by column
Add the matching elements from matrix A and B
Store the result in matrix R
Keep doing this until all elements are added



### Function countwords
### Probleme solving 
*input : a string
*output : number of words in the string

### Algorithm ( simple steps ) 

1.Initialization of variables:
count = 0, inWord = 0
2. Looping through characters in the string one by one
3. Condition for character being equal to a space:
inWord = 0
4. Condition for character NOT being a space and inWord = 0:
count++
inWord = 1
5.Condition for character NOT being a space and inWord = 1:
nothing to do
6.Next character


### Function palindrom
### Probleme solving
*input : a string
*output: palindrom or not

### Algorithm ( simple steps )

1.Compute string length.
2.Initialize:
i = 0 (first position)
j = len - 1 (last position)
3.Compare s[i] and s[j]
4.If s[i] ≠ s[j]: terminate and return 0
5.Else:
Advance i; decrement j
Repeat this until i meets j

### Function removechar
### Probleme solving
*input : a string
*output : a modified string


### Algorithm ( simple steps )

1.Establish two pointers:
i = 0 (for read) and  j = 0 (for write)
2.Scan each character up to '\0' in the string
3.For every character s[i] in the string
if s[i] ≠ c
s[j] = s[i]
increment j
else skip

4.Increment pointer: i++
5.At the end of the loop
s[j] = '\0'


### Function creatBinaryfile
### Probleme solving
*input  : a string (const char*) representing the name of the file to create
*output : a binary file


### Algorithm ( simple steps )

1.call fopen(filename, "wb")
2.File opened in write-binary mode
3.If file does not exist, it will be created
Otherwise, it will be overwritten
4.Check if the file pointer returned by fopen is NULL
NULL pointer implies failure
5.If successful:
Close file using fclose()
Return 0
Else:
Return -1


### Function insertBegining
### Problem solving
*input : 1. a pointer to the List structure
        2.t he integer value to be stored
     
*output : returns 0 on success or -1 if memory allocation fails

### Algorithm ( simple steps )

1. allocate memory for a new Node
2. assign the value to the node's data
3. set the node’s next pointer to the current head
4. update the head to point to this new node

### Function insertEnd
### Problem solving
*input : 1. a pointer to the List structure
         2.the integer value to be stored
*output : returns 0 on success or -1 if memory allocation fails

### Algorithm ( simple stps )
1. allocate memory for a new Node and set its next to NULL
2. if the list is empty, set head to the new node
3. else, traverse the list using a temp pointer until temp->next == NULL
4. link the current last node's next to the new node

### Function insertBegeningDLL
###Problem solving 
*input : DLL* L: A pointer to the list structure (which contains head and tail pointers)
*output : int value: The integer data you want to store in the new node


### Algorithm ( simple steps )
1.allocate: Creates a new Node in memory
2.fills the node with the value and points its next pointer toward the current head
3.if the list has nodes, it tells the old head to point back (prev) to the new node
4. ifthe list is empty, it sets the tail to this new node
5.Updates the head pointer to point to the new node


### Function pop
### Problem somving 
*input : stack Pointer (S): A pointer to the stack structure that contains the address of the current top node
* output : success: Returns the integer value that was stored at the top of the stack
           failure: Returns a sentinel value to indicate the stack was empty 

### Algorithm ( simple steps )
1.empty check: Verify if S->top is NULL. If it is, exit and return the sentinel value
2.data extraction: Copy the value from S->top->data into a local variable
3.Pointer Preservation: Create a temp pointer and point it to the current S->top node
4.update Top: Assign S->top to the next node in the list (S->top->next)
5.memory Release: Deallocate (free) the memory at the temp pointer  


### Function enqueue
### Problem solving
*input : 1.target Queue: A pointer to the queue structure (which tracks the front and rear)
         2.data Value: The integer (or data) you want to add to the queue
*output : 1.success Status: returns a 1 or 0 
          2.Updated State: The queue now contains the new element at the tail, and the rear pointer is updated to reflect the new end of the line
          
### Algorithm ( simple steps )
1.node Creation: Create a new node and assign the input value to its data field. Set its "next" pointer to NULL
2.empty Check: Check if the queue is currently empty (usually rear == NULL)
3.linking (Case A - Empty): If empty, point both front and rear to the new node
4.linking (Case B - Not Empty): If not empty:
5.point the current rear->next to the new node
6.update the rear pointer to be the new node


