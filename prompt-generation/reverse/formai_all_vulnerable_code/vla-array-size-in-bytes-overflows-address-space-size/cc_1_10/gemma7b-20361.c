//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void introspective_greedy_algorithm()
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int items[n];
    printf("Enter the weights of each item: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &items[i]);
    }

    int total_weight = 0;
    for (int i = 0; i < n; i++)
    {
        total_weight += items[i];
    }

    int bag_size = 0;
    printf("Enter the size of your bag: ");
    scanf("%d", &bag_size);

    int capacity = 0;
    for (int i = 0; i < n; i++)
    {
        capacity += items[i] * items[i];
    }

    if (total_weight <= bag_size)
    {
        printf("Your bag is big enough to fit all of the items.\n");
    }
    else
    {
        printf("Your bag is not big enough to fit all of the items. You will have to leave some items behind.\n");
    }

    int items_left_behind = 0;
    for (int i = 0; i < n; i++)
    {
        if (items[i] * items[i] <= capacity)
        {
            items_left_behind++;
        }
    }

    printf("The number of items left behind is: %d\n", items_left_behind);
}

int main()
{
    introspective_greedy_algorithm();

    return 0;
}