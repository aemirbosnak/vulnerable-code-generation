//FormAI DATASET v1.0 Category: Hotel Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures for hotel management system
typedef struct room {
    int room_number;
    int capacity;
    char type[20];
    float price;
    int is_reserved;
} Room;

typedef struct customer {
    char name[50];
    char address[100];
    char email[50];
    char phone_number[15];
} Customer;

typedef struct reservation {
    Room room;
    Customer customer;
    int duration;
    float total_cost;
} Reservation;

// Function prototypes
void add_room(Room *rooms, int *num_of_rooms);
void add_customer(Customer *customers, int *num_of_customers);
void make_reservation(Room *rooms, int num_of_rooms, Customer *customers, int num_of_customers, Reservation *reservations, int *num_of_reservations);
void view_reservations(Reservation *reservations, int num_of_reservations);
void cancel_reservation(Room *rooms, int num_of_rooms, Reservation *reservations, int *num_of_reservations);

// Main function
int main() {
    int option;
    int num_of_rooms = 0, num_of_customers = 0, num_of_reservations = 0;
    Room *rooms = NULL;
    Customer *customers = NULL;
    Reservation *reservations = NULL;
    
    while(1) {
        printf("Welcome to our shape-shifting hotel management system!\n");
        printf("Please select an option:\n");
        printf("1. Add a room\n");
        printf("2. Add a customer\n");
        printf("3. Make a reservation\n");
        printf("4. View reservations\n");
        printf("5. Cancel a reservation\n");
        printf("6. Exit\n");
        printf("Option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                add_room(rooms, &num_of_rooms);
                break;
            case 2:
                add_customer(customers, &num_of_customers);
                break;
            case 3:
                make_reservation(rooms, num_of_rooms, customers, num_of_customers, reservations, &num_of_reservations);
                break;
            case 4:
                view_reservations(reservations, num_of_reservations);
                break;
            case 5:
                cancel_reservation(rooms, num_of_rooms, reservations, &num_of_reservations);
                break;
            case 6:
                printf("Thank you for using our hotel management system!\n");
                exit(0);
            default:
                printf("Invalid option. Please select a valid option.\n");
        }
    }
    
    return 0;
}

// Function to add a room
void add_room(Room *rooms, int *num_of_rooms) {
    Room new_room;
    new_room.room_number = *num_of_rooms + 1;
    
    printf("Enter the room type: ");
    scanf("%s", new_room.type);
    
    printf("Enter the room capacity: ");
    scanf("%d", &new_room.capacity);
    
    printf("Enter the room price: ");
    scanf("%f", &new_room.price);
    
    new_room.is_reserved = 0;
    
    // If there are no rooms yet, allocate memory for one room
    if(*num_of_rooms == 0) {
        rooms = (Room *) malloc(sizeof(Room));
    } else {
        // If there are already rooms, reallocate memory to accomodate for one more room
        rooms = (Room *) realloc(rooms, (*num_of_rooms + 1) * sizeof(Room));
    }
    
    // Add the new room to the list of rooms
    rooms[*num_of_rooms] = new_room;
    *num_of_rooms += 1;
    
    printf("Room added successfully!\n");
}

// Function to add a customer
void add_customer(Customer *customers, int *num_of_customers) {
    Customer new_customer;
    
    printf("Enter the customer name: ");
    scanf("%s", new_customer.name);
    
    printf("Enter the customer address: ");
    scanf("%s", new_customer.address);
    
    printf("Enter the customer email: ");
    scanf("%s", new_customer.email);
    
    printf("Enter the customer phone number: ");
    scanf("%s", new_customer.phone_number);
    
    // If there are no customers yet, allocate memory for one customer
    if(*num_of_customers == 0) {
        customers = (Customer *) malloc(sizeof(Customer));
    } else {
        // If there are already customers, reallocate memory to accomodate for one more customer
        customers = (Customer *) realloc(customers, (*num_of_customers + 1) * sizeof(Customer));
    }
    
    // Add the new customer to the list of customers
    customers[*num_of_customers] = new_customer;
    *num_of_customers += 1;
    
    printf("Customer added successfully!\n");
}

