//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medical store items
typedef struct Item {
    char name[50];
    int quantity;
    float price;
    struct Item* next;
} Item;

// Create a linked list of items
Item* head = NULL;

// Function to insert an item into the linked list
void insertItem(char* name, int quantity, float price) {
    Item* newNode = (Item*)malloc(sizeof(Item));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->price = price;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Item* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for an item
Item* searchItem(char* name) {
    Item* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to update the quantity of an item
void updateQuantity(char* name, int newQuantity) {
    Item* item = searchItem(name);
    if (item) {
        item->quantity = newQuantity;
    }
}

// Function to delete an item
void deleteItem(char* name) {
    Item* item = searchItem(name);
    if (item) {
        Item* prevItem = NULL;
        Item* tempItem = head;
        while (tempItem) {
            if (strcmp(tempItem->name, name) == 0) {
                if (prevItem) {
                    prevItem->next = tempItem->next;
                } else {
                    head = tempItem->next;
                }
                free(item);
            } else {
                prevItem = tempItem;
                tempItem = tempItem->next;
            }
        }
    }
}

// Function to display all items
void displayItems() {
    Item* temp = head;
    while (temp) {
        printf("%s, %d, %.2f\n", temp->name, temp->quantity, temp->price);
        temp = temp->next;
    }
}

int main() {
    insertItem("Panadol", 10, 20.0);
    insertItem("Ibuprofen", 5, 15.0);
    insertItem("Paracetamol", 7, 12.0);

    displayItems();

    updateQuantity("Panadol", 15);

    displayItems();

    deleteItem("Ibuprofen");

    displayItems();

    return 0;
}