//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: interoperable
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

// Function to add a new medicine
void add_medicine(medicine *med) {
    printf("Enter medicine details:\n");
    printf("Name: ");
    scanf("%s", med->name);
    printf("Manufacturer: ");
    scanf("%s", med->manufacturer);
    printf("Price: ");
    scanf("%f", &med->price);
    printf("Quantity: ");
    scanf("%d", &med->quantity);
}

// Function to display medicine details
void display_medicine(medicine *med) {
    printf("\nMedicine Details:\n");
    printf("ID: %d\n", med->id);
    printf("Name: %s\n", med->name);
    printf("Manufacturer: %s\n", med->manufacturer);
    printf("Price: %.2f\n", med->price);
    printf("Quantity: %d\n", med->quantity);
}

// Function to search for a medicine by name
medicine *search_medicine(medicine *med, int num_med, char *name) {
    for (int i = 0; i < num_med; i++) {
        if (strcmp(med[i].name, name) == 0) {
            return &med[i];
        }
    }
    return NULL;
}

// Function to sell a medicine
void sell_medicine(medicine *med) {
    int quantity;
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    if (quantity <= med->quantity) {
        med->quantity -= quantity;
        printf("Medicine sold successfully!\n");
    } else {
        printf("Insufficient stock!\n");
    }
}

// Function to generate a report of all medicines
void generate_report(medicine *med, int num_med) {
    printf("\nMedicine Report:\n");
    printf("----------------------------------------------------------------------\n");
    printf("| ID | Name | Manufacturer | Price | Quantity |\n");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < num_med; i++) {
        printf("| %d | %s | %s | %.2f | %d |\n", med[i].id, med[i].name, med[i].manufacturer, med[i].price, med[i].quantity);
    }
    printf("----------------------------------------------------------------------\n");
}

// Main function
int main() {
    int num_med;
    printf("Enter number of medicines: ");
    scanf("%d", &num_med);

    // Allocate memory for the medicines
    medicine *med = (medicine *)malloc(num_med * sizeof(medicine));

    // Add medicines
    for (int i = 0; i < num_med; i++) {
        add_medicine(&med[i]);
        med[i].id = i + 1;
    }

    // Display medicines
    printf("\nMedicines:\n");
    for (int i = 0; i < num_med; i++) {
        display_medicine(&med[i]);
    }

    // Search for a medicine
    char name[50];
    printf("\nEnter medicine name to search: ");
    scanf("%s", name);
    medicine *found_med = search_medicine(med, num_med, name);
    if (found_med != NULL) {
        printf("\nMedicine found:\n");
        display_medicine(found_med);
    } else {
        printf("\nMedicine not found!\n");
    }

    // Sell a medicine
    printf("\nEnter medicine name to sell: ");
    scanf("%s", name);
    found_med = search_medicine(med, num_med, name);
    if (found_med != NULL) {
        sell_medicine(found_med);
    } else {
        printf("\nMedicine not found!\n");
    }

    // Generate a report
    generate_report(med, num_med);

    return 0;
}