// Function to make a reservation
void make_reservation(Room *rooms, int num_of_rooms, Customer *customers, int num_of_customers, Reservation *reservations, int *num_of_reservations) {
    Reservation new_reservation;
    
    // Check if there are available rooms
    int available_rooms[num_of_rooms];
    int num_of_available_rooms = 0;
    
    for(int i = 0; i < num_of_rooms; i++) {
        if(rooms[i].is_reserved == 0) {
            available_rooms[num_of_available_rooms] = rooms[i].room_number;
            num_of_available_rooms++;
        }
    }
    
    if(num_of_available_rooms == 0) {
        printf("There are no available rooms. Sorry!\n");
        return;
    }
    
    // Choose a room to reserve
    printf("Choose a room to reserve:\n");
    for(int i = 0; i < num_of_available_rooms; i++) {
        printf("%d. Room %d\n", i + 1, available_rooms[i]);
    }
    printf("Option: ");
    int room_choice;
    scanf("%d", &room_choice);
    new_reservation.room = rooms[available_rooms[room_choice - 1] - 1];
    
    // Add customer details
    printf("Enter customer name: ");
    scanf("%s", new_reservation.customer.name);
    
    printf("Enter customer address: ");
    scanf("%s", new_reservation.customer.address);
    
    printf("Enter customer email: ");
    scanf("%s", new_reservation.customer.email);
    
    printf("Enter customer phone number: ");
    scanf("%s", new_reservation.customer.phone_number);
    
    // Add reservation duration
    printf("Enter duration of stay (in days): ");
    scanf("%d", &new_reservation.duration);
    
    // Calculate total cost
    new_reservation.total_cost = new_reservation.duration * new_reservation.room.price;
    
    // Mark the room as reserved
    rooms[available_rooms[room_choice - 1] - 1].is_reserved = 1;
    
    // If there are no reservations yet, allocate memory for one reservation
    if(*num_of_reservations == 0) {
        reservations = (Reservation *) malloc(sizeof(Reservation));
    } else {
        // If there are already reservations, reallocate memory to accomodate for one more reservation
        reservations = (Reservation *) realloc(reservations, (*num_of_reservations + 1) * sizeof(Reservation));
    }
    
    // Add the new reservation to the list of reservations
    reservations[*num_of_reservations] = new_reservation;
    *num_of_reservations += 1;
    
    printf("Reservation made successfully!\n");
}

// Function to view reservations
void view_reservations(Reservation *reservations, int num_of_reservations) {
    if(num_of_reservations == 0) {
        printf("There are no reservations yet. Sorry!\n");
        return;
    }
    
    for(int i = 0; i < num_of_reservations; i++) {
        printf("Reservation %d:\n", i + 1);
        printf("Room %d reserved by %s (%s)\n", reservations[i].room.room_number, reservations[i].customer.name, reservations[i].customer.phone_number);
        printf("Duration of stay: %d days\n", reservations[i].duration);
        printf("Total cost: %.2f\n", reservations[i].total_cost);
        printf("\n");
    }
}

// Function to cancel a reservation
void cancel_reservation(Room *rooms, int num_of_rooms, Reservation *reservations, int *num_of_reservations) {
    if(*num_of_reservations == 0) {
        printf("There are no reservations to cancel. Sorry!\n");
        return;
    }
    
    printf("Choose a reservation to cancel:\n");
    for(int i = 0; i < *num_of_reservations; i++) {
        printf("%d. Room %d reserved by %s (%s)\n", i + 1, reservations[i].room.room_number, reservations[i].customer.name, reservations[i].customer.phone_number);
    }
    printf("Option: ");
    int res_choice;
    scanf("%d", &res_choice);
    
    // Mark the room as not reserved
    rooms[reservations[res_choice - 1].room.room_number - 1].is_reserved = 0;
    
    // Remove the reservation from the list of reservations
    for(int i = res_choice - 1; i < *num_of_reservations - 1; i++) {
        reservations[i] = reservations[i+1];
    }
    *num_of_reservations -= 1;
    
    printf("Reservation cancelled successfully!\n");
}