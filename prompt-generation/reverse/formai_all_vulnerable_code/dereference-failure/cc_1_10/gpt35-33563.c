//FormAI DATASET v1.0 Category: Digital Auction System ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Debugging function */
void error(const char* message){
    printf("Error: %s\n", message);
    exit(1);
}

/* Product struct */
typedef struct product{
    char* name;
    int current_price;
} product_t;

/* Bid struct */
typedef struct bid{
    char* bidder;
    int amount;
} bid_t;

/* Auction struct */
typedef struct auction{
    product_t* product;
    bid_t* highest_bid;
} auction_t;

/* Global variables */
auction_t* auctions[10];
int num_auctions = 0;

/* Function prototypes */
void add_auction(product_t* product);
void add_bid(int auction_index, bid_t* bid);
void show_auctions();
void show_auction(int auction_index);

int main(){
    /* Create products */
    product_t* product1 = malloc(sizeof(product_t));
    product_t* product2 = malloc(sizeof(product_t));
    product_t* product3 = malloc(sizeof(product_t));

    /* Initialize products */
    product1->name = "iPhone X";
    product1->current_price = 1000;
    product2->name = "Macbook Pro";
    product2->current_price = 1500;
    product3->name = "iPad Pro";
    product3->current_price = 700;

    /* Create auctions */
    add_auction(product1);
    add_auction(product2);
    add_auction(product3);

    /* Display auctions */
    printf("Welcome to the Digital Auction System!\n");
    show_auctions();

    /* Attempt to place a bid */
    printf("\nAlice bids 1100 for iPhone X.\n");
    bid_t* alice_bid = malloc(sizeof(bid_t));
    alice_bid->bidder = "Alice";
    alice_bid->amount = 1100;
    add_bid(0, alice_bid);

    /* Display new highest bid */
    show_auction(0);

    /* Attempt to place a lower bid */
    printf("\nBob bids 1000 for iPhone X.\n");
    bid_t* bob_bid = malloc(sizeof(bid_t));
    bob_bid->bidder = "Bob";
    bob_bid->amount = 1000;
    add_bid(0, bob_bid);

    /* Display same highest bid */
    show_auction(0);

    return 0;
}

/* Add an auction to the system */
void add_auction(product_t* product){
    /* Check if there is space in the system */
    if(num_auctions >= 10) error("Cannot add more auctions.");

    /* Create new auction */
    auction_t* auction = malloc(sizeof(auction_t));
    auction->product = product;
    auction->highest_bid = NULL;

    /* Add auction to system */
    auctions[num_auctions] = auction;
    num_auctions++;
}

/* Add a bid to an auction */
void add_bid(int auction_index, bid_t* bid){
    /* Check if auction exists */
    if(auction_index < 0 || auction_index >= num_auctions) 
        error("Invalid auction index.");

    /* Check if bid is higher */
    if(auctions[auction_index]->highest_bid == NULL || 
        bid->amount > auctions[auction_index]->highest_bid->amount){
        /* Add new highest bid */
        auctions[auction_index]->highest_bid = bid;
    }
}

/* Display all auctions */
void show_auctions(){
    printf("Current Auctions:\n\n");
    for(int i=0; i<num_auctions; i++){
        printf("%d. %s\n", i+1, auctions[i]->product->name);
    }
    printf("\n");
}

/* Display information about an auction */
void show_auction(int auction_index){
    /* Check if auction exists */
    if(auction_index < 0 || auction_index >= num_auctions) 
        error("Invalid auction index.");

    /* Display auction information */
    printf("%s\n", auctions[auction_index]->product->name);
    printf("Current Price: $%d\n", auctions[auction_index]->product->current_price);

    /* Display highest bid */
    if(auctions[auction_index]->highest_bid != NULL){
        printf("Highest Bid: $%d by %s\n", auctions[auction_index]->highest_bid->amount,
            auctions[auction_index]->highest_bid->bidder);
    }else{
        printf("No bids yet.\n");
    }

    printf("\n");
}