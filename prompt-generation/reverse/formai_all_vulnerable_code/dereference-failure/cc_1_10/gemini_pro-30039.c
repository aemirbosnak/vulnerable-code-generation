//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: future-proof
// Medical Store Management System in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    int id;
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} medicine;

// Function to create a new medicine
medicine* create_medicine(int id, char* name, char* manufacturer, float price, int quantity) {
    medicine* med = (medicine*)malloc(sizeof(medicine));
    med->id = id;
    strcpy(med->name, name);
    strcpy(med->manufacturer, manufacturer);
    med->price = price;
    med->quantity = quantity;
    return med;
}

// Function to display medicine details
void display_medicine(medicine* med) {
    printf("ID: %d\n", med->id);
    printf("Name: %s\n", med->name);
    printf("Manufacturer: %s\n", med->manufacturer);
    printf("Price: %f\n", med->price);
    printf("Quantity: %d\n\n", med->quantity);
}

// Function to add a medicine to the inventory
void add_medicine(medicine*** inventory, int* size, medicine* med) {
    *inventory = realloc(*inventory, sizeof(medicine*) * (*size + 1));
    (*inventory)[*size] = med;
    (*size)++;
}

// Function to search for a medicine by ID
medicine* search_medicine_by_id(medicine** inventory, int size, int id) {
    for (int i = 0; i < size; i++) {
        if (inventory[i]->id == id) {
            return inventory[i];
        }
    }
    return NULL;
}

// Function to sell a medicine
void sell_medicine(medicine** inventory, int* size, int id, int quantity) {
    medicine* med = search_medicine_by_id(inventory, *size, id);
    if (med == NULL) {
        printf("Medicine not found!\n");
    } else if (med->quantity < quantity) {
        printf("Insufficient stock!\n");
    } else {
        med->quantity -= quantity;
        printf("Medicine sold successfully!\n");
    }
}

// Function to display the inventory
void display_inventory(medicine** inventory, int size) {
    for (int i = 0; i < size; i++) {
        display_medicine(inventory[i]);
    }
}

// Driver code
int main() {
    // Create an empty inventory
    medicine** inventory = NULL;
    int size = 0;

    // Add some medicines to the inventory
    add_medicine(&inventory, &size, create_medicine(1, "Paracetamol", "XYZ Pharma", 10.0, 50));
    add_medicine(&inventory, &size, create_medicine(2, "Ibuprofen", "ABC Pharma", 15.0, 75));
    add_medicine(&inventory, &size, create_medicine(3, "Aspirin", "DEF Pharma", 7.0, 100));

    // Display the inventory
    display_inventory(inventory, size);

    // Search for a medicine by ID
    int id = 2;
    medicine* med = search_medicine_by_id(inventory, size, id);
    if (med == NULL) {
        printf("Medicine not found!\n");
    } else {
        display_medicine(med);
    }

    // Sell a medicine
    id = 1;
    int quantity = 20;
    sell_medicine(inventory, &size, id, quantity);

    // Display the updated inventory
    display_inventory(inventory, size);

    // Free the allocated memory
    for (int i = 0; i < size; i++) {
        free(inventory[i]);
    }
    free(inventory);

    return 0;
}