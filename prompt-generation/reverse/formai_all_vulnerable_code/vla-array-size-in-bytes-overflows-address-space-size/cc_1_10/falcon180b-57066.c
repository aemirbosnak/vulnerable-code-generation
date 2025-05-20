//Falcon-180B DATASET v1.0 Category: Recursive ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

//Function to print an array in reverse order
void printArrayReverse(int arr[], int size){
    int i;
    for(i=size-1; i>=0; i--){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//Recursive function to find the sum of all elements in an array
int sumArray(int arr[], int size){
    int sum = 0;
    int i;
    //Base case
    if(size == 0){
        return 0;
    }
    //Recursive case
    else{
        sum += arr[0];
        sum += sumArray(arr+1, size-1);
    }
    return sum;
}

//Recursive function to find the product of all elements in an array
int productArray(int arr[], int size){
    int product = 1;
    int i;
    //Base case
    if(size == 0){
        return 1;
    }
    //Recursive case
    else{
        product *= arr[0];
        product *= productArray(arr+1, size-1);
    }
    return product;
}

//Recursive function to find the factorial of a number
int factorial(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

//Main function
int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    printf("The array in reverse order is:\n");
    printArrayReverse(arr, size);
    printf("The sum of all elements in the array is: %d\n", sumArray(arr, size));
    printf("The product of all elements in the array is: %d\n", productArray(arr, size));
    printf("The factorial of 5 is: %d\n", factorial(5));
    return 0;
}