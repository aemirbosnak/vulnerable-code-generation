//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store medical store items
struct item {
    char name[50];
    int quantity;
    float price;
    struct item* next;
};

// Create a linked list of medical store items
struct item* head = NULL;

// Function to insert a new item into the linked list
void insert(char name[], int quantity, float price) {
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

// Function to search for an item in the linked list
struct item* search(char name[]) {
    struct item* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to update the quantity of an item in the linked list
void update(char name[], int new_quantity) {
    struct item* item = search(name);
    if (item) {
        item->quantity = new_quantity;
    }
}

// Function to delete an item from the linked list
void delete(char name[]) {
    struct item* item = search(name);
    if (item) {
        struct item* prev = NULL;
        struct item* temp = head;
        while (temp) {
            if (strcmp(temp->name, name) == 0) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                free(item);
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
    }
}

// Main function
int main() {
    insert("Paracetamol", 100, 2.5);
    insert("Ibuprofen", 50, 3.0);
    insert("Acetaminophen", 75, 2.2);

    struct item* item = search("Paracetamol");
    if (item) {
        printf("Name: %s\n", item->name);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
    }

    update("Ibuprofen", 60);
    item = search("Ibuprofen");
    if (item) {
        printf("Name: %s\n", item->name);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
    }

    delete("Acetaminophen");
    item = search("Acetaminophen");
    if (item) {
        printf("Name: %s\n", item->name);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
    }

    return 0;
}