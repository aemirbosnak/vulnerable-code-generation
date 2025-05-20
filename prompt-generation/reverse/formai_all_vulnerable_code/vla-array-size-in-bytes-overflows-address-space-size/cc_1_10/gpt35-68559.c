//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: automated
#include <stdio.h>

// structure to hold information about an item
struct Item {
    int value; // value of the item
    int weight; // weight of the item
};

// function to compare two items based on their value to weight ratio
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *) a;
    struct Item *item2 = (struct Item *) b;
    double ratio1 = (double) item1->value/item1->weight;
    double ratio2 = (double) item2->value/item2->weight;
    if (ratio1 < ratio2) {
        return 1;
    } else if (ratio1 > ratio2) {
        return -1;
    } else {
        return 0;
    }
}

// function to find the maximum value that can be obtained by using a given weight capacity and a list of items
double get_max_value(struct Item *items, int n, int capacity) {
    // sort the items in decreasing order of their value to weight ratio
    qsort(items, n, sizeof(struct Item), compare);
    double max_value = 0;
    for (int i = 0; i < n; i++) {
        if (capacity == 0) {
            break;
        }
        if (items[i].weight <= capacity) {
            // if the item can be fully included, include it and reduce the weight capacity
            max_value += items[i].value;
            capacity -= items[i].weight;
        } else {
            // if the item cannot be fully included, include a fraction of it and break out of the loop
            max_value += items[i].value * ((double) capacity/items[i].weight);
            capacity = 0;
        }
    }
    return max_value;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d: ", i+1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    printf("Enter the weight capacity: ");
    scanf("%d", &capacity);
    double max_value = get_max_value(items, n, capacity);
    printf("The maximum value that can be obtained is %.2lf", max_value);
    return 0;
}