//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random numbers
int rand_num(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

//Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function to implement bucket sort
void bucket_sort(int arr[], int n)
{
    int max = arr[0], min = arr[0], range, i, j, k;
    int *bucket[n];
    for(i=0; i<n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }
    range = max - min + 1;
    for(i=0; i<n; i++)
    {
        bucket[i] = (int *)malloc(range * sizeof(int));
        for(j=0; j<range; j++)
        {
            bucket[i][j] = 0;
        }
    }
    for(i=0; i<n; i++)
    {
        k = (arr[i] - min) / (max - min) * n;
        bucket[k][arr[i] - min]++;
    }
    for(i=0; i<n; i++)
    {
        k = 0;
        for(j=0; j<range; j++)
        {
            if(bucket[i][j] > 0)
            {
                arr[k++] = min + j;
                bucket[i][j]--;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        free(bucket[i]);
    }
}

int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    srand(time(NULL));
    for(i=0; i<n; i++)
    {
        swap(&arr[i], &arr[rand_num(0, n-1)]);
    }
    bucket_sort(arr, n);
    printf("Sorted array: ");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}