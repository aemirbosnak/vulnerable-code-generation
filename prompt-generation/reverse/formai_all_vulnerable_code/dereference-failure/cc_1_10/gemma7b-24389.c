//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define an array of auction items
struct item {
    char name[20];
    int starting_bid;
    int reserve_price;
    int current_bid;
    struct item* next;
};

// Create a linked list of auction items
struct item* head = NULL;

// Function to insert an item into the linked list
void insert_item(char* name, int starting_bid, int reserve_price) {
    struct item* new_item = malloc(sizeof(struct item));
    strcpy(new_item->name, name);
    new_item->starting_bid = starting_bid;
    new_item->reserve_price = reserve_price;
    new_item->current_bid = starting_bid;
    new_item->next = NULL;

    if (head == NULL) {
        head = new_item;
    } else {
        struct item* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_item;
    }
}

// Function to get the highest bid for an item
int get_highest_bid(char* name) {
    struct item* current_item = head;
    while (current_item) {
        if (strcmp(current_item->name, name) == 0) {
            return current_item->current_bid;
        }
        current_item = current_item->next;
    }
    return -1;
}

// Function to bid on an item
void bid(char* name, int bid) {
    struct item* current_item = head;
    while (current_item) {
        if (strcmp(current_item->name, name) == 0) {
            if (bid > current_item->current_bid) {
                current_item->current_bid = bid;
            }
        }
        current_item = current_item->next;
    }
}

// Function to check if an item has been sold
int is_item_sold(char* name) {
    struct item* current_item = head;
    while (current_item) {
        if (strcmp(current_item->name, name) == 0) {
            return current_item->current_bid >= current_item->reserve_price;
        }
        current_item = current_item->next;
    }
    return -1;
}

// Main function
int main() {
    // Insert some items into the linked list
    insert_item("Laptop", 500, 700);
    insert_item("Smartphone", 300, 500);
    insert_item("Watch", 200, 300);

    // Bid on an item
    bid("Laptop", 600);

    // Get the highest bid for an item
    int highest_bid = get_highest_bid("Laptop");
    printf("The highest bid for the Laptop is: %d\n", highest_bid);

    // Check if an item has been sold
    int is_sold = is_item_sold("Smartphone");
    printf("The Smartphone has been sold: %d\n", is_sold);

    return 0;
}