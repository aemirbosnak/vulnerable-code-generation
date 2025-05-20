//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the weights of each item: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int total_weight = 0;
    for (int i = 0; i < n; i++)
    {
        total_weight += arr[i];
    }

    int capacity;
    printf("Enter the capacity of the bag: ");
    scanf("%d", &capacity);

    int bag[capacity];
    for (int i = 0; i < capacity; i++)
    {
        bag[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < capacity; j++)
        {
            if (bag[j] + arr[i] <= capacity)
            {
                bag[j] += arr[i];
            }
        }
    }

    int total_value = 0;
    for (int i = 0; i < capacity; i++)
    {
        total_value += bag[i] * arr[i];
    }

    printf("The total value of the items that can be carried is: %d", total_value);

    return 0;
}