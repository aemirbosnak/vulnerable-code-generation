//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main()
{
    int n, i, j, k, m, temp, choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n\n");
        printf("1. Sort array in ascending order\n");
        printf("2. Sort array in descending order\n");
        printf("3. Reverse the array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                for(i=0; i<n-1; i++)
                {
                    for(j=0; j<n-i-1; j++)
                    {
                        if(arr[j] > arr[j+1])
                        {
                            temp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = temp;
                        }
                    }
                }
                printf("Sorted array in ascending order:\n");
                for(i=0; i<n; i++)
                {
                    printf("%d ", arr[i]);
                }
                break;

            case 2:
                for(i=0; i<n-1; i++)
                {
                    for(j=0; j<n-i-1; j++)
                    {
                        if(arr[j] < arr[j+1])
                        {
                            temp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = temp;
                        }
                    }
                }
                printf("Sorted array in descending order:\n");
                for(i=0; i<n; i++)
                {
                    printf("%d ", arr[i]);
                }
                break;

            case 3:
                for(i=0; i<n/2; i++)
                {
                    temp = arr[i];
                    arr[i] = arr[n-1-i];
                    arr[n-1-i] = temp;
                }
                printf("Reversed array:\n");
                for(i=0; i<n; i++)
                {
                    printf("%d ", arr[i]);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }while(TRUE);

    return 0;
}