//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct room {
    char *name;
    char *description;
    int num_exits;
    struct room *exits[MAX_ROOMS];
} room;

room *create_room(char *name, char *description) {
    room *new_room = malloc(sizeof(room));
    new_room->name = strdup(name);
    new_room->description = strdup(description);
    new_room->num_exits = 0;
    return new_room;
}

void destroy_room(room *room) {
    free(room->name);
    free(room->description);
    free(room);
}

void add_exit(room *from, room *to) {
    from->exits[from->num_exits++] = to;
}

room *find_room(room *rooms[], int num_rooms, char *name) {
    for (int i = 0; i < num_rooms; i++) {
        if (strcmp(rooms[i]->name, name) == 0) {
            return rooms[i];
        }
    }
    return NULL;
}

void print_room(room *room) {
    printf("%s\n", room->name);
    printf("%s\n", room->description);
    printf("Exits:");
    for (int i = 0; i < room->num_exits; i++) {
        printf(" %s", room->exits[i]->name);
    }
    printf("\n");
}

int main() {
    room *rooms[MAX_ROOMS];
    int num_rooms = 0;

    room *kitchen = create_room("Kitchen", "A small kitchen with a stove, oven, and refrigerator.");
    add_exit(kitchen, create_room("Living Room", "A cozy living room with a couch, TV, and fireplace."));
    add_exit(kitchen, create_room("Dining Room", "A formal dining room with a large table and chairs."));
    rooms[num_rooms++] = kitchen;

    room *living_room = find_room(rooms, num_rooms, "Living Room");
    add_exit(living_room, kitchen);
    add_exit(living_room, create_room("Bedroom", "A master bedroom with a king-sized bed and a private bathroom."));
    rooms[num_rooms++] = living_room;

    room *dining_room = find_room(rooms, num_rooms, "Dining Room");
    add_exit(dining_room, kitchen);
    rooms[num_rooms++] = dining_room;

    room *bedroom = find_room(rooms, num_rooms, "Bedroom");
    add_exit(bedroom, living_room);
    rooms[num_rooms++] = bedroom;

    room *current_room = kitchen;

    while (1) {
        print_room(current_room);

        printf("What do you want to do? (n/s/e/w/q): ");
        char input[2];
        scanf("%s", input);

        if (strcmp(input, "n") == 0) {
            current_room = current_room->exits[0];
        } else if (strcmp(input, "s") == 0) {
            current_room = current_room->exits[1];
        } else if (strcmp(input, "e") == 0) {
            current_room = current_room->exits[2];
        } else if (strcmp(input, "w") == 0) {
            current_room = current_room->exits[3];
        } else if (strcmp(input, "q") == 0) {
            break;
        }
    }

    for (int i = 0; i < num_rooms; i++) {
        destroy_room(rooms[i]);
    }

    return 0;
}