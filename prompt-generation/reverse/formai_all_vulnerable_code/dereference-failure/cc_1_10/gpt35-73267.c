//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: genious
#include<stdio.h>
#include<stdlib.h>

void performGreedy(int size, int* values, int* weights, int capacity);
void swap(int* a, int* b);
void sort(int size, int* values, int* weights);

int main()
{
    int size, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &size);

    int* values = (int*)malloc(size * sizeof(int));
    int* weights = (int*)malloc(size * sizeof(int));

    printf("Enter the values and weights of each item:\n");
    for(int i = 0; i < size; i++){
        scanf("%d %d", &values[i], &weights[i]);
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    performGreedy(size, values, weights, capacity);

    return 0;
}

void performGreedy(int size, int* values, int* weights, int capacity)
{
    sort(size, values, weights);
    int currentWeight = 0, currentValue = 0;

    printf("Selected items:\n");
    for(int i = 0; i < size; i++){
        if(currentWeight + weights[i] <= capacity){
            currentWeight += weights[i];
            currentValue += values[i];
            printf("Item %d added with value %d and weight %d\n", i+1, values[i], weights[i]);
        }
        else{
            int remaining = capacity - currentWeight;
            currentValue += values[i] * ((double)remaining / weights[i]);
            printf("Item %d added partially with value %d and weight %d\n", i+1, values[i], remaining);
            break;
        }
    }

    printf("Max value in knapsack: %d\n", currentValue);
}

void sort(int size, int* values, int* weights)
{
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            double val1 = ((double)values[i] / weights[i]);
            double val2 = ((double)values[j] / weights[j]);
            if(val1 < val2){
                swap(&values[i], &values[j]);
                swap(&weights[i], &weights[j]);
            }
        }
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}