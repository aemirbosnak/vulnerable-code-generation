//FormAI DATASET v1.0 Category: Linked list operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent each item in the shopping list
struct Item {
    char name[50];
    float price;
    struct Item* next;
};

// Global variable to hold the head of the linked list
struct Item* head = NULL;

// Function to add a new item to the shopping list
void add_item() {
    printf("Enter item name: ");
    char name[50];
    scanf("%s", name);

    printf("Enter item price: ");
    float price;
    scanf("%f", &price);

    // Allocate memory for the new item
    struct Item* new_item = (struct Item*)malloc(sizeof(struct Item));

    // Copy the data into the new item
    strcpy(new_item->name, name);
    new_item->price = price;
    new_item->next = NULL;

    // If the list is empty, set the new item as the head
    if (head == NULL) {
        head = new_item;
    }
    else {
        // Traverse the list and add the new item to the end
        struct Item* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_item;
    }

    printf("Item added to list.\n");
}

// Function to remove an item from the shopping list
void remove_item() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter name of item to remove: ");
    char name[50];
    scanf("%s", name);

    // Special case: if the head needs to be removed
    if (strcmp(head->name, name) == 0) {
        struct Item* temp = head;
        head = head->next;
        free(temp);
        printf("Item removed from list.\n");
        return;
    }

    // Traverse the list and remove the item
    struct Item* prev = head;
    while (prev->next != NULL && strcmp(prev->next->name, name) != 0) {
        prev = prev->next;
    }
    if (prev->next == NULL) {
        printf("Item not found.\n");
        return;
    }
    struct Item* temp = prev->next;
    prev->next = temp->next;
    free(temp);
    printf("Item removed from list.\n");
}

// Function to display the shopping list
void display_list() {
    if (head == NULL) {
        printf("List is empty.\n");
    }
    else {
        printf("Shopping List:\n");
        struct Item* temp = head;
        while (temp != NULL) {
            printf("%s - $%.2f\n", temp->name, temp->price);
            temp = temp->next;
        }
    }
}

// Function to free all memory allocated to the linked list before exiting the program
void free_list() {
    while (head != NULL) {
        struct Item* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Main program loop - waits for user input
    char input = ' ';
    while (input != 'q') {
        printf("\n(a)dd item | (r)emove item | (d)isplay list | (q)uit\n");
        scanf(" %c", &input);

        switch (input) {
            case 'a':
                add_item();
                break;
            case 'r':
                remove_item();
                break;
            case 'd':
                display_list();
                break;
            case 'q':
                break;
            default:
                printf("Invalid input!\n");
                break;
        }
    }

    // Free memory allocated to the linked list
    free_list();

    return 0;
}