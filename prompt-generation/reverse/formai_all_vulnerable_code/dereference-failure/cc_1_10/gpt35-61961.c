//FormAI DATASET v1.0 Category: Hotel Management System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct reservation{
    char name[50];
    char address[50];
    char phone[15];
    int room_number;
    int room_type;
    int days;
    int guests;
    struct reservation *next;
} Reservation;

Reservation *head = NULL;

void add_reservation(){
    Reservation *new_reservation = (Reservation*) malloc(sizeof(Reservation));
    printf("Enter guest name: ");
    scanf("%s", new_reservation->name);
    printf("Enter guest address: ");
    scanf("%s", new_reservation->address);
    printf("Enter guest phone number: ");
    scanf("%s", new_reservation->phone);
    printf("Enter room number: ");
    scanf("%d", &new_reservation->room_number);
    printf("Enter room type (1 for standard, 2 for deluxe, 3 for suite): ");
    scanf("%d", &new_reservation->room_type);
    printf("Enter number of guests: ");
    scanf("%d", &new_reservation->guests);
    printf("Enter number of days staying: ");
    scanf("%d", &new_reservation->days);
    new_reservation->next = head;
    head = new_reservation;
    printf("\nReservation added successfully!\n");
}

void view_reservations(){
    if(head == NULL){
        printf("There are no reservations to view.\n");
    } else {
        Reservation *current_reservation = head;
        while(current_reservation != NULL){
            printf("Guest: %s\n", current_reservation->name);
            printf("Address: %s\n", current_reservation->address);
            printf("Phone: %s\n", current_reservation->phone);
            printf("Room number: %d\n", current_reservation->room_number);
            printf("Room type: %d\n", current_reservation->room_type);
            printf("Guests: %d\n", current_reservation->guests);
            printf("Days staying: %d\n\n", current_reservation->days);
            current_reservation = current_reservation->next;
        }
    }
}

void search_reservation(){
    if(head == NULL){
        printf("There are no reservations to search.\n");
    } else {
        Reservation *current_reservation = head;
        char search_name[50];
        printf("Enter the guest name to search for: ");
        scanf("%s", search_name);
        while(current_reservation != NULL){
            if(strcmp(current_reservation->name, search_name) == 0){
                printf("Guest: %s\n", current_reservation->name);
                printf("Address: %s\n", current_reservation->address);
                printf("Phone: %s\n", current_reservation->phone);
                printf("Room number: %d\n", current_reservation->room_number);
                printf("Room type: %d\n", current_reservation->room_type);
                printf("Guests: %d\n", current_reservation->guests);
                printf("Days staying: %d\n\n", current_reservation->days);
                return;
            } else {
                current_reservation = current_reservation->next;
            }
        }
        printf("Reservation for guest %s not found.\n", search_name);
    }
}

void delete_reservation(){
    if(head == NULL){
        printf("There are no reservations to delete.\n");
    } else {
        Reservation *current_reservation = head;
        Reservation *previous_reservation = NULL;
        int delete_room;
        printf("Enter the room number to delete: ");
        scanf("%d", &delete_room);
        while(current_reservation != NULL){
            if(current_reservation->room_number == delete_room){
                if(previous_reservation == NULL){
                    head = current_reservation->next;
                    free(current_reservation);
                    printf("\nReservation deleted successfully!\n");
                    return;
                } else {
                    previous_reservation->next = current_reservation->next;
                    free(current_reservation);
                    printf("\nReservation deleted successfully!\n");
                    return;
                }
            } else {
                previous_reservation = current_reservation;
                current_reservation = current_reservation->next;
            }
        }
        printf("Reservation for room %d not found.\n", delete_room);
    }
}

void update_reservation(){
    if(head == NULL){
        printf("There are no reservations to update.\n");
    } else {
        Reservation *current_reservation = head;
        char update_name[50];
        printf("Enter the guest name to update: ");
        scanf("%s", update_name);
        while(current_reservation != NULL){
            if(strcmp(current_reservation->name, update_name) == 0){
                printf("Enter new address: ");
                scanf("%s", current_reservation->address);
                printf("Enter new phone: ");
                scanf("%s", current_reservation->phone);
                printf("Enter new number of guests: ");
                scanf("%d", &current_reservation->guests);
                printf("Enter new number of days staying: ");
                scanf("%d", &current_reservation->days);
                printf("\nReservation updated successfully!\n");
                return;
            } else {
                current_reservation = current_reservation->next;
            }
        }
        printf("Reservation for guest %s not found.\n", update_name);
    }
}

int main(){
    int option;
    do {
        printf("Welcome to the C Hotel Management System\n");
        printf("1. Add a reservation\n");
        printf("2. View all reservations\n");
        printf("3. Search for a reservation\n");
        printf("4. Delete a reservation\n");
        printf("5. Update a reservation\n");
        printf("6. Exit\n");
        scanf("%d", &option);

        switch(option){
            case 1:
                add_reservation();
                break;
            case 2:
                view_reservations();
                break;
            case 3:
                search_reservation();
                break;
            case 4:
                delete_reservation();
                break;
            case 5:
                update_reservation();
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while(option != 6);
    return 0;
}