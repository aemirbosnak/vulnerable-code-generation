//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: real-life
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
    int check_in_date;
    int check_out_date;
    int num_days;
    float bill_amount;
} guest;

// Function to create a new guest
guest* create_guest(char* name, char* address, char* phone, char* email, int room_number, int check_in_date, int check_out_date) {
    guest* new_guest = (guest*) malloc(sizeof(guest));
    strcpy(new_guest->name, name);
    strcpy(new_guest->address, address);
    strcpy(new_guest->phone, phone);
    strcpy(new_guest->email, email);
    new_guest->room_number = room_number;
    new_guest->check_in_date = check_in_date;
    new_guest->check_out_date = check_out_date;
    new_guest->num_days = check_out_date - check_in_date;
    new_guest->bill_amount = 0.0;
    return new_guest;
}

// Function to print guest information
void print_guest(guest* guest) {
    printf("Name: %s\n", guest->name);
    printf("Address: %s\n", guest->address);
    printf("Phone: %s\n", guest->phone);
    printf("Email: %s\n", guest->email);
    printf("Room Number: %d\n", guest->room_number);
    printf("Check-In Date: %d\n", guest->check_in_date);
    printf("Check-Out Date: %d\n", guest->check_out_date);
    printf("Number of Days: %d\n", guest->num_days);
    printf("Bill Amount: $%.2f\n", guest->bill_amount);
}

// Function to add a charge to the guest's bill
void add_charge(guest* guest, float amount) {
    guest->bill_amount += amount;
}

// Function to check out the guest and print their bill
void check_out_guest(guest* guest) {
    printf("Guest: %s\n", guest->name);
    printf("Room Number: %d\n", guest->room_number);
    printf("Number of Days: %d\n", guest->num_days);
    printf("Bill Amount: $%.2f\n", guest->bill_amount);
    free(guest);
}

// Main function
int main() {
    // Create a new guest
    guest* guest1 = create_guest("John Doe", "123 Main Street", "555-1212", "john.doe@email.com", 101, 20230301, 20230310);

    // Print the guest's information
    print_guest(guest1);

    // Add a charge to the guest's bill
    add_charge(guest1, 100.00);

    // Check out the guest
    check_out_guest(guest1);

    return 0;
}