//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records that can be stored
#define MAX_RECORDS 100

// Define the structure of a record
typedef struct {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int quantity;
    float price;
} record;

// Define the structure of a node in the linked list
typedef struct node {
    record data;
    struct node *next;
} node;

// Define the head of the linked list
node *head = NULL;

// Function to create a new record
record* create_record(char *name, char *address, char *phone, char *email, int quantity, float price) {
    record *new_record = (record*)malloc(sizeof(record));
    strcpy(new_record->name, name);
    strcpy(new_record->address, address);
    strcpy(new_record->phone, phone);
    strcpy(new_record->email, email);
    new_record->quantity = quantity;
    new_record->price = price;
    return new_record;
}

// Function to insert a new record into the linked list
void insert_record(record *new_record) {
    // If the linked list is empty, set the head to the new record
    if (head == NULL) {
        head = new_record;
        return;
    }

    // Otherwise, traverse the linked list until we find the last node
    node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Set the next pointer of the last node to the new record
    current->next = new_record;
}

// Function to search for a record by name
record* search_record(char *name) {
    // Traverse the linked list until we find the record with the matching name
    node *current = head;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            return &current->data;
        }
        current = current->next;
    }

    // If the record is not found, return NULL
    return NULL;
}

// Function to delete a record by name
void delete_record(char *name) {
    // If the linked list is empty, return
    if (head == NULL) {
        return;
    }

    // If the first record matches the name, set the head to the next record
    if (strcmp(head->data.name, name) == 0) {
        head = head->next;
        return;
    }

    // Otherwise, traverse the linked list until we find the record with the matching name
    node *current = head;
    while (current->next != NULL) {
        if (strcmp(current->next->data.name, name) == 0) {
            // If the record is found, set the next pointer of the previous node to the next node of the record to be deleted
            current->next = current->next->next;
            return;
        }
        current = current->next;
    }
}

// Function to print the records in the linked list
void print_records() {
    // Traverse the linked list and print each record
    node *current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->data.name);
        printf("Address: %s\n", current->data.address);
        printf("Phone: %s\n", current->data.phone);
        printf("Email: %s\n", current->data.email);
        printf("Quantity: %d\n", current->data.quantity);
        printf("Price: %.2f\n\n", current->data.price);
        current = current->next;
    }
}

// Function to get the total value of the records in the linked list
float get_total_value() {
    // Traverse the linked list and calculate the total value of the records
    node *current = head;
    float total_value = 0.0;
    while (current != NULL) {
        total_value += current->data.quantity * current->data.price;
        current = current->next;
    }
    return total_value;
}

// Main function
int main() {
    // Create a new record
    record *new_record = create_record("John Smith", "123 Main Street", "555-1212", "john.smith@example.com", 10, 10.0);

    // Insert the new record into the linked list
    insert_record(new_record);

    // Search for the record by name
    record *found_record = search_record("John Smith");

    // If the record was found, print its details
    if (found_record != NULL) {
        printf("Name: %s\n", found_record->name);
        printf("Address: %s\n", found_record->address);
        printf("Phone: %s\n", found_record->phone);
        printf("Email: %s\n", found_record->email);
        printf("Quantity: %d\n", found_record->quantity);
        printf("Price: %.2f\n", found_record->price);
    } else {
        printf("Record not found.\n");
    }

    // Delete the record by name
    delete_record("John Smith");

    // Print the records in the linked list
    print_records();

    // Get the total value of the records in the linked list
    float total_value = get_total_value();

    // Print the total value
    printf("Total value: %.2f\n", total_value);

    return 0;
}