//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
} Player;

typedef struct {
    Player* players;
    int numPlayers;
    int numRounds;
    int* scores;
} Game;

Game createGame(int numPlayers, int numRounds) {
    Game game;
    game.players = (Player*)malloc(numPlayers * sizeof(Player));
    game.numPlayers = numPlayers;
    game.numRounds = numRounds;
    game.scores = (int*)malloc(numPlayers * sizeof(int));
    for (int i = 0; i < numPlayers; i++) {
        strcpy(game.players[i].name, "Player ");
        game.players[i].id = i;
        game.scores[i] = 0;
    }
    return game;
}

void printGame(const Game* game) {
    printf("Players: ");
    for (int i = 0; i < game->numPlayers; i++) {
        printf("%s (%d): %d\n", game->players[i].name, game->players[i].id, game->scores[i]);
    }
}

int playRound(const Game* game) {
    int winner = -1;
    for (int i = 0; i < game->numPlayers; i++) {
        int score = 0;
        for (int j = 0; j < game->numRounds; j++) {
            score += rand() % 10;
        }
        game->scores[i] += score;
        if (score > game->scores[winner]) {
            winner = i;
        }
    }
    return winner;
}

void endGame(const Game* game) {
    int maxScore = 0;
    for (int i = 0; i < game->numPlayers; i++) {
        if (game->scores[i] > maxScore) {
            maxScore = game->scores[i];
        }
    }
    printf("Game over!\n");
    printf("Winner: Player %d with %d points\n", game->players[maxScore].id, maxScore);
}

int main() {
    Game game = createGame(5, 10);
    printf("Game started!\n");
    for (int i = 0; i < game.numRounds; i++) {
        printf("Round %d\n", i + 1);
        int winner = playRound(&game);
        printf("Winner of round %d: Player %d\n", i + 1, winner + 1);
    }
    endGame(&game);
    return 0;
}