//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 100
#define MAX_TITLE_LENGTH 50
#define MAX_USERNAME_LENGTH 30

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    float amount;
} Bid;

typedef struct {
    char title[MAX_TITLE_LENGTH];
    Bid bids[MAX_BIDS];
    int bid_count;
} Auction;

void create_auction(Auction *auction) {
    printf("Enter auction item title: ");
    fgets(auction->title, MAX_TITLE_LENGTH, stdin);
    auction->title[strcspn(auction->title, "\n")] = 0; // Remove newline
    auction->bid_count = 0;
    printf("Auction for '%s' created successfully!\n", auction->title);
}

void place_bid(Auction *auction) {
    if (auction->bid_count >= MAX_BIDS) {
        printf("Bid limit reached for this auction!\n");
        return;
    }
    
    Bid new_bid;
    printf("Enter your username: ");
    fgets(new_bid.username, MAX_USERNAME_LENGTH, stdin);
    new_bid.username[strcspn(new_bid.username, "\n")] = 0; // Remove newline
    
    printf("Enter your bid amount: ");
    scanf("%f", &new_bid.amount);
    getchar();  // Consume newline left by scanf
    
    auction->bids[auction->bid_count] = new_bid;
    auction->bid_count++;
    printf("Bid placed successfully by %s for amount %.2f!\n", new_bid.username, new_bid.amount);
}

void view_bids(Auction *auction) {
    if (auction->bid_count == 0) {
        printf("There are no bids for the auction '%s'.\n", auction->title);
        return;
    }

    printf("Bids for auction '%s':\n", auction->title);
    for (int i = 0; i < auction->bid_count; i++) {
        printf("User: %s, Bid: %.2f\n", auction->bids[i].username, auction->bids[i].amount);
    }

    // Find highest bid
    float highest_bid = auction->bids[0].amount;
    char highest_bidder[MAX_USERNAME_LENGTH];
    strcpy(highest_bidder, auction->bids[0].username);

    for (int i = 1; i < auction->bid_count; i++) {
        if (auction->bids[i].amount > highest_bid) {
            highest_bid = auction->bids[i].amount;
            strcpy(highest_bidder, auction->bids[i].username);
        }
    }

    printf("Current highest bid: %.2f by %s\n", highest_bid, highest_bidder);
}

void display_menu() {
    printf("\nDigital Auction System\n");
    printf("1. Create Auction\n");
    printf("2. Place Bid\n");
    printf("3. View Bids\n");
    printf("4. Exit\n");
}

int main() {
    Auction auction;
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                create_auction(&auction);
                break;
            case 2:
                place_bid(&auction);
                break;
            case 3:
                view_bids(&auction);
                break;
            case 4:
                printf("Exiting the auction system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}