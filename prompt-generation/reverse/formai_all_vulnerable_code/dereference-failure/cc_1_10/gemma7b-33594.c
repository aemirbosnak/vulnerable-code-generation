//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the hotel management system structure
typedef struct HotelManagementSystem {
    char guest_name[50];
    int room_number;
    char room_type[50];
    int num_days;
    double total_cost;
} HotelManagementSystem;

// Function to create a new hotel management system record
HotelManagementSystem* create_hotel_management_system_record() {
    HotelManagementSystem* hms = (HotelManagementSystem*)malloc(sizeof(HotelManagementSystem));
    hms->guest_name[0] = '\0';
    hms->room_number = 0;
    hms->room_type[0] = '\0';
    hms->num_days = 0;
    hms->total_cost = 0.0;
    return hms;
}

// Function to add a guest to the hotel management system
void add_guest(HotelManagementSystem* hms) {
    printf("Enter your name: ");
    scanf("%s", hms->guest_name);

    printf("Enter your room number: ");
    scanf("%d", &hms->room_number);

    printf("Enter your room type: ");
    scanf("%s", hms->room_type);

    printf("Enter the number of days you will be staying: ");
    scanf("%d", &hms->num_days);
}

// Function to calculate the total cost of a guest's stay
double calculate_total_cost(HotelManagementSystem* hms) {
    double cost_per_night = 0.0;

    // Calculate the cost per night based on the room type
    if (strcmp(hms->room_type, "Standard") == 0) {
        cost_per_night = 50.0;
    } else if (strcmp(hms->room_type, "Deluxe") == 0) {
        cost_per_night = 75.0;
    } else if (strcmp(hms->room_type, "Suite") == 0) {
        cost_per_night = 100.0;
    }

    // Calculate the total cost
    hms->total_cost = cost_per_night * hms->num_days;

    return hms->total_cost;
}

// Function to display the hotel management system record
void display_hotel_management_system_record(HotelManagementSystem* hms) {
    printf("Guest Name: %s\n", hms->guest_name);
    printf("Room Number: %d\n", hms->room_number);
    printf("Room Type: %s\n", hms->room_type);
    printf("Number of Days: %d\n", hms->num_days);
    printf("Total Cost: %.2lf\n", hms->total_cost);
}

int main() {
    HotelManagementSystem* hms = create_hotel_management_system_record();
    add_guest(hms);
    calculate_total_cost(hms);
    display_hotel_management_system_record(hms);

    return 0;
}