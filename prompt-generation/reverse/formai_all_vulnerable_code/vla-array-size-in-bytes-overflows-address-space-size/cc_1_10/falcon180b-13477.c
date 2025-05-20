//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int weight;
    int value;
    int index;
} Item;

void init_items(Item items[], int n) {
    for (int i = 0; i < n; i++) {
        items[i].index = i;
        items[i].weight = rand() % 1000;
        items[i].value = rand() % 1000;
    }
}

int compare_values(const void *a, const void *b) {
    return (*(Item *)b).value - (*(Item *)a).value;
}

int compare_weights(const void *a, const void *b) {
    return (*(Item *)b).weight - (*(Item *)a).weight;
}

void print_items(Item items[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", items[i].value, items[i].weight, items[i].index);
    }
}

void greedy_algorithm(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare_values);

    int selected_items = 0;
    int total_value = 0;

    for (int i = 0; i < n && selected_items < capacity; i++) {
        if (items[i].value > 0) {
            total_value += items[i].value;
            selected_items++;
        }
    }

    printf("Total value: %d\n", total_value);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];
    init_items(items, n);

    int capacity;
    printf("Enter the capacity: ");
    scanf("%d", &capacity);

    greedy_algorithm(items, n, capacity);

    return 0;
}