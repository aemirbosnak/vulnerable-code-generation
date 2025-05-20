//FormAI DATASET v1.0 Category: Hotel Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    char name[50];
    char contact[15];
    int room_number;
    int bill_amount;
};

struct room {
    int number;
    char type[20];
    int capacity;
};

int check_in(struct guest *guest_ptr, struct room *room_ptr, int total_rooms);
int check_out(struct guest *guest_ptr, int total_guests, FILE *fp);
void display_guest_details(struct guest *guest_ptr, int total_guests);
void display_room_details(struct room *room_ptr, int total_rooms);
void calculate_bill(struct guest *guest_ptr, int total_guests);

int main() {
    int choice, total_rooms = 5, total_guests = 0;
    struct guest *guests = (struct guest *) malloc(total_guests * sizeof(struct guest));
    struct room *rooms = (struct room *) malloc(total_rooms * sizeof(struct room));
    char filename[] = "guest_details.txt";
    FILE *fp;

    //Initialize rooms
    for (int i = 0; i < total_rooms; i++) {
        rooms[i].number = i+1;
        strcpy(rooms[i].type, "Standard");
        rooms[i].capacity = 2;
    }

    while(1) {
        printf("\nWelcome to C Hotel Management System. Select an option:\n");
        printf("1. Check-in\n");
        printf("2. Check-out\n");
        printf("3. Display Guest Details\n");
        printf("4. Display Room Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch(choice) {
            case 1: total_guests = check_in(guests, rooms, total_rooms);
                    break;
            case 2: fp = fopen(filename, "a");
                    total_guests = check_out(guests, total_guests, fp);
                    fclose(fp);
                    break;
            case 3: display_guest_details(guests, total_guests);
                    break;
            case 4: display_room_details(rooms, total_rooms);
                    break;
            case 5: calculate_bill(guests, total_guests);
                    free(guests);
                    free(rooms);
                    exit(0);
            default: printf("Invalid choice. Please try again.\n");
                     break;
        }
    }
    return 0;
}

int check_in(struct guest *guest_ptr, struct room *room_ptr, int total_rooms) {
    char name[50], contact[15], type[20];
    int room_number, capacity, flag = 0, i;
    printf("Enter guest name: ");
    scanf("%s", name);
    printf("Enter guest contact number: ");
    scanf("%s", contact);

    printf("Choose a room type from below options:\n");
    printf("1. Standard (2 guests)\n");
    printf("2. Deluxe (3 guests)\n");
    printf("3. Suite (4 guests)\n");
    printf("Enter your choice: ");
    scanf("%d", &i);

    if(i == 1) {
        strcpy(type, "Standard");
        capacity = 2;
    } else if(i == 2) {
        strcpy(type, "Deluxe");
        capacity = 3;
    } else {
        strcpy(type, "Suite");
        capacity = 4;
    }

    for(i = 0; i < total_rooms; i++) {
        if(room_ptr[i].capacity == capacity && room_ptr[i].number > 0) {
            guest_ptr = (struct guest *) realloc(guest_ptr, (total_rooms + 1) * sizeof(struct guest));
            strcpy(guest_ptr[total_rooms].name, name);
            strcpy(guest_ptr[total_rooms].contact, contact);
            guest_ptr[total_rooms].room_number = room_ptr[i].number;
            guest_ptr[total_rooms].bill_amount = 0;
            room_ptr[i].number = 0;
            printf("\nBooking confirmed. Guest details:\n");
            printf("Name: %s\n", guest_ptr[total_rooms].name);
            printf("Contact: %s\n", guest_ptr[total_rooms].contact);
            printf("Room Number: %d\n", guest_ptr[total_rooms].room_number);
            total_rooms--;
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        printf("Sorry, no %s rooms are available currently.\n", type);
    }
    return total_rooms;
}

int check_out(struct guest *guest_ptr, int total_guests, FILE *fp) {
    int i, room_number, bill_amount;
    char name[50], contact[15];
    printf("Enter guest name: ");
    scanf("%s", name);
    printf("Enter guest contact number: ");
    scanf("%s", contact);
    for(i = 0; i < total_guests; i++) {
        if(strcmp(guest_ptr[i].name, name) == 0 && strcmp(guest_ptr[i].contact, contact) == 0) {
            printf("Enter room number: ");
            scanf("%d", &room_number);
            if(room_number == guest_ptr[i].room_number) {
                printf("Enter bill amount: ");
                scanf("%d", &bill_amount);
                guest_ptr[i].bill_amount = bill_amount;
                printf("Guest checked-out. Bill generated.\n");
                fprintf(fp, "Name: %s\n", guest_ptr[i].name);
                fprintf(fp, "Contact: %s\n", guest_ptr[i].contact);
                fprintf(fp, "Room Number: %d\n", guest_ptr[i].room_number);
                fprintf(fp, "Bill Amount: %d\n\n", guest_ptr[i].bill_amount);
                for(int j = i; j < total_guests-1; j++) {
                    guest_ptr[j] = guest_ptr[j+1];
                }
                total_guests--;
                guest_ptr = (struct guest *) realloc(guest_ptr, total_guests * sizeof(struct guest));
                break;
            }
            else {
                printf("Incorrect room number. Please try again.\n");
                break;
            }
        }
    }
    if(i == total_guests) {
        printf("Guest details not found. Please try again.\n");
    }
    return total_guests;
}

void display_guest_details(struct guest *guest_ptr, int total_guests) {
    printf("Guest details:\n");
    for(int i = 0; i < total_guests; i++) {
        printf("Name: %s\n", guest_ptr[i].name);
        printf("Contact: %s\n", guest_ptr[i].contact);
        printf("Room Number: %d\n", guest_ptr[i].room_number);
        if(guest_ptr[i].bill_amount > 0) {
            printf("Bill Amount: %d\n", guest_ptr[i].bill_amount);
        }
        printf("\n");
    }
}

void display_room_details(struct room *room_ptr, int total_rooms) {
    printf("Room details:\n");
    for(int i = 0; i < total_rooms; i++) {
        printf("Room Number: %d\n", room_ptr[i].number);
        printf("Room Type: %s\n", room_ptr[i].type);
        printf("Room Capacity: %d\n", room_ptr[i].capacity);
        printf("\n");
    }
}

void calculate_bill(struct guest *guest_ptr, int total_guests) {
    int total_amount = 0;
    for(int i = 0; i < total_guests; i++) {
        total_amount += guest_ptr[i].bill_amount;
    }
    printf("Total bill amount: %d\n", total_amount);
}