//FormAI DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int* create_array(int size);
void print_array(int* arr, int size);
void bubble_sort(int* arr, int size);
int binary_search(int* arr, int size, int num);

int main()
{
    srand(time(NULL));

    int* arr = create_array(SIZE);
    printf("Unsorted Array:\n");
    print_array(arr, SIZE);

    bubble_sort(arr, SIZE);
    printf("Sorted Array:\n");
    print_array(arr, SIZE);

    int num = rand() % 20;
    int index = binary_search(arr, SIZE, num);

    if(index != -1)
        printf("%d was found at index %d.\n", num, index);
    else
        printf("%d was not found.\n", num);

    free(arr);

    return 0;
}

int* create_array(int size)
{
    int* arr = (int*)malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++)
        arr[i] = rand() % 20;

    return arr;
}

void print_array(int* arr, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void bubble_sort(int* arr, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binary_search(int* arr, int size, int num)
{
    int low = 0;
    int high = size - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == num)
            return mid;
        else if(arr[mid] < num)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}