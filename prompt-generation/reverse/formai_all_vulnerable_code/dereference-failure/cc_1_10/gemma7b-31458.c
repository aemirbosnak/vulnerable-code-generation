//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: genius
#include <stdio.h>
#include <string.h>

#define MAX_GUESTS 10

struct guest {
    char name[20];
    int room_number;
    float bill;
    struct guest* next;
};

struct hotel {
    struct guest* head;
    int num_guests;
    int rooms_available;
    struct hotel* next;
};

void add_guest(struct hotel* h, char* name, int room_number, float bill) {
    struct guest* new_guest = malloc(sizeof(struct guest));
    strcpy(new_guest->name, name);
    new_guest->room_number = room_number;
    new_guest->bill = bill;
    new_guest->next = NULL;

    if (h->head == NULL) {
        h->head = new_guest;
    } else {
        struct guest* temp = h->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_guest;
    }

    h->num_guests++;
    h->rooms_available--;
}

void check_out(struct hotel* h, char* name) {
    struct guest* temp = h->head;
    struct guest* prev = NULL;

    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            if (prev) {
                prev->next = temp->next;
            } else {
                h->head = temp->next;
            }
            h->num_guests--;
            h->rooms_available++;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Guest not found.\n");
}

int main() {
    struct hotel* h = malloc(sizeof(struct hotel));
    h->head = NULL;
    h->num_guests = 0;
    h->rooms_available = 100;
    h->next = NULL;

    add_guest(h, "John Doe", 101, 50.0);
    add_guest(h, "Jane Doe", 102, 60.0);
    add_guest(h, "Peter Pan", 103, 70.0);

    check_out(h, "Jane Doe");

    return 0;
}