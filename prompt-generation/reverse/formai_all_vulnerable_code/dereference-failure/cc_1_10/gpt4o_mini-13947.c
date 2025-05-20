//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Auction {
    char item[100];
    char seller[100];
    float starting_bid;
    float current_bid;
    char highest_bidder[100];
    int is_active;
};

struct Auction* auctions;
int auction_count = 0;

void add_auction() {
    auctions = realloc(auctions, sizeof(struct Auction) * (auction_count + 1));
    if (!auctions) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", auctions[auction_count].item);
    printf("Enter seller name: ");
    scanf("%s", auctions[auction_count].seller);
    printf("Enter starting bid: ");
    scanf("%f", &auctions[auction_count].starting_bid);

    auctions[auction_count].current_bid = auctions[auction_count].starting_bid;
    strcpy(auctions[auction_count].highest_bidder, "None");
    auctions[auction_count].is_active = 1;
    auction_count++;
    printf("Auction added successfully!\n");
}

void place_bid() {
    char bidder[100];
    int auction_index;

    printf("Enter auction index (0 to %d): ", auction_count - 1);
    scanf("%d", &auction_index);
    
    if (auction_index < 0 || auction_index >= auction_count) {
        printf("Invalid auction index!\n");
        return;
    }
    
    if (!auctions[auction_index].is_active) {
        printf("This auction is no longer active!\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", bidder);
    float bid;
    printf("Enter your bid amount: ");
    scanf("%f", &bid);

    if (bid <= auctions[auction_index].current_bid) {
        printf("Your bid must be higher than the current bid of %.2f!\n", auctions[auction_index].current_bid);
        return;
    }

    auctions[auction_index].current_bid = bid;
    strcpy(auctions[auction_index].highest_bidder, bidder);
    printf("Bid placed successfully! New current bid: %.2f by %s\n", auctions[auction_index].current_bid, auctions[auction_index].highest_bidder);
}

void close_auction() {
    int auction_index;
    printf("Enter auction index to close (0 to %d): ", auction_count - 1);
    scanf("%d", &auction_index);
    
    if (auction_index < 0 || auction_index >= auction_count || !auctions[auction_index].is_active) {
        printf("Invalid or already closed auction!\n");
        return;
    }

    auctions[auction_index].is_active = 0;
    printf("Auction for '%s' has been closed. Highest bid was %.2f by %s.\n",
           auctions[auction_index].item, auctions[auction_index].current_bid, auctions[auction_index].highest_bidder);
}

void list_auctions() {
    printf("Current Auctions:\n");
    for (int i = 0; i < auction_count; i++) {
        printf("Index: %d, Item: %s, Seller: %s, Starting Bid: %.2f, Current Bid: %.2f, Highest Bidder: %s, Status: %s\n",
               i, auctions[i].item, auctions[i].seller, auctions[i].starting_bid, 
               auctions[i].current_bid, auctions[i].highest_bidder, 
               auctions[i].is_active ? "Active" : "Closed");
    }
}

void free_auctions() {
    free(auctions);
    auctions = NULL;
    auction_count = 0;
}

int main() {
    int choice;

    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Add Auction\n");
        printf("2. Place Bid\n");
        printf("3. Close Auction\n");
        printf("4. List Auctions\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_auction();
                break;
            case 2:
                place_bid();
                break;
            case 3:
                close_auction();
                break;
            case 4:
                list_auctions();
                break;
            case 5:
                free_auctions();
                printf("Exiting the auction system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}