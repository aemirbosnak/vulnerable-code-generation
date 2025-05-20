//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, i, j, k, l, p, q, r, t, greedy_sum = 0, total_sum = 0;
    float average_price, total_cost;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int items[n];
    printf("Enter the prices of each item: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &items[i]);
    }

    printf("Enter the number of packets: ");
    scanf("%d", &p);

    int packets[p];
    printf("Enter the number of items that can fit into each packet: ");
    for (i = 0; i < p; i++)
    {
        scanf("%d", &packets[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < p; j++)
        {
            if (items[i] <= packets[j])
            {
                greedy_sum += items[i];
                packets[j] -= items[i];
            }
        }
    }

    total_sum = greedy_sum;
    total_cost = (float)total_sum * average_price;

    printf("The total sum of items that can be greedily packed is: %d", total_sum);
    printf("\nThe total cost of items that can be greedily packed is: %.2f", total_cost);

    return 0;
}