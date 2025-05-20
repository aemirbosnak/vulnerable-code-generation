//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DESCRIPTION 255

typedef enum {false, true} bool;

typedef struct Room Room;
struct Room {
    char *name;
    char *description;
    Room *north;
    Room *south;
    Room *east;
    Room *west;
};

typedef struct {
    Room **rooms;
    int num_rooms;
} House;

typedef struct {
    char *name;
    char *description;
    int health;
    Room *location;
} Player;

/* Function prototypes */
House *generate_house(int num_rooms);
void destroy_house(House *house);
Room *generate_room(char *name, char *description);
void destroy_room(Room *room);
void connect_rooms(Room *room1, Room *room2, char direction);
Player *create_player(char *name, char *description, Room *starting_room);
void destroy_player(Player *player);
void print_room(Room *room, Player *player);
void game_loop(Player *player);

int main(void) {
    srand(time(NULL));
    /* Generate a house with 10 rooms */
    House *house = generate_house(10);
    /* Create a player and place them in a randomly selected room */
    Player *player = create_player("Player", "You are the player", house->rooms[rand() % house->num_rooms]);
    /* Start the game loop */
    game_loop(player);
    /* Clean up memory */
    destroy_player(player);
    destroy_house(house);
    return 0;
}

/* Generates a house with the specified number of rooms */
House *generate_house(int num_rooms) {
    House *house = malloc(sizeof(House));
    house->rooms = malloc(num_rooms * sizeof(Room *));
    house->num_rooms = num_rooms;
    char room_name[MAX_DESCRIPTION];
    char room_description[MAX_DESCRIPTION];
    for (int i = 0; i < num_rooms; i++) {
        snprintf(room_name, MAX_DESCRIPTION, "Room %d", i+1);
        snprintf(room_description, MAX_DESCRIPTION, "You are in %s. ", room_name);
        house->rooms[i] = generate_room(room_name, room_description);
    }
    for (int i = 0; i < num_rooms; i++) {
        /* Connect the rooms to their neighbors randomly */
        if (i > 0) {
            connect_rooms(house->rooms[i], house->rooms[i-1], 'w');
        }
        if (i < num_rooms - 1) {
            connect_rooms(house->rooms[i], house->rooms[i+1], 'e');
        }
        /* Connect the rooms to their random north/south neighbors */
        if (rand() % 2 == 0 && i > 0) {
            connect_rooms(house->rooms[i], house->rooms[i-1], 'n');
        } else if (i < num_rooms - 1) {
            connect_rooms(house->rooms[i], house->rooms[i+1], 's');
        }
    }
    return house;
}

/* Frees memory allocated for the house and all its rooms */
void destroy_house(House *house) {
    for (int i = 0; i < house->num_rooms; i++) {
        destroy_room(house->rooms[i]);
    }
    free(house->rooms);
    free(house);
}

/* Generates a Room with the specified name and description */
Room *generate_room(char *name, char *description) {
    Room *room = malloc(sizeof(Room));
    room->name = strdup(name);
    room->description = strdup(description);
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    return room;
}

/* Frees memory allocated for the room */
void destroy_room(Room *room) {
    free(room->name);
    free(room->description);
    free(room);
}

/* Connects two rooms in the specified direction */
void connect_rooms(Room *room1, Room *room2, char direction) {
    switch(direction) {
        case 'n':
            room1->north = room2;
            room2->south = room1;
            break;
        case 's':
            room1->south = room2;
            room2->north = room1;
            break;
        case 'e':
            room1->east = room2;
            room2->west = room1;
            break;
        case 'w':
            room1->west = room2;
            room2->east = room1;
            break;
    }
}

/* Creates a player with the specified name, description, and starting location */
Player *create_player(char *name, char *description, Room *starting_room) {
    Player *player = malloc(sizeof(Player));
    player->name = strdup(name);
    player->description = strdup(description);
    player->health = 100;
    player->location = starting_room;
    return player;
}

/* Frees memory allocated for the player */
void destroy_player(Player *player) {
    free(player->name);
    free(player->description);
    free(player);
}

/* Prints out the description of the room and the available exits */
void print_room(Room *room, Player *player) {
    printf("%s\n", room->description);
    printf("Exits: ");
    if (room->north != NULL) {
        printf("N ");
    }
    if (room->south != NULL) {
        printf("S ");
    }
    if (room->east != NULL) {
        printf("E ");
    }
    if (room->west != NULL) {
        printf("W ");
    }
    printf("\n");
}

/* Main game loop */
void game_loop(Player *player) {
    bool quit = false;
    char input[MAX_DESCRIPTION];
    while (!quit) {
        /* Print out the current room's description and available exits */
        print_room(player->location, player);
        printf("> ");
        fgets(input, MAX_DESCRIPTION, stdin);
        /* Get rid of the newline character at the end of the user's input */
        input[strcspn(input, "\n")] = 0;
        /* Parse the user's input */
        if (strcmp(input, "quit") == 0 || strcmp(input, "q") == 0) {
            quit = true;
        } else if (strcmp(input, "help") == 0 || strcmp(input, "h") == 0) {
            printf("Available commands: help, quit, n, s, e, w\n");
        } else if (strcmp(input, "n") == 0 && player->location->north != NULL) {
            player->location = player->location->north;
        } else if (strcmp(input, "s") == 0 && player->location->south != NULL) {
            player->location = player->location->south;
        } else if (strcmp(input, "e") == 0 && player->location->east != NULL) {
            player->location = player->location->east;
        } else if (strcmp(input, "w") == 0 && player->location->west != NULL) {
            player->location = player->location->west;
        } else {
            printf("Invalid command. Type 'help' for a list of available commands.\n");
        }
    }
}