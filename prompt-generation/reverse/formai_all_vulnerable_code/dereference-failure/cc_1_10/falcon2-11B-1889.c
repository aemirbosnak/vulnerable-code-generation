//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a bidder
typedef struct {
    int id;
    int bid;
    int status;
} bidder_t;

// Structure to represent an auction
typedef struct {
    int id;
    char title[50];
    int current_bidder;
    int max_bid;
    int end_time;
} auction_t;

// Function to generate a random number between min and max (inclusive)
int rand_num(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to print the current auction status
void print_status(auction_t *auction) {
    printf("Auction ID: %d\n", auction->id);
    printf("Title: %s\n", auction->title);
    printf("Current Bidder: %d\n", auction->current_bidder);
    printf("Max Bid: %d\n", auction->max_bid);
    printf("End Time: %d\n", auction->end_time);
}

// Function to start a new auction
auction_t *start_auction(char *title, int end_time) {
    srand(time(NULL));

    auction_t *auction = (auction_t *) malloc(sizeof(auction_t));
    if (auction == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for auction\n");
        exit(1);
    }

    auction->id = rand_num(1, 100);
    strcpy(auction->title, title);
    auction->max_bid = 0;
    auction->current_bidder = 0;
    auction->end_time = end_time;

    return auction;
}

// Function to place a bid on an auction
void place_bid(auction_t *auction, int bidder_id, int bid) {
    if (auction->current_bidder!= 0 && bid < auction->max_bid) {
        printf("Invalid bid: Must be greater than the current bid\n");
        return;
    }

    if (auction->end_time <= time(NULL)) {
        printf("Auction has ended\n");
        return;
    }

    if (bid > auction->max_bid) {
        auction->max_bid = bid;
        auction->current_bidder = bidder_id;
        printf("New highest bid: %d\n", auction->max_bid);
    } else {
        printf("Invalid bid: Must be greater than the current bid\n");
    }
}

// Function to end the auction
void end_auction(auction_t *auction) {
    auction->end_time = time(NULL);
    printf("Auction has ended\n");
}

// Main function
int main() {
    char title[50];
    int end_time;

    printf("Enter the title of the auction (maximum 50 characters): ");
    fgets(title, sizeof(title), stdin);

    // Remove newline character at the end of the input
    title[strcspn(title, "\n")] = '\0';

    printf("Enter the end time of the auction (in seconds): ");
    scanf("%d", &end_time);

    auction_t *auction = start_auction(title, end_time);

    while (auction->end_time > time(NULL)) {
        printf("Enter the ID of the bidder: ");
        scanf("%d", &auction->current_bidder);

        printf("Enter the bid amount: ");
        scanf("%d", &auction->max_bid);

        print_status(auction);

        place_bid(auction, auction->current_bidder, auction->max_bid);
    }

    end_auction(auction);

    return 0;
}