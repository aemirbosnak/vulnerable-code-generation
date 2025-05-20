//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    double price;
} Item;

typedef struct {
    int id;
    char *name;
    double bid;
} Bidder;

typedef struct {
    int id;
    char *name;
    Item **items;
    int num_items;
} Auctioneer;

void print_item(Item *item) {
    printf("Item ID: %d\n", item->id);
    printf("Item Name: %s\n", item->name);
    printf("Item Price: %.2f\n\n", item->price);
}

void print_bidder(Bidder *bidder) {
    printf("Bidder ID: %d\n", bidder->id);
    printf("Bidder Name: %s\n", bidder->name);
    printf("Bidder Bid: %.2f\n\n", bidder->bid);
}

void print_auctioneer(Auctioneer *auctioneer) {
    printf("Auctioneer ID: %d\n", auctioneer->id);
    printf("Auctioneer Name: %s\n", auctioneer->name);
    printf("Number of Items: %d\n\n", auctioneer->num_items);
    for (int i = 0; i < auctioneer->num_items; i++) {
        print_item(auctioneer->items[i]);
    }
}

int main() {
    // Create some items
    Item *item1 = malloc(sizeof(Item));
    item1->id = 1;
    item1->name = strdup("Mona Lisa");
    item1->price = 1000000.00;

    Item *item2 = malloc(sizeof(Item));
    item2->id = 2;
    item2->name = strdup("Starry Night");
    item2->price = 500000.00;

    Item *item3 = malloc(sizeof(Item));
    item3->id = 3;
    item3->name = strdup("The Scream");
    item3->price = 200000.00;

    // Create some bidders
    Bidder *bidder1 = malloc(sizeof(Bidder));
    bidder1->id = 1;
    bidder1->name = strdup("John Doe");
    bidder1->bid = 1100000.00;

    Bidder *bidder2 = malloc(sizeof(Bidder));
    bidder2->id = 2;
    bidder2->name = strdup("Jane Doe");
    bidder2->bid = 550000.00;

    Bidder *bidder3 = malloc(sizeof(Bidder));
    bidder3->id = 3;
    bidder3->name = strdup("John Smith");
    bidder3->bid = 250000.00;

    // Create an auctioneer
    Auctioneer *auctioneer = malloc(sizeof(Auctioneer));
    auctioneer->id = 1;
    auctioneer->name = strdup("Sotheby's");
    auctioneer->items = malloc(sizeof(Item *) * 3);
    auctioneer->num_items = 3;
    auctioneer->items[0] = item1;
    auctioneer->items[1] = item2;
    auctioneer->items[2] = item3;

    // Print the auctioneer
    print_auctioneer(auctioneer);

    // Free the memory
    free(item1->name);
    free(item1);
    free(item2->name);
    free(item2);
    free(item3->name);
    free(item3);
    free(bidder1->name);
    free(bidder1);
    free(bidder2->name);
    free(bidder2);
    free(bidder3->name);
    free(bidder3);
    free(auctioneer->name);
    free(auctioneer->items);
    free(auctioneer);

    return 0;
}