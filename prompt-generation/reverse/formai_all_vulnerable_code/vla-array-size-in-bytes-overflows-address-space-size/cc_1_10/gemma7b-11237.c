//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algos()
{
    int n = 0;
    scanf("Enter the number of items: ", &n);

    int items[n];
    printf("Enter the weights of each item: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &items[i]);
    }

    int total_weight = 0;
    for (int i = 0; i < n; i++)
    {
        total_weight += items[i];
    }

    int bag_size = 0;
    printf("Enter the size of your bag: ");
    scanf("%d ", &bag_size);

    int capacity = 0;
    printf("Enter the capacity of your bag: ");
    scanf("%d ", &capacity);

    int packed_items = 0;
    for (int i = 0; i < n; i++)
    {
        if (total_weight - items[i] <= capacity && items[i] > packed_items)
        {
            packed_items++;
            total_weight -= items[i];
        }
    }

    printf("The number of items you can pack is: %d\n", packed_items);
}

int main()
{
    greedy_algos();

    return 0;
}