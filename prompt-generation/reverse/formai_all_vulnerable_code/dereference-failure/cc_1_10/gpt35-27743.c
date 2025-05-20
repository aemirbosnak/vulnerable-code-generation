//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for each medicine
typedef struct Medicine {
    char name[50];
    int quantity;
    double price;
    struct Medicine *next;
} Medicine;

// global variables
Medicine *head = NULL; // the head of the linked list

// function to add a new medicine to the list
void addMedicine(char name[], int quantity, double price) {
    // create a new medicine
    Medicine *newMedicine = (Medicine *) malloc(sizeof(Medicine));
    strcpy(newMedicine->name, name);
    newMedicine->quantity = quantity;
    newMedicine->price = price;
    newMedicine->next = NULL;
    
    // add the new medicine to the end of the list
    if (head == NULL) {
        head = newMedicine;
    } else {
        Medicine *currentMedicine = head;
        while (currentMedicine->next != NULL) {
            currentMedicine = currentMedicine->next;
        }
        currentMedicine->next = newMedicine;
    }
}

// function to display all the medicines in the list
void displayMedicines() {
    printf("Medicine Inventory:\n");
    printf("%-30s%-10s%-10s\n", "Name", "Quantity", "Price");
    Medicine *currentMedicine = head;
    while (currentMedicine != NULL) {
        printf("%-30s%-10d%.2f\n", currentMedicine->name, currentMedicine->quantity, currentMedicine->price);
        currentMedicine = currentMedicine->next;
    }
}

// function to sell a medicine
void sellMedicine(char name[], int amount) {
    Medicine *currentMedicine = head;
    while (currentMedicine != NULL) {
        if (strcmp(currentMedicine->name, name) == 0) {
            // medicine found
            if (currentMedicine->quantity >= amount) {
                // sell the medicine
                currentMedicine->quantity -= amount;
                printf("%d %s sold for %.2f\n", amount, currentMedicine->name, currentMedicine->price * amount);
            } else {
                // not enough stock
                printf("Not enough stock for %s\n", currentMedicine->name);
            }
            return;
        }
        currentMedicine = currentMedicine->next;
    }
    // medicine not found
    printf("%s not found\n", name);
}

// main function
int main() {
    // add some medicines
    addMedicine("Paracetamol", 100, 1.50);
    addMedicine("Amoxicillin", 50, 2.75);
    addMedicine("Ibuprofen", 75, 2.00);
    
    // display the medicines
    displayMedicines();
    
    // sell some medicines
    sellMedicine("Ibuprofen", 10);
    sellMedicine("Paracetamol", 40);
    sellMedicine("Aspirin", 5);
    
    // display the medicines again
    displayMedicines();
    
    return 0;
}