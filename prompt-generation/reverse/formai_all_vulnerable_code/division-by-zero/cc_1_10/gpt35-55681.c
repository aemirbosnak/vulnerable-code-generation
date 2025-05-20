//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: enthusiastic
#include<stdio.h>

int main()
{
    int n, value[20], weight[20], ratio[20], i, j, capacity, total_weight=0, profit=0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight and value of each item: \n");
    for(i=0; i<n; i++)
    {
        printf("Item %d: ", i+1);
        scanf("%d %d", &weight[i], &value[i]);
        ratio[i] = value[i]/weight[i];
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    //Sorting in descending order based on ratio
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(ratio[i]<ratio[j])
            {
                int temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = value[i];
                value[i] = value[j];
                value[j] = temp;
            }
        }
    }

    //Calculating the profit
    for(i=0; i<n; i++)
    {
        if(total_weight+weight[i]<=capacity)
        {
            profit += value[i];
            total_weight += weight[i];
        }
        else
        {
            int remaining = capacity - total_weight;
            profit += remaining * ratio[i];
            break;
        }
    }

    printf("Maximum profit possible is: %d", profit);
    return 0;
}