//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n, choice, i, j;
    float num1, num2, sum = 0, avg, std_dev;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n];

    for(i=0; i<n; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%f", &arr[i]);
    }

    printf("\nSelect an operation:\n");
    printf("1. Sum\n2. Average\n3. Standard Deviation\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            for(i=0; i<n; i++)
            {
                sum += arr[i];
            }
            printf("\nSum of elements: %.2f", sum);
            break;

        case 2:
            for(i=0; i<n; i++)
            {
                sum += arr[i];
            }
            avg = sum/n;
            printf("\nAverage of elements: %.2f", avg);
            break;

        case 3:
            for(i=0; i<n; i++)
            {
                sum += pow((arr[i]-avg), 2);
            }
            std_dev = sqrt(sum/n);
            printf("\nStandard Deviation: %.2f", std_dev);
            break;

        default:
            printf("\nInvalid choice!");
    }

    return 0;
}