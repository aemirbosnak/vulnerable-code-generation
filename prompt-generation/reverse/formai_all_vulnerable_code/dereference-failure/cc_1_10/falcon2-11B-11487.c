//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct hotel {
    char name[20];
    int capacity;
    int occupancy;
    char* city;
    char* country;
    float price;
    char* type;
};

void print_hotel_info(struct hotel* hotel) {
    printf("Hotel Name: %s\n", hotel->name);
    printf("Capacity: %d\n", hotel->capacity);
    printf("Occupancy: %d\n", hotel->occupancy);
    printf("City: %s\n", hotel->city);
    printf("Country: %s\n", hotel->country);
    printf("Price: $%.2f\n", hotel->price);
    printf("Type: %s\n", hotel->type);
}

void update_occupancy(struct hotel* hotel) {
    int new_occupancy = hotel->occupancy + 1;
    if (new_occupancy > hotel->capacity) {
        printf("Hotel is already full, occupancy cannot be updated.\n");
        return;
    }
    hotel->occupancy = new_occupancy;
    printf("Occupancy updated to %d.\n", hotel->occupancy);
}

int main() {
    struct hotel* hotel1 = malloc(sizeof(struct hotel));
    strcpy(hotel1->name, "Paranoid Hotel");
    hotel1->capacity = 50;
    hotel1->occupancy = 25;
    strcpy(hotel1->city, "Mumbai");
    strcpy(hotel1->country, "India");
    hotel1->price = 1000.00;
    strcpy(hotel1->type, "5-Star");

    printf("Initial Hotel Info:\n");
    print_hotel_info(hotel1);

    update_occupancy(hotel1);

    printf("\nUpdated Hotel Info:\n");
    print_hotel_info(hotel1);

    free(hotel1);
    return 0;
}