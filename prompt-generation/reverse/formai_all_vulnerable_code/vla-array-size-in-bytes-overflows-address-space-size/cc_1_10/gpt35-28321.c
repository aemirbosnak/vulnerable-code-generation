//FormAI DATASET v1.0 Category: Digital Auction System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function for quick sort algorithm
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int num_items, min_bid, max_bid;

    printf("Welcome to the Digital Auction System!\n");
    printf("Please enter the number of items to be auctioned: ");
    scanf("%d", &num_items);

    int items[num_items];
    srand((unsigned int)time(NULL));

    // Generate random item names and minimum/maximum bids
    for (int i = 0; i < num_items; i++) {
        char name[20];
        sprintf(name, "Item %d", i + 1);
        items[i] = rand() % 1000 + 1;
        min_bid = rand() % 100 + 1;
        max_bid = rand() % 1000 + 100;
        printf("%s - minimum bid: %d, maximum bid: %d\n", name, min_bid, max_bid);
    }

    // Start the auction
    for (int i = 0; i < num_items; i++) {
        char name[20];
        sprintf(name, "Item %d", i + 1);
        printf("\nAuctioning %s...\n", name);

        // Generate random bidder names and bids
        int num_bids = rand() % 10 + 1;
        char* bidders[num_bids];
        int bids[num_bids];

        for (int j = 0; j < num_bids; j++) {
            char bidder_name[20];
            sprintf(bidder_name, "Bidder %d", j + 1);
            bidders[j] = bidder_name;
            bids[j] = rand() % (max_bid - min_bid) + min_bid;
        }

        // Sort bids in descending order
        quickSort(bids, 0, num_bids - 1);

        // Print the results
        printf("%d bids were placed on %s:\n", num_bids, name);
        for (int j = 0; j < num_bids; j++) {
            printf("%s placed a bid of %d\n", bidders[j], bids[j]);
        }
        printf("%s is sold to %s for $%d!\n", name, bidders[0], bids[0]);
    }

    return 0;
}