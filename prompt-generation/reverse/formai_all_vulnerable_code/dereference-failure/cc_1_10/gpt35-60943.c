//FormAI DATASET v1.0 Category: Hotel Management System ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct room {
    int id;
    char type[20];
    float price;
    int availability;
};

void displayMenu() {
    printf("------- Hotel Management System Menu -------\n");
    printf("1. Add Room\n");
    printf("2. Remove Room\n");
    printf("3. Display Rooms\n");
    printf("4. Book Room\n");
    printf("5. Exit\n");
    printf("--------------------------------------------\n");
}

void addRoom(struct room *rooms, int *totalRooms) {
    char type[20];
    float price;
    int availability;
    
    printf("Enter room type: ");
    scanf("%s", type);
    printf("Enter room price: ");
    scanf("%f", &price);
    printf("Enter room availability (1 for available, 0 for not available): ");
    scanf("%d", &availability);
    
    (*totalRooms)++;
    rooms = (struct room*) realloc(rooms, (*totalRooms) * sizeof(struct room));
    rooms[*totalRooms-1].id = *totalRooms;
    strcpy(rooms[*totalRooms-1].type, type);
    rooms[*totalRooms-1].price = price;
    rooms[*totalRooms-1].availability = availability;
    
    printf("Room added successfully!\n");
}

void removeRoom(struct room *rooms, int *totalRooms) {
    int id;
    
    printf("Enter the room ID you want to remove: ");
    scanf("%d", &id);
    
    for(int i=0; i<*totalRooms; i++) {
        if(rooms[i].id == id) {
            for(int j=i; j<*totalRooms-1; j++) {
                rooms[j] = rooms[j+1];
            }
            (*totalRooms)--;
            rooms = (struct room*) realloc(rooms, (*totalRooms) * sizeof(struct room));
            printf("Room removed successfully!\n");
            return;
        }
    }
    
    printf("Room not found!\n");
}

void displayRooms(struct room *rooms, int totalRooms) {
    if(totalRooms == 0) {
        printf("No rooms found!\n");
        return;
    }
    
    printf("ID\tType\tPrice\tAvailability\n");
    for(int i=0; i<totalRooms; i++) {
        printf("%d\t%s\t%.2f\t%s\n", rooms[i].id, rooms[i].type, rooms[i].price, rooms[i].availability == 1 ? "Available" : "Not Available");
    }
}

void bookRoom(struct room *rooms, int totalRooms) {
    int id;
    
    printf("Enter the room ID you want to book: ");
    scanf("%d", &id);
    
    for(int i=0; i<totalRooms; i++) {
        if(rooms[i].id == id) {
            if(rooms[i].availability == 1) {
                rooms[i].availability = 0;
                printf("Room booked successfully!\n");
            }
            else {
                printf("Selected room is not available!\n");
            }
            return;
        }
    }
    
    printf("Room not found!\n");
}

int main() {
    struct room *rooms = NULL;
    int totalRooms = 0;
    
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addRoom(rooms, &totalRooms);
                break;
            case 2:
                removeRoom(rooms, &totalRooms);
                break;
            case 3:
                displayRooms(rooms, totalRooms);
                break;
            case 4:
                bookRoom(rooms, totalRooms);
                break;
            case 5:
                printf("Exiting Hotel Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}