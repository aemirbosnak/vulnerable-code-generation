//FormAI DATASET v1.0 Category: Data mining ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size, i, j;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    srand(time(0));
    for(i = 0; i < size; i++) {
        arr[i] = rand()%100; //generating random numbers between 0 and 99
    }
    printf("\nThe array: ");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nFinding the largest and smallest numbers in the array...\n\n");

    int largest = arr[0], smallest = arr[0];
    for(i = 1; i < size; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    printf("The largest number in the array is %d\n", largest);
    printf("The smallest number in the array is %d\n", smallest);

    printf("\nFinding the mean of the array...\n\n");

    int sum = 0;
    for(i = 0; i < size; i++) {
        sum += arr[i];
    }
    float mean = (float)sum/size;
    printf("The mean of the array is %0.2f\n", mean);

    printf("\nSorting the array in ascending order using bubble sort...\n\n");

    int temp;
    for(i = 0; i < size-1; i++) {
        for(j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("The sorted array: ");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nFinding the median of the array...\n\n");
    float median;
    if(size%2 == 0) {
        median = (float)(arr[size/2] + arr[(size/2)-1])/2;
    }
    else {
        median = (float)arr[size/2];
    }
    printf("The median of the array is %0.2f\n", median);

    return 0;
}