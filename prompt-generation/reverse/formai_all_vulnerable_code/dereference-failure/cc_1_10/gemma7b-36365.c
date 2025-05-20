//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char name[20];
    int quantity;
    float price;
    struct item* next;
};

struct item* head = NULL;

void add_item(char* name, int quantity, float price) {
    struct item* new_item = (struct item*)malloc(sizeof(struct item));

    strcpy(new_item->name, name);
    new_item->quantity = quantity;
    new_item->price = price;
    new_item->next = NULL;

    if (head == NULL) {
        head = new_item;
    } else {
        struct item* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_item;
    }
}

void print_inventory() {
    struct item* temp = head;
    printf("Inventory:\n");
    while (temp) {
        printf("%s: %d @ $%.2f\n", temp->name, temp->quantity, temp->price);
        temp = temp->next;
    }
}

int main() {
    add_item("Apple", 10, 1.20);
    add_item("Banana", 5, 1.50);
    add_item("Orange", 7, 1.70);
    add_item("Peach", 3, 1.90);
    add_item("Pear", 2, 2.00);

    print_inventory();

    return 0;
}