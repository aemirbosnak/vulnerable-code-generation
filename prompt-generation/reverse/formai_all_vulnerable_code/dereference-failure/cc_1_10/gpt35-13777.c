//FormAI DATASET v1.0 Category: Hotel Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
    char room_number[10];
    char room_type[20];
    int occupancy;
    int price;
    struct room *next;
};

struct room *room_list;

void add_room() {
    struct room *new_room;
    new_room = (struct room*)malloc(sizeof(struct room));
    printf("Enter Room Number: ");
    scanf("%s", new_room -> room_number);
    printf("Enter Room Type: ");
    scanf("%s", new_room -> room_type);
    printf("Enter Room Occupancy: ");
    scanf("%d", &(new_room -> occupancy));
    printf("Enter Room Price: ");
    scanf("%d", &(new_room -> price));
    new_room -> next = room_list;
    room_list = new_room;
    printf("Room successfully added.\n\n");
}

void display_room(struct room *ptr) {
    printf("\n");
    printf("Room Number: %s\n", ptr -> room_number);
    printf("Room Type: %s\n", ptr -> room_type);
    printf("Occupancy: %d\n", ptr -> occupancy);
    printf("Price: %d\n", ptr -> price);
    printf("\n");
}

void display_all_rooms() {
    struct room *ptr;
    ptr = room_list;
    if(ptr == NULL) {
        printf("No rooms available.\n\n");
    } else {
        printf("Rooms available:\n");
        while(ptr != NULL) {
            display_room(ptr);
            ptr = ptr -> next;
        }
    }
}

void remove_room() {
    char room_number[10];
    struct room *ptr, *prev;
    ptr = room_list;
    prev = NULL;
    if(ptr == NULL) {
        printf("No rooms available to remove.\n\n");
    } else {
        printf("Enter Room Number to remove: ");
        scanf("%s", room_number);
        while(ptr != NULL) {
            if(strcmp(ptr -> room_number, room_number) == 0) {
                if(prev == NULL) {
                    room_list = ptr -> next;
                } else {
                    prev -> next = ptr -> next;
                }
                free(ptr);
                printf("Room removed successfully.\n\n");
                return;
            }
            prev = ptr;
            ptr = ptr -> next;
        }
        printf("Room with Room Number %s not found.\n\n", room_number);
    }
}

void search_room() {
    char room_number[10];
    struct room *ptr;
    ptr = room_list;
    if(ptr == NULL) {
        printf("No rooms available.\n\n");
    } else {
        printf("Enter Room Number to search: ");
        scanf("%s", room_number);
        while(ptr != NULL) {
            if(strcmp(ptr -> room_number, room_number) == 0) {
                display_room(ptr);
                return;
            }
            ptr = ptr -> next;
        }
        printf("Room with Room Number %s not found.\n\n", room_number);
    }
}

int main() {
    int option;
    while(1) {
        printf("Welcome to C Hotel Management System!\n\n");
        printf("Please select an option:\n");
        printf("1. Add Room\n");
        printf("2. Display All Rooms\n");
        printf("3. Remove Room\n");
        printf("4. Search Room\n");
        printf("5. Exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_room();
                break;
            case 2:
                display_all_rooms();
                break;
            case 3:
                remove_room();
                break;
            case 4:
                search_room();
                break;
            case 5:
                printf("Thank you for using C Hotel Management System!\n\n");
                exit(0);
            default:
                printf("Invalid option!\n\n");
        }
    }
    return 0;
}