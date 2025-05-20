//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Guest {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int roomNumber;
    int daysStaying;
    float billAmount;
};

struct Hotel {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int numRooms;
    int numGuests;
    struct Guest *guests;
};

void createHotel(struct Hotel *hotel) {
    printf("Enter hotel name: ");
    scanf("%s", hotel->name);
    printf("Enter hotel address: ");
    scanf("%s", hotel->address);
    printf("Enter hotel phone number: ");
    scanf("%s", hotel->phone);
    printf("Enter hotel email address: ");
    scanf("%s", hotel->email);
    printf("Enter number of rooms: ");
    scanf("%d", &hotel->numRooms);
    hotel->guests = (struct Guest *)malloc(sizeof(struct Guest) * hotel->numRooms);
    hotel->numGuests = 0;
}

void addGuest(struct Hotel *hotel) {
    if (hotel->numGuests == hotel->numRooms) {
        printf("Error: Hotel is full!\n");
        return;
    }
    struct Guest *guest = &hotel->guests[hotel->numGuests];
    printf("Enter guest name: ");
    scanf("%s", guest->name);
    printf("Enter guest address: ");
    scanf("%s", guest->address);
    printf("Enter guest phone number: ");
    scanf("%s", guest->phone);
    printf("Enter guest email address: ");
    scanf("%s", guest->email);
    printf("Enter guest room number: ");
    scanf("%d", &guest->roomNumber);
    printf("Enter number of days staying: ");
    scanf("%d", &guest->daysStaying);
    guest->billAmount = 0.0;
    hotel->numGuests++;
}

void removeGuest(struct Hotel *hotel, int roomNumber) {
    int i;
    for (i = 0; i < hotel->numGuests; i++) {
        if (hotel->guests[i].roomNumber == roomNumber) {
            for (int j = i; j < hotel->numGuests - 1; j++) {
                hotel->guests[j] = hotel->guests[j + 1];
            }
            hotel->numGuests--;
            return;
        }
    }
    printf("Error: Guest not found!\n");
}

void printGuests(struct Hotel *hotel) {
    int i;
    printf("Guests:\n");
    for (i = 0; i < hotel->numGuests; i++) {
        printf("Name: %s\n", hotel->guests[i].name);
        printf("Address: %s\n", hotel->guests[i].address);
        printf("Phone: %s\n", hotel->guests[i].phone);
        printf("Email: %s\n", hotel->guests[i].email);
        printf("Room Number: %d\n", hotel->guests[i].roomNumber);
        printf("Days Staying: %d\n", hotel->guests[i].daysStaying);
        printf("Bill Amount: %.2f\n\n", hotel->guests[i].billAmount);
    }
}

void calculateBill(struct Hotel *hotel, int roomNumber, float amount) {
    int i;
    for (i = 0; i < hotel->numGuests; i++) {
        if (hotel->guests[i].roomNumber == roomNumber) {
            hotel->guests[i].billAmount += amount;
            return;
        }
    }
    printf("Error: Guest not found!\n");
}

void printBill(struct Hotel *hotel, int roomNumber) {
    int i;
    for (i = 0; i < hotel->numGuests; i++) {
        if (hotel->guests[i].roomNumber == roomNumber) {
            printf("Guest Name: %s\n", hotel->guests[i].name);
            printf("Room Number: %d\n", hotel->guests[i].roomNumber);
            printf("Bill Amount: %.2f\n", hotel->guests[i].billAmount);
            return;
        }
    }
    printf("Error: Guest not found!\n");
}

int main() {
    struct Hotel hotel;
    int choice;
    int roomNumber;
    float amount;

    createHotel(&hotel);

    while (1) {
        printf("\n1. Add Guest\n2. Remove Guest\n3. Print Guests\n4. Calculate Bill\n5. Print Bill\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGuest(&hotel);
                break;
            case 2:
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                removeGuest(&hotel, roomNumber);
                break;
            case 3:
                printGuests(&hotel);
                break;
            case 4:
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                printf("Enter amount: ");
                scanf("%f", &amount);
                calculateBill(&hotel, roomNumber, amount);
                break;
            case 5:
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                printBill(&hotel, roomNumber);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}