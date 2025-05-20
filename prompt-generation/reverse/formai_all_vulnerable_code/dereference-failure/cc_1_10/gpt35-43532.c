//FormAI DATASET v1.0 Category: Hotel Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structures to store information
struct Room {
    int roomNo;
    int occupancy;
    int price;
    char availability[10];
};

struct Guest {
    char name[50];
    char phone[20];
    char email[50];
    int roomNo;
};

//Function to display main menu
void displayMainMenu() {
    printf("-------------------------------------------------------------\n");
    printf("\t\tWELCOME TO C HOTEL MANAGEMENT SYSTEM\n");
    printf("-------------------------------------------------------------\n\n");
    printf("\t\tMAIN MENU\n\n");
    printf("1. Add Room\n");
    printf("2. Display Rooms\n");
    printf("3. Book Room\n");
    printf("4. Guest Information\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

//Function to display rooms
void displayRooms(struct Room rooms[], int count) {
    printf("\n-------------------------------------------------------------\n");
    printf("\t\tDISPLAY ROOMS\n");
    printf("-------------------------------------------------------------\n\n");
    printf("Room No\tOccupancy\tPrice\tAvailability\n");
    for(int i=0;i<count;i++) {
        printf("%d\t%d\t\t$%d\t%s\n", rooms[i].roomNo, rooms[i].occupancy, rooms[i].price, rooms[i].availability);
    }
    printf("\n");
}

//Function to add new room to the system
void addRoom(struct Room rooms[], int count) {
    printf("\n-------------------------------------------------------------\n");
    printf("\t\tADD NEW ROOM\n");
    printf("-------------------------------------------------------------\n\n");
    printf("Enter Room No: ");
    scanf("%d", &rooms[count].roomNo);
    printf("Enter Occupancy: ");
    scanf("%d", &rooms[count].occupancy);
    printf("Enter Price: ");
    scanf("%d", &rooms[count].price);
    strcpy(rooms[count].availability, "Available");
    printf("\nNew Room Added Successfully!\n\n");
}

//Function to book a room
void bookRoom(struct Room rooms[], struct Guest guests[], int count1, int count2) {
    int roomNo;
    printf("\n-------------------------------------------------------------\n");
    printf("\t\tBOOK A ROOM\n");
    printf("-------------------------------------------------------------\n\n");
    printf("Enter Room Number to Book: ");
    scanf("%d", &roomNo);
    for(int i=0;i<count1;i++) {
        if(rooms[i].roomNo == roomNo) {
            if(strcmp(rooms[i].availability, "Available") == 0) {
                printf("\nRoom Available!\n");
                printf("\nEnter Guest Name: ");
                scanf("%s", guests[count2].name);
                printf("Enter Phone Number: ");
                scanf("%s", guests[count2].phone);
                printf("Enter Email Address: ");
                scanf("%s", guests[count2].email);
                guests[count2].roomNo = roomNo;
                strcpy(rooms[i].availability, "Booked");
                printf("\nRoom Booked Successfully!\n\n");
            } else {
                printf("\nRoom Already Booked!\n\n");
            }
            break;
        }
        if(i == count1-1) {
            printf("\nRoom Number Not Found!\n\n");
        }
    }
}

//Function to display guest information
void displayGuests(struct Guest guests[], int count) {
    printf("\n-------------------------------------------------------------\n");
    printf("\t\tGUEST INFORMATION\n");
    printf("-------------------------------------------------------------\n\n");
    printf("Name\tPhone\t\tEmail\t\tRoom No\n");
    for(int i=0;i<count;i++) {
        printf("%s\t%s\t%s\t%d\n", guests[i].name, guests[i].phone, guests[i].email, guests[i].roomNo);
    }
    printf("\n");
}

int main() {
    struct Room rooms[50];
    struct Guest guests[50];
    int roomCount = 0;
    int guestCount = 0;
    int choice;
    do {
        displayMainMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addRoom(rooms, roomCount);
                roomCount++;
                break;
            case 2:
                displayRooms(rooms, roomCount);
                break;
            case 3:
                bookRoom(rooms, guests, roomCount, guestCount);
                if(strcmp(rooms[roomCount-1].availability, "Booked") == 0) {
                    guestCount++;
                }
                break;
            case 4:
                displayGuests(guests, guestCount);
                break;
            case 5:
                printf("\nExiting System...\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Please Try Again.\n");
        }
    } while(1);
    return 0;
}