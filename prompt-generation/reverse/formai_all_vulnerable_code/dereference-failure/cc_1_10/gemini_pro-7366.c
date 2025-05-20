//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item struct to hold item details
typedef struct Item {
    char name[50];
    float starting_bid;
    float current_bid;
    int num_bids;
    char highest_bidder[50];
} Item;

// User struct to hold user details
typedef struct User {
    char name[50];
    float balance;
    int num_bids;
} User;

// Function to create a new item
Item* create_item(char* name, float starting_bid) {
    Item* item = malloc(sizeof(Item));
    strcpy(item->name, name);
    item->starting_bid = starting_bid;
    item->current_bid = starting_bid;
    item->num_bids = 0;
    strcpy(item->highest_bidder, "");
    return item;
}

// Function to create a new user
User* create_user(char* name, float balance) {
    User* user = malloc(sizeof(User));
    strcpy(user->name, name);
    user->balance = balance;
    user->num_bids = 0;
    return user;
}

// Function to print item details
void print_item(Item* item) {
    printf("Item Name: %s\n", item->name);
    printf("Starting Bid: %.2f\n", item->starting_bid);
    printf("Current Bid: %.2f\n", item->current_bid);
    printf("Number of Bids: %d\n", item->num_bids);
    printf("Highest Bidder: %s\n\n", item->highest_bidder);
}

// Function to print user details
void print_user(User* user) {
    printf("User Name: %s\n", user->name);
    printf("Balance: %.2f\n", user->balance);
    printf("Number of Bids: %d\n\n", user->num_bids);
}

// Main function
int main() {

    // Create an array of items
    Item* items[] = {
        create_item("Painting", 100.0),
        create_item("Sculpture", 200.0),
        create_item("Vase", 50.0),
        create_item("Clock", 75.0),
        create_item("Book", 25.0)
    };

    // Create an array of users
    User* users[] = {
        create_user("Alice", 500.0),
        create_user("Bob", 300.0),
        create_user("Carol", 200.0),
        create_user("Dave", 100.0),
        create_user("Eve", 50.0)
    };

    // Print the list of items
    printf("Welcome to the Digital Auction System!\n\n");
    printf("Here are the items up for auction:\n\n");
    for (int i = 0; i < 5; i++) {
        print_item(items[i]);
    }

    // Start the auction
    printf("\nLet the auction begin!\n\n");
    while (1) {
        // Get the user's input
        char input[100];
        printf("Enter your command (bid, list, user, or quit): ");
        scanf("%s", input);

        // Process the user's input
        if (strcmp(input, "bid") == 0) {
            // Get the item name and bid amount
            char item_name[50];
            float bid_amount;
            printf("Enter the item name: ");
            scanf("%s", item_name);
            printf("Enter your bid amount: ");
            scanf("%f", &bid_amount);

            // Find the item
            Item* item = NULL;
            for (int i = 0; i < 5; i++) {
                if (strcmp(items[i]->name, item_name) == 0) {
                    item = items[i];
                    break;
                }
            }

            // Check if the item exists
            if (!item) {
                printf("Item not found!\n");
            }
            // Check if the bid amount is valid
            else if (bid_amount <= item->current_bid) {
                printf("Bid amount must be greater than the current bid!\n");
            }
            // Check if the user has enough balance
            else if (bid_amount > users[0]->balance) {
                printf("You don't have enough balance!\n");
            }
            // Place the bid
            else {
                item->current_bid = bid_amount;
                strcpy(item->highest_bidder, users[0]->name);
                item->num_bids++;
                users[0]->balance -= bid_amount;
                users[0]->num_bids++;
                printf("Bid placed successfully!\n");
            }
        }
        else if (strcmp(input, "list") == 0) {
            // Print the list of items
            printf("\nHere are the items up for auction:\n\n");
            for (int i = 0; i < 5; i++) {
                print_item(items[i]);
            }
        }
        else if (strcmp(input, "user") == 0) {
            // Print the user's details
            printf("\nYour details:\n\n");
            print_user(users[0]);
        }
        else if (strcmp(input, "quit") == 0) {
            // Exit the auction
            printf("\nThank you for participating in the auction!\n");
            break;
        }
        else {
            // Invalid input
            printf("Invalid command!\n");
        }
    }

    return 0;
}