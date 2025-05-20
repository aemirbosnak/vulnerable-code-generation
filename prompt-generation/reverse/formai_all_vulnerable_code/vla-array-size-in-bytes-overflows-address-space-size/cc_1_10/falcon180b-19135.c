//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 100

int main()
{
    srand(time(NULL));
    int arr[MAX_SIZE];
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the elements of array:\n");
    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % 100;
    }
    int sum = 0;
    int max_val = arr[0];
    int min_val = arr[0];
    float avg = 0.0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
        if(arr[i] > max_val)
        {
            max_val = arr[i];
        }
        if(arr[i] < min_val)
        {
            min_val = arr[i];
        }
    }
    avg = (float)sum/n;
    printf("Sum of elements: %d\n", sum);
    printf("Maximum value: %d\n", max_val);
    printf("Minimum value: %d\n", min_val);
    printf("Average value: %.2f\n", avg);
    printf("Enter the number of elements to be sorted:\n");
    int num_sort;
    scanf("%d", &num_sort);
    int sort_arr[num_sort];
    printf("Enter the elements to be sorted:\n");
    for(int i=0; i<num_sort; i++)
    {
        scanf("%d", &sort_arr[i]);
    }
    int count = 0;
    for(int i=0; i<n; i++)
    {
        bool found = false;
        for(int j=0; j<num_sort; j++)
        {
            if(arr[i] == sort_arr[j])
            {
                found = true;
                break;
            }
        }
        if(found)
        {
            count++;
        }
    }
    printf("Number of elements in array that are also in sorted array: %d\n", count);
    return 0;
}