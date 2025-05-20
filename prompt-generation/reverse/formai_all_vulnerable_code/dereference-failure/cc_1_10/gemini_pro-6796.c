//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    char company[50];
    float price;
    int quantity;
} medicine;

// Create a list of medicines
medicine *medicines;
int num_medicines = 0;

// Add a new medicine to the list
void add_medicine() {
    // Allocate memory for the new medicine
    medicine *new_medicine = malloc(sizeof(medicine));

    // Get the medicine details from the user
    printf("Enter medicine name: ");
    scanf("%s", new_medicine->name);

    printf("Enter medicine company: ");
    scanf("%s", new_medicine->company);

    printf("Enter medicine price: ");
    scanf("%f", &new_medicine->price);

    printf("Enter medicine quantity: ");
    scanf("%d", &new_medicine->quantity);

    // Add the new medicine to the list
    medicines = realloc(medicines, (num_medicines + 1) * sizeof(medicine));
    medicines[num_medicines] = *new_medicine;
    num_medicines++;
}

// Display the list of medicines
void display_medicines() {
    // Print the header
    printf("%-5s %-20s %-20s %-10s %-10s\n", "ID", "Name", "Company", "Price", "Quantity");

    // Print the details of each medicine
    for (int i = 0; i < num_medicines; i++) {
        printf("%-5d %-20s %-20s %-10.2f %-10d\n", i + 1, medicines[i].name, medicines[i].company, medicines[i].price, medicines[i].quantity);
    }
}

// Search for a medicine by name
void search_medicine() {
    // Get the medicine name from the user
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);

    // Search for the medicine in the list
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            // Print the details of the medicine
            printf("Medicine found:\n");
            printf("Name: %s\n", medicines[i].name);
            printf("Company: %s\n", medicines[i].company);
            printf("Price: %.2f\n", medicines[i].price);
            printf("Quantity: %d\n", medicines[i].quantity);
            found = 1;
            break;
        }
    }

    // If the medicine was not found, print an error message
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Update the quantity of a medicine
void update_medicine() {
    // Get the medicine name from the user
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);

    // Search for the medicine in the list
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            // Get the new quantity from the user
            int quantity;
            printf("Enter new quantity: ");
            scanf("%d", &quantity);

            // Update the quantity of the medicine
            medicines[i].quantity = quantity;
            found = 1;
            break;
        }
    }

    // If the medicine was not found, print an error message
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Delete a medicine from the list
void delete_medicine() {
    // Get the medicine name from the user
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);

    // Search for the medicine in the list
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            // Delete the medicine from the list
            for (int j = i; j < num_medicines - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            num_medicines--;
            found = 1;
            break;
        }
    }

    // If the medicine was not found, print an error message
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Main function
int main() {
    // Add some sample medicines to the list
    add_medicine("Paracetamol", "GlaxoSmithKline", 10.0, 100);
    add_medicine("Ibuprofen", "Reckitt Benckiser", 15.0, 50);
    add_medicine("Aspirin", "Bayer", 5.0, 200);

    // Display the list of medicines
    printf("List of medicines:\n");
    display_medicines();

    // Search for a medicine by name
    search_medicine();

    // Update the quantity of a medicine
    update_medicine();

    // Delete a medicine from the list
    delete_medicine();

    // Display the updated list of medicines
    printf("Updated list of medicines:\n");
    display_medicines();

    return 0;
}