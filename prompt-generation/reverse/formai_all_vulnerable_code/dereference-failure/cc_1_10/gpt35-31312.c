//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: complete
#include <stdio.h> 

int maxProfit(int weights[], int values[], int n, int capacity) 
{ 
    int i, j; 
    int final_profit = 0; 
    float fract; 
    int arr[n];
    float per[n];

    for (i = 0; i < n; i++)
    {
        arr[i] = values[i] / weights[i];
        per[i] = (float)arr[i];
    }
  
    for (i = 0; i < n - 1; i++)  
    {
        for (j = i + 1; j < n; j++)  
        {
            if (per[i] < per[j])  
            {
                int temp = per[j];
                per[j] = per[i];
                per[i] = temp;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                temp = weights[j];
                weights[j] = weights[i];
                weights[i] = temp;
                temp = values[j];
                values[j] = values[i];
                values[i] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)  
    {
        if (weights[arr[i]] <= capacity)  
        {
            final_profit = final_profit + values[arr[i]];
            capacity = capacity - weights[arr[i]];
        }
        else
        {
            fract = (float)capacity / (float)weights[arr[i]];
            final_profit = final_profit + (int)(values[arr[i]] * fract);
            capacity = (int)(capacity - weights[arr[i]] * fract);
        }
    }
    return final_profit; 
} 

int main() 
{ 
    int weights[] = {10, 20, 30}; 
    int values[] = {60, 100, 120}; 
    int n = sizeof(weights) / sizeof(weights[0]); 
    int capacity = 50; 
  
    printf("Maximum profit: %d", maxProfit(weights, values, n, capacity)); 
  
    return 0; 
}