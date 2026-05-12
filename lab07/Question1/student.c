#include <stdbool.h>
#include <stddef.h>
/*
Question 1: Bubble Sort

Description:
Implement two versions of bubble sort for an integer array.

1. bubbleSort:
   Implement the basic bubble sort algorithm.
   Repeatedly compare adjacent elements and swap them if they are
   in the wrong order. After each pass, the largest unsorted element
   should move to its correct position.

2. bubbleSortOptimized:
   Implement an improved version of bubble sort.
   This version should stop early if a full pass completes without
   any swaps, which means the array is already sorted.

Both functions should sort the array in ascending order.

Example:
Input:  [5, 1, 4, 2, 8]

[1,5,4,2,8]   1 swap
[1,4,5,2,8]   2 swap
[1,4,2,5,8]   3 swap    keep smallest and largest value 1,8
[1,2,4,5,8]   4 swaps  


[4,5,2,8,1] 1

[4,2,5,8,1] 1 swap
[4,2,5,1,8] 1st pass through 2 swaps
[2,4,5,1,8] 3 swap 
[2,4,1,5,8] 4 swap
[2,1,4,5,8] 5 swap 
[1,2,4,5,8] 6 swap


Output: [1, 2, 4, 5, 8]

Notes:
- If the array is empty or has only one element, do nothing.
- You may write a helper function such as swap(...) if you want.
*/

void bubbleSort(int arr[], int size) {

    if((size == 1) || (arr == NULL)){
      return;
    } 

 bool swapped = true;

    while (swapped) {
        swapped = false;
        for (int i = 0; i < size - 1; i++) {

            if (arr[i + 1] < arr[i]) {  //if a swap has occured, 
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;   //then set swapped to true, keeping the loop going

            }
        }
        size--;
    }

}

void bubbleSortOptimized(int arr[], int size) {
    
     if((size == 1) || (arr == NULL)){
      return;
    } 

 bool swapped = true;

    while (swapped) {
        swapped = false;
        for (int i = 0; i < size - 1; i++) {

            if (arr[i + 1] < arr[i]) {  //if a swap has occured, 
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;   //then set swapped to true, keeping the loop going
                
            }
        }
        size--;
    }
}

