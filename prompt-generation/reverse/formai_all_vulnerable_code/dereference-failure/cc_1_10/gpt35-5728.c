//FormAI DATASET v1.0 Category: Hotel Management System ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct rooms {
    int roomNum;
    int avail;
    float rate;
    char* guestName;
};
typedef struct rooms Rooms;

void display(Rooms* room, int size) {
    printf("RoomNum\tAvail\tRate\tGuest\n");
    for(int i = 0; i < size; i++) {
        printf("%d\t", room[i].roomNum);
        printf("%d\t", room[i].avail);
        printf("%.2f\t", room[i].rate);
        printf("%s\n", room[i].guestName);
    }
}

void checkIn(Rooms* room, int size) {
    int roomNum;
    char* guestName;
    printf("Enter Room Number: ");
    scanf("%d", &roomNum);

    for(int i = 0; i < size; i++) {
        if(room[i].roomNum == roomNum && room[i].avail == 1) {
            printf("Enter Guest Name: ");
            scanf("%s", guestName);
            room[i].avail = 0;
            strcpy(room[i].guestName, guestName);
            printf("%s has been checked into Room %d\n", guestName, roomNum);
            return;
        }
    }
    printf("Room number entered is either unavailable or invalid\n");
}

void checkOut(Rooms* room, int size) {
    int roomNum;
    printf("Enter Room Number: ");
    scanf("%d", &roomNum);

    for(int i = 0; i < size; i++) {
        if(room[i].roomNum == roomNum && room[i].avail == 0) {
            printf("%s has been checked out of Room %d\n", room[i].guestName, roomNum);
            room[i].avail = 1;
            room[i].guestName = " ";
            return;
        }
    }
    printf("Room number entered is either available or invalid\n");
}

int main() {
    int size;
    printf("Enter number of Rooms: ");
    scanf("%d", &size);

    Rooms* room = (Rooms*)malloc(sizeof(Rooms) * size);

    for(int i = 0; i < size; i++) {
        printf("Enter Room %d Number: ", i+1);
        scanf("%d", &(room + i)->roomNum);

        printf("Enter Room %d Rate: ", i+1);
        scanf("%f", &(room + i)->rate);
        (room + i)->avail = 1;
        (room + i)->guestName = " ";
    }

    int choice;
    do {
        printf("\n");
        printf("*** Hotel Management System Menu ***\n");
        printf("1. Display Rooms\n");
        printf("2. Check-in Guest\n");
        printf("3. Check-out Guest\n");
        printf("4. Quit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display(room, size);
                break;
            case 2:
                checkIn(room, size);
                break;
            case 3:
                checkOut(room, size);
                break;
            case 4:
                printf("Quitting Program...\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    }while(choice != 4);

    free(room);

    return 0;
}