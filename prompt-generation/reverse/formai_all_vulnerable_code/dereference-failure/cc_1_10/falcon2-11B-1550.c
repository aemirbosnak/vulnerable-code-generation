//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hotel {
    char name[50];
    int capacity;
} Hotel;

typedef struct room {
    int id;
    char name[50];
    int price;
} Room;

typedef struct customer {
    char name[50];
    int age;
} Customer;

int main() {
    Hotel* hotels = malloc(sizeof(Hotel) * 3);
    Room* rooms = malloc(sizeof(Room) * 6);
    Customer* customers = malloc(sizeof(Customer) * 2);

    strcpy(hotels[0].name, "Hotel A");
    hotels[0].capacity = 10;

    strcpy(hotels[1].name, "Hotel B");
    hotels[1].capacity = 15;

    strcpy(hotels[2].name, "Hotel C");
    hotels[2].capacity = 12;

    strcpy(rooms[0].name, "Room 1");
    rooms[0].price = 50;

    strcpy(rooms[1].name, "Room 2");
    rooms[1].price = 60;

    strcpy(rooms[2].name, "Room 3");
    rooms[2].price = 70;

    strcpy(rooms[3].name, "Room 4");
    rooms[3].price = 80;

    strcpy(rooms[4].name, "Room 5");
    rooms[4].price = 90;

    strcpy(rooms[5].name, "Room 6");
    rooms[5].price = 100;

    strcpy(customers[0].name, "John");
    customers[0].age = 25;

    strcpy(customers[1].name, "Jane");
    customers[1].age = 30;

    for (int i = 0; i < 3; i++) {
        printf("Hotel %d: %s\n", i+1, hotels[i].name);
    }

    for (int i = 0; i < 6; i++) {
        printf("Room %d: %s ($%d)\n", i+1, rooms[i].name, rooms[i].price);
    }

    for (int i = 0; i < 2; i++) {
        printf("Customer %d: %s (age: %d)\n", i+1, customers[i].name, customers[i].age);
    }

    free(hotels);
    free(rooms);
    free(customers);

    return 0;
}