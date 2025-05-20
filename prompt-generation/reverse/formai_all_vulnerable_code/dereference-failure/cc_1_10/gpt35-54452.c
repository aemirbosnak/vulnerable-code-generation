//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Item {
    char name[20];
    int quantity;
    struct Item *next;
} Item_node;

void add_item(Item_node **head);
void remove_item(Item_node **head);
void display_inventory(Item_node *head);
void search_item(Item_node *head);
void update_item(Item_node *head);

int main() {
    Item_node *head = NULL;
    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add an item\n");
        printf("2. Remove an item\n");
        printf("3. Display inventory\n");
        printf("4. Search item\n");
        printf("5. Update item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_item(&head);
                break;
            case 2:
                remove_item(&head);
                break;
            case 3:
                display_inventory(head);
                break;
            case 4:
                search_item(head);
                break;
            case 5:
                update_item(head);
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while(1);
    return 0;
}

void add_item(Item_node **head) {
    Item_node *new_node = (Item_node*)malloc(sizeof(Item_node));
    printf("Enter item name: ");
    scanf("%s", new_node->name);
    printf("Enter quantity: ");
    scanf("%d", &new_node->quantity);
    new_node->next = *head;
    *head = new_node;
    printf("%s with quantity %d has been added to inventory.\n", new_node->name, new_node->quantity);
}

void remove_item(Item_node **head) {
    char item_name[20];
    printf("Enter name of item to remove: ");
    scanf("%s", item_name);
    Item_node *current = *head;
    Item_node *previous = NULL;
    while(current != NULL) {
        if(strcmp(current->name, item_name) == 0) {
            if(previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            printf("Removed item %s with quantity %d.\n", current->name, current->quantity);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Item %s not found in inventory.\n", item_name);
}

void display_inventory(Item_node *head) {
    if(head == NULL) {
        printf("No items in inventory.\n");
        return;
    }
    printf("Inventory:\n");
    while(head != NULL) {
        printf("%s - %d\n", head->name, head->quantity);
        head = head->next;
    }
}

void search_item(Item_node *head) {
    char item_name[20];
    printf("Enter name of item to search for: ");
    scanf("%s", item_name);
    Item_node *current = head;
    while(current != NULL) {
        if(strcmp(current->name, item_name) == 0) {
            printf("Item %s with quantity %d found in inventory.\n", current->name, current->quantity);
            return;
        }
        current = current->next;
    }
    printf("Item %s not found in inventory.\n", item_name);
}

void update_item(Item_node *head) {
    char item_name[20];
    printf("Enter name of item to update: ");
    scanf("%s", item_name);
    Item_node *current = head;
    while(current != NULL) {
        if(strcmp(current->name, item_name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &current->quantity);
            printf("Item %s now has quantity %d.\n", current->name, current->quantity);
            return;
        }
        current = current->next;
    }
    printf("Item %s not found in inventory.\n", item_name);
}