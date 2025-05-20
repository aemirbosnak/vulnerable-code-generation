//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: introspective
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
  float bill_amount;
} guest;

// Function to create a new guest
guest* create_guest(char* name, char* address, char* phone, char* email, int room_number, int num_nights, float bill_amount) {
  guest* new_guest = (guest*)malloc(sizeof(guest));
  strcpy(new_guest->name, name);
  strcpy(new_guest->address, address);
  strcpy(new_guest->phone, phone);
  strcpy(new_guest->email, email);
  new_guest->room_number = room_number;
  new_guest->num_nights = num_nights;
  new_guest->bill_amount = bill_amount;
  return new_guest;
}

// Function to print guest information
void print_guest(guest* guest) {
  printf("Guest Name: %s\n", guest->name);
  printf("Guest Address: %s\n", guest->address);
  printf("Guest Phone: %s\n", guest->phone);
  printf("Guest Email: %s\n", guest->email);
  printf("Guest Room Number: %d\n", guest->room_number);
  printf("Guest Number of Nights: %d\n", guest->num_nights);
  printf("Guest Bill Amount: $%.2f\n", guest->bill_amount);
}

// Function to check if a guest is eligible for a discount
int is_eligible_for_discount(guest* guest) {
  if (guest->num_nights >= 3) {
    return 1;
  } else {
    return 0;
  }
}

// Function to apply a discount to a guest's bill
void apply_discount(guest* guest) {
  if (is_eligible_for_discount(guest)) {
    guest->bill_amount *= 0.9;
  }
}

// Main function
int main() {
  // Create an array of guests
  guest* guests[10];
  
  // Create some test guests
  guests[0] = create_guest("John Smith", "123 Main Street", "555-1212", "john.smith@email.com", 101, 3, 200.00);
  guests[1] = create_guest("Jane Doe", "456 Elm Street", "555-1213", "jane.doe@email.com", 102, 2, 150.00);
  guests[2] = create_guest("Bill Jones", "789 Oak Street", "555-1214", "bill.jones@email.com", 103, 1, 100.00);
  
  // Print the guest information
  for (int i=0;i<3;++i) {
    print_guest(guests[i]);
    printf("\n");
  }
  
  // Apply discounts to eligible guests
  for (int i=0;i<3;++i) {
    apply_discount(guests[i]);
  }
  
  // Print the guest information after discounts have been applied
  for (int i=0;i<3;++i) {
    print_guest(guests[i]);
    printf("\n");
  }
  
  return 0;
}