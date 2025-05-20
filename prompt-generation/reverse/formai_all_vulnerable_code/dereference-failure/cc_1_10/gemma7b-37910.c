//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define the hotel management system structure
typedef struct HotelManagementSystem {
    char name[50];
    int rooms;
    double average_rate;
    struct HotelManagementSystem* next;
} HotelManagementSystem;

// Function to insert a hotel management system node
void insert_node(HotelManagementSystem** head, char* name, int rooms, double average_rate) {
    HotelManagementSystem* new_node = (HotelManagementSystem*)malloc(sizeof(HotelManagementSystem));
    strcpy(new_node->name, name);
    new_node->rooms = rooms;
    new_node->average_rate = average_rate;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

// Function to search for a hotel management system node
HotelManagementSystem* search_node(HotelManagementSystem* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update a hotel management system node
void update_node(HotelManagementSystem* head, char* name, int rooms, double average_rate) {
    HotelManagementSystem* node = search_node(head, name);

    if (node) {
        strcpy(node->name, name);
        node->rooms = rooms;
        node->average_rate = average_rate;
    }
}

// Function to delete a hotel management system node
void delete_node(HotelManagementSystem* head, char* name) {
    HotelManagementSystem* node = search_node(head, name);

    if (node) {
        HotelManagementSystem* prev = NULL;

        if (node->next) {
            prev = node->next;
        }

        free(node);

        if (prev) {
            prev->next = NULL;
        } else {
            head = NULL;
        }
    }
}

int main() {
    HotelManagementSystem* head = NULL;

    // Insert some nodes
    insert_node(&head, "The Ritz-Carlton", 500, 500.0);
    insert_node(&head, "The Bellagio", 400, 400.0);
    insert_node(&head, "The Grand Hyatt", 300, 300.0);

    // Search for a node
    HotelManagementSystem* node = search_node(head, "The Bellagio");

    // Update a node
    update_node(head, "The Bellagio", 500, 550.0);

    // Delete a node
    delete_node(head, "The Grand Hyatt");

    // Print the nodes
    for (node = head; node; node = node->next) {
        printf("%s, %d, %f\n", node->name, node->rooms, node->average_rate);
    }

    return 0;
}