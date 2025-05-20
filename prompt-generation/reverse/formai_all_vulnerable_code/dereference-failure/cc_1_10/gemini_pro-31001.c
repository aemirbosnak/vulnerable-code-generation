//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: protected
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
} med;

// Function to create a new node
med *create_node(char *name, char *company, int quantity, float price) {
    med *new_node = (med *)malloc(sizeof(med));
    strcpy(new_node->name, name);
    strcpy(new_node->company, company);
    new_node->quantity = quantity;
    new_node->price = price;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the linked list
med *insert_at_beginning(med *head, med *new_node) {
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to insert a new node at the end of the linked list
med *insert_at_end(med *head, med *new_node) {
    med *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

// Function to insert a new node after a given node
med *insert_after(med *head, med *new_node, med *prev_node) {
    if (prev_node == NULL) {
        return insert_at_beginning(head, new_node);
    }
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    return head;
}

// Function to delete a node from the linked list
med *delete_node(med *head, med *node_to_delete) {
    if (head == node_to_delete) {
        head = head->next;
    } else {
        med *temp = head;
        while (temp->next != node_to_delete) {
            temp = temp->next;
        }
        temp->next = node_to_delete->next;
    }
    free(node_to_delete);
    return head;
}

// Function to search for a node in the linked list
med *search_node(med *head, char *name) {
    med *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to display the linked list
void display_list(med *head) {
    med *temp = head;
    while (temp != NULL) {
        printf("%s %s %d %.2f\n", temp->name, temp->company, temp->quantity, temp->price);
        temp = temp->next;
    }
}

// Main function
int main() {
    // Create a linked list of medicines
    med *head = NULL;
    head = insert_at_end(head, create_node("Paracetamol", "Cipla", 100, 10.0));
    head = insert_at_end(head, create_node("Ibuprofen", "Advil", 50, 15.0));
    head = insert_at_end(head, create_node("Aspirin", "Bayer", 20, 5.0));

    // Display the linked list
    printf("Original linked list:\n");
    display_list(head);

    // Insert a new node at the beginning of the linked list
    head = insert_at_beginning(head, create_node("Acetaminophen", "Tylenol", 75, 12.0));

    // Display the linked list
    printf("Linked list after inserting a node at the beginning:\n");
    display_list(head);

    // Insert a new node at the end of the linked list
    head = insert_at_end(head, create_node("Naproxen", "Aleve", 40, 18.0));

    // Display the linked list
    printf("Linked list after inserting a node at the end:\n");
    display_list(head);

    // Insert a new node after a given node
    med *node_after_which_to_insert = search_node(head, "Ibuprofen");
    head = insert_after(head, create_node("Diclofenac", "Voltaren", 30, 20.0), node_after_which_to_insert);

    // Display the linked list
    printf("Linked list after inserting a node after a given node:\n");
    display_list(head);

    // Delete a node from the linked list
    head = delete_node(head, search_node(head, "Aspirin"));

    // Display the linked list
    printf("Linked list after deleting a node:\n");
    display_list(head);

    // Search for a node in the linked list
    med *node_found = search_node(head, "Paracetamol");
    if (node_found != NULL) {
        printf("Node found: %s\n", node_found->name);
    } else {
        printf("Node not found.\n");
    }

    return 0;
}