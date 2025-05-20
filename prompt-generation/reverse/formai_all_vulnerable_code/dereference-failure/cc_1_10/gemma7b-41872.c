//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store auction items
typedef struct Item {
    char name[20];
    int starting_price;
    int reserve_price;
    int current_price;
    struct Item* next;
} Item;

// Function to insert an item into the auction
void insertItem(Item** head) {
    Item* newNode = (Item*)malloc(sizeof(Item));
    printf("Enter item name: ");
    scanf("%s", newNode->name);
    printf("Enter starting price: ");
    scanf("%d", &newNode->starting_price);
    printf("Enter reserve price: ");
    scanf("%d", &newNode->reserve_price);
    newNode->current_price = newNode->starting_price;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to bid on an item
void bidItem(Item* item) {
    int bid;
    printf("Enter your bid: ");
    scanf("%d", &bid);

    if (bid > item->current_price) {
        item->current_price = bid;
        printf("Your bid has been accepted. Current price: $%d\n", item->current_price);
    } else {
        printf("Your bid is not high enough. Current price: $%d\n", item->current_price);
    }
}

// Function to start the auction
void startAuction(Item* head) {
    while (head) {
        printf("Item: %s\n", head->name);
        printf("Starting price: $%d\n", head->starting_price);
        printf("Reserve price: $%d\n", head->reserve_price);
        printf("Current price: $%d\n", head->current_price);
        printf("------------------------\n");
        bidItem(head);
        printf("------------------------\n");
        head = head->next;
    }
}

int main() {
    Item* head = NULL;
    insertItem(&head);
    insertItem(&head);
    insertItem(&head);
    startAuction(head);

    return 0;
}