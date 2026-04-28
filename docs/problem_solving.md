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