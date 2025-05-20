//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
    struct medicine *next;
} medicine;

// Function to create a new medicine node
medicine *create_medicine(char *name, char *manufacturer, int quantity, float price) {
    medicine *new_medicine = (medicine *)malloc(sizeof(medicine));
    strcpy(new_medicine->name, name);
    strcpy(new_medicine->manufacturer, manufacturer);
    new_medicine->quantity = quantity;
    new_medicine->price = price;
    new_medicine->next = NULL;
    return new_medicine;
}

// Function to insert a new medicine node at the end of the linked list
void insert_medicine(medicine **head, medicine *new_medicine) {
    if (*head == NULL) {
        *head = new_medicine;
        return;
    }
    medicine *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_medicine;
}

// Function to search for a medicine by name
medicine *search_medicine(medicine *head, char *name) {
    medicine *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to delete a medicine by name
void delete_medicine(medicine **head, char *name) {
    medicine *temp = *head;
    medicine *prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Function to print the details of all medicines
void print_medicines(medicine *head) {
    medicine *temp = head;
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Manufacturer: %s\n", temp->manufacturer);
        printf("Quantity: %d\n", temp->quantity);
        printf("Price: %.2f\n\n", temp->price);
        temp = temp->next;
    }
}

// Main function
int main() {
    // Create a linked list of medicines
    medicine *head = NULL;
    insert_medicine(&head, create_medicine("Paracetamol", "Cipla", 100, 10.0));
    insert_medicine(&head, create_medicine("Ibuprofen", "Advil", 50, 15.0));
    insert_medicine(&head, create_medicine("Amoxicillin", "GlaxoSmithKline", 200, 20.0));

    // Print the details of all medicines
    printf("List of all medicines:\n\n");
    print_medicines(head);

    // Search for a medicine by name
    char name[50];
    printf("\nEnter the name of the medicine you want to search for: ");
    scanf("%s", name);
    medicine *medicine = search_medicine(head, name);
    if (medicine == NULL) {
        printf("Medicine not found.\n");
    } else {
        printf("Medicine found:\n\n");
        print_medicines(medicine);
    }

    // Delete a medicine by name
    printf("\nEnter the name of the medicine you want to delete: ");
    scanf("%s", name);
    delete_medicine(&head, name);

    // Print the details of all medicines after deletion
    printf("\nList of all medicines after deletion:\n\n");
    print_medicines(head);

    return 0;
}