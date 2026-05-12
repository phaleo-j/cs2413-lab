#include <stddef.h>

/*
Question 2: Merge Sort

Description:
Implement merge sort to sort an integer array in ascending order.

Merge sort is a divide-and-conquer algorithm:
1. Divide the array into two halves.
2. Recursively sort each half.
3. Merge the two sorted halves into one sorted array.

You should implement:

    void mergeSort(int arr[], int size);

You may design your own helper functions.
Suggested helper functions:

    void mergeSortHelper(int arr[], int left, int right);
    merge(arr, leftArr, mid, rightArr, size - mid);

Example:
Input:  [38, 27, 43, 3, 9, 82, 10]
Output: [3, 9, 10, 27, 38, 43, 82]

Notes:
- If the array is empty or has only one element, do nothing.
- You may use temporary arrays inside your merge function.
*/


void merge(int arr[], int leftArr[], int leftSize, int rightArr[], int rightSize){
    
    int indxLeft = 0;
    int indxRight = 0;
    int indxArr = 0;

while ((indxLeft < leftSize) && (indxRight < rightSize)){  //once value of last index of index left is reached we stop
// cmp leftArr[indxLeft] and rightArr[indexRight]:
    if (rightArr[indxRight] > leftArr[indxLeft]){  

    arr[indxArr] = leftArr[indxLeft];  //choose left array
    indxArr++;                           // increment array index
    indxLeft++;                         //increment left index

    } else {

    arr[indxArr] = rightArr[indxRight];   //choose right array 
    indxArr++;                            //incerment array index
    indxRight++;                         //increment right index
    
    }
}

while(indxRight < rightSize){     // if left loop exhausted first, copy elements from right array

arr[indxArr++] = rightArr[indxRight++];    
    
}

while(indxLeft < leftSize){

arr[indxArr++] = leftArr[indxLeft++];    

} 
}



void mergeSort(int arr[], int size) {

 if(arr == NULL){  // if array is empty
    return;
 }   

if(size == 1){  // if array has one element
 return;
} 

    //split array into two parts first   
int mid = size / 2;  //right hand size gets larger array
int leftArr[mid];       
int rightArr[size - mid];

for (int i = 0; i < mid; i++){    //fill each half
leftArr[i] = arr[i];
}

for (int x = 0; x < size - mid; x++){   
rightArr[x] = arr[mid+x];
}

 mergeSort(leftArr, mid);  //left half
 mergeSort(rightArr, size - mid);  //right half
 merge(arr, leftArr, mid, rightArr, size - mid);

}

