//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESC_LEN 256

typedef struct {
    char* name;
    char* description;
    int num_exits;
    char* exits[4];
} Room;

typedef struct {
    Room* current_room;
    int inventory[10];
    int num_inventory_items;
} Player;

Player player;

Room rooms[10];

void init_rooms() {
    strcpy(rooms[0].name, "The Hall of Mirrors");
    strcpy(rooms[0].description, "You are in a large hall with mirrors on all sides. You can see your reflection in each mirror, and you can hear your own voice echoing around the room.");
    rooms[0].num_exits = 4;
    rooms[0].exits[0] = "north";
    rooms[0].exits[1] = "east";
    rooms[0].exits[2] = "south";
    rooms[0].exits[3] = "west";

    strcpy(rooms[1].name, "The Room of Doors");
    strcpy(rooms[1].description, "You are in a room with doors on all sides. Each door is a different color, and you can hear strange noises coming from behind each one.");
    rooms[1].num_exits = 4;
    rooms[1].exits[0] = "north";
    rooms[1].exits[1] = "east";
    rooms[1].exits[2] = "south";
    rooms[1].exits[3] = "west";

    strcpy(rooms[2].name, "The Room of Shadows");
    strcpy(rooms[2].description, "You are in a dark room with shadows dancing on the walls. You can feel the shadows moving around you, and you can hear their whispers.");
    rooms[2].num_exits = 4;
    rooms[2].exits[0] = "north";
    rooms[2].exits[1] = "east";
    rooms[2].exits[2] = "south";
    rooms[2].exits[3] = "west";

    strcpy(rooms[3].name, "The Room of Dreams");
    strcpy(rooms[3].description, "You are in a strange room that seems to be made of clouds. You can see strange creatures floating in the air, and you can hear the sound of music.");
    rooms[3].num_exits = 4;
    rooms[3].exits[0] = "north";
    rooms[3].exits[1] = "east";
    rooms[3].exits[2] = "south";
    rooms[3].exits[3] = "west";

    strcpy(rooms[4].name, "The Room of Nightmares");
    strcpy(rooms[4].description, "You are in a dark room with strange creatures crawling on the walls. You can hear the sound of screams, and you can smell the stench of death.");
    rooms[4].num_exits = 4;
    rooms[4].exits[0] = "north";
    rooms[4].exits[1] = "east";
    rooms[4].exits[2] = "south";
    rooms[4].exits[3] = "west";

    strcpy(rooms[5].name, "The Room of Secrets");
    strcpy(rooms[5].description, "You are in a small room with a single door. The door is locked, and you can hear voices coming from behind it.");
    rooms[5].num_exits = 1;
    rooms[5].exits[0] = "door";

    strcpy(rooms[6].name, "The Room of Time");
    strcpy(rooms[6].description, "You are in a large room with a clock on the wall. The clock is ticking, and you can feel the time slipping away.");
    rooms[6].num_exits = 4;
    rooms[6].exits[0] = "north";
    rooms[6].exits[1] = "east";
    rooms[6].exits[2] = "south";
    rooms[6].exits[3] = "west";

    strcpy(rooms[7].name, "The Room of Space");
    strcpy(rooms[7].description, "You are in a vast room with no walls or ceiling. You can see stars twinkling in the distance, and you can feel the wind blowing through your hair.");
    rooms[7].num_exits = 4;
    rooms[7].exits[0] = "north";
    rooms[7].exits[1] = "east";
    rooms[7].exits[2] = "south";
    rooms[7].exits[3] = "west";

    strcpy(rooms[8].name, "The Room of Mind");
    strcpy(rooms[8].description, "You are in a strange room that seems to be made of your own thoughts. You can see your memories floating in the air, and you can hear the sound of your own thoughts.");
    rooms[8].num_exits = 4;
    rooms[8].exits[0] = "north";
    rooms[8].exits[1] = "east";
    rooms[8].exits[2] = "south";
    rooms[8].exits[3] = "west";

    strcpy(rooms[9].name, "The Room of Soul");
    strcpy(rooms[9].description, "You are in a dark room with a single candle burning in the center. You can see your own reflection in the candle flame, and you can hear the sound of your own heartbeat.");
    rooms[9].num_exits = 1;
    rooms[9].exits[0] = "door";
}

void init_player() {
    player.current_room = &rooms[0];
    player.num_inventory_items = 0;
}

void print_room_description() {
    printf("%s\n", player.current_room->description);
}

void print_exit_options() {
    printf("Exits: ");
    for (int i = 0; i < player.current_room->num_exits; i++) {
        printf("%s ", player.current_room->exits[i]);
    }
    printf("\n");
}

void handle_input() {
    char input[MAX_DESC_LEN];
    printf("> ");
    fgets(input, MAX_DESC_LEN, stdin);

    char* command = strtok(input, " ");
    char* argument = strtok(NULL, " ");

    if (strcmp(command, "go") == 0) {
        for (int i = 0; i < player.current_room->num_exits; i++) {
            if (strcmp(argument, player.current_room->exits[i]) == 0) {
                player.current_room = &rooms[i];
                print_room_description();
                print_exit_options();
                return;
            }
        }
        printf("Invalid exit.\n");
    } else if (strcmp(command, "examine") == 0) {
        printf("%s\n", player.current_room->description);
    } else if (strcmp(command, "quit") == 0) {
        exit(0);
    } else {
        printf("Invalid command.\n");
    }
}

int main() {
    init_rooms();
    init_player();
    print_room_description();
    print_exit_options();

    while (1) {
        handle_input();
    }

    return 0;
}