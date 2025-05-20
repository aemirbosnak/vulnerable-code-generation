//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct room {
    int room_number;
    char room_type;
    int is_occupied;
    char *guest_name;
} room;

typedef struct hotel {
    int num_rooms;
    room *rooms;
} hotel;

hotel *create_hotel(int num_rooms)
{
    hotel *h = malloc(sizeof(hotel));
    h->num_rooms = num_rooms;
    h->rooms = malloc(num_rooms * sizeof(room));

    for (int i = 0; i < num_rooms; i++) {
        h->rooms[i].room_number = i + 1;
        h->rooms[i].room_type = 'S';
        h->rooms[i].is_occupied = 0;
        h->rooms[i].guest_name = NULL;
    }

    return h;
}

void destroy_hotel(hotel *h)
{
    for (int i = 0; i < h->num_rooms; i++) {
        free(h->rooms[i].guest_name);
    }

    free(h->rooms);
    free(h);
}

void check_in(hotel *h, int room_number, char *guest_name)
{
    room *r = &h->rooms[room_number - 1];

    if (r->is_occupied) {
        printf("Room %d is already occupied.\n", room_number);
        return;
    }

    r->is_occupied = 1;

    if (r->guest_name != NULL) {
        free(r->guest_name);
    }

    r->guest_name = malloc(strlen(guest_name) + 1);
    strcpy(r->guest_name, guest_name);
}

void check_out(hotel *h, int room_number)
{
    room *r = &h->rooms[room_number - 1];

    if (!r->is_occupied) {
        printf("Room %d is already empty.\n", room_number);
        return;
    }

    r->is_occupied = 0;

    if (r->guest_name != NULL) {
        free(r->guest_name);
        r->guest_name = NULL;
    }
}

void print_hotel(hotel *h)
{
    printf("Room\tType\tOccupied\tGuest\n");

    for (int i = 0; i < h->num_rooms; i++) {
        room *r = &h->rooms[i];
        printf("%d\t", r->room_number);
        printf("%c\t", r->room_type);
        printf("%d\t", r->is_occupied);
        printf("%s\n", r->guest_name != NULL ? r->guest_name : "Vacant");
    }
}

int main()
{
    int num_rooms = 10;
    hotel *h = create_hotel(num_rooms);

    print_hotel(h);

    check_in(h, 1, "John Doe");
    check_in(h, 5, "Jane Smith");

    print_hotel(h);

    check_out(h, 1);
    check_out(h, 5);

    print_hotel(h);

    destroy_hotel(h);

    return 0;
}