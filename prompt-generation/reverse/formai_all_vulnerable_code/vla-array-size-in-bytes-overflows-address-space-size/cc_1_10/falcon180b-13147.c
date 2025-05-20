//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

int main(){
    int choice, i, n, sum=0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter the elements of the array:\n");

    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nEnter your choice:\n");
    printf("1. Sum of all elements\n");
    printf("2. Average of all elements\n");
    printf("3. Product of all elements\n");
    scanf("%d", &choice);

    switch(choice){

        case 1:
            for(i=0; i<n; i++){
                sum += arr[i];
            }
            printf("The sum of all elements is: %d\n", sum);
            break;

        case 2:
            if(n==0){
                printf("Array is empty.\n");
            }
            else{
                float avg = (float)sum/n;
                printf("The average of all elements is: %.2f\n", avg);
            }
            break;

        case 3:
            for(i=0; i<n; i++){
                sum *= arr[i];
            }
            printf("The product of all elements is: %d\n", sum);
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}