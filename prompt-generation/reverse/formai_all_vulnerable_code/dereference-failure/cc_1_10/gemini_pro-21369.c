//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_NAME_LENGTH 20
#define MAX_DESC_LENGTH 100

struct room {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESC_LENGTH];
    struct room *north;
    struct room *south;
    struct room *east;
    struct room *west;
};

struct player {
    char name[MAX_NAME_LENGTH];
    struct room *current_room;
};

struct game {
    struct room *rooms[MAX_ROOMS];
    struct player player;
};

struct room *create_room(char *name, char *description)
{
    struct room *room = malloc(sizeof(struct room));
    strcpy(room->name, name);
    strcpy(room->description, description);
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    return room;
}

struct game *create_game()
{
    struct game *game = malloc(sizeof(struct game));

    // Create rooms
    game->rooms[0] = create_room("Room 1", "This is room 1.");
    game->rooms[1] = create_room("Room 2", "This is room 2.");
    game->rooms[2] = create_room("Room 3", "This is room 3.");

    // Connect rooms
    game->rooms[0]->north = game->rooms[1];
    game->rooms[0]->east = game->rooms[2];
    game->rooms[1]->south = game->rooms[0];
    game->rooms[2]->west = game->rooms[0];

    // Set player's current room
    game->player.current_room = game->rooms[0];

    return game;
}

void free_game(struct game *game)
{
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (game->rooms[i] != NULL) {
            free(game->rooms[i]);
        }
    }
    free(game);
}

void print_room_description(struct room *room)
{
    printf("You are in %s.\n", room->name);
    printf("%s\n", room->description);
}

void print_room_exits(struct room *room)
{
    if (room->north != NULL) {
        printf("There is a door to the north.\n");
    }
    if (room->south != NULL) {
        printf("There is a door to the south.\n");
    }
    if (room->east != NULL) {
        printf("There is a door to the east.\n");
    }
    if (room->west != NULL) {
        printf("There is a door to the west.\n");
    }
}

void get_player_input(struct game *game)
{
    char input[10];
    printf("> ");
    scanf("%s", input);

    if (strcmp(input, "n") == 0) {
        if (game->player.current_room->north != NULL) {
            game->player.current_room = game->player.current_room->north;
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(input, "s") == 0) {
        if (game->player.current_room->south != NULL) {
            game->player.current_room = game->player.current_room->south;
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(input, "e") == 0) {
        if (game->player.current_room->east != NULL) {
            game->player.current_room = game->player.current_room->east;
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(input, "w") == 0) {
        if (game->player.current_room->west != NULL) {
            game->player.current_room = game->player.current_room->west;
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(input, "q") == 0) {
        exit(0);
    } else {
        printf("I don't understand that command.\n");
    }
}

void play_game(struct game *game)
{
    while (1) {
        print_room_description(game->player.current_room);
        print_room_exits(game->player.current_room);
        get_player_input(game);
    }
}

int main()
{
    struct game *game = create_game();
    play_game(game);
    free_game(game);
    return 0;
}