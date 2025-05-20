//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store guest information
typedef struct guest {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int room_number;
    int nights_staying;
    float bill_amount;
} guest;

// Function to create a new guest
guest* create_guest(char* name, char* address, char* phone, char* email, int room_number, int nights_staying, float bill_amount) {
    guest* new_guest = (guest*)malloc(sizeof(guest));
    strcpy(new_guest->name, name);
    strcpy(new_guest->address, address);
    strcpy(new_guest->phone, phone);
    strcpy(new_guest->email, email);
    new_guest->room_number = room_number;
    new_guest->nights_staying = nights_staying;
    new_guest->bill_amount = bill_amount;
    return new_guest;
}

// Function to print guest information
void print_guest(guest* guest) {
    printf("Guest Information:\n");
    printf("Name: %s\n", guest->name);
    printf("Address: %s\n", guest->address);
    printf("Phone: %s\n", guest->phone);
    printf("Email: %s\n", guest->email);
    printf("Room Number: %d\n", guest->room_number);
    printf("Nights Staying: %d\n", guest->nights_staying);
    printf("Bill Amount: %.2f\n\n", guest->bill_amount);
}

// Function to check in a guest
void check_in_guest(guest* guest) {
    printf("Checking in guest...\n");
    // Assign a room to the guest
    guest->room_number = 101;
    // Calculate the bill amount
    guest->bill_amount = guest->nights_staying * 100;
    printf("Guest checked in successfully!\n");
}

// Function to check out a guest
void check_out_guest(guest* guest) {
    printf("Checking out guest...\n");
    // Print the guest's bill
    print_guest(guest);
    // Free the memory allocated for the guest
    free(guest);
    printf("Guest checked out successfully!\n");
}

// Main function
int main() {
    // Create a new guest
    guest* new_guest = create_guest("John Doe", "123 Main Street", "555-123-4567", "john.doe@email.com", 0, 0, 0);

    // Check in the guest
    check_in_guest(new_guest);

    // Check out the guest
    check_out_guest(new_guest);

    return 0;
}