//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct room {
    char *description;
    int north;
    int south;
    int east;
    int west;
};

void print_room(struct room *room) {
    printf("%s\n", room->description);
}

int main() {
    srand(time(NULL));

    struct room *rooms = malloc(sizeof(struct room) * 6);

    rooms[0] = (struct room) {
       .description = "You are standing in a forest. There is a path leading north and east.",
       .north = 1,
       .east = 2,
    };

    rooms[1] = (struct room) {
       .description = "You are standing at the entrance of a dark cave. There is a torch on the ground.",
       .north = -1,
    };

    rooms[2] = (struct room) {
       .description = "You are in a small room with a locked door. There is a key on the table.",
       .north = -1,
    };

    rooms[3] = (struct room) {
       .description = "You are in a large room with a throne. A king is sitting on the throne.",
       .north = -1,
    };

    rooms[4] = (struct room) {
       .description = "You are in a maze. There are four paths leading in different directions.",
       .north = 3,
       .south = 5,
       .east = 1,
       .west = 2,
    };

    rooms[5] = (struct room) {
       .description = "You are in a dark room. There is a glowing crystal on a pedestal.",
       .north = -1,
    };

    int current_room = 0;

    while (1) {
        print_room(rooms + current_room);

        char direction;
        scanf("%c", &direction);

        switch (direction) {
            case 'n':
                if (rooms[current_room].north!= -1)
                    current_room = rooms[current_room].north;
                else
                    printf("There is no path leading north.\n");
                break;
            case's':
                if (rooms[current_room].south!= -1)
                    current_room = rooms[current_room].south;
                else
                    printf("There is no path leading south.\n");
                break;
            case 'e':
                if (rooms[current_room].east!= -1)
                    current_room = rooms[current_room].east;
                else
                    printf("There is no path leading east.\n");
                break;
            case 'w':
                if (rooms[current_room].west!= -1)
                    current_room = rooms[current_room].west;
                else
                    printf("There is no path leading west.\n");
                break;
            default:
                printf("Invalid direction.\n");
        }
    }

    free(rooms);

    return 0;
}