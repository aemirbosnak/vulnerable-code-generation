//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    struct Item* next;
} Item;

Item* head = NULL;

void add_item(char* name, int quantity) {
    Item* new_item = malloc(sizeof(Item));
    strcpy(new_item->name, name);
    new_item->quantity = quantity;
    new_item->next = NULL;

    if (head == NULL) {
        head = new_item;
    } else {
        Item* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_item;
    }
}

void backup_items() {
    FILE* file = fopen("items.txt", "w");
    fprintf(file, "List of items:\n");
    Item* current = head;
    while (current) {
        fprintf(file, "%s - %d\n", current->name, current->quantity);
        current = current->next;
    }
    fclose(file);
}

int main() {
    add_item("Sword", 5);
    add_item("Shield", 3);
    add_item("Potion", 2);
    add_item("Armor", 1);

    backup_items();

    FILE* file = fopen("items.txt", "r");
    fprintf(file, "Items:\n");
    Item* current = head;
    while (current) {
        fprintf(file, "%s - %d\n", current->name, current->quantity);
        current = current->next;
    }
    fclose(file);

    return 0;
}