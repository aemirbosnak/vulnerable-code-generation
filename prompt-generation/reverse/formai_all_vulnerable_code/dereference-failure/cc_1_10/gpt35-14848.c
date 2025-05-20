//FormAI DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Node to store the information of each item in the auction
typedef struct item {
    char name[50];
    int starting_bid;
    int current_bid;
    bool sold;
    struct item *next;
} Item;

// Function to create a new item with the given name and starting bid
Item *createItem(char *name, int starting_bid) {
    Item *item = (Item *) malloc(sizeof(Item));
    strncpy(item->name, name, 50);
    item->starting_bid = starting_bid;
    item->current_bid = starting_bid;
    item->sold = false;
    item->next = NULL;
    return item;
}

// Function to add a new item to the auction
void addItem(Item **auction, char *name, int starting_bid) {
    Item *item = createItem(name, starting_bid);
    if (*auction == NULL) {
        *auction = item;
        return;
    }
    Item *curr = *auction;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = item;
}

// Function to remove an item from the auction
void removeItem(Item **auction, char *name) {
    if (*auction == NULL) {
        printf("Auction is empty!\n");
        return;
    }
    if (strcmp((*auction)->name, name) == 0) {
        Item *temp = *auction;
        *auction = (*auction)->next;
        free(temp);
        return;
    }
    Item *curr = *auction;
    while (curr->next != NULL && strcmp(curr->next->name, name) != 0) {
        curr = curr->next;
    }
    if (curr->next == NULL) {
        printf("Item not found!\n");
        return;
    }
    Item *temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
}

// Function to display all items in the auction
void displayItems(Item *auction) {
    if (auction == NULL) {
        printf("Auction is empty!\n");
        return;
    }
    printf("Items in the auction:\n");
    while (auction != NULL) {
        printf("%s - Starting Bid: %d - Current Bid: %d\n", auction->name, auction->starting_bid, auction->current_bid);
        auction = auction->next;
    }
}

// Function to make a bid on an item in the auction
void makeBid(Item *auction, char *name, int bid) {
    if (auction == NULL) {
        printf("Auction is empty!\n");
        return;
    }
    Item *curr = auction;
    while (curr != NULL && strcmp(curr->name, name) != 0) {
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Item not found!\n");
        return;
    }
    if (curr->sold) {
        printf("Item already sold!\n");
        return;
    }
    if (bid <= curr->current_bid) {
        printf("Bid must be higher than current bid!\n");
        return;
    }
    curr->current_bid = bid;
    printf("Bid accepted!\n");
}

// Function to sell an item in the auction
void sellItem(Item *auction, char *name) {
    if (auction == NULL) {
        printf("Auction is empty!\n");
        return;
    }
    Item *curr = auction;
    while (curr != NULL && strcmp(curr->name, name) != 0) {
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Item not found!\n");
        return;
    }
    if (curr->sold) {
        printf("Item already sold!\n");
        return;
    }
    curr->sold = true;
    printf("Item sold for %d!\n", curr->current_bid);
}

int main() {
    Item *auction = NULL;
    addItem(&auction, "Painting", 200);
    addItem(&auction, "Antique Vase", 500);
    addItem(&auction, "Vintage Watch", 1000);
    displayItems(auction);
    printf("\n");
    makeBid(auction, "Painting", 250);
    makeBid(auction, "Antique Vase", 600);
    makeBid(auction, "Vintage Watch", 1500);
    makeBid(auction, "Painting", 300);
    displayItems(auction);
    printf("\n");
    sellItem(auction, "Antique Vase");
    displayItems(auction);
    printf("\n");
    removeItem(&auction, "Vintage Watch");
    displayItems(auction);
    return 0;
}