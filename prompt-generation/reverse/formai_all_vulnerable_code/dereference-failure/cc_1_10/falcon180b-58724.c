//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_USERS 50
#define MAX_BIDS 1000

typedef struct {
    char name[50];
    int id;
} User;

typedef struct {
    char name[100];
    int id;
    int starting_price;
    int current_price;
    time_t end_time;
    User* highest_bidder;
} Item;

User users[MAX_USERS];
Item items[MAX_ITEMS];
int num_users = 0;
int num_items = 0;

void register_user(char* name) {
    User* new_user = &users[num_users];
    strcpy(new_user->name, name);
    new_user->id = num_users;
    num_users++;
}

int login_user(char* name) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void create_item(char* name, int starting_price, time_t end_time) {
    Item* new_item = &items[num_items];
    strcpy(new_item->name, name);
    new_item->id = num_items;
    new_item->starting_price = starting_price;
    new_item->current_price = starting_price;
    new_item->end_time = end_time;
    new_item->highest_bidder = NULL;
    num_items++;
}

int place_bid(int item_id, int price) {
    Item* item = &items[item_id];
    time_t current_time = time(NULL);

    if (current_time > item->end_time) {
        return -1;
    }

    if (item->current_price >= price) {
        return -2;
    }

    item->current_price = price;
    item->highest_bidder = &users[login_user(item->highest_bidder->name)];

    return 0;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Register some users
    register_user("Alice");
    register_user("Bob");
    register_user("Charlie");

    // Create some items
    create_item("Laptop", 1000, time(NULL) + 3600);
    create_item("Phone", 500, time(NULL) + 1800);

    // Place some bids
    place_bid(0, 1100);
    place_bid(0, 1200);
    place_bid(1, 600);

    return 0;
}