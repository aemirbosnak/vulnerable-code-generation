//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure to store auction items
typedef struct Item {
    char name[20];
    int start_price;
    int reserve_price;
    int current_bid;
    struct Item* next;
} Item;

// Define a function to insert an item into the auction
void insert_item(Item** head) {
    Item* new_item = malloc(sizeof(Item));
    printf("Enter item name: ");
    scanf("%s", new_item->name);
    printf("Enter start price: ");
    scanf("%d", &new_item->start_price);
    printf("Enter reserve price: ");
    scanf("%d", &new_item->reserve_price);
    new_item->current_bid = 0;
    new_item->next = NULL;

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

// Define a function to display the auction items
void display_items(Item* head) {
    while (head) {
        printf("%s - $%d - $%d\n", head->name, head->start_price, head->reserve_price);
        head = head->next;
    }
}

// Define a function to place a bid
void place_bid(Item* head) {
    printf("Enter item name: ");
    char item_name[20];
    scanf("%s", item_name);

    Item* current_item = head;
    while (current_item) {
        if (strcmp(item_name, current_item->name) == 0) {
            printf("Enter your bid: $");
            int bid;
            scanf("%d", &bid);

            if (bid > current_item->current_bid) {
                current_item->current_bid = bid;
            }
        }
        current_item = current_item->next;
    }
}

// Define a function to check if the auction has ended
int check_auction_end(Item* head) {
    Item* current_item = head;
    while (current_item) {
        if (current_item->current_bid >= current_item->reserve_price) {
            return 1;
        }
        current_item = current_item->next;
    }
    return 0;
}

int main() {
    Item* head = NULL;

    // Insert items into the auction
    insert_item(&head);
    insert_item(&head);
    insert_item(&head);

    // Display the auction items
    display_items(head);

    // Place bids on the items
    place_bid(head);

    // Check if the auction has ended
    if (check_auction_end(head)) {
        printf("The auction has ended.\n");
    } else {
        printf("The auction is still ongoing.\n");
    }

    return 0;
}