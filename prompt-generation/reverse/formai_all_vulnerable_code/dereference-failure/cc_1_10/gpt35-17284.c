//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item {
    char name[50];
    int id;
    int quantity;
    float price;
    struct item* next;
};

struct item* head = NULL;
struct item* tail = NULL;

void add_item() {
    // function to add new item to the warehouse
    struct item* new_item = (struct item*)malloc(sizeof(struct item));
    printf("Enter the name of the item: ");
    scanf("%s", new_item->name);
    printf("Enter the item ID: ");
    scanf("%d", &new_item->id);
    printf("Enter the item price: ");
    scanf("%f", &new_item->price);
    printf("Enter the item quantity: ");
    scanf("%d", &new_item->quantity);
    new_item->next = NULL;

    if (head == NULL) {
        head = new_item;
        tail = new_item;
    }
    else {
        tail->next = new_item;
        tail = new_item;
    }
    printf("\nItem added successfully!\n");
}

void display_items() {
    // function to display all the items in the warehouse
    if (head == NULL) {
        printf("Warehouse is empty!\n");
        return;
    }
    struct item* current = head;
    printf("Item Name\tItem ID\tItem Price\tItem Quantity\n");
    while (current != NULL) {
        printf("%s\t\t%d\t%.2f\t\t%d\n", current->name, current->id, current->price, current->quantity);
        current = current->next;
    }
}

void search_item() {
    // function to search for an item in the warehouse
    if (head == NULL) {
        printf("Warehouse is empty!\n");
        return;
    }
    int item_id;
    printf("Enter the item ID: ");
    scanf("%d", &item_id);
    struct item* current = head;
    while (current != NULL) {
        if (current->id == item_id) {
            printf("Item Name: %s\nItem Price: %.2f\nItem Quantity: %d\n", current->name, current->price, current->quantity);
            return;
        }
        current = current->next;
    }
    printf("Item not found!\n");
}

void update_item() {
    // function to update the quantity of an item in the warehouse
    if (head == NULL) {
        printf("Warehouse is empty!\n");
        return;
    }
    int item_id, new_quantity;
    printf("Enter the item ID: ");
    scanf("%d", &item_id);
    printf("Enter the new quantity: ");
    scanf("%d", &new_quantity);
    struct item* current = head;
    while (current != NULL) {
        if (current->id == item_id) {
            current->quantity = new_quantity;
            printf("Item quantity updated!\n");
            return;
        }
        current = current->next;
    }
    printf("Item not found!\n");
}

void delete_item() {
    // function to delete an item from the warehouse
    if (head == NULL) {
        printf("Warehouse is empty!\n");
        return;
    }
    int item_id;
    printf("Enter the item ID: ");
    scanf("%d", &item_id);
    struct item *current = head, *prev;
    if (current->id == item_id) {
        head = current->next;
        free(current);
        printf("Item deleted!\n");
        return;
    }
    while (current != NULL && current->id != item_id) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Item not found!\n");
        return;
    }
    prev->next = current->next;
    if (current == tail)
        tail = prev;
    free(current);
    printf("Item deleted!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nWarehouse Management System\n");
        printf("===========================\n");
        printf("1. Add new item\n");
        printf("2. Display all items\n");
        printf("3. Search for an item\n");
        printf("4. Update an item\n");
        printf("5. Delete an item\n");
        printf("6. Exit\n");
        printf("===========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_item();
            break;
        case 2:
            display_items();
            break;
        case 3:
            search_item();
            break;
        case 4:
            update_item();
            break;
        case 5:
            delete_item();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}