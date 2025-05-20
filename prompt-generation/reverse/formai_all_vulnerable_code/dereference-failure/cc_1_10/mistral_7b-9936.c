//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <signal.h>
#include <math.h>

#define HAUNTED_HOUSE_SIZE 10

typedef struct Room {
    int id;
    float ghost_density;
    struct Room *next;
} Room;

void randomize_ghost_density(Room *room) {
    room->ghost_density = (float) rand() / RAND_MAX;
}

void create_room(Room **rooms, int id) {
    Room *new_room = (Room *) malloc(sizeof(Room));
    new_room->id = id;
    new_room->next = *rooms;
    *rooms = new_room;
}

void generate_haunted_house(Room **rooms) {
    int i;

    for(i = 0; i < HAUNTED_HOUSE_SIZE; i++) {
        create_room(rooms, i);
        randomize_ghost_density(*rooms);
        (*rooms) = (*rooms)->next;
    }
}

void print_room(Room *room) {
    printf("Room %d: Ghost density: %.2f\n", room->id, room->ghost_density);
}

void print_haunted_house(Room *rooms) {
    while(rooms != NULL) {
        print_room(rooms);
        rooms = rooms->next;
    }
}

int main() {
    Room *haunted_house = NULL;

    srand(time(NULL));

    printf("Generating Haunted House...\n");
    generate_haunted_house(&haunted_house);

    printf("\nHaunted House Details:\n");
    print_haunted_house(haunted_house);

    free(haunted_house);

    return 0;
}