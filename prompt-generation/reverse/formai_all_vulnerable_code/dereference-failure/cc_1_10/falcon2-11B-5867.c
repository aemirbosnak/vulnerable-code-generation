//Falcon2-11B DATASET v1.0 Category: Greedy Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int weight;
    int value;
} Item;

typedef struct {
    int capacity;
    int weight;
    int value;
} Knapsack;

void create_items(Item items[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        items[i].weight = rand() % 100 + 1;
        items[i].value = rand() % 100 + 1;
    }
}

void create_knapsack(Knapsack knapsack[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        knapsack[i].capacity = rand() % 100 + 1;
        knapsack[i].weight = rand() % 100 + 1;
        knapsack[i].value = rand() % 100 + 1;
    }
}

int get_max_value(Knapsack knapsack[], int size, int index) {
    if (knapsack[index].capacity == 0) {
        return 0;
    } else if (index == size - 1) {
        return knapsack[index].value;
    } else {
        int max_value = 0;
        for (int i = 0; i < knapsack[index].capacity; i++) {
            int temp_value = knapsack[index].value + get_max_value(knapsack, size, index + 1);
            if (temp_value > max_value) {
                max_value = temp_value;
            }
        }
        return max_value;
    }
}

int main() {
    int size;
    printf("Enter the size of the knapsack: ");
    scanf("%d", &size);

    Item items[size];
    create_items(items, size);

    Knapsack knapsack[size];
    create_knapsack(knapsack, size);

    int max_value = get_max_value(knapsack, size, 0);
    printf("The maximum value is %d\n", max_value);

    return 0;
}