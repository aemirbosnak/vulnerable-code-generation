//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store medicine information
struct Medicine {
    char name[50];
    int quantity;
    float price;
    struct Medicine* next;
};

// Function to insert a medicine into the linked list
void insertMedicine(struct Medicine** head) {
    struct Medicine* newMedicine = (struct Medicine*)malloc(sizeof(struct Medicine));
    printf("Enter the name of the medicine: ");
    scanf("%s", newMedicine->name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &newMedicine->quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &newMedicine->price);
    newMedicine->next = NULL;

    if (*head == NULL) {
        *head = newMedicine;
    } else {
        (*head)->next = newMedicine;
    }
}

// Function to display the medicine list
void displayMedicineList(struct Medicine* head) {
    struct Medicine* currentMedicine = head;
    printf("Here is the list of medicines:\n");
    while (currentMedicine) {
        printf("Name: %s, Quantity: %d, Price: %.2f\n", currentMedicine->name, currentMedicine->quantity, currentMedicine->price);
        currentMedicine = currentMedicine->next;
    }
}

// Main function
int main() {
    struct Medicine* head = NULL;

    // Insert some medicines
    insertMedicine(&head);
    insertMedicine(&head);
    insertMedicine(&head);

    // Display the medicine list
    displayMedicineList(head);

    return 0;
}