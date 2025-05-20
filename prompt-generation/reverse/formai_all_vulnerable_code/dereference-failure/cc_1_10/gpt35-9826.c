//FormAI DATASET v1.0 Category: Hotel Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* structures for the hotel management system */
typedef struct {
    int room_number;
    char room_type[10];
    char availability[4];
    float room_rate;
} Room;

typedef struct {
    int reservation_number;
    char reservation_name[20];
    int guest_count;
    char check_in_date[11];
    char check_out_date[11];
    Room *reserved_room;
} Reservation;

/* function prototypes */
void display_main_menu();
void display_rooms(Room *rooms, int room_count);
void display_reservations(Reservation *reservations, int reservation_count);
void add_reservation(Reservation *reservations, int *reservation_count, Room *rooms, int room_count);
void delete_reservation(Reservation *reservations, int *reservation_count);
void edit_reservation(Reservation *reservations, int reservation_count, Room *rooms, int room_count);
void save_data(Reservation *reservations, int reservation_count);

int main() {
    int choice;
    int room_count = 5;
    int reservation_count = 0;
    Room *rooms = (Room*)malloc(room_count * sizeof(Room));
    Reservation *reservations = (Reservation*)malloc(100 * sizeof(Reservation));
    
    /* initialize rooms */
    for (int i = 0; i < room_count; i++) {
        rooms[i].room_number = i + 1;
        strcpy(rooms[i].room_type, "Standard");
        strcpy(rooms[i].availability, "Yes");
        rooms[i].room_rate = 50.00;
    }
    
    /* display the main menu */
    do {
        display_main_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_rooms(rooms, room_count);
                break;
            case 2:
                display_reservations(reservations, reservation_count);
                break;
            case 3:
                add_reservation(reservations, &reservation_count, rooms, room_count);
                break;
            case 4:
                delete_reservation(reservations, &reservation_count);
                break;
            case 5:
                edit_reservation(reservations, reservation_count, rooms, room_count);
                break;
            case 6:
                save_data(reservations, reservation_count);
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 7);
    
    free(rooms);
    free(reservations);
    return 0;
}

