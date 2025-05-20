//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int id;
    char* name;
} Player;

typedef struct {
    int id;
    int num;
} Ball;

typedef struct {
    int id;
    Player* players;
    Ball* balls;
} Game;

int main() {
    srand(time(NULL));

    Game game;
    game.players = NULL;
    game.balls = NULL;

    int num_players = 4;
    int num_balls = 75;

    game.players = (Player*)malloc(num_players * sizeof(Player));
    game.balls = (Ball*)malloc(num_balls * sizeof(Ball));

    for (int i = 0; i < num_players; i++) {
        game.players[i].id = i + 1;
        strcpy(game.players[i].name, "Player ");
        strcat(game.players[i].name, &game.players[i].id);
    }

    for (int i = 0; i < num_balls; i++) {
        game.balls[i].id = i + 1;
        game.balls[i].num = rand() % 75 + 1;
    }

    printf("Game started with %d players and %d balls.\n", num_players, num_balls);

    for (int i = 0; i < num_balls; i++) {
        Ball* ball = &game.balls[i];
        int player_id = rand() % num_players;
        Player* player = &game.players[player_id];
        if (player->name[0] == 'P') {
            player->name[0] = 'X';
            printf("%s called Bingo!\n", player->name);
            break;
        } else {
            printf("%s called %d.\n", player->name, ball->num);
        }
    }

    for (int i = 0; i < num_players; i++) {
        free(game.players[i].name);
    }
    free(game.players);
    free(game.balls);

    return 0;
}