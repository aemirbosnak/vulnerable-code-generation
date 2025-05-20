//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 100

struct Guest {
    char name[50];
    int room_no;
    float cost;
    struct Guest* next;
};

struct Hotel {
    struct Guest* head;
    int num_guests;
    float total_cost;
};

void insertGuest(struct Hotel* h) {
    struct Guest* new_guest = (struct Guest*)malloc(sizeof(struct Guest));
    printf("Enter guest name: ");
    scanf("%s", new_guest->name);
    printf("Enter room number: ");
    scanf("%d", &new_guest->room_no);
    printf("Enter guest cost: ");
    scanf("%f", &new_guest->cost);

    new_guest->next = h->head;
    h->head = new_guest;
    h->num_guests++;
    h->total_cost += new_guest->cost;
}

void checkIn(struct Hotel* h) {
    printf("Enter guest name: ");
    char guest_name[50];
    scanf("%s", guest_name);

    struct Guest* current_guest = h->head;
    while (current_guest) {
        if (strcmp(current_guest->name, guest_name) == 0) {
            printf("Room number: %d\n", current_guest->room_no);
            printf("Cost: %.2f\n", current_guest->cost);
            break;
        }
        current_guest = current_guest->next;
    }

    if (current_guest == NULL) {
        printf("Guest not found.\n");
    }
}

void checkOut(struct Hotel* h) {
    printf("Enter guest name: ");
    char guest_name[50];
    scanf("%s", guest_name);

    struct Guest* current_guest = h->head;
    struct Guest* previous_guest = NULL;

    while (current_guest) {
        if (strcmp(current_guest->name, guest_name) == 0) {
            if (previous_guest) {
                previous_guest->next = current_guest->next;
            } else {
                h->head = current_guest->next;
            }
            h->num_guests--;
            h->total_cost -= current_guest->cost;
            free(current_guest);
            break;
        }
        previous_guest = current_guest;
        current_guest = current_guest->next;
    }

    if (current_guest == NULL) {
        printf("Guest not found.\n");
    }
}

int main() {
    struct Hotel hotel;
    hotel.head = NULL;
    hotel.num_guests = 0;
    hotel.total_cost = 0.0f;

    int choice;

    while (1) {
        printf("Enter 1 to insert guest, 2 to check in, 3 to check out, or 4 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertGuest(&hotel);
                break;
            case 2:
                checkOut(&hotel);
                break;
            case 3:
                checkOut(&hotel);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    }

    return 0;
}