//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

// Structure to store the details of an item
typedef struct {
    int id;
    char name[100];
    char description[255];
    float starting_price;
    float current_price;
    int time_left;
    char owner[100];
} Item;

// Structure to store the details of a bid
typedef struct {
    int id;
    int item_id;
    float amount;
    char bidder[100];
} Bid;

// Function to generate a unique ID
int generate_id() {
    static int id = 0;
    return ++id;
}

// Function to hash a string using SHA256
char *hash_string(char *str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str, strlen(str));
    SHA256_Final(hash, &sha256);
    char *hashed_string = malloc(SHA256_DIGEST_LENGTH * 2 + 1);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hashed_string + i * 2, "%02x", hash[i]);
    }
    return hashed_string;
}

// Function to create a new item
Item *create_item(char *name, char *description, float starting_price, int time_left, char *owner) {
    Item *item = malloc(sizeof(Item));
    item->id = generate_id();
    strcpy(item->name, name);
    strcpy(item->description, description);
    item->starting_price = starting_price;
    item->current_price = starting_price;
    item->time_left = time_left;
    strcpy(item->owner, owner);
    return item;
}

// Function to create a new bid
Bid *create_bid(int item_id, float amount, char *bidder) {
    Bid *bid = malloc(sizeof(Bid));
    bid->id = generate_id();
    bid->item_id = item_id;
    bid->amount = amount;
    strcpy(bid->bidder, bidder);
    return bid;
}

// Function to add a bid to an item
void add_bid(Item *item, Bid *bid) {
    if (bid->amount > item->current_price) {
        item->current_price = bid->amount;
        strcpy(item->owner, bid->bidder);
    }
}

// Function to print the details of an item
void print_item(Item *item) {
    printf("Item ID: %d\n", item->id);
    printf("Name: %s\n", item->name);
    printf("Description: %s\n", item->description);
    printf("Starting Price: %.2f\n", item->starting_price);
    printf("Current Price: %.2f\n", item->current_price);
    printf("Time Left: %d\n", item->time_left);
    printf("Owner: %s\n", item->owner);
}

// Function to print the details of a bid
void print_bid(Bid *bid) {
    printf("Bid ID: %d\n", bid->id);
    printf("Item ID: %d\n", bid->item_id);
    printf("Amount: %.2f\n", bid->amount);
    printf("Bidder: %s\n", bid->bidder);
}

// Main function
int main() {
    // Create some items
    Item *item1 = create_item("iPhone 13 Pro", "The latest and greatest iPhone", 999.00, 3600, "Apple");
    Item *item2 = create_item("MacBook Air M2", "The new MacBook Air with the M2 chip", 1199.00, 3600, "Apple");
    Item *item3 = create_item("Apple Watch Series 8", "The latest Apple Watch with new health features", 399.00, 3600, "Apple");

    // Create some bids
    Bid *bid1 = create_bid(item1->id, 1050.00, "John Doe");
    Bid *bid2 = create_bid(item2->id, 1250.00, "Jane Doe");
    Bid *bid3 = create_bid(item3->id, 420.00, "Bob Smith");

    // Add the bids to the items
    add_bid(item1, bid1);
    add_bid(item2, bid2);
    add_bid(item3, bid3);

    // Print the details of the items and bids
    print_item(item1);
    print_bid(bid1);
    print_item(item2);
    print_bid(bid2);
    print_item(item3);
    print_bid(bid3);

    return 0;
}