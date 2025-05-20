//FormAI DATASET v1.0 Category: Digital Auction System ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Item {
    int id;
    char name[50];
    int price;
};

int current_id = 0; //current auction id
struct Item* items[10]; //maximum 10 items in auction
int num_items = 0; //number of items in auction

void add_item(char name[], int price) {
    if (num_items >= 10) {
        printf("Auction is full! Cannot add more items.\n");
        return;
    }
    struct Item* item = (struct Item*)malloc(sizeof(struct Item));
    item->id = ++current_id;
    strcpy(item->name, name);
    item->price = price;
    items[num_items++] = item;
    printf("Item added successfully! Item id is: %d\n", item->id);
}

void remove_item(int id) {
    int index = -1;
    for (int i = 0; i < num_items; i++) {
        if (items[i]->id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Item with id %d not found in auction!\n", id);
        return;
    }
    free(items[index]);
    for (int i = index; i < num_items - 1; i++) {
        items[i] = items[i+1];
    }
    num_items--;
    printf("Item with id %d removed successfully!\n", id);
}

void view_items() {
    printf("Current Auction Items:\n");
    printf("======================\n");
    printf("ID\tName\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d\t%s\t%d\n", items[i]->id, items[i]->name, items[i]->price);
    }
}

void bid(int id, int amount) {
    int index = -1;
    for (int i = 0; i < num_items; i++) {
        if (items[i]->id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Item with id %d not found in auction!\n", id);
        return;
    }
    if (amount <= items[index]->price) {
        printf("Your bid should be higher than the current price!\n");
        return;
    }
    items[index]->price = amount;
    printf("Bid placed successfully! Current price of item is: %d\n", items[index]->price);
}

int main() {
    int choice, id, price;
    char name[50];
    do {
        printf("\nWelcome to the Digital Auction System!\n");
        printf("======================================\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. View Items\n");
        printf("4. Bid\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item price: ");
                scanf("%d", &price);
                add_item(name, price);
                break;
            case 2:
                printf("Enter item id: ");
                scanf("%d", &id);
                remove_item(id);
                break;
            case 3:
                view_items();
                break;
            case 4:
                printf("Enter item id: ");
                scanf("%d", &id);
                printf("Enter bid amount: ");
                scanf("%d", &price);
                bid(id, price);
                break;
            case 5:
                printf("Thank you for using the Digital Auction System!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}