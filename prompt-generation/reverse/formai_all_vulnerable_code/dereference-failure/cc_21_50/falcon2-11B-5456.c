//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num_rooms = 10;
    int num_monsters = 5;
    int num_players = 3;
    int num_items = 7;
    int room_size = 10;
    int monster_size = 20;
    int player_size = 15;
    int item_size = 5;

    char** rooms = malloc(num_rooms * sizeof(char*));
    char** monsters = malloc(num_monsters * sizeof(char*));
    char** players = malloc(num_players * sizeof(char*));
    char** items = malloc(num_items * sizeof(char*));

    srand(time(NULL));

    for (int i = 0; i < num_rooms; i++) {
        rooms[i] = malloc(room_size * sizeof(char));
        for (int j = 0; j < room_size; j++) {
            rooms[i][j] = '.';
        }
    }

    for (int i = 0; i < num_monsters; i++) {
        monsters[i] = malloc(monster_size * sizeof(char));
        for (int j = 0; j < monster_size; j++) {
            monsters[i][j] = 'M';
        }
    }

    for (int i = 0; i < num_players; i++) {
        players[i] = malloc(player_size * sizeof(char));
        for (int j = 0; j < player_size; j++) {
            players[i][j] = 'P';
        }
    }

    for (int i = 0; i < num_items; i++) {
        items[i] = malloc(item_size * sizeof(char));
        for (int j = 0; j < item_size; j++) {
            items[i][j] = 'I';
        }
    }

    int room_x = 0;
    int room_y = 0;
    int monster_x = 0;
    int monster_y = 0;
    int player_x = 0;
    int player_y = 0;
    int item_x = 0;
    int item_y = 0;

    printf("Welcome to the Haunted House Simulator!\n");

    while (1) {
        printf("What do you want to do?\n");
        printf("1. Move\n");
        printf("2. Look around\n");
        printf("3. Attack\n");
        printf("4. Pick up item\n");
        printf("5. Use item\n");
        printf("6. Exit\n");
        int choice = 0;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Where do you want to move?\n");
                printf("1. Up\n");
                printf("2. Down\n");
                printf("3. Left\n");
                printf("4. Right\n");
                printf("5. Back\n");
                int direction = 0;
                scanf("%d", &direction);

                if (direction == 1) {
                    if (room_x == 0) {
                        printf("You can't move up from the starting room.\n");
                    } else {
                        room_y--;
                        printf("You moved up to room %d.\n", room_y);
                    }
                } else if (direction == 2) {
                    if (room_y == 9) {
                        printf("You can't move down from the last room.\n");
                    } else {
                        room_x++;
                        printf("You moved down to room %d.\n", room_x);
                    }
                } else if (direction == 3) {
                    if (room_x == 0) {
                        printf("You can't move left from the starting room.\n");
                    } else {
                        room_y--;
                        printf("You moved left to room %d.\n", room_y);
                    }
                } else if (direction == 4) {
                    if (room_x == 9) {
                        printf("You can't move right from the last room.\n");
                    } else {
                        room_x++;
                        printf("You moved right to room %d.\n", room_x);
                    }
                } else if (direction == 5) {
                    printf("You are back in the starting room.\n");
                } else {
                    printf("Invalid direction. Please try again.\n");
                }

                break;
            case 2:
                printf("What do you want to look at?\n");
                printf("1. Room\n");
                printf("2. Monster\n");
                printf("3. Player\n");
                printf("4. Item\n");
                int look_at = 0;
                scanf("%d", &look_at);

                if (look_at == 1) {
                    printf("You look at the room.\n");
                    printf("Room %d:\n", room_x);
                    for (int i = 0; i < room_size; i++) {
                        printf("%c ", rooms[room_y][i]);
                    }
                    printf("\n");
                } else if (look_at == 2) {
                    printf("You look at the monster.\n");
                    printf("Monster %d:\n", monster_x);
                    for (int i = 0; i < monster_size; i++) {
                        printf("%c ", monsters[monster_y][i]);
                    }
                    printf("\n");
                } else if (look_at == 3) {
                    printf("You look at the player.\n");
                    printf("Player %d:\n", player_x);
                    for (int i = 0; i < player_size; i++) {
                        printf("%c ", players[player_y][i]);
                    }
                    printf("\n");
                } else if (look_at == 4) {
                    printf("You look at the item.\n");
                    printf("Item %d:\n", item_x);
                    for (int i = 0; i < item_size; i++) {
                        printf("%c ", items[item_y][i]);
                    }
                    printf("\n");
                } else {
                    printf("Invalid look_at choice. Please try again.\n");
                }

                break;
            case 3:
                printf("You attack the monster.\n");
                if (monster_x == 0 || monster_y == 0) {
                    printf("The monster is not in this room.\n");
                } else if (monster_x == room_x && monster_y == room_y) {
                    printf("You attack the monster!\n");
                    monster_x = 0;
                    monster_y = 0;
                    printf("The monster is dead.\n");
                    printf("You gained %d experience points.\n", 10);
                } else {
                    printf("You attack the monster!\n");
                    monster_x = 0;
                    monster_y = 0;
                    printf("The monster is dead.\n");
                    printf("You gained %d experience points.\n", 10);
                }

                break;
            case 4:
                printf("You pick up the item.\n");
                if (item_x == 0 || item_y == 0) {
                    printf("The item is not in this room.\n");
                } else if (item_x == room_x && item_y == room_y) {
                    printf("You pick up the item!\n");
                    item_x = 0;
                    item_y = 0;
                    printf("You gained %d experience points.\n", 5);
                } else {
                    printf("You pick up the item!\n");
                    item_x = 0;
                    item_y = 0;
                    printf("You gained %d experience points.\n", 5);
                }

                break;
            case 5:
                printf("You use the item.\n");
                if (item_x == 0 || item_y == 0) {
                    printf("The item is not in this room.\n");
                } else if (item_x == room_x && item_y == room_y) {
                    printf("You use the item!\n");
                    item_x = 0;
                    item_y = 0;
                    printf("You gained %d experience points.\n", 10);
                } else {
                    printf("You use the item!\n");
                    item_x = 0;
                    item_y = 0;
                    printf("You gained %d experience points.\n", 10);
                }

                break;
            case 6:
                printf("Thanks for playing!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    free(rooms);
    free(monsters);
    free(players);
    free(items);

    return 0;
}