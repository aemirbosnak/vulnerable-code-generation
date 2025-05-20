//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 1000

struct Bid {
    char bidder[20];
    int amount;
    struct Bid* next;
};

struct Item {
    char name[50];
    int reserve_price;
    struct Bid* bids;
    struct Item* next;
};

void insert_bid(struct Bid* head, char* bidder, int amount) {
    struct Bid* new_bid = malloc(sizeof(struct Bid));
    strcpy(new_bid->bidder, bidder);
    new_bid->amount = amount;
    new_bid->next = NULL;

    if (head == NULL) {
        head = new_bid;
    } else {
        struct Bid* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_bid;
    }
}

void print_bids(struct Bid* head) {
    struct Bid* temp = head;
    while (temp) {
        printf("%s: %d\n", temp->bidder, temp->amount);
        temp = temp->next;
    }
}

struct Item* insert_item(struct Item* head, char* name, int reserve_price) {
    struct Item* new_item = malloc(sizeof(struct Item));
    strcpy(new_item->name, name);
    new_item->reserve_price = reserve_price;
    new_item->bids = NULL;
    new_item->next = NULL;

    if (head == NULL) {
        head = new_item;
    } else {
        struct Item* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_item;
    }
    return head;
}

void auction(struct Item* item) {
    printf("Auction for item: %s\n", item->name);
    printf("Reserve price: %d\n", item->reserve_price);
    printf("Bids:\n");
    print_bids(item->bids);

    int highest_bid = 0;
    struct Bid* current_bid = item->bids;
    while (current_bid) {
        if (current_bid->amount > highest_bid) {
            highest_bid = current_bid->amount;
        }
        current_bid = current_bid->next;
    }

    if (highest_bid >= item->reserve_price) {
        printf("Congratulations, %s, you won the auction!\n", current_bid->bidder);
        printf("Your total bid: %d\n", highest_bid);
    } else {
        printf("No bids met the reserve price. The item is not sold.\n");
    }
}

int main() {
    struct Item* item_head = insert_item(NULL, "Laptop", 500);
    insert_bid(item_head->bids, "John Doe", 400);
    insert_bid(item_head->bids, "Jane Doe", 300);
    insert_bid(item_head->bids, "Bill Smith", 200);

    auction(item_head);

    return 0;
}