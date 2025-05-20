//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: configurable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int item_id;
    char *item_name;
    double starting_bid;
    double reserve_price;
    int active;
    int sold;
} item_t;

typedef struct {
    int user_id;
    char *user_name;
    double balance;
} user_t;

typedef struct {
    int bid_id;
    item_t *item;
    user_t *user;
    double bid_amount;
} bid_t;

// Create a new item
item_t *create_item(int item_id, char *item_name, double starting_bid, double reserve_price) {
    item_t *item = malloc(sizeof(item_t));
    item->item_id = item_id;
    item->item_name = strdup(item_name);
    item->starting_bid = starting_bid;
    item->reserve_price = reserve_price;
    item->active = 1;
    item->sold = 0;
    return item;
}

// Create a new user
user_t *create_user(int user_id, char *user_name, double balance) {
    user_t *user = malloc(sizeof(user_t));
    user->user_id = user_id;
    user->user_name = strdup(user_name);
    user->balance = balance;
    return user;
}

// Create a new bid
bid_t *create_bid(item_t *item, user_t *user, double bid_amount) {
    bid_t *bid = malloc(sizeof(bid_t));
    bid->bid_id = 0;
    bid->item = item;
    bid->user = user;
    bid->bid_amount = bid_amount;
    return bid;
}

// Print the details of an item
void print_item(item_t *item) {
    printf("Item ID: %d\n", item->item_id);
    printf("Item Name: %s\n", item->item_name);
    printf("Starting Bid: $%.2f\n", item->starting_bid);
    printf("Reserve Price: $%.2f\n", item->reserve_price);
    printf("Active: %s\n", item->active ? "Yes" : "No");
    printf("Sold: %s\n", item->sold ? "Yes" : "No");
}

// Print the details of a user
void print_user(user_t *user) {
    printf("User ID: %d\n", user->user_id);
    printf("User Name: %s\n", user->user_name);
    printf("Balance: $%.2f\n", user->balance);
}

// Print the details of a bid
void print_bid(bid_t *bid) {
    printf("Bid ID: %d\n", bid->bid_id);
    print_item(bid->item);
    print_user(bid->user);
    printf("Bid Amount: $%.2f\n", bid->bid_amount);
}

// Main function
int main() {
    // Create some items
    item_t *item1 = create_item(1, "iPhone 12", 1000.00, 1200.00);
    item_t *item2 = create_item(2, "Macbook Pro", 1500.00, 1800.00);
    item_t *item3 = create_item(3, "iPad Air", 500.00, 600.00);

    // Create some users
    user_t *user1 = create_user(1, "John Doe", 10000.00);
    user_t *user2 = create_user(2, "Jane Doe", 5000.00);
    user_t *user3 = create_user(3, "Bob Smith", 20000.00);

    // Create some bids
    bid_t *bid1 = create_bid(item1, user1, 1100.00);
    bid_t *bid2 = create_bid(item2, user2, 1600.00);
    bid_t *bid3 = create_bid(item3, user3, 550.00);

    // Print the details of the items, users, and bids
    printf("Items:\n");
    print_item(item1);
    print_item(item2);
    print_item(item3);
    printf("\n");

    printf("Users:\n");
    print_user(user1);
    print_user(user2);
    print_user(user3);
    printf("\n");

    printf("Bids:\n");
    print_bid(bid1);
    print_bid(bid2);
    print_bid(bid3);
    printf("\n");

    // Clean up
    free(item1->item_name);
    free(item2->item_name);
    free(item3->item_name);
    free(item1);
    free(item2);
    free(item3);
    free(user1->user_name);
    free(user2->user_name);
    free(user3->user_name);
    free(user1);
    free(user2);
    free(user3);
    free(bid1);
    free(bid2);
    free(bid3);

    return 0;
}