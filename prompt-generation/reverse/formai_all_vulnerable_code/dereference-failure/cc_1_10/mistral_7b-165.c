//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MIN_VALUE -100
#define MAX_VALUE 100

typedef struct{
    int num[MAX_SIZE];
    int length;
} myArray;

void readArray(myArray* arr){
    int i = 0;
    char temp[10];

    printf("Enter %d numbers separated by space\n", MAX_SIZE);
    while(i < MAX_SIZE && fgets(temp, sizeof(temp), stdin) != NULL){
        arr->num[i] = atoi(strtok(temp, " "));
        if(arr->num[i] < MIN_VALUE || arr->num[i] > MAX_VALUE){
            printf("Invalid number! Please enter a number between %d and %d\n", MIN_VALUE, MAX_VALUE);
            i--;
            continue;
        }
        i++;
    }
    arr->length = i;
}

int sumArray(myArray arr1, myArray arr2){
    int i = 0, sum = 0;

    if(arr1.length != arr2.length){
        printf("Error: Arrays must have the same length!\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < arr1.length; i++){
        sum += arr1.num[i] + arr2.num[i];
    }

    return sum;
}

int main(){
    myArray arr1, arr2, result;

    readArray(&arr1);
    readArray(&arr2);

    result.length = MAX_SIZE;
    printf("Sum of arrays %s and %s:\n", arr1.num, arr2.num);
    printf("Array 1: [");
    for(int i = 0; i < arr1.length; i++){
        printf("%d, ", arr1.num[i]);
    }
    printf("\b]");

    printf("\nArray 2: [");
    for(int i = 0; i < arr2.length; i++){
        printf("%d, ", arr2.num[i]);
    }
    printf("\b]");

    result.length = 0;

    if(sumArray(arr1, arr2) > MAX_VALUE || sumArray(arr1, arr2) < MIN_VALUE){
        printf("Error: Sum of arrays is out of range!\n");
        exit(EXIT_FAILURE);
    }

    result.num[result.length++] = sumArray(arr1, arr2);
    printf("\nSum of arrays %s and %s is: [%d]\n", arr1.num, arr2.num, result.num[0]);

    return 0;
}