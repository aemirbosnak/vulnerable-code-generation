//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: dynamic
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
  int num_nights;
  float total_cost;
} guest;

// Function to create a new guest
guest* create_guest(char* name, char* address, char* phone, char* email, int room_number, int num_nights, float total_cost) {
  guest* new_guest = (guest*)malloc(sizeof(guest));
  strcpy(new_guest->name, name);
  strcpy(new_guest->address, address);
  strcpy(new_guest->phone, phone);
  strcpy(new_guest->email, email);
  new_guest->room_number = room_number;
  new_guest->num_nights = num_nights;
  new_guest->total_cost = total_cost;
  return new_guest;
}

// Function to print guest information
void print_guest(guest* guest) {
  printf("Guest Name: %s\n", guest->name);
  printf("Address: %s\n", guest->address);
  printf("Phone: %s\n", guest->phone);
  printf("Email: %s\n", guest->email);
  printf("Room Number: %d\n", guest->room_number);
  printf("Number of Nights: %d\n", guest->num_nights);
  printf("Total Cost: %.2f\n\n", guest->total_cost);
}

// Main function
int main() {
  // Create an array of guests
  guest* guests[100];

  // Initialize the array with some sample data
  guests[0] = create_guest("John Doe", "123 Main Street", "555-123-4567", "john.doe@email.com", 101, 3, 250.00);
  guests[1] = create_guest("Jane Smith", "456 Elm Street", "555-234-5678", "jane.smith@email.com", 102, 2, 180.00);
  guests[2] = create_guest("Bill Jones", "789 Oak Street", "555-345-6789", "bill.jones@email.com", 103, 1, 100.00);

  // Print the guest information
  for (int i = 0; i < 3; i++) {
    print_guest(guests[i]);
  }

  return 0;
}