//FormAI DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure for an item in the auction
typedef struct item {
    int id;
    char name[100];
    int current_price;
    int min_bid;
    struct item *next;
} item_t;

// Creating global head and tail pointers
item_t *head = NULL;
item_t *tail = NULL;

// Function to add an item to the auction
void add_item() {
    item_t *new_item = (item_t*) malloc(sizeof(item_t));
    printf("\nEnter item id: ");
    scanf("%d", &new_item->id);
    printf("Enter item name: ");
    scanf("%s", new_item->name);
    printf("Enter starting price: ");
    scanf("%d", &new_item->current_price);
    printf("Enter minimum bid increment: ");
    scanf("%d", &new_item->min_bid);
    new_item->next = NULL;
    if (head == NULL) {
        head = new_item;
        tail = new_item;
    }
    else {
        tail->next = new_item;
        tail = new_item;
    }
    printf("\nItem added to the auction successfully.\n");
}

// Function to display all items in the auction
void display_items(item_t *item) {
    if (item == NULL) {
        printf("\nNo items to display in the auction.\n");
    }
    else {
        printf("\n%-5s %-20s %-10s %-10s\n", "ID", "Name", "Price ($)", "Min. Bid ($)");
        printf("---------------------------------------------------------\n");
        printf("%-5d %-20s %-10d %-10d\n", item->id, item->name, item->current_price, item->min_bid);
        if (item->next != NULL) {
            display_items(item->next);
        }
    }
}

// Function to update the current price of an item in the auction
void update_price(item_t *item) {
    int item_id, new_price;
    printf("\nEnter item id to update price: ");
    scanf("%d", &item_id);
    while (item != NULL) {
        if (item->id == item_id) {
            printf("Current price of the item is $%d.\n", item->current_price);
            printf("Enter new price (minimum bid increment of $%d): ", item->min_bid);
            scanf("%d", &new_price);
            if (new_price < item->current_price + item->min_bid) {
                printf("Error: New price must be at least $%d more than current price.\n", item->min_bid);
            }
            else {
                item->current_price = new_price;
                printf("Price of the item updated successfully.\n");
            }
            break;
        }
        item = item->next;
    }
    if (item == NULL) {
        printf("Error: Item with the given id not found.\n");
    }
}

// Function to recursively find the item with the highest bid
item_t *find_highest_bid(item_t *item, item_t *highest_bid_item) {
    if (item == NULL) {
        return highest_bid_item;
    }
    else {
        if (highest_bid_item == NULL || item->current_price > highest_bid_item->current_price) {
            highest_bid_item = item;
        }
        return find_highest_bid(item->next, highest_bid_item);
    }
}

// Function to close the auction and declare the winner
void close_auction() {
    int highest_bid;
    item_t *winner = find_highest_bid(head, NULL);
    if (winner == NULL) {
        printf("\nNo items in the auction to close.\n");
    }
    else {
        printf("\nThe auction is closed!\n");
        printf("Winning bid is $%d for item %d (%s).\n", winner->current_price, winner->id, winner->name);
        printf("Congratulations to the winner!\n");
        // Removing the winning item from the auction
        if (winner == head) {
            head = head->next;
        }
        else {
            item_t *temp = head;
            while (temp->next != winner) {
                temp = temp->next;
            }
            temp->next = winner->next;
            if (winner == tail) {
                tail = temp;
            }
        }
        free(winner);
    }
}

// Main function
int main() {
    int choice;
    do {
        printf("\nDigital Auction System\n");
        printf("----------------------\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Update Price\n");
        printf("4. Close Auction\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_items(head);
                break;
            case 3:
                update_price(head);
                break;
            case 4:
                close_auction();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (1);
    return 0;
}