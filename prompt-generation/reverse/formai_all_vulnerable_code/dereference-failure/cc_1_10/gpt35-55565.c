//FormAI DATASET v1.0 Category: Hotel Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct booking {
    int room_number;
    char guest_name[50];
    int days_of_stay;
    float room_cost;
    float total_cost;
};

void add_booking(struct booking *bookings, int num_of_bookings) {
    printf("Enter room number: ");
    scanf("%d", &bookings[num_of_bookings].room_number);
    printf("Enter guest name: ");
    scanf("%s", bookings[num_of_bookings].guest_name);
    printf("Enter days of stay: ");
    scanf("%d", &bookings[num_of_bookings].days_of_stay);
    printf("Enter room cost: ");
    scanf("%f", &bookings[num_of_bookings].room_cost);
    bookings[num_of_bookings].total_cost = bookings[num_of_bookings].days_of_stay * bookings[num_of_bookings].room_cost;
    printf("Booking added successfully!\n");
}

void view_booking(struct booking booking) {
    printf("Room number: %d\n", booking.room_number);
    printf("Guest name: %s\n", booking.guest_name);
    printf("Days of stay: %d\n", booking.days_of_stay);
    printf("Room cost per day: $%.2f\n", booking.room_cost);
    printf("Total cost: $%.2f\n", booking.total_cost);
}

void display_bookings(struct booking *bookings, int num_of_bookings) {
    if (num_of_bookings == 0) {
        printf("There are no bookings yet.\n");
    } else {
        printf("Bookings:\n");
        for (int i = 0; i < num_of_bookings; i++) {
            view_booking(bookings[i]);
        }
    }
}

int main() {
    int num_of_bookings = 0;
    struct booking *bookings = (struct booking*) malloc(sizeof(struct booking) * 10);
    printf("Welcome to C Hotel Management System!\n");

    while (1) {
        printf("\nMain menu:\n");
        printf("1. Add booking\n");
        printf("2. View bookings\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_booking(bookings, num_of_bookings);
            num_of_bookings++;
        } else if (choice == 2) {
            display_bookings(bookings, num_of_bookings);
        } else if (choice == 3) {
            printf("Thank you for using C Hotel Management System!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    free(bookings);
    return 0;
}