//FormAI DATASET v1.0 Category: Hotel Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

struct room {
    int roomNumber;
    char guestName[50];
    float rate;
    int daysOfStay;
    float totalAmount;
    int checkoutDate;
    int isCheckedOut;
};

// Function to check if a room is available
int isRoomAvailable(struct room* ptr, int roomNumber, int totalRooms) {
    int i, count = 0;
    for(i = 0; i < totalRooms; i++) {
        if(ptr[i].roomNumber == roomNumber && ptr[i].isCheckedOut == 0) {
            count++;
        }
    }
    if(count == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to display room details
void displayRooms(struct room* ptr, int totalRooms) {
    int i;
    printf("Room No.\tGuest Name\tRate\tDays\tTotal\tCO Date\n");
    for(i = 0; i < totalRooms; i++) {
        printf("%d\t\t%s\t\t%f\t%d\t%f\t%d\n", ptr[i].roomNumber, ptr[i].guestName, ptr[i].rate, ptr[i].daysOfStay, ptr[i].totalAmount, ptr[i].checkoutDate);
    }
}

int main() {
    int totalRooms = 10, choice, roomNumber, i, count = 0;
    float rate;
    struct room* ptr;
    ptr = (struct room*) malloc(totalRooms * sizeof(struct room));
    
    // Initialize room details
    for(i = 0; i < totalRooms; i++) {
        ptr[i].roomNumber = i + 101;
        ptr[i].guestName[0] = '\0';
        ptr[i].rate = 2000.0;
        ptr[i].daysOfStay = 0;
        ptr[i].totalAmount = 0.0;
        ptr[i].checkoutDate = 0;
        ptr[i].isCheckedOut = 0;
    }
    
    do {
        printf("\n");
        printf("1. Book a room\n");
        printf("2. Check out a room\n");
        printf("3. Display room details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Book a room
                printf("Enter the room number (101 to 110): ");
                scanf("%d", &roomNumber);
                if(isRoomAvailable(ptr, roomNumber, totalRooms)) {
                    for(i = 0; i < totalRooms; i++) {
                        if(ptr[i].roomNumber == roomNumber) {
                            printf("Enter guest name: ");
                            scanf("%s", ptr[i].guestName);
                            printf("Enter number of days of stay: ");
                            scanf("%d", &ptr[i].daysOfStay);
                            ptr[i].totalAmount = ptr[i].rate * ptr[i].daysOfStay;
                            count++;
                        }
                    }
                } else {
                    printf("Room is already booked.\n");
                }
                break;
            case 2:
                // Check out a room
                printf("Enter the room number (101 to 110): ");
                scanf("%d", &roomNumber);
                for(i = 0; i < totalRooms; i++) {
                    if(ptr[i].roomNumber == roomNumber && ptr[i].isCheckedOut == 0) {
                        printf("Total Amount: %f\n", ptr[i].totalAmount);
                        printf("Enter checkout date (yyyymmdd): ");
                        scanf("%d", &ptr[i].checkoutDate);
                        ptr[i].isCheckedOut = 1;
                    }
                }
                break;
            case 3:
                // Display room details
                displayRooms(ptr, totalRooms);
                break;
            case 4:
                // Exit
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);
    
    printf("Thanks for using the hotel management system!\n");
    return 0;
}