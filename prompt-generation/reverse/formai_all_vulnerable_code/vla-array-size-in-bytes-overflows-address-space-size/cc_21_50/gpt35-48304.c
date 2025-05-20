//FormAI DATASET v1.0 Category: Hotel Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the structure for each room in the hotel
typedef struct {
    int roomNumber;
    int floor;
    char roomType[20];
    int numberOfBeds;
    char status[10];
    float price;
} Room;

// Defining the structure for each guest staying in the hotel
typedef struct {
    char name[50];
    char address[100];
    char email[50];
    char phone[20];
    int roomNumber;
} Guest;

// Defining the hotel management system
int main() {
    // Initializing variables
    int i, j, choice, numberOfRooms, numberOfGuests = 0;
    
    // Asking the user for the number of rooms in the hotel
    printf("Enter the number of rooms in the hotel: ");
    scanf("%d", &numberOfRooms);
    
    // Creating an array of rooms based on the user input
    Room hotel[numberOfRooms];
    
    // Initializing the room details for each room
    for(i=0; i<numberOfRooms; i++) {
        hotel[i].roomNumber = i+1;
        if(i < 10) {
            hotel[i].floor = 1;
        } else if(i < 20) {
            hotel[i].floor = 2;
        } else {
            hotel[i].floor = 3;
        }
        
        if(i%3 == 0) {
            strcpy(hotel[i].roomType, "Single");
            hotel[i].numberOfBeds = 1;
        } else if(i%3 == 1) {
            strcpy(hotel[i].roomType, "Double");
            hotel[i].numberOfBeds = 2;
        } else {
            strcpy(hotel[i].roomType, "Suite");
            hotel[i].numberOfBeds = 3;
        }
        
        strcpy(hotel[i].status, "Available");
        hotel[i].price = 100 + (hotel[i].numberOfBeds * 25);
    }
    
    // Creating an array of guests
    Guest guests[50];

    // Displaying the main menu
    printf("\nWelcome to the Hotel Management System!\n");
    printf("Please choose an option: \n");
    printf("1. Check in a guest\n");
    printf("2. Check out a guest\n");
    printf("3. Show available rooms\n");
    printf("4. Show occupied rooms\n");
    printf("5. Show all guests\n");
    printf("6. Exit\n");
    
    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // Checking in a guest
                printf("\nEnter guest details:\n");
                printf("Name: ");
                scanf("%s", guests[numberOfGuests].name);
                printf("Address: ");
                scanf("%s", guests[numberOfGuests].address);
                printf("Email: ");
                scanf("%s", guests[numberOfGuests].email);
                printf("Phone: ");
                scanf("%s", guests[numberOfGuests].phone);
                printf("Enter room number (1-%d): ", numberOfRooms);
                scanf("%d", &guests[numberOfGuests].roomNumber);
                
                if(strcmp(hotel[guests[numberOfGuests].roomNumber-1].status, "Available") == 0) {
                    strcpy(hotel[guests[numberOfGuests].roomNumber-1].status, "Occupied");
                    numberOfGuests++;
                    printf("Guest checked in successfully!\n");
                } else {
                    printf("The room is already occupied. Please choose another room.\n");
                }
                break;
            case 2:
                // Checking out a guest
                printf("\nEnter room number (1-%d): ", numberOfRooms);
                scanf("%d", &choice);
                
                if(strcmp(hotel[choice-1].status, "Occupied") == 0) {
                    for(i=0; i<numberOfGuests; i++) {
                        if(guests[i].roomNumber == choice) {
                            printf("Guest details:\n");
                            printf("Name: %s\n", guests[i].name);
                            printf("Address: %s\n", guests[i].address);
                            printf("Email: %s\n", guests[i].email);
                            printf("Phone: %s\n", guests[i].phone);
                            printf("=====================\n");
                            strcpy(hotel[choice-1].status, "Available");
                            for(j=i; j<numberOfGuests-1; j++) {
                                guests[j] = guests[j+1];
                            }
                            numberOfGuests--;
                            printf("Guest checked out successfully!\n");
                            break;
                        }
                    }
                } else {
                    printf("The room is already available. Please choose an occupied room to check out.\n");
                }
                break;
            case 3:
                // Showing available rooms
                printf("\nAvailable rooms:\n");
                for(i=0; i<numberOfRooms; i++) {
                    if(strcmp(hotel[i].status, "Available") == 0) {
                        printf("Room %d - Type: %s, Beds: %d, Price: %.2f\n", hotel[i].roomNumber, hotel[i].roomType, hotel[i].numberOfBeds, hotel[i].price);
                    }
                }
                break;
            case 4:
                // Showing occupied rooms
                printf("\nOccupied rooms:\n");
                for(i=0; i<numberOfRooms; i++) {
                    if(strcmp(hotel[i].status, "Occupied") == 0) {
                        for(j=0; j<numberOfGuests; j++) {
                            if(guests[j].roomNumber == hotel[i].roomNumber) {
                                printf("%s is staying in Room %d\n", guests[j].name, hotel[i].roomNumber);
                                break;
                            }
                        }
                    }
                }
                break;
            case 5:
                // Showing all guests
                printf("\nAll guests:\n");
                for(i=0; i<numberOfGuests; i++) {
                    printf("%s is staying in Room %d\n", guests[i].name, guests[i].roomNumber);
                }
                break;
            case 6:
                // Exiting the program
                printf("\nThank you for using the Hotel Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}