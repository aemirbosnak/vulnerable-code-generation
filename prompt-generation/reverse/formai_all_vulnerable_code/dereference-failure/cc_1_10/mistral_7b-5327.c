//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEM_NAME_LENGTH 50
#define MAX_NUM_ITEMS 100

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH + 1];
    int quantity;
} Item;

Item inventory[MAX_NUM_ITEMS];
int num_items = 0;

void error_exit(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

int validate_name(const char *name) {
    int i;
    for (i = 0; i < num_items && strcmp(inventory[i].name, name) != 0; i++);
    return i < num_items;
}

void add_item(const char *name, int quantity) {
    if (num_items >= MAX_NUM_ITEMS) {
        error_exit("Warehouse is full.\n");
    }
    strncpy(inventory[num_items].name, name, MAX_ITEM_NAME_LENGTH);
    inventory[num_items].quantity = quantity;
    num_items++;
}

void remove_item(const char *name) {
    int i;
    for (i = 0; i < num_items && strcmp(inventory[i].name, name) != 0; i++);
    if (i >= num_items) {
        error_exit("Item not found.\n");
    }
    for (; i < num_items - 1; i++) {
        strncpy(inventory[i].name, inventory[i+1].name, MAX_ITEM_NAME_LENGTH);
        inventory[i].quantity = inventory[i+1].quantity;
    }
    num_items--;
}

void print_inventory() {
    int i;
    for (i = 0; i < num_items; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        error_exit("Usage: warehouse [add|remove] [name] [quantity]\n");
    }

    const char *command = argv[1];
    if (strcmp(command, "add") != 0 && strcmp(command, "remove") != 0) {
        error_exit("Invalid command.\n");
    }

    const char *name = argv[2];
    if (strlen(name) > MAX_ITEM_NAME_LENGTH || strlen(name) + strlen(argv[3]) > MAX_ITEM_NAME_LENGTH + 10) {
        error_exit("Name or quantity too long.\n");
    }

    int quantity;
    if (sscanf(argv[3], "%d", &quantity) != 1) {
        error_exit("Invalid quantity.\n");
    }

    if (strcmp(command, "add") == 0) {
        if (validate_name(name)) {
            error_exit("Item already exists.\n");
        }
        add_item(name, quantity);
    } else {
        if (!validate_name(name)) {
            error_exit("Item not found.\n");
        }
        remove_item(name);
    }

    print_inventory();

    return EXIT_SUCCESS;
}