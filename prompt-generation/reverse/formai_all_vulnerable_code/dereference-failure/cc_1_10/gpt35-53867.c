//FormAI DATASET v1.0 Category: Hotel Management System ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to display the main menu
void displayMenu()
{
    printf("\n---------------------\n");
    printf("Welcome to C Hotel Management System\n");
    printf("---------------------\n");
    printf("1. Check-in\n");
    printf("2. Check-out\n");
    printf("3. Room service\n");
    printf("4. View bill\n");
    printf("5. Exit\n");
}

// Structure to store guest details
struct Guest
{
    char name[50];
    char address[100];
    int roomNo;
    int daysStayed;
    int roomServiceCharges;
    int totalBill;
};

// Function to check in a guest
void checkIn(struct Guest *guests, int *roomOccupancy)
{
    int i, room;

    // Find a vacant room
    for(i = 0; i < 10; i++)
    {
        if(roomOccupancy[i] == 0)
        {
            room = i+1;
            roomOccupancy[i] = 1;
            break;
        }
    }

    // Store guest details
    printf("\nEnter guest name: ");
    scanf("%s", guests[room-1].name);
    printf("Enter guest address: ");
    scanf("%s", guests[room-1].address);
    guests[room-1].roomNo = room;
    printf("Enter number of days to stay: ");
    scanf("%d", &guests[room-1].daysStayed);

    printf("\nGuest checked in successfully. Room number: %d\n", room);
}

// Function to check out a guest
void checkOut(struct Guest *guests, int *roomOccupancy)
{
    int room;

    // Get room number
    printf("\nEnter room number: ");
    scanf("%d", &room);

    // Check if room is occupied
    if(roomOccupancy[room-1] == 0)
    {
        printf("\nRoom is not occupied.\n");
        return;
    }

    // Calculate total bill
    guests[room-1].totalBill = guests[room-1].daysStayed * 1000 + guests[room-1].roomServiceCharges;

    // Display bill
    printf("\nGuest details:\n");
    printf("Name: %s\n", guests[room-1].name);
    printf("Address: %s\n", guests[room-1].address);
    printf("Room number: %d\n", guests[room-1].roomNo);
    printf("Number of days stayed: %d\n", guests[room-1].daysStayed);
    printf("Room service charges: %d\n", guests[room-1].roomServiceCharges);
    printf("Total bill: %d\n", guests[room-1].totalBill);

    // Mark room as vacant
    roomOccupancy[room-1] = 0;
}

// Function to order room service
void roomService(struct Guest *guests)
{
    int room, charges;

    // Get room number and room service charges
    printf("\nEnter room number: ");
    scanf("%d", &room);
    printf("Enter room service charges: ");
    scanf("%d", &charges);

    // Add room service charges to guest's bill
    guests[room-1].roomServiceCharges += charges;

    printf("\nRoom service charges added successfully.\n");
}

int main()
{
    int i, choice;
    int roomOccupancy[10] = {0};
    struct Guest guests[10];

    while(1)
    {
        // Display main menu
        displayMenu();

        // Get user choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                checkIn(guests, roomOccupancy);
                break;

            case 2:
                checkOut(guests, roomOccupancy);
                break;

            case 3:
                roomService(guests);
                break;

            case 4:
                // Display bills
                printf("\n--------------\n");
                printf("View bills\n");
                printf("--------------\n");
                for(i = 0; i < 10; i++)
                {
                    if(roomOccupancy[i] == 1)
                    {
                        printf("\nGuest details:\n");
                        printf("Name: %s\n", guests[i].name);
                        printf("Address: %s\n", guests[i].address);
                        printf("Room number: %d\n", guests[i].roomNo);
                        printf("Number of days stayed: %d\n", guests[i].daysStayed);
                        printf("Room service charges: %d\n", guests[i].roomServiceCharges);
                        printf("Total bill: %d\n", guests[i].totalBill);
                    }
                }
                break;

            case 5:
                // Exit program
                printf("\nThank you for using C Hotel Management System\n");
                exit(0);

            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }
    return 0;
}