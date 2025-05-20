//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define a structure to store auction items
typedef struct item {
    char name[20];
    int starting_bid;
    int current_bid;
    int reserve_price;
    struct item* next;
} item;

// Function to add an item to the auction
void add_item(item** head) {
    item* new_item = malloc(sizeof(item));
    printf("Enter item name: ");
    scanf("%s", new_item->name);
    printf("Enter starting bid: ");
    scanf("%d", &new_item->starting_bid);
    printf("Enter reserve price: ");
    scanf("%d", &new_item->reserve_price);
    new_item->next = NULL;

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

// Function to bid on an item
void bid(item* item) {
    int bid_amount;
    printf("Enter your bid: ");
    scanf("%d", &bid_amount);

    if (bid_amount > item->current_bid) {
        item->current_bid = bid_amount;
        printf("Your bid has been accepted. Current bid: $%d\n", item->current_bid);
    } else {
        printf("Your bid is not high enough. Current bid: $%d\n", item->current_bid);
    }
}

// Function to start the auction
void start_auction(item* head) {
    // Iterate over the items and invite bidders
    for (item* item = head; item; item = item->next) {
        printf("Auction item: %s\n", item->name);
        printf("Starting bid: $%d\n", item->starting_bid);
        printf("Reserve price: $%d\n", item->reserve_price);
        bid(item);
    }

    // Check if the reserve price has been met for each item
    for (item* item = head; item; item = item->next) {
        if (item->current_bid >= item->reserve_price) {
            printf("Congratulations! You have won the item: %s\n", item->name);
        } else {
            printf("Sorry, you have not won the item: %s\n", item->name);
        }
    }
}

int main() {
    item* head = NULL;
    add_item(&head);
    add_item(&head);
    add_item(&head);
    start_auction(head);

    return 0;
}