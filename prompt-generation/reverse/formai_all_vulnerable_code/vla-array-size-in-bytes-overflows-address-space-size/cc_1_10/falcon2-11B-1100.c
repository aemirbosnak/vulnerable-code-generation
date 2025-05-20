//Falcon2-11B DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int dice;
    int sides;
    int count;
} Dice;

Dice roll_dice(Dice dice) {
    Dice result;
    srand(time(NULL));

    for (int i = 0; i < dice.count; i++) {
        result.dice = rand() % dice.sides;
    }

    return result;
}

int main() {
    int num_players, num_dice, num_sides;
    printf("Number of players: ");
    scanf("%d", &num_players);
    printf("Number of dice: ");
    scanf("%d", &num_dice);
    printf("Number of sides: ");
    scanf("%d", &num_sides);

    Dice players[num_players];

    for (int i = 0; i < num_players; i++) {
        printf("Player %d: ", i + 1);
        scanf("%d%d%d", &players[i].dice, &players[i].sides, &players[i].count);
    }

    for (int i = 0; i < num_players; i++) {
        Dice player_rolls[players[i].count];

        for (int j = 0; j < players[i].count; j++) {
            player_rolls[j] = roll_dice(players[i]);
        }

        printf("Player %d: ", i + 1);
        for (int j = 0; j < players[i].count; j++) {
            printf("%d ", player_rolls[j].dice);
        }
        printf("\n");
    }

    return 0;
}