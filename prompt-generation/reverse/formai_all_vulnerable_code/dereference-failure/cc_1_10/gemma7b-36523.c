//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: shape shifting
#include <stdlib.h>
#include <time.h>

#define ROOM_NUM 5

typedef struct room_t {
    char name[20];
    struct room_t* next;
} room_t;

room_t* create_room(char* name) {
    room_t* new_room = (room_t*)malloc(sizeof(room_t));
    strcpy(new_room->name, name);
    new_room->next = NULL;
    return new_room;
}

void connect_rooms(room_t* room1, room_t* room2) {
    room1->next = room2;
}

void simulate_haunted_house(room_t* current_room) {
    srand(time(NULL));
    int rand_num = rand() % ROOM_NUM;

    switch (rand_num) {
        case 0:
            printf("You hear a shuffling sound coming from the hallway.\n");
            current_room = current_room->next;
            break;
        case 1:
            printf("You smell a faint burning odor in the air.\n");
            current_room = current_room->next;
            break;
        case 2:
            printf("You hear a disembodied voice whispering your name.\n");
            current_room = current_room->next;
            break;
        case 3:
            printf("You see a ghostly figure moving towards you.\n");
            current_room = current_room->next;
            break;
        case 4:
            printf("You feel a cold hand brush against your skin.\n");
            current_room = current_room->next;
            break;
    }

    simulate_haunted_house(current_room);
}

int main() {
    room_t* first_room = create_room("The Foyer");
    room_t* second_room = create_room("The Living Room");
    room_t* third_room = create_room("The Dining Room");
    room_t* fourth_room = create_room("The Kitchen");
    room_t* fifth_room = create_room("The Master Bedroom");

    connect_rooms(first_room, second_room);
    connect_rooms(second_room, third_room);
    connect_rooms(third_room, fourth_room);
    connect_rooms(fourth_room, fifth_room);

    simulate_haunted_house(first_room);

    return 0;
}