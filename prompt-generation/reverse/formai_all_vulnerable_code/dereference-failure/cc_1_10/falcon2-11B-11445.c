//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to search a string in an array of strings
int search(char *arr[], char search_str[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (strcmp(arr[i], search_str) == 0)
            return 1;
    }
    return 0;
}

// Function to print array elements
void print_array(char *arr[], int size)
{
    int i;

    for (i = 0; i < size; i++)
        printf("%s\n", arr[i]);
}

// Function to sort the array in ascending order
void sort_array(char *arr[], int size)
{
    int i, j;
    char temp;

    // Bubble sort algorithm
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (strcmp(arr[j], arr[j + 1]) > 0)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the kth smallest element in the array
int find_kth_smallest(char *arr[], int size, int k)
{
    int i, j;
    int min_index = 0;
    char min_element = arr[0];

    // Find the minimum element in the array
    for (i = 0; i < size; i++)
    {
        if (strcmp(arr[i], min_element) < 0)
        {
            min_element = arr[i];
            min_index = i;
        }
    }

    // Find the kth smallest element
    for (i = 0; i < size; i++)
    {
        if (i + 1 == k)
            return min_element;
        else if (strcmp(arr[i], min_element) > 0)
        {
            min_element = arr[i];
            min_index = i;
        }
    }
    return min_element;
}

int main()
{
    char *arr[5];
    int size = 5;
    int i;

    for (i = 0; i < size; i++)
    {
        arr[i] = (char *)malloc(sizeof(char) * 10);
        if (arr[i] == NULL)
            break;
        printf("Enter the %d string: ", i + 1);
        fgets(arr[i], 10, stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0';
    }

    if (i == size)
    {
        printf("Sorted array:\n");
        sort_array(arr, size);
        print_array(arr, size);

        printf("5th smallest element: %s\n", find_kth_smallest(arr, size, 5));
    }

    return 0;
}