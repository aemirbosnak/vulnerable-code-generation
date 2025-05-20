//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int bid_price;
    char bidder_name[50];
} Bidder;

typedef struct {
    int item_price;
    char item_name[50];
} Item;

void print_menu() {
    printf("Welcome to the C Digital Auction System!\n");
    printf("1. Add an item\n");
    printf("2. Add a bidder\n");
    printf("3. Start an auction\n");
    printf("4. View auction results\n");
    printf("5. Quit\n");
}

void add_item() {
    Item item;

    printf("Enter the item price: ");
    scanf("%d", &item.item_price);
    printf("Enter the item name: ");
    scanf("%s", item.item_name);

    printf("Item '%s' added successfully!\n", item.item_name);
}

void add_bidder() {
    Bidder bidder;

    printf("Enter the bidder name: ");
    scanf("%s", bidder.bidder_name);
    printf("Enter the bidder bid price: ");
    scanf("%d", &bidder.bid_price);

    printf("Bidder '%s' added successfully!\n", bidder.bidder_name);
}

void start_auction() {
    int num_items;
    int num_bidders;

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    Item* items = (Item*) malloc(num_items * sizeof(Item));
    for (int i = 0; i < num_items; i++) {
        items[i].item_price = i + 1;
        strcpy(items[i].item_name, "Item #");
        sprintf(items[i].item_name + 6, "%d", i + 1);
    }

    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    Bidder* bidders = (Bidder*) malloc(num_bidders * sizeof(Bidder));
    for (int i = 0; i < num_bidders; i++) {
        bidders[i].bid_price = i + 1;
        strcpy(bidders[i].bidder_name, "Bidder #");
        sprintf(bidders[i].bidder_name + 6, "%d", i + 1);
    }

    int item_index = 0;
    int bidder_index = 0;
    int bid_amount = 0;

    while (item_index < num_items && bidder_index < num_bidders) {
        printf("Item %d - Bidder %d\n", item_index + 1, bidder_index + 1);
        printf("Current bid: %d\n", bidders[bidder_index].bid_price);

        printf("Enter your bid: ");
        scanf("%d", &bid_amount);

        if (bid_amount > bidders[bidder_index].bid_price) {
            bidders[bidder_index].bid_price = bid_amount;
            printf("New highest bid: %d\n", bidders[bidder_index].bid_price);

            if (item_index < num_items) {
                if (bidders[bidder_index].bid_price > items[item_index].item_price) {
                    printf("Bidder %d wins item %d!\n", bidder_index + 1, item_index + 1);
                    bidders[bidder_index].bid_price = 0;
                    items[item_index].item_price = 0;
                    item_index++;
                    bidder_index++;
                }
            }
        } else {
            printf("Invalid bid\n");
        }
    }

    if (item_index < num_items) {
        printf("No bidders placed a bid for item %d\n", item_index + 1);
    }

    if (bidder_index < num_bidders) {
        printf("No items are left for bidder %d\n", bidder_index + 1);
    }

    free(items);
    free(bidders);
}

void view_results() {
    int num_items;
    int num_bidders;

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    Item* items = (Item*) malloc(num_items * sizeof(Item));
    for (int i = 0; i < num_items; i++) {
        items[i].item_price = i + 1;
        strcpy(items[i].item_name, "Item #");
        sprintf(items[i].item_name + 6, "%d", i + 1);
    }

    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    Bidder* bidders = (Bidder*) malloc(num_bidders * sizeof(Bidder));
    for (int i = 0; i < num_bidders; i++) {
        bidders[i].bid_price = i + 1;
        strcpy(bidders[i].bidder_name, "Bidder #");
        sprintf(bidders[i].bidder_name + 6, "%d", i + 1);
    }

    int item_index = 0;
    int bidder_index = 0;

    while (item_index < num_items && bidder_index < num_bidders) {
        printf("Item %d - Bidder %d\n", item_index + 1, bidder_index + 1);
        printf("Current bid: %d\n", bidders[bidder_index].bid_price);

        if (bidders[bidder_index].bid_price > 0) {
            printf("Bidder %d won item %d for %d!\n", bidder_index + 1, item_index + 1, bidders[bidder_index].bid_price);
        }

        item_index++;
        bidder_index++;
    }

    free(items);
    free(bidders);
}

int main() {
    int choice;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                add_bidder();
                break;
            case 3:
                start_auction();
                break;
            case 4:
                view_results();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}