//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: medieval
// Arise, brave knights and fair maidens, for we embark on a noble quest to seek the elusive Grail!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lo, a vast castle of stone and timber, with many towers and secret passages!
typedef struct Castle {
    char *name;
    int num_rooms;
    struct Room *rooms;
} Castle;

// Each room is a sanctuary, a place of respite or peril.
typedef struct Room {
    char *name;
    int num_treasures;
    char **treasures;
} Room;

// The Grail, the object of our desire, hidden within the deepest chambers of the castle.
typedef struct Grail {
    char *name;
    int value;
} Grail;

// Our noble knights, each with their own unique skills and abilities.
typedef struct Knight {
    char *name;
    int strength;
    int agility;
    int intelligence;
} Knight;

// The heart of our quest, the search for the Grail within the castle's labyrinthine halls.
int search_for_grail(Castle *castle, Knight *knight) {
    printf("Sir %s, thou hast embarked on a most perilous quest.\n", knight->name);

    // Iterate through each room of the castle, seeking the Grail.
    for (int i = 0; i < castle->num_rooms; i++) {
        Room *room = &castle->rooms[i];

        // Lo, a room! Let us explore its secrets.
        printf("Thou enterest the %s.\n", room->name);

        // Search for the Grail among the room's treasures.
        for (int j = 0; j < room->num_treasures; j++) {
            char *treasure = room->treasures[j];

            // Behold! Is this the Grail we seek?
            if (strcmp(treasure, "Holy Grail") == 0) {
                printf("Huzzah! Sir %s, thou hast found the Grail!\n", knight->name);

                // Our quest is complete! We have found the Grail.
                return 0;
            }
        }
    }

    // Alas, the Grail was not found in this castle.
    printf("Thy quest ends here, Sir %s. The Grail remains elusive.\n", knight->name);
    return 1;
}

int main(void) {
    // Let us construct a magnificent castle for our quest.
    Castle castle = {
        .name = "Castle Anthrax",
        .num_rooms = 100,
        .rooms = malloc(sizeof(Room) * 100)
    };

    // Now, we must populate the castle with treacherous rooms.
    for (int i = 0; i < castle.num_rooms; i++) {
        Room *room = &castle.rooms[i];
        room->name = malloc(32);
        sprintf(room->name, "Room %d", i + 1);
        room->num_treasures = rand() % 10;
        room->treasures = malloc(sizeof(char *) * room->num_treasures);
        for (int j = 0; j < room->num_treasures; j++) {
            room->treasures[j] = malloc(32);
            sprintf(room->treasures[j], "Treasure %d", j + 1);
        }
    }

    // And finally, we summon a brave knight to embark on this perilous journey.
    Knight knight = {
        .name = "Sir Galahad",
        .strength = 10,
        .agility = 8,
        .intelligence = 12
    };

    // Let us now begin our search for the Holy Grail within the castle's treacherous depths.
    int result = search_for_grail(&castle, &knight);

    // Our quest is now complete. Let us bid farewell to the castle and its secrets.
    for (int i = 0; i < castle.num_rooms; i++) {
        Room *room = &castle.rooms[i];
        free(room->name);
        for (int j = 0; j < room->num_treasures; j++) {
            free(room->treasures[j]);
        }
        free(room->treasures);
    }
    free(castle.rooms);
    return result;
}