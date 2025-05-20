//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ROOMS 10
#define MAX_PLAYERS 5
#define MAX_ROOM_SIZE 100
#define MAX_PLAYER_NAME_LEN 50

typedef struct player_s {
    char name[MAX_PLAYER_NAME_LEN];
    int x;
    int y;
} player_t;

typedef struct room_s {
    char name[MAX_ROOM_SIZE];
    int n_players;
    player_t players[MAX_PLAYERS];
} room_t;

room_t rooms[MAX_ROOMS];
int num_rooms;

void init_rooms(void) {
    int i;
    for (i = 0; i < num_rooms; i++) {
        rooms[i].name[0] = '\0';
        rooms[i].n_players = 0;
        memset(rooms[i].players, 0, sizeof(rooms[i].players));
    }
}

void print_rooms(void) {
    int i;
    for (i = 0; i < num_rooms; i++) {
        printf("Room %d: %s\n", i + 1, rooms[i].name);
        printf("Players: ");
        for (int j = 0; j < rooms[i].n_players; j++) {
            printf("%s ", rooms[i].players[j].name);
        }
        printf("\n");
    }
}

void add_player_to_room(int room_num, char* player_name) {
    int i;
    for (i = 0; i < num_rooms; i++) {
        if (strcmp(rooms[i].name, "Room " + room_num) == 0) {
            if (rooms[i].n_players < MAX_PLAYERS) {
                strcpy(rooms[i].players[rooms[i].n_players].name, player_name);
                rooms[i].n_players++;
                break;
            }
        }
    }
}

int main(int argc, char** argv) {
    int i, j;
    char player_name[MAX_PLAYER_NAME_LEN];
    int num_rooms = 0;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-r") == 0) {
            i++;
            num_rooms = atoi(argv[i]);
        }
    }
    if (num_rooms < 1 || num_rooms > MAX_ROOMS) {
        printf("Invalid number of rooms specified\n");
        exit(1);
    }
    init_rooms();
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Please enter the names of the players:\n");
    for (i = 0; i < num_rooms; i++) {
        printf("Room %d: ", i + 1);
        fgets(player_name, MAX_PLAYER_NAME_LEN, stdin);
        add_player_to_room(i + 1, player_name);
    }
    print_rooms();
    printf("Players have entered the haunted house!\n");
    for (i = 0; i < num_rooms; i++) {
        printf("Room %d: ", i + 1);
        for (j = 0; j < rooms[i].n_players; j++) {
            printf("%s ", rooms[i].players[j].name);
        }
        printf("\n");
    }
    return 0;
}