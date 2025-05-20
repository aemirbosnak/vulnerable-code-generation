//FormAI DATASET v1.0 Category: Hotel Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    char type[20];
    int number;
    double price;
    int status;
};

struct Reservation {
    int room_number;
    char guest_name[50];
    char check_in_date[20];
    char check_out_date[20];
    double total_cost;
};

int num_rooms = 10;
struct Room *rooms;

void initialize_rooms() {
    rooms = (struct Room*) malloc(num_rooms * sizeof(struct Room));
    
    for (int i = 0; i < num_rooms; i++) {
        strcpy(rooms[i].type, "Single");
        rooms[i].number = i+1;
        rooms[i].price = 50;
        rooms[i].status = 0;
    }
}

void print_room(struct Room r) {
    printf("Room Number: %d\n", r.number);
    printf("Room Type: %s\n", r.type);
    printf("Price: %.2f\n", r.price);
    if (r.status == 0) {
        printf("Status: Available\n");
    } else {
        printf("Status: Not Available\n");
    }
}

void print_rooms() {
    for (int i = 0; i < num_rooms; i++) {
        print_room(rooms[i]);
        printf("\n");
    }
}

void reserve_room(int room_num, char *name, char *check_in, char *check_out) {
    rooms[room_num-1].status = 1;
    
    int num_nights = (int) (difftime(mktime(check_out) - mktime(check_in)) / (60 * 60 * 24));
    double total = rooms[room_num-1].price * num_nights;
    
    struct Reservation res = {room_num, name, check_in, check_out, total};
    printf("\nReservation Details:\n");
    printf("Guest Name: %s\n", res.guest_name);
    printf("Room Number: %d\n", res.room_number);
    printf("Check-in Date: %s\n", res.check_in_date);
    printf("Check-out Date: %s\n", res.check_out_date);
    printf("Total Cost: %.2f\n\n", res.total_cost);
}

int main() {
    initialize_rooms();
    
    while (1) {
        printf("1. Display Rooms\n");
        printf("2. Reserve Room\n");
        printf("3. Exit\n\n");
        printf("Enter Choice: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nHotel Rooms:\n\n");
                print_rooms();
                break;
            case 2:
                printf("\nEnter Guest Name: ");
                char name[50];
                scanf("%s", name);
                
                printf("Enter Room Number: ");
                int room_num;
                scanf("%d", &room_num);
                
                printf("Enter Check-in Date (yyyy-mm-dd): ");
                char check_in[20];
                scanf("%s", check_in);
                
                printf("Enter Check-out Date (yyyy-mm-dd): ");
                char check_out[20];
                scanf("%s", check_out);
                
                reserve_room(room_num, name, check_in, check_out);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    
    return 0;
}