//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct item_t {
    char name[20];
    int quantity;
    struct item_t* next;
} item_t;

item_t* inventory = NULL;

void add_item(char* name, int quantity) {
    item_t* new_item = malloc(sizeof(item_t));
    strcpy(new_item->name, name);
    new_item->quantity = quantity;
    new_item->next = inventory;
    inventory = new_item;
}

void use_item(char* name) {
    item_t* item = inventory;
    while (item) {
        if (strcmp(item->name, name) == 0) {
            item->quantity--;
            if (item->quantity == 0) {
                free(item);
                item = NULL;
            }
            break;
        }
        item = item->next;
    }
}

void print_inventory() {
    item_t* item = inventory;
    printf("Inventory:\n");
    while (item) {
        printf("%s: %d\n", item->name, item->quantity);
        item = item->next;
    }
}

int main() {
    add_item("Sword", 5);
    add_item("Shield", 2);
    add_item("Potion", 3);

    print_inventory();

    use_item("Sword");
    use_item("Potion");

    print_inventory();

    return 0;
}