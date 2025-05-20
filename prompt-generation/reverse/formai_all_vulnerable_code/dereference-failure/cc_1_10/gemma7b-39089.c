//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of bidders
#define MAX_BIDDERS 10

// Define the maximum number of items
#define MAX_ITEMS 5

// Define the structure of a bidder
typedef struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
} Bidder;

// Define the structure of an item
typedef struct Item {
    char name[20];
    int reservePrice;
    struct Item* next;
} Item;

// Create a linked list of bidders
Bidder* createBidderList() {
    Bidder* head = NULL;
    head = malloc(sizeof(Bidder));
    head->name[0] = '\0';
    head->bid = 0;
    head->next = NULL;
    return head;
}

// Create a linked list of items
Item* createItemList() {
    Item* head = NULL;
    head = malloc(sizeof(Item));
    head->name[0] = '\0';
    head->reservePrice = 0;
    head->next = NULL;
    return head;
}

// Auction function
void auction() {
    // Get the number of bidders and items
    int numBidders = 0;
    int numItems = 0;

    // Create the bidder and item lists
    Bidder* bidders = createBidderList();
    Item* items = createItemList();

    // Get the items and bidders
    printf("Enter the number of items you want to sell: ");
    scanf("%d", &numItems);

    for (int i = 0; i < numItems; i++) {
        Item* item = malloc(sizeof(Item));
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", item->name);
        printf("Enter the reserve price of item %d: ", i + 1);
        scanf("%d", &item->reservePrice);
        items->next = item;
        items = items->next;
    }

    printf("Enter the number of bidders: ");
    scanf("%d", &numBidders);

    for (int i = 0; i < numBidders; i++) {
        Bidder* bidder = malloc(sizeof(Bidder));
        printf("Enter the name of bidder %d: ", i + 1);
        scanf("%s", bidder->name);
        printf("Enter the bid of bidder %d: ", i + 1);
        scanf("%d", &bidder->bid);
        bidders->next = bidder;
        bidders = bidders->next;
    }

    // Bidder with the highest bid wins
    Bidder* winner = bidders;
    for (Bidder* bidder = bidders; bidder->next != NULL; bidder = bidder->next) {
        if (bidder->bid > winner->bid) {
            winner = bidder;
        }
    }

    // The winner's bid is the final price
    int finalPrice = winner->bid;

    // Print the winner's name and final price
    printf("The winner is: %s\n", winner->name);
    printf("The final price is: %d\n", finalPrice);
}

int main() {
    auction();
    return 0;
}