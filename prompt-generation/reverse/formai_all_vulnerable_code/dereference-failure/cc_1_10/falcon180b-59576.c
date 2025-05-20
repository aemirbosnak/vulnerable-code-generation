//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100
#define MAX_BIDS 1000

typedef struct {
    char name[50];
    int id;
} Bidder;

typedef struct {
    char name[100];
    int id;
    int highest_bid;
    Bidder* bidder;
} Item;

Bidder bidders[MAX_BIDDERS];
Item items[MAX_ITEMS];
int num_bidders = 0;
int num_items = 0;

void add_bidder(char* name) {
    strcpy(bidders[num_bidders].name, name);
    bidders[num_bidders].id = num_bidders;
    num_bidders++;
}

int get_bidder_id(char* name) {
    for(int i=0; i<num_bidders; i++) {
        if(strcmp(bidders[i].name, name) == 0) {
            return bidders[i].id;
        }
    }
    return -1;
}

void add_item(char* name, int starting_price) {
    strcpy(items[num_items].name, name);
    items[num_items].id = num_items;
    items[num_items].highest_bid = starting_price;
    items[num_items].bidder = NULL;
    num_items++;
}

int get_item_id(char* name) {
    for(int i=0; i<num_items; i++) {
        if(strcmp(items[i].name, name) == 0) {
            return items[i].id;
        }
    }
    return -1;
}

void place_bid(int item_id, int amount) {
    int bidder_id = get_bidder_id(items[item_id].bidder->name);
    if(bidder_id == -1) {
        printf("Bidder not found.\n");
        return;
    }
    if(amount <= items[item_id].highest_bid) {
        printf("Bid must be higher than current highest bid.\n");
        return;
    }
    items[item_id].highest_bid = amount;
    items[item_id].bidder = &bidders[bidder_id];
}

void display_items() {
    printf("Item ID | Name | Current Bid | Bidder\n");
    for(int i=0; i<num_items; i++) {
        printf("%d | %s | $%d | ", items[i].id, items[i].name, items[i].highest_bid);
        if(items[i].bidder!= NULL) {
            printf("%s\n", items[i].bidder->name);
        } else {
            printf("No bidder\n");
        }
    }
}

int main() {
    add_bidder("Alice");
    add_bidder("Bob");
    add_item("Laptop", 500);
    add_item("Phone", 300);
    place_bid(0, 600);
    place_bid(1, 400);
    display_items();
    return 0;
}