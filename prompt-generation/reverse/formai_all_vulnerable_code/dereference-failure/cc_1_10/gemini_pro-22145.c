//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the structure of a medicine
typedef struct medicine {
    char name[50];
    char company[50];
    float price;
    int quantity;
} medicine;

// Declare the structure of a node in the linked list
typedef struct node {
    medicine data;
    struct node *next;
} node;

// Declare the head of the linked list
node *head = NULL;

// Function to insert a medicine at the end of the linked list
void insertMedicine(medicine m) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = m;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to delete a medicine from the linked list
void deleteMedicine(char *name) {
    node *temp = head;
    node *prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Function to search for a medicine in the linked list
medicine *searchMedicine(char *name) {
    node *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            return &temp->data;
        }
        temp = temp->next;
    }

    return NULL;
}

// Function to display the list of medicines
void displayMedicines() {
    node *temp = head;

    while (temp != NULL) {
        printf("Name: %s\n", temp->data.name);
        printf("Company: %s\n", temp->data.company);
        printf("Price: %f\n", temp->data.price);
        printf("Quantity: %d\n\n", temp->data.quantity);
        temp = temp->next;
    }
}

// Main function
int main() {
    // Insert some medicines into the linked list
    medicine m1 = {"Paracetamol", "Cipla", 10.0, 100};
    insertMedicine(m1);
    
    medicine m2 = {"Ibuprofen", "Advil", 15.0, 50};
    insertMedicine(m2);

    medicine m3 = {"Aspirin", "Bayer", 20.0, 25};
    insertMedicine(m3);

    // Delete a medicine from the linked list
    deleteMedicine("Ibuprofen");

    // Search for a medicine in the linked list
    medicine *m = searchMedicine("Paracetamol");
    if (m != NULL) {
        printf("Medicine found!\n");
        printf("Name: %s\n", m->name);
        printf("Company: %s\n", m->company);
        printf("Price: %f\n", m->price);
        printf("Quantity: %d\n", m->quantity);
    } else {
        printf("Medicine not found!\n");
    }

    // Display the list of medicines
    printf("\nList of Medicines:\n");
    displayMedicines();

    return 0;
}