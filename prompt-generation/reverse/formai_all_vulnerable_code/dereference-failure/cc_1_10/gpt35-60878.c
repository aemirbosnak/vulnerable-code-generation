//FormAI DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _item {
    char name[20];
    int price;
    struct _item *next;
} item;

item *auction = NULL; // List of items up for auction

void print_auction_items() {
    item *current = auction;

    printf("Items up for auction:\n");

    while (current != NULL) {
        printf("%s - Current Price: %d\n", current->name, current->price);
        current = current->next;
    }
}

void bid(char* item_name, int bid_amount) {
    item *current = auction;

    while (current != NULL) {
        if (strcmp(current->name, item_name) == 0) { // Item found
            if (bid_amount > current->price) { // Bid is higher than current price
                current->price = bid_amount;
                printf("New bid of %d on %s accepted.\n", bid_amount, item_name);
            } else { // Bid is lower than or equal to current price
                printf("Bid of %d on %s is not higher than the current price of %d.\n", bid_amount, item_name, current->price);
            }

            return;
        }

        current = current->next;
    }

    printf("Item '%s' not found.\n", item_name);
}

void add_item(char* item_name, int starting_price) {
    item *new_item = (item*) malloc(sizeof(item));
    strcpy(new_item->name, item_name);
    new_item->price = starting_price;
    new_item->next = NULL;

    if (auction == NULL) { // First item in the auction
        auction = new_item;
    } else { // Add item to end of list
        item *current = auction;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = new_item;
    }

    printf("New item '%s' added to the auction with a starting price of %d.\n", item_name, starting_price);
}

int main() {
    add_item("Painting", 50);
    add_item("Antique Vase", 100);
    add_item("Signed Baseball", 25);
    add_item("Vintage Record Player", 75);
    print_auction_items();

    srand(time(NULL));

    while (auction != NULL) { // Auction continues until all items have been sold
        int random = rand() % 4; // Choose a random item to bid on

        item *current = auction;
        for (int i = 0; i < random; i++) { // Move to the correct item in the list
            current = current->next;
        }

        bid(current->name, current->price + (rand() % 25)); // Place a random bid on the item
    }

    printf("All items have been sold.\n");

    return 0;
}