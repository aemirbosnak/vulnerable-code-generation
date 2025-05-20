//FormAI DATASET v1.0 Category: Hotel Management System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[50];
    int room_number;
    char room_type[10];
    int price;
    int availability; // 1 for available, 0 for occupied
}room;

int main() {
    int n=0; // number of rooms in the hotel
    int choice;
    printf("Welcome to C Hotel Management System\n");
    printf("Please enter the number of rooms in the hotel: ");
    scanf("%d",&n);

    room hotel[n]; //array of structures for storing room details

    //initialize the hotel information
    for(int i=0;i<n;i++) {
        strcpy(hotel[i].name,"");
        hotel[i].room_number = i+1;
        strcpy(hotel[i].room_type,"");
        hotel[i].price = 0;
        hotel[i].availability = 1;
    }

    //Hotel Management System Menu
    while(1) { //infinite loop
        printf("\n\n");
        printf("==============================================\n");
        printf("\t\tMENU\n");
        printf("==============================================\n");
        printf("1. View All Rooms\n");
        printf("2. Book a Room\n");
        printf("3. View Customer Records\n");
        printf("4. Quit\n");

        printf("\nEnter your selection: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1: //View all Rooms
                printf("\n\n\t\tHOTEL ROOMS\n");
                printf("=============================================================\n");
                printf("Room No.\tRoom Type\tPrice\tAvailability\n");
                printf("=============================================================\n");
                for(int i=0;i<n;i++) {
                    printf("%d\t\t%s\t%d\t",hotel[i].room_number,hotel[i].room_type,hotel[i].price);
                    if(hotel[i].availability == 1)
                        printf("Available\n");
                    else
                        printf("Occupied\n");
                }
                break;

            case 2: //Book a Room
                printf("\n\n\t\tBOOK A ROOM\n");
                printf("=============================================================\n");
                printf("Room Types\tRoom No.\tPrice\n");
                printf("=============================================================\n");
                printf("Single\t\tS-1\t\t2000\n");
                printf("Double\t\tD-1\t\t3000\n");
                printf("Deluxe\t\tL-1\t\t5000\n");
                printf("\n");

                printf("Enter the Room Type you want to book (Single/Double/Deluxe): ");
                char room_type[10];
                scanf("%s",room_type);

                int found_room=0, room_number=0;
                for(int i=0;i<n;i++) {
                    if(strcmp(hotel[i].room_type,room_type) == 0 && hotel[i].availability == 1) {
                        found_room=1;
                        room_number = hotel[i].room_number;
                        hotel[i].availability = 0; //mark the room as occupied
                        break;
                    }
                }

                if(found_room == 1) {
                    printf("Congratulations, Room %d is booked successfully\n",room_number);
                    printf("What is your name?\n");
                    char name[50];
                    scanf("%s",name);

                    //save customer record
                    strcpy(hotel[room_number-1].name,name);
                    hotel[room_number-1].price = (strcmp(room_type,"Single") == 0) ? 2000 : (strcmp(room_type,"Double") == 0) ? 3000 : 5000;
                } else {
                    printf("Sorry, no %s rooms are available now\n",room_type);
                }
                break;

            case 3: //View Customer Records
                printf("\n\n\t\tCUSTOMER RECORDS\n");
                printf("=============================================================\n");
                printf("Room No.\tName\t\tRoom Type\tPrice\n");
                printf("=============================================================\n");
                for(int i=0;i<n;i++) {
                    if(hotel[i].availability == 0)
                        printf("%d\t\t%s\t\t%s\t\t%d\n",hotel[i].room_number,hotel[i].name,hotel[i].room_type,hotel[i].price);
                }
                break;

            case 4: //Quit
                printf("\nThank you for using C Hotel Management System\n\n");
                exit(0); //exits the program
        }
    }

    return 0;
}