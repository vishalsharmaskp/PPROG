#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define MAX_Depth 14
#define arraySize 2048

// static int depth = 0;

static int num_operation[MAX_Depth] = {0};

void printArray(int A[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int arr[], int l, int m , int r, int depth){
    // printf("depth %d\n", depth);
    // printf("numoperation %d\n", num_operation[depth]);


    int n1 = m - l + 1;
    int n2 = r - m;

    //create temp arrays
    int L[n1], R[n2];

    //Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j]; 
    }
    // merge the two temporary array into one shorted array
    int i = 0, j = 0, k = l; 
    while (i < n1 && j < n2) {
        num_operation[depth] = num_operation[depth] + 1;
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++; 
    }

    while (i < n1){
        arr[k] = L[i]; 
        i++;
        k++;

    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    } 
}

void mergeSort(int arr[], int l, int r, int depth){
        
    if (l < r){
        // printf("Depth: %d\n", depth);
        depth = depth + 1;
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m, depth);
        mergeSort(arr, m + 1, r, depth);

        // Merge the sorted halves
        merge(arr, l, m, r, depth);
    }
}


int main(){
    // strad(time(0));
    int depth = 0;
    int arr[arraySize];
    for (int i = 0; i < arraySize; i++){
        arr[i] = rand() % 10 +1;
    }
    printf("Unsorted array: \n");
    // printArray(arr, arraySize);
    
    mergeSort(arr, 0, arraySize - 1,   depth);   
    printf("Sorted array: \n");
    // printArray(arr, arraySize);
  

    printf("Number of operations: \n");
    for (int i = 0; i < MAX_Depth; i++){
        printf("Depth %d: %d\n", i, num_operation[i]);
    }

    return 0;
}

