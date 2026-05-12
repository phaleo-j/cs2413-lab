#include <stddef.h>


/*
Question 3: Quick Sort

Description:
Implement quick sort to sort an integer array in ascending order.

Quick sort is a divide-and-conquer algorithm:
1. Choose a pivot element.
2. Partition the array so that elements smaller than or equal to
   the pivot come before it, and elements greater than the pivot
   come after it.
3. Recursively sort the left and right parts.

You should implement:

    void quickSort(int arr[], int size);

You may design your own helper functions.
Suggested helper functions:

    void quickSortHelper(int arr[], int low, int high);
    int partition(int arr[], int low, int high);

For simplicity, you may use the last element as the pivot.

Example:
Input:  [10, 7, 8, 9, 1, 5]
Output: [1, 5, 7, 8, 9, 10]

pivot: 5
then, we simply do 
[]
[1,5,10,7,8,9]

for


Notes:
- If the array is empty or has only one element, do nothing.
- The sorting should be done in ascending order.
*/


void quickSort(int arr[], int size) {

    int temp = 0;
    // TODO: implement quick sort
    if (size == 1){                  //array with only 1 element
        return;
    }   
    if ((arr == NULL) || (size <= 0)){  //empty array
        return;

    }

    int pivot = arr[size - 1];  //choosing the last element as pivot
    int placement_index = -1;

    for(int i = 0; i < size - 1; i++){

        if(arr[i] < pivot){ 
            placement_index++;  //increment placement index
            temp = arr[placement_index];
            arr[placement_index] = arr[i];
            arr[i] = temp;     //swap
        }
    }
    
temp = arr[placement_index + 1];    //place pivot at the correct index
arr[placement_index + 1] = arr[size - 1];
arr[size - 1] = temp;

quickSort(arr, placement_index + 1);  //right partition and size
quickSort(arr + placement_index + 2, size - placement_index - 2 );  //

}

