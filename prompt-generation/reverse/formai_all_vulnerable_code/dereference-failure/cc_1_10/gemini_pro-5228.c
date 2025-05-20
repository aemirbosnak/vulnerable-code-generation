//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    float reserve_price;
    float current_bid;
    int status; // 0: open, 1: closed, 2: sold
} Item;

Item *items;
int num_items;

void init_auction(const char *filename) {
    FILE *fp;
    char line[1024];
    char *delim = ",";

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Get the number of items
    fgets(line, sizeof(line), fp);
    num_items = atoi(line);

    // Allocate memory for the items
    items = malloc(sizeof(Item) * num_items);
    if (items == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the items from the file
    for (int i = 0; i < num_items; i++) {
        fgets(line, sizeof(line), fp);
        char *id_str = strtok(line, delim);
        char *name = strtok(NULL, delim);
        char *reserve_price_str = strtok(NULL, delim);
        char *current_bid_str = strtok(NULL, delim);
        char *status_str = strtok(NULL, delim);

        items[i].id = atoi(id_str);
        items[i].name = strdup(name);
        items[i].reserve_price = atof(reserve_price_str);
        items[i].current_bid = atof(current_bid_str);
        items[i].status = atoi(status_str);
    }

    fclose(fp);
}

void print_menu() {
    printf("1. List items\n");
    printf("2. Bid on an item\n");
    printf("3. Close an item\n");
    printf("4. Exit\n");
}

void list_items() {
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s (%f)\n", items[i].id, items[i].name, items[i].current_bid);
    }
}

void bid_on_item() {
    int item_id;
    float bid_amount;

    printf("Enter the ID of the item you want to bid on: ");
    scanf("%d", &item_id);

    // Find the item by its ID
    Item *item = NULL;
    for (int i = 0; i < num_items; i++) {
        if (items[i].id == item_id) {
            item = &items[i];
            break;
        }
    }

    if (item == NULL) {
        printf("Invalid item ID\n");
        return;
    }

    // Check if the item is open for bidding
    if (item->status != 0) {
        printf("This item is not open for bidding\n");
        return;
    }

    // Get the bid amount from the user
    printf("Enter your bid amount: ");
    scanf("%f", &bid_amount);

    // Check if the bid amount is valid
    if (bid_amount < item->reserve_price) {
        printf("Your bid amount is too low\n");
        return;
    }

    // Update the current bid
    item->current_bid = bid_amount;
}

void close_item() {
    int item_id;

    printf("Enter the ID of the item you want to close: ");
    scanf("%d", &item_id);

    // Find the item by its ID
    Item *item = NULL;
    for (int i = 0; i < num_items; i++) {
        if (items[i].id == item_id) {
            item = &items[i];
            break;
        }
    }

    if (item == NULL) {
        printf("Invalid item ID\n");
        return;
    }

    // Check if the item is open for bidding
    if (item->status != 0) {
        printf("This item is not open for bidding\n");
        return;
    }

    // Close the item
    item->status = 1;

    // If the current bid is above the reserve price, sell the item
    if (item->current_bid >= item->reserve_price) {
        item->status = 2;
    }
}

int main() {
    char filename[] = "items.txt";
    char choice;

    init_auction(filename);

    do {
        print_menu();

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                list_items();
                break;
            case '2':
                bid_on_item();
                break;
            case '3':
                close_item();
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != '4');

    return 0;
}