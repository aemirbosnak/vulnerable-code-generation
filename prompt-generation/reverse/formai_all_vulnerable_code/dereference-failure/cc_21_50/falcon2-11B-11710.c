//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef struct Room {
    char name[50];
    char description[200];
    int doors;
    int exit;
    int num_enemies;
    int num_traps;
} Room;

typedef struct Enemy {
    char name[50];
    char description[200];
    int health;
    int damage;
} Enemy;

typedef struct Trap {
    char name[50];
    char description[200];
    int damage;
} Trap;

typedef struct Player {
    char name[50];
    int health;
    int stamina;
    int x;
    int y;
    int current_room;
} Player;

int main() {
    srand(time(NULL));

    Room rooms[10];
    Enemy enemies[5];
    Trap traps[3];
    Player player;

    for (int i = 0; i < 10; i++) {
        strcpy(rooms[i].name, "Room ");
        strcat(rooms[i].name, i + 1);
        rooms[i].doors = rand() % 3 + 1;
        rooms[i].exit = rand() % 2 + 1;
        rooms[i].num_enemies = rand() % 4 + 1;
        rooms[i].num_traps = rand() % 3 + 1;
    }

    for (int i = 0; i < 5; i++) {
        strcpy(enemies[i].name, "Enemy ");
        strcat(enemies[i].name, i + 1);
        enemies[i].health = rand() % 10 + 1;
        enemies[i].damage = rand() % 5 + 1;
    }

    for (int i = 0; i < 3; i++) {
        strcpy(traps[i].name, "Trap ");
        strcat(traps[i].name, i + 1);
        traps[i].damage = rand() % 10 + 1;
    }

    strcpy(player.name, "Player");
    player.health = 10;
    player.stamina = 5;
    player.x = rand() % 10 + 1;
    player.y = rand() % 10 + 1;
    player.current_room = rand() % 10 + 1;

    printf("Welcome to the Haunted House Simulator!\n");

    while (player.health > 0 && player.stamina > 0) {
        printf("Current Room: %s\n", rooms[player.current_room].name);
        printf("Enemies: %d\n", rooms[player.current_room].num_enemies);
        printf("Traps: %d\n", rooms[player.current_room].num_traps);

        for (int i = 0; i < rooms[player.current_room].doors; i++) {
            if (i == rooms[player.current_room].exit) {
                printf("You have escaped the room!\n");
                player.current_room = rand() % 10 + 1;
                continue;
            }

            if (i == rand() % rooms[player.current_room].doors) {
                printf("The door is locked!\n");
            } else {
                printf("You open the door and enter a new room.\n");
                player.current_room = rand() % 10 + 1;
            }
        }

        printf("Enemies:\n");
        for (int i = 0; i < rooms[player.current_room].num_enemies; i++) {
            printf("Enemy %d:\n", i + 1);
            printf("Name: %s\n", enemies[i].name);
            printf("Description: %s\n", enemies[i].description);
            printf("Health: %d\n", enemies[i].health);
            printf("Damage: %d\n", enemies[i].damage);
            printf("\n");
        }

        printf("Traps:\n");
        for (int i = 0; i < rooms[player.current_room].num_traps; i++) {
            printf("Trap %d:\n", i + 1);
            printf("Name: %s\n", traps[i].name);
            printf("Description: %s\n", traps[i].description);
            printf("Damage: %d\n", traps[i].damage);
            printf("\n");
        }

        printf("What would you like to do?\n");
        printf("1. Attack an enemy\n");
        printf("2. Open a door\n");
        printf("3. Run away\n");
        printf("4. Look around\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Choose an enemy to attack:\n");
                for (int i = 0; i < rooms[player.current_room].num_enemies; i++) {
                    printf("%d. Enemy %d\n", i + 1, i + 1);
                }
                int enemy_id = rand() % rooms[player.current_room].num_enemies;
                printf("You attack enemy %d:\n", enemy_id + 1);
                printf("Health: %d\n", enemies[enemy_id].health);
                printf("Damage: %d\n", enemies[enemy_id].damage);
                printf("\n");

                if (enemies[enemy_id].health > 0) {
                    enemies[enemy_id].health -= rand() % 10 + 1;
                    printf("Enemy %d's health is now %d.\n", enemy_id + 1, enemies[enemy_id].health);
                } else {
                    printf("You have killed enemy %d!\n", enemy_id + 1);
                    enemies[enemy_id].health = 10;
                    enemies[enemy_id].damage = 1;
                    printf("Enemy %d has regenerated!\n", enemy_id + 1);
                }

                break;

            case 2:
                printf("Choose a door to open:\n");
                for (int i = 0; i < rooms[player.current_room].doors; i++) {
                    printf("%d. Door %d\n", i + 1, i + 1);
                }
                int door_id = rand() % rooms[player.current_room].doors;
                printf("You open door %d:\n", door_id + 1);

                if (door_id == rooms[player.current_room].exit) {
                    printf("You have escaped the room!\n");
                    player.current_room = rand() % 10 + 1;
                    continue;
                }

                if (door_id == rand() % rooms[player.current_room].doors) {
                    printf("The door is locked!\n");
                } else {
                    printf("You enter a new room.\n");
                    player.current_room = rand() % 10 + 1;
                }

                break;

            case 3:
                printf("You run away!\n");
                player.x = rand() % 10 + 1;
                player.y = rand() % 10 + 1;
                player.current_room = rand() % 10 + 1;
                break;

            case 4:
                printf("You look around.\n");
                printf("Current Room: %s\n", rooms[player.current_room].name);
                printf("Enemies: %d\n", rooms[player.current_room].num_enemies);
                printf("Traps: %d\n", rooms[player.current_room].num_traps);

                for (int i = 0; i < rooms[player.current_room].doors; i++) {
                    if (i == rooms[player.current_room].exit) {
                        printf("You have escaped the room!\n");
                        player.current_room = rand() % 10 + 1;
                        continue;
                    }

                    if (i == rand() % rooms[player.current_room].doors) {
                        printf("The door is locked!\n");
                    } else {
                        printf("You open the door and enter a new room.\n");
                        player.current_room = rand() % 10 + 1;
                    }
                }

                printf("Enemies:\n");
                for (int i = 0; i < rooms[player.current_room].num_enemies; i++) {
                    printf("Enemy %d:\n", i + 1);
                    printf("Name: %s\n", enemies[i].name);
                    printf("Description: %s\n", enemies[i].description);
                    printf("Health: %d\n", enemies[i].health);
                    printf("Damage: %d\n", enemies[i].damage);
                    printf("\n");
                }

                printf("Traps:\n");
                for (int i = 0; i < rooms[player.current_room].num_traps; i++) {
                    printf("Trap %d:\n", i + 1);
                    printf("Name: %s\n", traps[i].name);
                    printf("Description: %s\n", traps[i].description);
                    printf("Damage: %d\n", traps[i].damage);
                    printf("\n");
                }

                break;

            case 5:
                printf("You have exited the game.\n");
                return 0;
        }
    }

    return 0;
}