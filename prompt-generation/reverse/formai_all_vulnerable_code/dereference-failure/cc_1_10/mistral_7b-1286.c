//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: intelligent
#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    char phone[15];
    int check_in_date;
    int check_out_date;
    int is_occupied;
} Room;

Room rooms[MAX_ROOMS];
int num_rooms = 0;

void add_guest(int room_number) {
    if (rooms[room_number].is_occupied) {
        printf("Room %d is already occupied.\n", room_number);
        return;
    }

    printf("Enter guest name: ");
    fgets(rooms[room_number].name, sizeof(rooms[room_number].name), stdin);
    rooms[room_number].name[strcspn(rooms[room_number].name, "\n")] = '\0';

    printf("Enter guest phone number: ");
    fgets(rooms[room_number].phone, sizeof(rooms[room_number].phone), stdin);
    rooms[room_number].phone[strcspn(rooms[room_number].phone, "\n")] = '\0';

    rooms[room_number].check_in_date = time(NULL);
    rooms[room_number].is_occupied = 1;

    num_rooms++;
    printf("Guest added to Room %d successfully.\n", room_number);
}

void remove_guest(int room_number) {
    if (!rooms[room_number].is_occupied) {
        printf("Room %d is vacant.\n", room_number);
        return;
    }

    rooms[room_number].is_occupied = 0;
    num_rooms--;

    printf("Guest removed from Room %d successfully.\n", room_number);
}

void display_rooms() {
    int i;

    printf("\nAvailable Rooms:\n");
    for (i = 0; i < num_rooms; i++) {
        if (!rooms[i].is_occupied) {
            printf("Room %d\n", i);
        }
    }
}

int main() {
    int choice, room_number;

    while (1) {
        printf("\nHotel Management System\n");
        printf("1. Add Guest\n");
        printf("2. Remove Guest\n");
        printf("3. Display Available Rooms\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter room number: ");
                scanf("%d", &room_number);
                add_guest(room_number);
                break;
            case 2:
                printf("Enter room number: ");
                scanf("%d", &room_number);
                remove_guest(room_number);
                break;
            case 3:
                display_rooms();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}