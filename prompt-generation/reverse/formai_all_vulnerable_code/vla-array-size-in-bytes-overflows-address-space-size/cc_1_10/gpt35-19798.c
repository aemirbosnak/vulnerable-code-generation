//FormAI DATASET v1.0 Category: Hotel Management System ; Style: statistical
#include <stdio.h>
#include <string.h>

// define a structure for each hotel room
struct hotel_room {
    int room_number;
    char guest_name[50];
    int days_reserved;
    float price_per_day;
};

// function to determine the total price for a reservation
float calculate_price(int days_reserved, float price_per_day) {
    return days_reserved * price_per_day;
}

int main() {
    int num_rooms; // number of hotel rooms
    printf("Enter the number of hotel rooms: ");
    scanf("%d", &num_rooms);
    
    struct hotel_room rooms[num_rooms]; // array of hotel rooms
    
    // loop to get information for each room
    for (int i = 0; i < num_rooms; i++) {
        printf("\nRoom %d:", i+1);
        printf("\nEnter the room number: ");
        scanf("%d", &rooms[i].room_number);
        
        printf("Enter the guest name: ");
        scanf("%s", &rooms[i].guest_name);
        
        printf("Enter the number of days reserved: ");
        scanf("%d", &rooms[i].days_reserved);
        
        printf("Enter the price per day: $");
        scanf("%f", &rooms[i].price_per_day);
    }
    
    // print a summary of all the reservations
    printf("\nHotel Room Reservations:\n");
    printf("=========================\n");
    float total_sales = 0.0; // variable to keep track of total sales
    for (int i = 0; i < num_rooms; i++) {
        printf("\nRoom %d:\n", rooms[i].room_number);
        printf("Guest Name: %s\n", rooms[i].guest_name);
        printf("Days reserved: %d\n", rooms[i].days_reserved);
        printf("Price per day: $%.2f\n", rooms[i].price_per_day);
        float room_sales = calculate_price(rooms[i].days_reserved, rooms[i].price_per_day);
        printf("Total price: $%.2f\n", room_sales);
        total_sales += room_sales;
    }
    printf("\nTotal sales: $%.2f\n", total_sales);
    
    return 0;
}