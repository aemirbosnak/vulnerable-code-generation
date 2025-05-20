//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a room
typedef struct room {
    char room_number[5];
    char room_type[20];
    int available;
    int price;
    struct room* next;
} room;

// Define the structure of a customer
typedef struct customer {
    char name[20];
    char address[100];
    char phone_number[20];
    char email[50];
    struct customer* next;
} customer;

// Create a linked list of rooms
room* create_room_list() {
    room* head = NULL;
    room* new_room = malloc(sizeof(room));
    new_room->available = 1;
    strcpy(new_room->room_number, "101");
    strcpy(new_room->room_type, "Standard");
    new_room->price = 5000;
    new_room->next = NULL;
    head = new_room;
    return head;
}

// Create a linked list of customers
customer* create_customer_list() {
    customer* head = NULL;
    customer* new_customer = malloc(sizeof(customer));
    strcpy(new_customer->name, "John Doe");
    strcpy(new_customer->address, "123 Main St.");
    strcpy(new_customer->phone_number, "555-123-4567");
    strcpy(new_customer->email, "john.doe@example.com");
    new_customer->next = NULL;
    head = new_customer;
    return head;
}

// Book a room
void book_room(room* head, customer* head_customer) {
    char room_number[5];
    printf("Enter the room number: ");
    scanf("%s", room_number);

    room* current_room = head;
    while (current_room) {
        if (strcmp(room_number, current_room->room_number) == 0) {
            if (current_room->available) {
                current_room->available = 0;
                customer* new_customer = create_customer_list();
                new_customer->next = head_customer;
                head_customer = new_customer;
                printf("Room booked successfully!\n");
            } else {
                printf("Room is not available.\n");
            }
            break;
        }
        current_room = current_room->next;
    }

    if (current_room == NULL) {
        printf("Room not found.\n");
    }
}

int main() {
    room* head_room = create_room_list();
    customer* head_customer = create_customer_list();

    book_room(head_room, head_customer);

    return 0;
}