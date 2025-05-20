//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int item_id;
    char *item_name;
    float reserve_price;
    float current_bid;
    char *owner;
} auction_item;

typedef struct {
    int num_items;
    auction_item *items;
} auction;

void print_auction(auction *a) {
    for (int i = 0; i < a->num_items; i++) {
        printf("Item %d: %s\n", a->items[i].item_id, a->items[i].item_name);
        printf("Reserve price: %.2f\n", a->items[i].reserve_price);
        printf("Current bid: %.2f\n", a->items[i].current_bid);
        printf("Owner: %s\n\n", a->items[i].owner);
    }
}

int main() {
    // Create an auction with 3 items
    auction a;
    a.num_items = 3;
    a.items = malloc(sizeof(auction_item) * a.num_items);

    // Initialize the items
    a.items[0].item_id = 1;
    a.items[0].item_name = "Painting";
    a.items[0].reserve_price = 100.0;
    a.items[0].current_bid = 0.0;
    a.items[0].owner = NULL;

    a.items[1].item_id = 2;
    a.items[1].item_name = "Sculpture";
    a.items[1].reserve_price = 200.0;
    a.items[1].current_bid = 0.0;
    a.items[1].owner = NULL;

    a.items[2].item_id = 3;
    a.items[2].item_name = "Vase";
    a.items[2].reserve_price = 300.0;
    a.items[2].current_bid = 0.0;
    a.items[2].owner = NULL;

    // Print the auction
    print_auction(&a);

    // Get a bid from the user
    int item_id;
    float bid;
    printf("Enter the item ID you want to bid on: ");
    scanf("%d", &item_id);
    printf("Enter your bid: ");
    scanf("%f", &bid);

    // Find the item in the auction
    auction_item *item = NULL;
    for (int i = 0; i < a.num_items; i++) {
        if (a.items[i].item_id == item_id) {
            item = &a.items[i];
            break;
        }
    }

    // Check if the bid is valid
    if (item == NULL || bid < item->reserve_price) {
        printf("Invalid bid.\n");
    } else {
        // Update the item's current bid and owner
        item->current_bid = bid;
        item->owner = "User";

        // Print the updated auction
        print_auction(&a);
    }

    // Free the memory allocated for the items
    free(a.items);

    return 0;
}