/* function to display main menu */
void display_main_menu() {
    printf("***Hotel Management System***\n");
    printf("1. Display Rooms\n");
    printf("2. Display Reservations\n");
    printf("3. Add Reservation\n");
    printf("4. Delete Reservation\n");
    printf("5. Edit Reservation\n");
    printf("6. Save Data\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

/* function to display rooms */
void display_rooms(Room *rooms, int room_count) {
    printf("***Rooms***\n");
    printf("Room Number\tRoom Type\tAvailability\tRoom Rate\n");
    for (int i = 0; i < room_count; i++) {
        printf("%d\t\t%s\t\t%s\t\t$%.2f\n", rooms[i].room_number, rooms[i].room_type, rooms[i].availability, rooms[i].room_rate);
    }
    printf("\n");
}

/* function to display reservations */
void display_reservations(Reservation *reservations, int reservation_count) {
    printf("***Reservations***\n");
    printf("Reservation Number\tGuest Name\tGuest Count\tCheck-in Date\tCheck-out Date\tRoom Number\tRoom Type\n");
    for (int i = 0; i < reservation_count; i++) {
        printf("%d\t\t\t%s\t\t%d\t\t%s\t%s\t\t%d\t\t%s\n", reservations[i].reservation_number, reservations[i].reservation_name, reservations[i].guest_count, reservations[i].check_in_date, reservations[i].check_out_date, reservations[i].reserved_room->room_number, reservations[i].reserved_room->room_type);
    }
    printf("\n");
}

/* function to add reservation */
void add_reservation(Reservation *reservations, int *reservation_count, Room *rooms, int room_count) {
    int room_number;
    int index;
    int reservation_number = *reservation_count + 1;
    char reservation_name[20];
    int guest_count;
    char check_in_date[11];
    char check_out_date[11];
    Reservation new_reservation;
    
    /* get reservation details */
    printf("Enter guest name: ");
    scanf("%s", reservation_name);
    printf("Enter guest count: ");
    scanf("%d", &guest_count);
    printf("Enter check-in date (dd/mm/yyyy): ");
    scanf("%s", check_in_date);
    printf("Enter check-out date (dd/mm/yyyy): ");
    scanf("%s", check_out_date);
    
    /* display available rooms */
    printf("***Available Rooms***\n");
    printf("Room Number\tRoom Type\tAvailability\tRoom Rate\n");
    for (int i = 0; i < room_count; i++) {
        if (strcmp(rooms[i].availability, "Yes") == 0) {
            printf("%d\t\t%s\t\t%s\t\t$%.2f\n", rooms[i].room_number, rooms[i].room_type, rooms[i].availability, rooms[i].room_rate);
        }
    }
    printf("\nEnter room number: ");
    scanf("%d", &room_number);
    
    /* check if room is available */
    index = room_number - 1;
    if (strcmp(rooms[index].availability, "Yes") != 0) {
        printf("Room not available!\n");
        return;
    }
    
    /* update room availability and create new reservation */
    rooms[index].availability[0] = 'N';
    rooms[index].availability[1] = 'o';
    rooms[index].room_rate *= guest_count;
    new_reservation.reservation_number = reservation_number;
    strcpy(new_reservation.reservation_name, reservation_name);
    new_reservation.guest_count = guest_count;
    strcpy(new_reservation.check_in_date, check_in_date);
    strcpy(new_reservation.check_out_date, check_out_date);
    new_reservation.reserved_room = &rooms[index];
    
    /* add reservation to list */
    reservations[*reservation_count] = new_reservation;
    *reservation_count += 1;
    
    printf("Reservation added successfully!\n");
}

/* function to delete reservation */
void delete_reservation(Reservation *reservations, int *reservation_count) {
    int reservation_number;
    int index;
    
    /* get reservation number */
    printf("Enter reservation number: ");
    scanf("%d", &reservation_number);
    
    /* check if reservation exists */
    index = -1;
    for (int i = 0; i < *reservation_count; i++) {
        if (reservations[i].reservation_number == reservation_number) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Reservation not found!\n");
        return;
    }
    
    /* update room availability and delete reservation */
    reservations[index].reserved_room->availability[0] = 'Y';
    reservations[index].reserved_room->availability[1] = 'e';
    reservations[index].reserved_room->room_rate /= reservations[index].guest_count;
    for (int i = index; i < *reservation_count - 1; i++) {
        reservations[i] = reservations[i + 1];
    }
    *reservation_count -= 1;
    
    printf("Reservation deleted successfully!\n");
}

/* function to edit reservation */
void edit_reservation(Reservation *reservations, int reservation_count, Room *rooms, int room_count) {
    int reservation_number;
    int index;
    int room_number;
    char check_in_date[11];
    char check_out_date[11];
    char choice;
    
    /* get reservation number */
    printf("Enter reservation number: ");
    scanf("%d", &reservation_number);
    
    /* check if reservation exists */
    index = -1;
    for (int i = 0; i < reservation_count; i++) {
        if (reservations[i].reservation_number == reservation_number) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Reservation not found!\n");
        return;
    }
    
    /* display current reservation details */
    printf("***Current Reservation Details***\n");
    printf("Reservation Number: %d\n", reservations[index].reservation_number);
    printf("Guest Name: %s\n", reservations[index].reservation_name);
    printf("Guest Count: %d\n", reservations[index].guest_count);
    printf("Check-in Date: %s\n", reservations[index].check_in_date);
    printf("Check-out Date: %s\n", reservations[index].check_out_date);
    printf("Room Number: %d\n", reservations[index].reserved_room->room_number);
    printf("Room Type: %s\n", reservations[index].reserved_room->room_type);
    
    /* get new reservation details */
    printf("Change check-in date? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        printf("Enter new check-in date (dd/mm/yyyy): ");
        scanf("%s", check_in_date);
        strcpy(reservations[index].check_in_date, check_in_date);
    }
    printf("Change check-out date? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        printf("Enter new check-out date (dd/mm/yyyy): ");
        scanf("%s", check_out_date);
        strcpy(reservations[index].check_out_date, check_out_date);
    }
    printf("Change room number? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        /* display available rooms */
        printf("***Available Rooms***\n");
        printf("Room Number\tRoom Type\tAvailability\tRoom Rate\n");
        for (int i = 0; i < room_count; i++) {
            if (strcmp(rooms[i].availability, "Yes") == 0) {
                printf("%d\t\t%s\t\t%s\t\t$%.2f\n", rooms[i].room_number, rooms[i].room_type, rooms[i].availability, rooms[i].room_rate);
            }
        }
        printf("\nEnter new room number: ");
        scanf("%d", &room_number);
        
        /* check if room is available */
        index = room_number - 1;
        if (strcmp(rooms[index].availability, "Yes") != 0) {
            printf("Room not available!\n");
            return;
        }
        reservations[index].reserved_room->availability[0] = 'N';
        reservations[index].reserved_room->availability[1] = 'o';
        rooms[index].room_rate *= reservations[index].guest_count;
    }
    
    printf("Reservation updated successfully!\n");
}

/* function to save data to file */
void save_data(Reservation *reservations, int reservation_count) {
    FILE *fp;
    fp = fopen("reservations.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < reservation_count; i++) {
        fprintf(fp, "%d,%s,%d,%s,%s,%d,%s\n", reservations[i].reservation_number, reservations[i].reservation_name, reservations[i].guest_count, reservations[i].check_in_date, reservations[i].check_out_date, reservations[i].reserved_room->room_number, reservations[i].reserved_room->room_type);
    }
    fclose(fp);
    printf("Data saved successfully!\n");
}