//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    int id;
    char name[50];
    int quantity;
    float price;
} medicine;

// Function to add a new medicine to the store
void add_medicine(medicine** store, int* count) {
    printf("Enter medicine ID: ");
    int id;
    scanf("%d", &id);

    // Check if the medicine ID already exists
    for (int i = 0; i < *count; i++) {
        if ((*store)[i].id == id) {
            printf("Medicine with ID %d already exists.\n", id);
            return;
        }
    }

    // Get the medicine details from the user
    printf("Enter medicine name: ");
    char name[50];
    scanf(" %[^\n]", name);

    printf("Enter medicine quantity: ");
    int quantity;
    scanf("%d", &quantity);

    printf("Enter medicine price: ");
    float price;
    scanf("%f", &price);

    // Allocate memory for the new medicine
    *store = realloc(*store, (*count + 1) * sizeof(medicine));

    // Add the new medicine to the store
    (*store)[*count].id = id;
    strcpy((*store)[*count].name, name);
    (*store)[*count].quantity = quantity;
    (*store)[*count].price = price;

    (*count)++;
    printf("Medicine added successfully.\n");
}

// Function to search for a medicine in the store
void search_medicine(medicine* store, int count) {
    printf("Enter medicine ID: ");
    int id;
    scanf("%d", &id);

    // Search for the medicine in the store
    for (int i = 0; i < count; i++) {
        if (store[i].id == id) {
            printf("Medicine found:\n");
            printf("ID: %d\n", store[i].id);
            printf("Name: %s\n", store[i].name);
            printf("Quantity: %d\n", store[i].quantity);
            printf("Price: %.2f\n", store[i].price);
            return;
        }
    }

    printf("Medicine not found.\n");
}

// Function to sell a medicine from the store
void sell_medicine(medicine* store, int* count) {
    printf("Enter medicine ID: ");
    int id;
    scanf("%d", &id);

    // Search for the medicine in the store
    for (int i = 0; i < *count; i++) {
        if (store[i].id == id) {
            printf("Enter quantity to sell: ");
            int quantity;
            scanf("%d", &quantity);

            // Check if the requested quantity is available
            if (store[i].quantity < quantity) {
                printf("Insufficient stock.\n");
                return;
            }

            // Update the medicine quantity
            store[i].quantity -= quantity;

            printf("Medicine sold successfully.\n");
            return;
        }
    }

    printf("Medicine not found.\n");
}

// Function to display all medicines in the store
void display_medicines(medicine* store, int count) {
    printf("Medicine inventory:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", store[i].id);
        printf("Name: %s\n", store[i].name);
        printf("Quantity: %d\n", store[i].quantity);
        printf("Price: %.2f\n", store[i].price);
        printf("\n");
    }
}

// Main function
int main() {
    // Declare an array of medicines
    medicine* store = NULL;
    int count = 0;

    // Add some sample medicines to the store
    add_medicine(&store, &count);
    add_medicine(&store, &count);
    add_medicine(&store, &count);

    // Display the medicines in the store
    display_medicines(store, count);

    // Search for a medicine in the store
    search_medicine(store, count);

    // Sell a medicine from the store
    sell_medicine(store, &count);

    // Display the medicines in the store after selling
    display_medicines(store, count);

    return 0;
}