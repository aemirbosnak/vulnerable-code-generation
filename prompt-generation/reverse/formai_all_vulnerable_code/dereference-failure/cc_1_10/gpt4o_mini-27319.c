//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 5

typedef struct {
    char* name;
    int key;
} Item;

typedef struct {
    char* description;
    Item* items[MAX_ITEMS];
    int items_count;
} Room;

typedef struct {
    Room* current_room;
} Player;

void initialize_rooms(Room* rooms) {
    rooms[0].description = "You are in a dimly lit dungeon entrance. There are doors to the north and east.";
    rooms[0].items_count = 0;

    rooms[1].description = "You find yourself in a treasure room filled with gold. Doors lead back south and east.";
    rooms[1].items_count = 0;

    rooms[2].description = "You are in a dark and scary room. The only way out is to the west.";
    rooms[2].items_count = 0;

    // Adding some items
    Item* sword = malloc(sizeof(Item));
    sword->name = "Sword";
    sword->key = 0;

    Item* key = malloc(sizeof(Item));
    key->name = "Rusty Key";
    key->key = 1;

    rooms[1].items[rooms[1].items_count++] = sword; // Add sword to treasure room
    rooms[0].items[rooms[0].items_count++] = key;   // Add key to dungeon entrance
}

void free_rooms(Room* rooms) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < rooms[i].items_count; j++) {
            free(rooms[i].items[j]);
        }
    }
}

void print_room_description(Room* room) {
    printf("%s\n", room->description);
    if (room->items_count > 0) {
        printf("You see:\n");
        for (int i = 0; i < room->items_count; i++) {
            printf("- %s\n", room->items[i]->name);
        }
    } else {
        printf("The room is empty.\n");
    }
}

void move_player(Player* player, Room* rooms, char* direction) {
    if (strcmp(direction, "north") == 0 && player->current_room == &rooms[0]) {
        player->current_room = &rooms[1];
    } else if (strcmp(direction, "east") == 0 && player->current_room == &rooms[0]) {
        player->current_room = &rooms[2];
    } else if (strcmp(direction, "south") == 0 && player->current_room == &rooms[1]) {
        player->current_room = &rooms[0];
    } else if (strcmp(direction, "west") == 0 && player->current_room == &rooms[2]) {
        player->current_room = &rooms[0];
    } else {
        printf("You can't go that way!\n");
    }
}

int main() {
    Room rooms[3];
    initialize_rooms(rooms);

    Player player;
    player.current_room = &rooms[0];

    char command[20];
    printf("Welcome to the Dungeon Adventure!\n");
    
    while (1) {
        print_room_description(player.current_room);
        printf("Enter a command (move [north/east/south/west] or exit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // remove trailing newline
        
        if (strcmp(command, "exit") == 0) {
            printf("Thank you for playing!\n");
            break;
        } else if (strncmp(command, "move ", 5) == 0) {
            move_player(&player, rooms, &command[5]);
        } else {
            printf("Unknown command.\n");
        }
    }

    free_rooms(rooms);
    return 0;
}