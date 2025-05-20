//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Room {
    int x, y;
    char name[50];
};

struct Player {
    struct Room *room;
    int health;
};

struct Room *getRandomRoom() {
    struct Room *room = (struct Room*)malloc(sizeof(struct Room));
    srand(time(NULL));
    room->x = rand() % 10 + 1;
    room->y = rand() % 10 + 1;
    sprintf(room->name, "Room %d %d", room->x, room->y);
    return room;
}

void printRoom(struct Room *room) {
    printf("Current room: %s\n", room->name);
}

void printHealth(struct Player *player) {
    printf("Health: %d\n", player->health);
}

int main() {
    struct Player *player = (struct Player*)malloc(sizeof(struct Player));
    player->room = getRandomRoom();
    player->health = 100;

    while (player->health > 0) {
        printRoom(player->room);
        printf("Health: %d\n", player->health);
        printHealth(player);
        printf("Enter 'e' to go east, 'w' to go west, 'n' to go north,'s' to go south, 'q' to quit: ");
        char direction = getchar();
        if (direction == 'e') {
            if (player->room->x == 1) {
                player->health -= 10;
                printf("You hit your head on the wall!\n");
            } else {
                player->room->x--;
                printRoom(player->room);
            }
        } else if (direction == 'w') {
            if (player->room->x == 10) {
                player->health -= 10;
                printf("You hit your head on the wall!\n");
            } else {
                player->room->x++;
                printRoom(player->room);
            }
        } else if (direction == 'n') {
            if (player->room->y == 1) {
                player->health -= 10;
                printf("You hit your head on the ceiling!\n");
            } else {
                player->room->y--;
                printRoom(player->room);
            }
        } else if (direction =='s') {
            if (player->room->y == 10) {
                player->health -= 10;
                printf("You hit your head on the floor!\n");
            } else {
                player->room->y++;
                printRoom(player->room);
            }
        } else if (direction == 'q') {
            break;
        } else {
            printf("Invalid direction!\n");
        }
    }

    free(player->room);
    free(player);

    return 0;
}