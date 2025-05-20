//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Define the Hotel Management System (HMS) structure
typedef struct hms_t {
    char name[50];
    int room_num;
    float price;
    struct hms_t* next;
} hms_t;

// Create a linked list of HMS structures
hms_t* hms_head = NULL;

// Function to insert a new HMS node at the end
void insert_node(char* name, int room_num, float price) {
    hms_t* new_node = (hms_t*)malloc(sizeof(hms_t));
    strcpy(new_node->name, name);
    new_node->room_num = room_num;
    new_node->price = price;
    new_node->next = NULL;

    if (hms_head == NULL) {
        hms_head = new_node;
    } else {
        hms_t* temp = hms_head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to search for a room by number
hms_t* search_room(int room_num) {
    hms_t* current_node = hms_head;
    while (current_node) {
        if (current_node->room_num == room_num) {
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

// Function to update the price of a room
void update_price(int room_num, float new_price) {
    hms_t* current_node = search_room(room_num);
    if (current_node) {
        current_node->price = new_price;
    }
}

// Function to delete a room
void delete_room(int room_num) {
    hms_t* current_node = search_room(room_num);
    if (current_node) {
        hms_t* prev_node = NULL;
        while (current_node->next) {
            prev_node = current_node;
            current_node = current_node->next;
        }
        if (prev_node) {
            prev_node->next = current_node->next;
        } else {
            hms_head = current_node->next;
        }
        free(current_node);
    }
}

// Main function
int main() {
    insert_node("John Doe", 101, 50.0);
    insert_node("Jane Doe", 102, 60.0);
    insert_node("Mike Smith", 103, 70.0);

    hms_t* room = search_room(102);
    if (room) {
        printf("Name: %s\n", room->name);
        printf("Room Number: %d\n", room->room_num);
        printf("Price: %f\n", room->price);
    }

    update_price(101, 65.0);

    room = search_room(101);
    if (room) {
        printf("Name: %s\n", room->name);
        printf("Room Number: %d\n", room->room_num);
        printf("Price: %f\n", room->price);
    }

    delete_room(103);

    room = search_room(103);
    if (room) {
        printf("Name: %s\n", room->name);
        printf("Room Number: %d\n", room->room_num);
        printf("Price: %f\n", room->price);
    }

    return 0;
}