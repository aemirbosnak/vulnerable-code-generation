//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of guests
#define MAX_GUESTS 10

// Define the guest structure
typedef struct guest {
    char name[50];
    int room_number;
    int num_days;
    struct guest* next;
} guest;

// Create a linked list of guests
guest* head = NULL;

// Function to insert a guest into the linked list
void insert_guest(char* name, int room_number, int num_days) {
    guest* new_guest = (guest*)malloc(sizeof(guest));
    strcpy(new_guest->name, name);
    new_guest->room_number = room_number;
    new_guest->num_days = num_days;
    new_guest->next = NULL;

    if (head == NULL) {
        head = new_guest;
    } else {
        guest* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_guest;
    }
}

// Function to find a guest by name
guest* find_guest(char* name) {
    guest* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to calculate the total cost of a guest's stay
int calculate_cost(guest* guest) {
    int cost = guest->num_days * 50;
    return cost;
}

// Function to check if a room is available
int is_room_available(int room_number) {
    guest* temp = head;
    while (temp) {
        if (temp->room_number == room_number) {
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

// Main function
int main() {
    // Insert some guests
    insert_guest("John Doe", 101, 3);
    insert_guest("Jane Doe", 102, 2);
    insert_guest("Peter Pan", 103, 4);

    // Find a guest by name
    guest* guest = find_guest("John Doe");

    // Calculate the total cost of the guest's stay
    int cost = calculate_cost(guest);

    // Print the cost
    printf("The total cost of John Doe's stay is $%d.\n", cost);

    // Check if a room is available
    if (is_room_available(102)) {
        printf("Room 102 is available.\n");
    }

    return 0;
}