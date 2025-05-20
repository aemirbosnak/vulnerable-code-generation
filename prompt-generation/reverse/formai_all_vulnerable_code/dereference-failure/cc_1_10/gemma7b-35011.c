//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    struct Item* next;
} Item;

Item* inventory = NULL;

void add_item(char* name, int quantity) {
    Item* new_item = malloc(sizeof(Item));
    strcpy(new_item->name, name);
    new_item->quantity = quantity;
    new_item->next = inventory;
    inventory = new_item;
}

void use_item(char* name) {
    Item* item = inventory;
    while (item) {
        if (strcmp(item->name, name) == 0) {
            item->quantity--;
            if (item->quantity == 0) {
                free(item);
                item = NULL;
            }
            printf("You used the %s.\n", item->name);
            break;
        }
        item = item->next;
    }

    if (item == NULL) {
        printf("You do not have that item.\n");
    }
}

int main() {
    add_item("Sword", 1);
    add_item("Shield", 1);
    add_item("Healing Potion", 3);

    use_item("Sword");
    use_item("Healing Potion");
    use_item("Shield");

    return 0;
}