//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    double value;
} Item;

int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemA->value < itemB->value) return 1; // Descending order
    if (itemA->value > itemB->value) return -1;
    return 0;
}

void greedy_knapsack(Item items[], int n, double capacity) {
    double totalValue = 0.0;
    double remainingCapacity = capacity;

    printf("Selected items:\n");
    for (int i = 0; i < n; i++) {
        if (items[i].value > remainingCapacity) {
            printf("Item %d: Cannot be selected, needs %.2f but only %.2f left.\n", 
                    items[i].index, items[i].value, remainingCapacity);
            continue;
        }
        
        remainingCapacity -= items[i].value;
        totalValue += items[i].value;
        printf("Item %d included, value: %.2f, remaining capacity: %.2f\n", 
                items[i].index, items[i].value, remainingCapacity);
    }

    printf("Total value of selected items: %.2f\n", totalValue);
}

int main() {
    int n;

    printf("Enter number of items: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("No items to process.\n");
        return 0;
    }

    double capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%lf", &capacity);

    Item *items = (Item *)malloc(n * sizeof(Item));

    printf("Enter value for each item:\n");
    for (int i = 0; i < n; i++) {
        items[i].index = i + 1; // Store index for reporting
        printf("Value of item %d: ", i + 1);
        scanf("%lf", &items[i].value);
    }

    qsort(items, n, sizeof(Item), compare);

    printf("\nItems sorted by value (descending):\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Value: %.2f\n", items[i].index, items[i].value);
    }

    greedy_knapsack(items, n, capacity);
    
    free(items);
    return 0;
}