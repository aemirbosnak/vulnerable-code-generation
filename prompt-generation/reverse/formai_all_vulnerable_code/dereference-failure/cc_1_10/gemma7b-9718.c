//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_number;
    int num_days;
    float total_cost;
} Guest;

Guest guests[MAX_GUESTS];

void calculate_cost(Guest *guest) {
    int num_days = guest->num_days;
    float room_rate = 1000; // Assume a room rate of $1000 per night
    guest->total_cost = num_days * room_rate;
}

void check_in(Guest *guest) {
    printf("Welcome, %s! Please select your room number:", guest->name);
    int room_number = atoi(fgets(guest->room_number, 50, stdin));
    guest->room_number = room_number;
}

void check_out(Guest *guest) {
    printf("Thank you for your stay, %s. Please pay your total cost:", guest->name);
    calculate_cost(guest);
    printf("Total cost: $%.2f", guest->total_cost);
}

int main() {
    int num_guests = 0;
    while (num_guests < MAX_GUESTS) {
        Guest *guest = &guests[num_guests];
        printf("Enter your name: ");
        fgets(guest->name, 50, stdin);

        printf("Enter the number of days you will be staying: ");
        guest->num_days = atoi(fgets(guest->num_days, 50, stdin));

        check_in(guest);
        check_out(guest);

        num_guests++;
    }

    return 0;
}