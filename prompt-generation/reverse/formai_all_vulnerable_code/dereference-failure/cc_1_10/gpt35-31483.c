//FormAI DATASET v1.0 Category: Hotel Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct room{
    int num;
    int occupancy;
    int price;
    char *amenities;
    char *status;
} Room;

typedef struct reservation{
    int res_num;
    char *name;
    int room_num;
    int start_date;
    int end_date; 
} Reservation;

Room rooms[10]; // Room array to hold all the rooms in the hotel
Reservation reservations[10]; // Reservation array to hold all the reservations made by guests

void displayAvailableRooms(){
    printf("\n|==========|=============|===============|===========|=========================|============|");
    printf("\n| Room No. | Occupancy   | Price         | Amenities | Status                  |            |");
    printf("\n|==========|=============|===============|===========|=========================|============|");

    for(int i = 0; i < 10; i++){
        if(strcmp(rooms[i].status, "Available") == 0){
            printf("\n| %-8d | %-11d | $%-13d | %-9s | %-24s |            |", rooms[i].num, rooms[i].occupancy, rooms[i].price, rooms[i].amenities, rooms[i].status);
        }
    }
    printf("\n|==========|=============|===============|===========|=========================|============|\n");
}

void displayAllRooms(){
    printf("\n|==========|=============|===============|===========|=========================|============|");
    printf("\n| Room No. | Occupancy   | Price         | Amenities | Status                  |            |");
    printf("\n|==========|=============|===============|===========|=========================|============|");

    for(int i = 0; i < 10; i++){
        printf("\n| %-8d | %-11d | $%-13d | %-9s | %-24s |            |", rooms[i].num, rooms[i].occupancy, rooms[i].price, rooms[i].amenities, rooms[i].status);
    }
    printf("\n|==========|=============|===============|===========|=========================|============|\n");
}

void displayGuestReservations(char *name){
    printf("\n|=======|=================|=========|=============|===========|\n");
    printf("| Res.# | Guest Name     | Room No | Start Date  | End Date  |\n");
    printf("|=======|=================|=========|=============|===========|");

    for(int i = 0; i < 10; i++){
        if(strcmp(reservations[i].name, name) == 0){
            printf("\n| %-5d | %-15s | %-7d | %-11d | %-9d |", reservations[i].res_num, reservations[i].name, reservations[i].room_num, reservations[i].start_date, reservations[i].end_date);
        }
    }
    printf("\n|=======|=================|=========|=============|===========|\n");
}

void makeReservation(char *name, int room_num, int start_date, int end_date){
    int res_num = -1;
    for(int i = 0; i < 10; i++){
        if(reservations[i].res_num == -1){
            res_num = i; // If there is an empty spot in the reservations array, use it
            break;
        }
    }

    if(res_num == -1){ // No empty spots found in reservations array
        printf("\n\nSorry, we are fully booked at the moment.\n");
        return;
    }

    reservations[res_num].res_num = res_num + 1; // Set reservation number 
    reservations[res_num].name = name; // Set guest name
    reservations[res_num].room_num = room_num; // Set chosen room number 
    reservations[res_num].start_date = start_date; // Set check-in date
    reservations[res_num].end_date = end_date; // Set check-out date

    // Update the status of the room being reserved
    for(int i = 0; i < 10; i++){
        if(rooms[i].num == room_num){
            strcpy(rooms[i].status, "Reserved");
            break;
        }
    }

    printf("\n\nReservation made successfully!\n");
}

int main(){
    // Initialize the rooms array
    for(int i = 0; i < 10; i++){
        rooms[i].num = i+1;
        rooms[i].occupancy = 2;
        rooms[i].price = 100;
        rooms[i].amenities = "TV, mini fridge, free Wi-Fi";
        rooms[i].status = "Available";
    }

    // Initialize the reservations array
    for(int i = 0; i < 10; i++){
        reservations[i].res_num = -1;
    }

    // Display available rooms before making a reservation
    displayAvailableRooms();

    // Make a reservation for guest John Smith
    makeReservation("John Smith", 1, 20210701, 20210703);

    // Display all rooms after making a reservation
    displayAllRooms();

    // Display the reservations for guest John Smith
    displayGuestReservations("John Smith");

    return 0;
}