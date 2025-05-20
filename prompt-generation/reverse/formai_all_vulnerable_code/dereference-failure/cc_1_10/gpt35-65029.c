//FormAI DATASET v1.0 Category: Benchmarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void happyPrint(char* message){
    printf(":) %s\n", message);
}

void generateRandomArray(int* arr, int arrSize){
    int i;
    for(i = 0; i < arrSize; i++){
        arr[i] = rand();
    }
}

void bubbleSort(int* arr, int arrSize){
    int i, j, temp;
    for(i = 0; i < arrSize-1; i++){
        for(j = 0; j < arrSize-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void quicksort(int numbers[], int left, int right)
{
    int pivot, l_hold, r_hold;
    l_hold = left;
    r_hold = right;
    pivot = numbers[left];
    while (left < right)
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        quicksort(numbers, left, pivot-1);
    if (right > pivot)
        quicksort(numbers, pivot+1, right);
}

int main(){
    int arrSize = 1000000;
    int* arr = (int*) malloc(sizeof(int) * arrSize);

    srand(time(NULL));
    generateRandomArray(arr, arrSize);

    clock_t start = clock();
    bubbleSort(arr, arrSize);
    clock_t end = clock();
    happyPrint("Bubble Sort finished in:");
    printf("%f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    generateRandomArray(arr, arrSize);

    start = clock();
    quicksort(arr, 0, arrSize-1);
    end = clock();
    happyPrint("Quick Sort finished in:");
    printf("%f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);

    return 0;
}