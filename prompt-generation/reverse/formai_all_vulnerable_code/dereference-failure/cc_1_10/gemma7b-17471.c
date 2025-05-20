//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Hotel Management System structure
typedef struct hotel_management_system {
    char guest_name[50];
    int room_number;
    char room_type[20];
    int num_days;
    float total_cost;
    struct hotel_management_system* next;
} hotel_management_system;

// Function to insert a new guest into the hotel management system
void insert_guest(hotel_management_system** head) {
    // Allocate memory for the new guest
    hotel_management_system* new_guest = (hotel_management_system*)malloc(sizeof(hotel_management_system));

    // Get the guest's name, room number, room type, number of days, and total cost
    printf("Enter guest name: ");
    scanf("%s", new_guest->guest_name);

    printf("Enter room number: ");
    scanf("%d", &new_guest->room_number);

    printf("Enter room type: ");
    scanf("%s", new_guest->room_type);

    printf("Enter number of days: ");
    scanf("%d", &new_guest->num_days);

    printf("Enter total cost: ");
    scanf("%f", &new_guest->total_cost);

    // Insert the new guest into the linked list
    if (*head == NULL) {
        *head = new_guest;
    } else {
        (*head)->next = new_guest;
        *head = new_guest;
    }
}

// Function to print the guest list
void print_guest_list(hotel_management_system* head) {
    // Traverse the linked list and print each guest's information
    while (head) {
        printf("Guest name: %s\n", head->guest_name);
        printf("Room number: %d\n", head->room_number);
        printf("Room type: %s\n", head->room_type);
        printf("Number of days: %d\n", head->num_days);
        printf("Total cost: %.2f\n", head->total_cost);
        printf("\n");
        head = head->next;
    }
}

int main() {
    // Create a linked list to store the guests
    hotel_management_system* head = NULL;

    // Insert guests into the linked list
    insert_guest(&head);
    insert_guest(&head);
    insert_guest(&head);

    // Print the guest list
    print_guest_list(head);

    return 0;
}