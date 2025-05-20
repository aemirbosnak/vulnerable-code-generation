//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Ada Lovelace
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

struct node {
    struct medicine med;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void add_medicine(char *name, int quantity, float price) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->med.name, name);
    new_node->med.quantity = quantity;
    new_node->med.price = price;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void display_medicines() {
    struct node *current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->med.name);
        printf("Quantity: %d\n", current->med.quantity);
        printf("Price: %.2f\n\n", current->med.price);
        current = current->next;
    }
}

void search_medicine(char *name) {
    struct node *current = head;
    while (current != NULL) {
        if (strcmp(current->med.name, name) == 0) {
            printf("Medicine found!\n");
            printf("Name: %s\n", current->med.name);
            printf("Quantity: %d\n", current->med.quantity);
            printf("Price: %.2f\n\n", current->med.price);
            return;
        }
        current = current->next;
    }
    printf("Medicine not found.\n");
}

void update_medicine(char *name, int quantity, float price) {
    struct node *current = head;
    while (current != NULL) {
        if (strcmp(current->med.name, name) == 0) {
            current->med.quantity = quantity;
            current->med.price = price;
            printf("Medicine updated successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("Medicine not found.\n");
}

void delete_medicine(char *name) {
    struct node *current = head;
    struct node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->med.name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Medicine deleted successfully.\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Medicine not found.\n");
}

int main() {
    // Add some medicines to the store
    add_medicine("Paracetamol", 100, 10.0);
    add_medicine("Ibuprofen", 50, 15.0);
    add_medicine("Aspirin", 25, 5.0);

    // Display the medicines in the store
    printf("Medicines in the store:\n\n");
    display_medicines();

    // Search for a medicine
    char *name = "Ibuprofen";
    search_medicine(name);

    // Update a medicine
    int quantity = 75;
    float price = 17.5;
    update_medicine(name, quantity, price);

    // Display the updated medicines in the store
    printf("Medicines in the store after update:\n\n");
    display_medicines();

    // Delete a medicine
    name = "Aspirin";
    delete_medicine(name);

    // Display the medicines in the store after deletion
    printf("Medicines in the store after deletion:\n\n");
    display_medicines();

    return 0;
}