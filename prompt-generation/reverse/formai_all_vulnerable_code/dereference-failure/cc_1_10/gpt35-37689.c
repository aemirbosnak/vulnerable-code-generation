//FormAI DATASET v1.0 Category: Math exercise ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    // seed for generating random numbers
    srand(time(NULL));
    
    // generate a random number between 10 and 30
    int n = rand() % 21 + 10;
    
    // dynamically allocate memory for array of size n
    int* arr = malloc(n * sizeof(int));
    
    // generate n random integers and store in array
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 101;
    }
    
    // calculate sum of array elements
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    
    // calculate average of array elements
    float avg = (float)sum / n;
    
    // calculate standard deviation of array elements
    float sd = 0.0;
    for (int i = 0; i < n; i++)
    {
        sd += pow(arr[i] - avg, 2);
    }
    sd = sqrt(sd / n);
    
    // print array elements
    printf("Array elements:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // print sum, average, and standard deviation
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);
    printf("Standard deviation: %.2f\n", sd);
    
    // free dynamically allocated memory
    free(arr);
    
    return 0;
}