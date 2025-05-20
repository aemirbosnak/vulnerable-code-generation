//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void main()
{
    int i, j, n, items, total_weight, current_weight = 0, maximum_profit = 0, current_profit = 0;
    char **items_name = NULL;
    int *items_weight = NULL;
    int *items_profit = NULL;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    items_name = (char**)malloc(n * sizeof(char*));
    items_weight = (int*)malloc(n * sizeof(int));
    items_profit = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", items_name[i]);

        printf("Enter the weight of item %d: ", i + 1);
        scanf("%d", &items_weight[i]);

        printf("Enter the profit of item %d: ", i + 1);
        scanf("%d", &items_profit[i]);
    }

    printf("Enter the total weight of the bag: ");
    scanf("%d", &total_weight);

    for (i = 0; i < n; i++)
    {
        current_profit = items_profit[i] * items_weight[i];
        if (current_weight + items_weight[i] <= total_weight)
        {
            current_weight += items_weight[i];
            maximum_profit += current_profit;
        }
    }

    printf("The maximum profit is: %d", maximum_profit);

    free(items_name);
    free(items_weight);
    free(items_profit);

    return;
}