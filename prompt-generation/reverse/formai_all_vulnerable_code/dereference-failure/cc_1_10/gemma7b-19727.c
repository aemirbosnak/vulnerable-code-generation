//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_BIDS 10
#define MAX_ITEM_NAME_LENGTH 255

typedef struct Bid {
    char bidder[MAX_BIDS];
    int bid_amount;
    struct Bid* next;
} Bid;

typedef struct Item {
    char item_name[MAX_ITEM_NAME_LENGTH];
    int starting_price;
    int current_price;
    struct Item* next;
} Item;

void add_bid(Bid** head, char* bidder, int bid_amount) {
    Bid* new_bid = malloc(sizeof(Bid));
    strcpy(new_bid->bidder, bidder);
    new_bid->bid_amount = bid_amount;
    new_bid->next = NULL;

    if (*head == NULL) {
        *head = new_bid;
    } else {
        (*head)->next = new_bid;
    }
}

void add_item(Item** head, char* item_name, int starting_price) {
    Item* new_item = malloc(sizeof(Item));
    strcpy(new_item->item_name, item_name);
    new_item->starting_price = starting_price;
    new_item->current_price = starting_price;
    new_item->next = NULL;

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

int main() {
    Item* item_head = NULL;
    add_item(&item_head, "Rare Diamond Ring", 1000);
    add_item(&item_head, "Antique Clock", 500);

    Bid* bid_head = NULL;
    add_bid(&bid_head, "John Doe", 800);
    add_bid(&bid_head, "Jane Doe", 700);

    time_t start_time = time(NULL);
    time_t end_time = start_time + 60;

    while (time(NULL) < end_time) {
        sleep(1);

        // Randomly select a bidder and item
        int bidder_index = rand() % MAX_BIDS;
        char* bidder = bid_head->next->bidder;

        int item_index = rand() % MAX_ITEM_NAME_LENGTH;
        char* item_name = item_head->next->item_name;

        // Calculate the new bid amount
        int new_bid_amount = rand() % (item_head->next->current_price - item_head->next->starting_price) + item_head->next->starting_price;

        // Add the new bid
        add_bid(&bid_head, bidder, new_bid_amount);

        // Update the item's current price
        item_head->next->current_price = new_bid_amount;
    }

    // Print the winner
    printf("The winner is: %s\n", bid_head->next->bidder);

    // Print the final price
    printf("The final price is: %d\n", item_head->next->current_price);

    return 0;
}