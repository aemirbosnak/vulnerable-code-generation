//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

// Struct for items in the bin packing problem
typedef struct Item {
    int id;
    int size;
} Item;

// Function to sort the items in descending order according to their sizes
int cmp(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;
    return itemB->size - itemA->size;
}

// Asynchronous function to perform the greedy algorithm for bin packing
void binPacking(Item* items, int num_items, int bin_size) {
    int* bins = (int*)calloc(num_items, sizeof(int)); // Array of bins, initially all empty
    int num_bins = 0; // Count of number of bins used
    for (int i = 0; i < num_items; i++) {
        int filled_bin = 0; // Flag to indicate if item has been placed in a bin
        for (int j = 0; j < num_bins; j++) {
            if (bins[j] + items[i].size <= bin_size) { // If item fits in current bin
                bins[j] += items[i].size; // Place item in bin
                filled_bin = 1;
                break;
            }
        }
        if (!filled_bin) { // If item does not fit in any existing bin, create a new bin
            bins[num_bins++] = items[i].size;
        }
    }
    printf("Number of bins used: %d\n", num_bins);
    free(bins);
}

int main() {
    // Generate random items with sizes between 1 and 10
    int num_items = 50;
    Item* items = (Item*)malloc(num_items * sizeof(Item));
    for (int i = 0; i < num_items; i++) {
        items[i].id = i;
        items[i].size = (rand() % 10) + 1;
    }

    // Sort items in descending order according to their sizes
    qsort(items, num_items, sizeof(Item), cmp);

    // Test bin packing algorithm for bin size of 20
    int bin_size = 20;
    binPacking(items, num_items, bin_size);

    free(items);
    return 0;
}