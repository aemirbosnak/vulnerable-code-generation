//FormAI DATASET v1.0 Category: Educational ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, sum, sub, mul, div, mod;
    
    printf("Enter first number :");
    scanf("%d", &num1);
    
    printf("Enter second number :");
    scanf("%d", &num2);
    
    sum = num1 + num2;
    sub = num1 - num2;
    mul = num1 * num2;
    div = num1 / num2;
    mod = num1 % num2;
    
    printf("\nMathematical Operations on the given numbers :\n");
    printf("Addition of %d and %d is     : %d\n", num1, num2, sum);
    printf("Subtraction of %d and %d is  : %d\n", num1, num2, sub);
    printf("Multiplication of %d and %d is: %d\n", num1, num2, mul);
    printf("Division of %d and %d is     : %d\n", num1, num2, div);
    printf("Modulo of %d and %d is       : %d\n\n", num1, num2, mod);
    
    int arr[10];
    int i;
    
    printf("Enter 10 elements in the array :\n");
    for(i=0;i<10;i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("\nElements in the array :\n");
    for(i=0;i<10;i++)
    {
        printf("%d ", arr[i]);
    }
    
    int j;
    int temp;
    
    for(i=0;i<10;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    
    printf("\n\nElements in the array after Sorting :\n");
    for(i=0;i<10;i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}