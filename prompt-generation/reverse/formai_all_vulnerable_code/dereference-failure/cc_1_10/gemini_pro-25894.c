//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: grateful
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
    int days_staying;
    float bill_amount;
} guest;

// Function to create a new guest
guest* create_guest(char *name, char *address, char *phone, char *email, int room_number, int days_staying, float bill_amount) {
    guest *new_guest = (guest*)malloc(sizeof(guest));
    strcpy(new_guest->name, name);
    strcpy(new_guest->address, address);
    strcpy(new_guest->phone, phone);
    strcpy(new_guest->email, email);
    new_guest->room_number = room_number;
    new_guest->days_staying = days_staying;
    new_guest->bill_amount = bill_amount;
    return new_guest;
}

// Function to check in a guest
void check_in(guest *new_guest) {
    printf("Thank you for choosing our hotel, %s!\n", new_guest->name);
    printf("You have been assigned room number %d.\n", new_guest->room_number);
    printf("Your bill amount is $%.2f.\n", new_guest->bill_amount);
    printf("Please enjoy your stay!\n");
}

// Function to check out a guest
void check_out(guest *guest) {
    printf("Thank you for staying with us, %s!\n", guest->name);
    printf("Your total bill amount is $%.2f.\n", guest->bill_amount);
    printf("We hope to see you again soon!\n");
}

// Function to print guest information
void print_guest_info(guest *guest) {
    printf("Name: %s\n", guest->name);
    printf("Address: %s\n", guest->address);
    printf("Phone: %s\n", guest->phone);
    printf("Email: %s\n", guest->email);
    printf("Room number: %d\n", guest->room_number);
    printf("Days staying: %d\n", guest->days_staying);
    printf("Bill amount: $%.2f\n", guest->bill_amount);
}

// Main function
int main() {
    // Create a new guest
    guest *new_guest = create_guest("John Smith", "123 Main Street", "555-1212", "john.smith@email.com", 101, 3, 200.00);

    // Check in the guest
    check_in(new_guest);

    // Print guest information
    print_guest_info(new_guest);

    // Check out the guest
    check_out(new_guest);

    return 0;
}