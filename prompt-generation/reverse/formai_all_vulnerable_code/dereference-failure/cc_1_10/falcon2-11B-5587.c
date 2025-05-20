//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Struct to store information about a guest
typedef struct {
    char name[50];
    int age;
    int room_number;
    float total_amount;
} Guest;

// Function to create a new guest
Guest* createGuest() {
    Guest* guest = (Guest*)malloc(sizeof(Guest));

    printf("Enter guest name: ");
    scanf("%s", guest->name);

    printf("Enter guest age: ");
    scanf("%d", &guest->age);

    printf("Enter guest room number: ");
    scanf("%d", &guest->room_number);

    printf("Enter total amount: ");
    scanf("%f", &guest->total_amount);

    return guest;
}

// Function to display information about a guest
void displayGuest(Guest* guest) {
    printf("Guest name: %s\n", guest->name);
    printf("Guest age: %d\n", guest->age);
    printf("Guest room number: %d\n", guest->room_number);
    printf("Total amount: $%.2f\n", guest->total_amount);
}

// Function to update the total amount for a guest
void updateTotalAmount(Guest* guest, float new_total_amount) {
    guest->total_amount = new_total_amount;
}

// Function to delete a guest
void deleteGuest(Guest* guest) {
    free(guest);
}

// Main function
int main() {
    Guest* guest1 = createGuest();
    Guest* guest2 = createGuest();

    // Display information about guests
    displayGuest(guest1);
    displayGuest(guest2);

    // Update total amount for guest2
    updateTotalAmount(guest2, 150.00);

    // Delete guest1
    deleteGuest(guest1);

    return 0;
}