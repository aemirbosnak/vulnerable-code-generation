//FormAI DATASET v1.0 Category: Hotel Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    int roomNumber;
    int capacity;
    int filledCapacity;
    int vacancy;
};

void displayMenu() {
    printf("Welcome to the Post-Apocalyptic C Hotel!\n\n");
    printf("1. Check In\n");
    printf("2. Check Out\n");
    printf("3. View Room Status\n");
    printf("4. Exit\n\n");
}

void checkIn(struct Room *rooms, int size) {
    int i, roomNum, capacity, persons, vacant = 0;
    for(i = 0; i < size; i++) {
        if(rooms[i].vacancy) {
            vacant = 1;
        }
    }
    if(vacant) {
        printf("Please enter the requested room number (1-%d): ", size);
        scanf("%d", &roomNum);
        if(roomNum < 1 || roomNum > size) {
            printf("\nInvalid room number! Please try again.\n\n");
            checkIn(rooms, size);
        } else if(rooms[roomNum-1].vacancy == 0) {
            printf("\nSorry, the room is already occupied.\n\n");
            checkIn(rooms, size);
        } else {
            printf("\nEnter the number of persons staying in the room: ");
            scanf("%d", &persons);
            if(persons > rooms[roomNum-1].capacity) {
                printf("\nSorry, the room capacity is %d persons. Please try another room.\n\n", rooms[roomNum-1].capacity);
                checkIn(rooms, size);
            } else {
                printf("\nChecking In...\n\n");
                rooms[roomNum-1].vacancy = 0;
                rooms[roomNum-1].filledCapacity = persons;
            }
        }
    } else {
        printf("\nSorry, there are no rooms available at the moment. Please check later.\n\n");
    }
}

void checkOut(struct Room *rooms, int size) {
    int i, roomNum, vacancy = 0;
    for(i = 0; i < size; i++) {
        if(rooms[i].vacancy == 0) {
            vacancy = 1;
        }
    }
    if(vacancy) {
        printf("Enter the room number to check out (1-%d): ", size);
        scanf("%d", &roomNum);
        if(roomNum < 1 || roomNum > size) {
            printf("\nInvalid room number! Please try again.\n\n");
            checkOut(rooms, size);
        } else if(rooms[roomNum-1].vacancy == 1) {
            printf("\nThis room is not occupied.\n\n");
            checkOut(rooms, size);
        } else {
            printf("\nChecking Out...\n\n");
            rooms[roomNum-1].vacancy = 1;
            rooms[roomNum-1].filledCapacity = 0;
        }
    } else {
        printf("\nSorry, there are no occupied rooms at the moment.\n\n");
    }
}

void viewRooms(struct Room *rooms, int size) {
    int i;
    printf("\nRoom\tCapacity\tFilled Capacity\tVacancy\n\n");
    for(i = 0; i < size; i++) {
        printf("%d\t%d\t\t%d\t\t", rooms[i].roomNumber, rooms[i].capacity, rooms[i].filledCapacity);
        if(rooms[i].vacancy) {
            printf("Available\n");
        } else {
            printf("Occupied\n");
        }
    }
    printf("\n\n");
}

int main() {
    int size, i;
    printf("Enter the number of rooms in the hotel: ");
    scanf("%d", &size);
    struct Room rooms[size];
    for(i = 0; i < size; i++) {
        rooms[i].vacancy = 1;
        rooms[i].roomNumber = i+1;
        printf("\nEnter the capacity of Room No. %d: ", i+1);
        scanf("%d", &rooms[i].capacity);
    }
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                checkIn(rooms, size);
                break;
            case 2:
                checkOut(rooms, size);
                break;
            case 3:
                viewRooms(rooms, size);
                break;
            case 4:
                printf("\nThank you for staying with us!\n\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n\n");
        }
    } while(choice != 4);
    return 0;
}