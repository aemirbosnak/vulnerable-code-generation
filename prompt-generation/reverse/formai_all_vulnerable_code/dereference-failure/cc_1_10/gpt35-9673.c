//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for hotel room */
typedef struct room{
    int roomNum;
    char roomType[20];
    int roomPrice;
    int availability;
}room;

/* Function prototypes */
void addRooms(room **, int);
void printRooms(room **, int);
void bookRoom(room **, int);
void viewBooking(room **, int);
void exitProgram();

int main(){
    int numRooms;
    printf("Welcome to the C Hotel Management System!\n");
    printf("Please enter the number of rooms in the hotel: ");
    scanf("%d", &numRooms);

    /* Allocate memory for rooms */
    room **rooms = malloc(sizeof(room *) * numRooms);
    for(int i = 0; i < numRooms; i++){
        rooms[i] = malloc(sizeof(room));
    }

    addRooms(rooms, numRooms);

    int choice;
    do{
        printf("\n-----------------------\n");
        printf("Please select an option: \n");
        printf("1. View available rooms\n");
        printf("2. Book a room\n");
        printf("3. View booking\n");
        printf("4. Exit\n");
        printf("-----------------------\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printRooms(rooms, numRooms);
                break;
            case 2:
                bookRoom(rooms, numRooms);
                break;
            case 3:
                viewBooking(rooms, numRooms);
                break;
            case 4:
                exitProgram();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }while(choice != 4);

    /* Free allocated memory */
    for(int i = 0; i < numRooms; i++){
        free(rooms[i]);
    }
    free(rooms);

    return 0;
}

/* Function to add initial rooms */
void addRooms(room **rooms, int numRooms){
    for(int i = 0; i < numRooms; i++){
        int roomNum = i+1;
        strcpy(rooms[i]->roomType, "Standard");
        rooms[i]->roomPrice = 500;
        rooms[i]->roomNum = roomNum;
        rooms[i]->availability = 1;
    }
}

/* Function to print available rooms */
void printRooms(room **rooms, int numRooms){
    printf("\n-----------------------\n");
    printf("Available Rooms: \n");
    for(int i = 0; i < numRooms; i++){
        if(rooms[i]->availability == 1){
            printf("Room %d - Type: %s, Price: %d\n", rooms[i]->roomNum, rooms[i]->roomType, rooms[i]->roomPrice);
        }
    }
    printf("-----------------------\n");
}

/* Function to book a room */
void bookRoom(room **rooms, int numRooms){
    int roomNum;
    printf("Please enter the room number you would like to book: ");
    scanf("%d", &roomNum);

    if(roomNum > 0 && roomNum <= numRooms){
        if(rooms[roomNum-1]->availability == 1){
            rooms[roomNum-1]->availability = 0;
            printf("Room %d has been successfully booked!\n", roomNum);
        }
        else{
            printf("Room %d is already booked.\n", roomNum);
        }
    }
    else{
        printf("Invalid room number. Please try again.\n");
    }
}

/* Function to view booking */
void viewBooking(room **rooms, int numRooms){
    int roomNum;
    printf("Please enter the room number for your booking: ");
    scanf("%d", &roomNum);

    if(roomNum > 0 && roomNum <= numRooms){
        if(rooms[roomNum-1]->availability == 0){
            printf("Booking Details for Room %d:\n", roomNum);
            printf("Type: %s\n", rooms[roomNum-1]->roomType);
            printf("Price: %d\n", rooms[roomNum-1]->roomPrice);
        }
        else{
            printf("Room %d has not been booked.\n", roomNum);
        }
    }
    else{
        printf("Invalid room number. Please try again.\n");
    }
}

/* Function to exit program */
void exitProgram(){
    printf("Thank you for using the C Hotel Management System!\n");
    exit(0);
}