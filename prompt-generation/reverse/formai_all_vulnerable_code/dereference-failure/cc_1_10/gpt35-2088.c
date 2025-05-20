//FormAI DATASET v1.0 Category: Digital Auction System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct that represents a bid
typedef struct 
{
    char name[50];
    int value;
} Bid;

// Struct that represents an auction
typedef struct 
{
    char item[100];
    int startingPrice;
    Bid highestBid;
} Auction;

// Function to create a new bid
void createBid(Bid* bid, char* name, int value)
{
    strcpy(bid->name, name);
    bid->value = value;
}

// Function to create a new auction
void createAuction(Auction* auction, char* item, int startingPrice)
{
    strcpy(auction->item, item);
    auction->startingPrice = startingPrice;
    createBid(&auction->highestBid, "None", startingPrice);
}

// Function to display a bid on the screen
void displayBid(Bid* bid)
{
    printf("%s: $%d\n", bid->name, bid->value);
}

// Function to display an auction on the screen
void displayAuction(Auction* auction)
{
    printf("Item: %s\n", auction->item);
    printf("Starting Price: $%d\n", auction->startingPrice);
    printf("Highest Bid: ");
    displayBid(&auction->highestBid);
}

// Function to place a bid on an auction
void placeBid(Auction* auction, char* name, int value)
{
    if (value > auction->highestBid.value)
    {
        createBid(&auction->highestBid, name, value);
        printf("New highest bid!\n");
    }
    else
    {
        printf("Bid not high enough.\n");
    }
}

int main()
{
    srand(time(NULL)); // seed the random number generator
    Auction auction;
    createAuction(&auction, "Painting", 500);
    displayAuction(&auction);
    
    for (int i = 0; i < 10; i++)
    {
        int randomBidValue = rand() % 1000 + 1; // generate a random bid value between 1 and 1000
        char bidderName[50];
        sprintf(bidderName, "Bidder %d", i + 1); // create a unique bidder name
        placeBid(&auction, bidderName, randomBidValue);
        displayAuction(&auction);
    }
    
    return 0;
}