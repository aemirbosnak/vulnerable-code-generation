//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

typedef struct Room
{
    int id;
    char* name;
    int price;
} Room;

typedef struct Hotel
{
    int id;
    char* name;
    int capacity;
    int current_occupancy;
    Room* rooms;
} Hotel;

void create_room(Hotel* hotel, Room* room)
{
    room->id = hotel->current_occupancy;
    hotel->current_occupancy++;

    printf("Room %d created\n", room->id);
}

void create_hotel(Hotel* hotel)
{
    hotel->id = 1;
    hotel->name = "My Hotel";
    hotel->capacity = 10;
    hotel->current_occupancy = 0;
    hotel->rooms = malloc(sizeof(Room));
    hotel->rooms[0].id = 1;
    hotel->rooms[0].name = "Room 1";
    hotel->rooms[0].price = 100;
}

void display_hotel(Hotel* hotel)
{
    printf("Hotel %d - %s\n", hotel->id, hotel->name);
    printf("Capacity: %d\n", hotel->capacity);
    printf("Current Occupancy: %d\n", hotel->current_occupancy);
    printf("Rooms:\n");
    for(int i = 0; i < hotel->current_occupancy; i++)
    {
        printf("Room %d - %s\n", i + 1, hotel->rooms[i].name);
    }
}

int main()
{
    Hotel* hotel = malloc(sizeof(Hotel));

    create_hotel(hotel);
    display_hotel(hotel);

    Room room = {1, "Room 1", 100};
    create_room(hotel, &room);
    display_hotel(hotel);

    free(hotel);
    return 0;
}