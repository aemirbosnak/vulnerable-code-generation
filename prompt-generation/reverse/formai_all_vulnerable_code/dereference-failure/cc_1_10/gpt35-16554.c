//FormAI DATASET v1.0 Category: Digital Auction System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char name[50];
    float price;
    struct Item *next;
} Item;

typedef struct Bidder {
    char name[50];
    float bid;
    struct Bidder *next;
} Bidder;

Item *get_items();
Bidder *get_bidders();
Item *add_item(Item *head, char name[50], float price);
void display_items(Item *head);
Bidder *add_bidder(Bidder *head, char name[50], float bid);
void display_bidders(Bidder *head);
void auction(Item *items, Bidder *bidders);

int main() {
    Item *items = get_items();
    Bidder *bidders = get_bidders();

    printf("Items:\n");
    display_items(items);
    printf("\nBidders:\n");
    display_bidders(bidders);

    printf("\nStarting auction...\n\n");
    auction(items, bidders);

    return 0;
}

Item *get_items() {
    Item *head = NULL;
    head = add_item(head, "Painting", 100);
    head = add_item(head, "Vase", 50);
    head = add_item(head, "Silverware", 75);
    return head;
}

Bidder *get_bidders() {
    Bidder *head = NULL;
    head = add_bidder(head, "Alice", 80);
    head = add_bidder(head, "Bob", 120);
    head = add_bidder(head, "Charlie", 50);
    return head;
}

Item *add_item(Item *head, char name[50], float price) {
    Item *new_item = (Item *) malloc(sizeof(Item));
    strcpy(new_item->name, name);
    new_item->price = price;
    new_item->next = head;
    return new_item;
}

void display_items(Item *head) {
    while (head != NULL) {
        printf("%-15s $%.2f\n", head->name, head->price);
        head = head->next;
    }
}

Bidder *add_bidder(Bidder *head, char name[50], float bid) {
    Bidder *new_bidder = (Bidder *) malloc(sizeof(Bidder));
    strcpy(new_bidder->name, name);
    new_bidder->bid = bid;
    new_bidder->next = head;
    return new_bidder;
}

void display_bidders(Bidder *head) {
    while (head != NULL) {
        printf("%-15s $%.2f\n", head->name, head->bid);
        head = head->next;
    }
}

void auction(Item *items, Bidder *bidders) {
    Item *current_item = items;
    while (current_item != NULL) {
        printf("Item: %s\n", current_item->name);
        printf("Starting price: $%.2f\n", current_item->price);
        printf("Bids:\n");

        Bidder *highest_bidder = NULL;
        float highest_bid = current_item->price;

        Bidder *current_bidder = bidders;
        while (current_bidder != NULL) {
            if (current_bidder->bid > highest_bid) {
                highest_bidder = current_bidder;
                highest_bid = current_bidder->bid;
            }
            printf("%-15s $%.2f\n", current_bidder->name, current_bidder->bid);
            current_bidder = current_bidder->next;
        }

        if (highest_bidder != NULL) {
            printf("Current highest bid: $%.2f by %s\n", highest_bid, highest_bidder->name);
            if (highest_bid > current_item->price) {
                printf("Item sold to %s for $%.2f\n", highest_bidder->name, highest_bid);
                current_item = current_item->next;
            } else {
                printf("Reserve not met\n");
            }
        } else {
            printf("No bids\n");
        }

        printf("\n");

        bidders = add_bidder(bidders, "New Bidder", rand() % 100 + 1);
    }
}