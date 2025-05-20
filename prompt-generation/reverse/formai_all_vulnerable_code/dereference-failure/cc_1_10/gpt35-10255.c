//FormAI DATASET v1.0 Category: Digital Auction System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct for storing auction items
typedef struct auction_item {
    char item_name[50];
    int starting_bid;
    int current_bid;
    char highest_bidder[50];
    int auction_status; //0 for closed, 1 for open
} Auction_Item;

//Function for opening a new auction
void open_auction(Auction_Item* items, int num_items) {
    int item_num;
    printf("Enter the number of the item you want to auction: ");
    scanf("%d", &item_num);

    if (item_num > num_items || item_num < 1) { //Invalid item number
        printf("Invalid item number.\n");
    } else if (items[item_num-1].auction_status == 1) { //Item already open for bidding
        printf("%s is already open for bidding.\n", items[item_num-1].item_name);
    } else { //Open auction for selected item
        int starting_bid;
        printf("Enter starting bid: ");
        scanf("%d", &starting_bid);

        items[item_num-1].starting_bid = starting_bid;
        items[item_num-1].current_bid = starting_bid;
        items[item_num-1].auction_status = 1;

        printf("Auction for %s is now open with starting bid of %d.\n", items[item_num-1].item_name, starting_bid);
    }
}

//Function for making a bid
void make_bid(Auction_Item* items, int num_items, char* username) {
    int item_num;
    printf("Enter the number of the item you want to bid on: ");
    scanf("%d", &item_num);

    if (item_num > num_items || item_num < 1) { //Invalid item number
        printf("Invalid item number.\n");
    } else if (items[item_num-1].auction_status == 0) { //Auction not open for bidding
        printf("%s is not open for bidding.\n", items[item_num-1].item_name);
    } else {
        int bid;
        printf("Enter bid amount: ");
        scanf("%d", &bid);

        if (bid <= items[item_num-1].current_bid) { //Bid is less than current highest bid
            printf("Bid must be higher than current highest bid of %d.\n", items[item_num-1].current_bid);
        } else {
            strncpy(items[item_num-1].highest_bidder, username, 50);
            items[item_num-1].current_bid = bid;
            printf("Bid of %d accepted for %s.\n", bid, items[item_num-1].item_name);
        }
    }
}

//Function for closing an auction
void close_auction(Auction_Item* items, int num_items) {
    int item_num;
    printf("Enter the number of the item you want to close: ");
    scanf("%d", &item_num);

    if (item_num > num_items || item_num < 1) { //Invalid item number
        printf("Invalid item number.\n");
    } else if (items[item_num-1].auction_status == 0) { //Auction not open for bidding
        printf("%s is not open for bidding.\n", items[item_num-1].item_name);
    } else { //Close auction and print winner
        printf("Auction for %s closed.\n", items[item_num-1].item_name);
        printf("%s won the auction with a bid of %d.\n", items[item_num-1].highest_bidder, items[item_num-1].current_bid);
        items[item_num-1].auction_status = 0;
    }
}

//Main function
int main() {
    int num_items;
    printf("Enter the number of items you want to auction: ");
    scanf("%d", &num_items);

    Auction_Item* items = (Auction_Item*)malloc(num_items * sizeof(Auction_Item)); //Allocate memory for items

    for (int i = 0; i < num_items; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", items[i].item_name);
        items[i].starting_bid = 0;
        items[i].current_bid = 0;
        strncpy(items[i].highest_bidder, "", 50);
        items[i].auction_status = 0;
    }

    int choice;
    char username[50];

    printf("Enter your username: ");
    scanf("%s", username);

    do {
        printf("\n1. Open auction\n2. Make bid\n3. Close auction\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                open_auction(items, num_items);
                break;
            case 2:
                make_bid(items, num_items, username);
                break;
            case 3:
                close_auction(items, num_items);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

    } while (choice != 4);

    free(items); //Free allocated memory

    return 0;
}