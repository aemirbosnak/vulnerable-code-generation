//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct auction {
    int id;
    char *name;
    double price;
    int num_bids;
    struct auction *next;
} Auction;

Auction *head = NULL;

void add_auction(int id, char *name, double price) {
    Auction *new_auction = malloc(sizeof(Auction));
    new_auction->id = id;
    new_auction->name = strdup(name);
    new_auction->price = price;
    new_auction->num_bids = 0;
    new_auction->next = NULL;

    if (head == NULL) {
        head = new_auction;
    } else {
        Auction *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_auction;
    }
}

void print_auctions() {
    Auction *current = head;
    while (current != NULL) {
        printf("Auction ID: %d\n", current->id);
        printf("Auction Name: %s\n", current->name);
        printf("Auction Price: $%.2f\n", current->price);
        printf("Number of Bids: %d\n\n", current->num_bids);
        current = current->next;
    }
}

void place_bid(int auction_id, double bid_price) {
    Auction *current = head;
    while (current != NULL) {
        if (current->id == auction_id) {
            if (bid_price > current->price) {
                current->price = bid_price;
                current->num_bids++;
                printf("Bid placed successfully!\n");
            } else {
                printf("Bid price must be higher than current price.\n");
            }
            break;
        }
        current = current->next;
    }
}

int main() {

    // Create some auctions
    add_auction(1, "Painting by Picasso", 1000.00);
    add_auction(2, "Sculpture by Michelangelo", 2000.00);
    add_auction(3, "Violin by Stradivarius", 3000.00);
    add_auction(4, "Book by Shakespeare", 4000.00);
    add_auction(5, "Car by Ferrari", 5000.00);

    // Print the auctions
    printf("Available Auctions:\n");
    print_auctions();

    // Place some bids
    place_bid(1, 1100.00);
    place_bid(2, 2100.00);
    place_bid(3, 3100.00);
    place_bid(4, 4100.00);
    place_bid(5, 5100.00);

    // Print the auctions again
    printf("\nUpdated Auctions:\n");
    print_auctions();

    return 0;
}