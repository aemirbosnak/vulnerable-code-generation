//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int value;
    int weight;
} Item;

void selection(Item items[], int size, int capacity, int *selectedIndex, int *numSelected) {
    int i, j;
    Item selectedItem;

    for (*selectedIndex = 0, *numSelected = 0; *numSelected < size && capacity > 0; (*numSelected)++) {
        selectedItem = items[*numSelected];
        for (i = *numSelected + 1; i < size && (selectedItem.value / selectedItem.weight > items[i].value / items[i].weight); i++) {}

        if (i == size || (i < size && (capacity - items[i].weight >= 0))) {
            *selectedIndex = i;
            capacity -= items[*selectedIndex].weight;
        } else {
            break;
        }
    }
}

int main() {
    int x[] = {1, 2, 3, 4, 5};
    int size = sizeof(x) / sizeof(x[0]);
    int n = 7;
    int i, numSelected = 0;
    Item items[size];

    for (i = 0; i < size; i++) {
        items[i] = (Item){x[i], i};
    }

    int selectedIndex;
    while (n > 0 && numSelected < size) {
        selection(items, size, n, &selectedIndex, &numSelected);
        printf("Selected item %d with weight %d and value %d\n", items[selectedIndex].value, items[selectedIndex].weight, x[selectedIndex]);
        n -= items[selectedIndex].weight;
    }

    if (n == 0) {
        printf("Found a subset with sum %d\n", n);
    } else {
        printf("No subset with sum %d found\n", n);
    }

    return 0;
}