//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct Medicine {
    char name[50];
    char brand[50];
    char category[50];
    int quantity;
    float price;
} Medicine;

// Linked list node to store medicine data
typedef struct Node {
    Medicine medicine;
    struct Node *next;
} Node;

// Head of the linked list
Node *head = NULL;

// Function to add a medicine to the linked list
void addMedicine(Medicine medicine) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->medicine = medicine;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to search for a medicine by name
Medicine *searchMedicineByName(char *name) {
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->medicine.name, name) == 0) {
            return &temp->medicine;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to update the quantity of a medicine
void updateQuantity(char *name, int new_quantity) {
    Medicine *medicine = searchMedicineByName(name);
    if (medicine != NULL) {
        medicine->quantity = new_quantity;
    } else {
        printf("Medicine not found!\n");
    }
}

// Function to delete a medicine from the linked list
void deleteMedicine(char *name) {
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->medicine.name, name) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Medicine not found!\n");
}

// Function to display the entire stock
void displayStock() {
    Node *temp = head;
    printf("%-5s %-20s %-20s %-20s %-10s %-10s\n", "ID", "Name", "Brand", "Category", "Quantity", "Price");
    int i = 1;
    while (temp != NULL) {
        printf("%-5d %-20s %-20s %-20s %-10d %-10.2f\n", i, temp->medicine.name, temp->medicine.brand, temp->medicine.category, temp->medicine.quantity, temp->medicine.price);
        i++;
        temp = temp->next;
    }
}

// Main function
int main() {
    // Initialize the stock
    Medicine medicine1 = {"Paracetamol", "Cipla", "Pain Relief", 100, 10.0};
    Medicine medicine2 = {"Ibuprofen", "Advil", "Pain Relief", 50, 15.0};
    Medicine medicine3 = {"Amoxicillin", "GlaxoSmithKline", "Antibiotic", 20, 20.0};
    addMedicine(medicine1);
    addMedicine(medicine2);
    addMedicine(medicine3);

    // Display the initial stock
    printf("Initial Stock:\n");
    displayStock();

    // Search for a medicine by name
    char *name = "Ibuprofen";
    Medicine *medicine = searchMedicineByName(name);
    if (medicine != NULL) {
        printf("Medicine found: %s\n", medicine->name);
    } else {
        printf("Medicine not found!\n");
    }

    // Update the quantity of a medicine
    name = "Paracetamol";
    int new_quantity = 150;
    updateQuantity(name, new_quantity);
    printf("Updated stock:\n");
    displayStock();

    // Delete a medicine from the linked list
    name = "Amoxicillin";
    deleteMedicine(name);
    printf("Updated stock:\n");
    displayStock();

    return 0;
}