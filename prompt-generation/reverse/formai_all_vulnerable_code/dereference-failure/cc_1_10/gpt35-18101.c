//FormAI DATASET v1.0 Category: Hotel Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    int id;
    char name[50];
    char address[100];
    char phone[20];
    int room_no;
    char room_type[20];
};

struct room {
    int no;
    char type[20];
    int price;
    int occupancy;
    int available;
};

void book_room(struct guest[], struct room[]);
void check_out(struct guest[], struct room[]);
void display_guests(struct guest[]);
void display_rooms(struct room[]);
void add_room(struct room[]);
void show_menu();
void save_data(struct guest[], struct room[]);
void load_data(struct guest[], struct room[]);

int main() {
    struct guest guests[50];
    struct room rooms[20];
    int choice;

    load_data(guests, rooms);

    do {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                book_room(guests, rooms);
                break;
            case 2:
                check_out(guests, rooms);
                break;
            case 3:
                display_guests(guests);
                break;
            case 4:
                display_rooms(rooms);
                break;
            case 5:
                add_room(rooms);
                break;
            case 6:
                save_data(guests, rooms);
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}

void book_room(struct guest guests[], struct room rooms[]) {
    int id, room_no, price, i, j, found = 0;
    char name[50], address[100], phone[20], room_type[20];

    printf("Enter guest ID: ");
    scanf("%d", &id);

    for (i = 0; i < 50; i++) {
        if (guests[i].id == id) {
            printf("Guest is already checked in!\n");
            return;
        }
    }

    printf("Enter guest name: ");
    getchar();
    fgets(name, 50, stdin);
    strtok(name, "\n");

    printf("Enter guest address: ");
    fgets(address, 100, stdin);
    strtok(address, "\n");

    printf("Enter guest phone: ");
    fgets(phone, 20, stdin);
    strtok(phone, "\n");

    printf("Rooms available:\n");
    printf("No\tType\tPrice\tOccupancy\n");

    for (i = 0; i < 20; i++) {
        if (rooms[i].available) {
            printf("%d\t%s\t%d\t%d\n", rooms[i].no, rooms[i].type, rooms[i].price, rooms[i].occupancy);
        }
    }

    do {
        printf("Enter room no: ");
        scanf("%d", &room_no);

        for (i = 0; i < 20; i++) {
            if (rooms[i].no == room_no) {
                found = 1;
                if (!rooms[i].available) {
                    printf("Room is already booked!\n");
                    found = 0;
                    break;
                }
                strcpy(room_type, rooms[i].type);
                price = rooms[i].price;
                rooms[i].available = 0;
                break;
            }
        }

        if (!found) {
            printf("Invalid room number! Please try again.\n");
        }
    } while (!found);

    i = 0;
    while (guests[i].id != 0) {
        i++;
    }

    guests[i].id = id;
    strcpy(guests[i].name, name);
    strcpy(guests[i].address, address);
    strcpy(guests[i].phone, phone);
    guests[i].room_no = room_no;
    strcpy(guests[i].room_type, room_type);

    printf("Room booked successfully!\n");
    printf("Total price: %d\n", price);
}

void check_out(struct guest guests[], struct room rooms[]) {
    int id, i, j, found = 0;

    printf("Enter guest ID: ");
    scanf("%d", &id);

    for (i = 0; i < 50; i++) {
        if (guests[i].id == id) {
            found = 1;
            for (j = 0; j < 20; j++) {
                if (rooms[j].no == guests[i].room_no) {
                    rooms[j].available = 1;
                    break;
                }
            }
            guests[i].id = 0;
            guests[i].name[0] = '\0';
            guests[i].address[0] = '\0';
            guests[i].phone[0] = '\0';
            guests[i].room_no = 0;
            guests[i].room_type[0] = '\0';
            printf("Check out successful!\n");
            break;
        }
    }

    if (!found) {
        printf("Invalid guest ID! Please try again.\n");
    }
}

void display_guests(struct guest guests[]) {
    int i;

    printf("ID\tName\tAddress\tPhone\tRoom No\tRoom Type\n");

    for (i = 0; i < 50; i++) {
        if (guests[i].id != 0) {
            printf("%d\t%s\t%s\t%s\t%d\t%s\n", guests[i].id, guests[i].name, guests[i].address, guests[i].phone, guests[i].room_no, guests[i].room_type);
        }
    }
}

void display_rooms(struct room rooms[]) {
    int i;

    printf("No\tType\tPrice\tOccupancy\tAvailability\n");

    for (i = 0; i < 20; i++) {
        printf("%d\t%s\t%d\t%d\t\t%s\n", rooms[i].no, rooms[i].type, rooms[i].price, rooms[i].occupancy, rooms[i].available ? "Available" : "Booked");
    }
}

void add_room(struct room rooms[]) {
    int no, price, occupancy, i;

    for (i = 0; i < 20; i++) {
        if (rooms[i].no == 0) {
            printf("Enter room no: ");
            scanf("%d", &no);

            printf("Enter room type: ");
            getchar();
            fgets(rooms[i].type, 20, stdin);
            strtok(rooms[i].type, "\n");

            printf("Enter room price: ");
            scanf("%d", &price);

            printf("Enter room occupancy: ");
            scanf("%d", &occupancy);

            rooms[i].no = no;
            rooms[i].price = price;
            rooms[i].occupancy = occupancy;
            rooms[i].available = 1;

            printf("Room added successfully!\n");
            return;
        }
    }

    printf("No rooms available for addition!\n");
}

void show_menu() {
    printf("\n===== C Hotel Management System =====\n");
    printf("1. Book Room\n");
    printf("2. Check Out\n");
    printf("3. Display Guests\n");
    printf("4. Display Rooms\n");
    printf("5. Add Room\n");
    printf("6. Save and Exit\n");
    printf("Enter your choice: ");
}

void save_data(struct guest guests[], struct room rooms[]) {
    FILE *file = fopen("data.txt", "w");
    int i;

    for (i = 0; i < 50; i++) {
        if (guests[i].id != 0) {
            fprintf(file, "%d;%s;%s;%s;%d;%s\n", guests[i].id, guests[i].name, guests[i].address, guests[i].phone, guests[i].room_no, guests[i].room_type);
        }
    }

    for (i = 0; i < 20; i++) {
        fprintf(file, "%d;%s;%d;%d;%d\n", rooms[i].no, rooms[i].type, rooms[i].price, rooms[i].occupancy, rooms[i].available);
    }

    fclose(file);
}

void load_data(struct guest guests[], struct room rooms[]) {
    FILE *file = fopen("data.txt", "r");
    char line[200];
    char *token;
    int i, j;

    if (file == NULL) {
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        j = 0;
        token = strtok(line, ";");
        guests[i].id = atoi(token);

        while (token != NULL) {
            token = strtok(NULL, ";");
            switch (j) {
                case 0:
                    strcpy(guests[i].name, token);
                    break;
                case 1:
                    strcpy(guests[i].address, token);
                    break;
                case 2:
                    strcpy(guests[i].phone, token);
                    break;
                case 3:
                    guests[i].room_no = atoi(token);
                    break;
                case 4:
                    strcpy(guests[i].room_type, token);
                    break;
                default:
                    break;
            }
            j++;
        }

        i++;
    }

    i = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        j = 0;
        token = strtok(line, ";");
        rooms[i].no = atoi(token);

        while (token != NULL) {
            token = strtok(NULL, ";");
            switch (j) {
                case 0:
                    strcpy(rooms[i].type, token);
                    break;
                case 1:
                    rooms[i].price = atoi(token);
                    break;
                case 2:
                    rooms[i].occupancy = atoi(token);
                    break;
                case 3:
                    rooms[i].available = atoi(token);
                    break;
                default:
                    break;
            }
            j++;
        }

        i++;
    }

    fclose(file);
}