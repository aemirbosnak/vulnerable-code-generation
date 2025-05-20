//FormAI DATASET v1.0 Category: Hotel Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int roomNumber;
    int numDays;
    int totalPrice;
} Booking;

void createBooking(Booking* booking) {
    printf("Enter guest name: ");
    scanf("%s", booking->name);

    printf("Enter room number: ");
    scanf("%d", &booking->roomNumber);

    printf("Enter number of days: ");
    scanf("%d", &booking->numDays);

    booking->totalPrice = booking->numDays * 100;
}

void displayBooking(Booking booking) {
    printf("Guest name: %s\n", booking.name);
    printf("Room number: %d\n", booking.roomNumber);
    printf("Number of days: %d\n", booking.numDays);
    printf("Total price: %d\n", booking.totalPrice);
}

void saveBooking(Booking booking, FILE* file) {
    fprintf(file, "%s,%d,%d,%d\n", booking.name, booking.roomNumber, booking.numDays, booking.totalPrice);
}

void loadBooking(Booking* booking, char* str) {
    char* token = strtok(str, ",");
    strcpy(booking->name, token);

    token = strtok(NULL, ",");
    booking->roomNumber = atoi(token);

    token = strtok(NULL, ",");
    booking->numDays = atoi(token);

    token = strtok(NULL, ",");
    booking->totalPrice = atoi(token);
}

int main() {
    FILE* file = fopen("bookings.txt", "r");

    Booking* bookings = NULL;
    int numBookings = 0;

    if (file != NULL) {
        char buffer[100];

        while (fgets(buffer, 100, file)) {
            numBookings++;
            bookings = realloc(bookings, numBookings * sizeof(Booking));

            loadBooking(&bookings[numBookings - 1], buffer);
        }

        fclose(file);
    }

    int choice;

    do {
        printf("Hotel management system\n");
        printf("-----------------------\n");
        printf("1. Create booking\n");
        printf("2. View bookings\n");
        printf("3. Save bookings\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                numBookings++;
                bookings = realloc(bookings, numBookings * sizeof(Booking));

                createBooking(&bookings[numBookings - 1]);
                break;

            case 2:
                for (int i = 0; i < numBookings; i++) {
                    displayBooking(bookings[i]);
                    printf("-----------------------\n");
                }
                break;

            case 3:
                file = fopen("bookings.txt", "w");

                for (int i = 0; i < numBookings; i++) {
                    saveBooking(bookings[i], file);
                }

                fclose(file);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice, try again\n");
                break;
        }
    } while (choice != 4);

    free(bookings);

    return 0;
}