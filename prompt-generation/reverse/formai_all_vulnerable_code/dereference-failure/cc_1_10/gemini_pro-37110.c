//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    char company[50];
    int quantity;
    float price;
    struct medicine *next;
} medicine;

// Function to create a new node
medicine *create_node(char *name, char *company, int quantity, float price) {
    medicine *new_node = (medicine *)malloc(sizeof(medicine));
    strcpy(new_node->name, name);
    strcpy(new_node->company, company);
    new_node->quantity = quantity;
    new_node->price = price;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the linked list
medicine *insert_at_beginning(medicine *head, medicine *new_node) {
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to insert a new node at the end of the linked list
medicine *insert_at_end(medicine *head, medicine *new_node) {
    medicine *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

// Function to insert a new node after a given node
medicine *insert_after(medicine *head, medicine *new_node, char *name) {
    medicine *temp = head;
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Medicine not found!\n");
        return head;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

// Function to delete a node from the linked list
medicine *delete_node(medicine *head, char *name) {
    medicine *temp = head;
    medicine *prev = NULL;
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Medicine not found!\n");
        return head;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    return head;
}

// Function to search for a medicine in the linked list
medicine *search_medicine(medicine *head, char *name) {
    medicine *temp = head;
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        temp = temp->next;
    }
    return temp;
}

// Function to display the linked list
void display_list(medicine *head) {
    medicine *temp = head;
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Company: %s\n", temp->company);
        printf("Quantity: %d\n", temp->quantity);
        printf("Price: %.2f\n\n", temp->price);
        temp = temp->next;
    }
}

// Function to calculate the total price of all medicines in the linked list
float calculate_total_price(medicine *head) {
    medicine *temp = head;
    float total_price = 0;
    while (temp != NULL) {
        total_price += temp->quantity * temp->price;
        temp = temp->next;
    }
    return total_price;
}

// Function to generate a report of all medicines in the linked list
void generate_report(medicine *head) {
    medicine *temp = head;
    FILE *fp = fopen("report.txt", "w");
    fprintf(fp, "Medical Store Management System Report\n\n");
    fprintf(fp, "Sr. No.\tName\t\tCompany\t\tQuantity\tPrice\t\tTotal Price\n");
    int i = 1;
    while (temp != NULL) {
        fprintf(fp, "%d\t%s\t\t%s\t\t%d\t%.2f\t\t%.2f\n", i, temp->name, temp->company, temp->quantity, temp->price, temp->quantity * temp->price);
        temp = temp->next;
        i++;
    }
    fprintf(fp, "\nTotal Price: %.2f\n", calculate_total_price(head));
    fclose(fp);
    printf("Report generated successfully!\n");
}

// Main function
int main() {
    // Create a linked list of medicines
    medicine *head = NULL;
    head = insert_at_beginning(head, create_node("Paracetamol", "Cipla", 100, 10.0));
    head = insert_at_end(head, create_node("Ibuprofen", "Advil", 50, 5.0));
    head = insert_after(head, create_node("Amoxicillin", "GlaxoSmithKline", 200, 15.0), "Paracetamol");

    // Display the linked list
    printf("Medicines in the Medical Store:\n");
    display_list(head);

    // Search for a medicine
    medicine *med = search_medicine(head, "Amoxicillin");
    if (med == NULL) {
        printf("Medicine not found!\n");
    } else {
        printf("Medicine found:\n");
        printf("Name: %s\n", med->name);
        printf("Company: %s\n", med->company);
        printf("Quantity: %d\n", med->quantity);
        printf("Price: %.2f\n", med->price);
    }

    // Delete a medicine
    head = delete_node(head, "Ibuprofen");
    printf("Medicines in the Medical Store after deletion:\n");
    display_list(head);

    // Calculate the total price of all medicines
    float total_price = calculate_total_price(head);
    printf("Total price of all medicines: %.2f\n", total_price);

    // Generate a report of all medicines
    generate_report(head);

    return 0;
}