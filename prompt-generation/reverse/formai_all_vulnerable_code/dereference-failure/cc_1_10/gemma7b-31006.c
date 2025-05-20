//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Hotel Management System structure
typedef struct HotelManagementSystem {
    char name[50];
    int room_number;
    float price;
    struct HotelManagementSystem* next;
} HotelManagementSystem;

// Function to insert a new room into the hotel management system
void insert_room(HotelManagementSystem** head) {
    HotelManagementSystem* new_room = (HotelManagementSystem*)malloc(sizeof(HotelManagementSystem));
    printf("Enter the name of the room: ");
    scanf("%s", new_room->name);
    printf("Enter the room number: ");
    scanf("%d", &new_room->room_number);
    printf("Enter the price of the room: ");
    scanf("%f", &new_room->price);

    if (*head == NULL) {
        *head = new_room;
    } else {
        (*head)->next = new_room;
    }
    *head = new_room;
}

// Function to search for a room in the hotel management system
void search_room(HotelManagementSystem* head) {
    char search_name[50];
    int search_number;

    printf("Enter the name of the room: ");
    scanf("%s", search_name);

    printf("Enter the room number: ");
    scanf("%d", &search_number);

    HotelManagementSystem* current_room = head;
    while (current_room) {
        if (strcmp(current_room->name, search_name) == 0 && current_room->room_number == search_number) {
            printf("Room found!\n");
            printf("Name: %s\n", current_room->name);
            printf("Room number: %d\n", current_room->room_number);
            printf("Price: %f\n", current_room->price);
            break;
        }
        current_room = current_room->next;
    }

    if (current_room == NULL) {
        printf("Room not found.\n");
    }
}

// Function to delete a room from the hotel management system
void delete_room(HotelManagementSystem* head) {
    char delete_name[50];
    int delete_number;

    printf("Enter the name of the room: ");
    scanf("%s", delete_name);

    printf("Enter the room number: ");
    scanf("%d", &delete_number);

    HotelManagementSystem* current_room = head;
    HotelManagementSystem* previous_room = NULL;

    while (current_room) {
        if (strcmp(current_room->name, delete_name) == 0 && current_room->room_number == delete_number) {
            if (previous_room) {
                previous_room->next = current_room->next;
            } else {
                head = current_room->next;
            }
            free(current_room);
            break;
        }
        previous_room = current_room;
        current_room = current_room->next;
    }

    if (current_room == NULL) {
        printf("Room not found.\n");
    }
}

int main() {
    HotelManagementSystem* head = NULL;

    // Insert some rooms
    insert_room(&head);
    insert_room(&head);
    insert_room(&head);

    // Search for a room
    search_room(head);

    // Delete a room
    delete_room(head);

    // Search for the room after deletion
    search_room(head);

    return 0;
}