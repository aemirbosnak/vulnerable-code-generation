//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_VALUE 1000

struct Item {
    int value;
    int weight;
    double value_per_weight;
};

void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct Item *array, int low, int high) {
    struct Item pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j].value_per_weight > pivot.value_per_weight) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quick_sort(struct Item *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

double fractional_knapsack(struct Item *array, int n, int capacity) {
    double total_value = 0.0;
    double current_weight = 0.0;
    int i = 0;

    quick_sort(array, 0, n - 1);

    while (current_weight < capacity && i < n) {
        if (current_weight + array[i].weight <= capacity) {
            total_value += array[i].value;
            current_weight += array[i].weight;
            i++;
        } else {
            double remaining_capacity = capacity - current_weight;
            total_value += (remaining_capacity / array[i].weight) * array[i].value;
            current_weight += remaining_capacity;
            break;
        }
    }

    return total_value;
}

int main() {
    struct Item array[MAX_SIZE];
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    assert(n <= MAX_SIZE);
    assert(capacity <= MAX_VALUE);

    for (int i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d: ", i + 1);
        scanf("%d %d", &array[i].value, &array[i].weight);
        array[i].value_per_weight = (double)array[i].value / (double)array[i].weight;
    }

    double total_value = fractional_knapsack(array, n, capacity);
    printf("Total value of items: %.2f\n", total_value);

    return 0;
}