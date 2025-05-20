//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MAX_DICE 100

typedef struct {
    int sides;
    int value;
} Die;

typedef struct {
    int num_dice;
    Die dice[MAX_DICE];
} Roll;

void init_die(Die *die, int sides) {
    die->sides = sides;
    die->value = rand() % sides + 1;
}

void init_roll(Roll *roll, int num_dice, int sides) {
    roll->num_dice = num_dice;
    for (int i = 0; i < num_dice; i++) {
        init_die(&roll->dice[i], sides);
    }
}

void roll_dice(Roll *roll, int num_rolls) {
    for (int i = 0; i < num_rolls; i++) {
        for (int j = 0; j < roll->num_dice; j++) {
            roll->dice[j].value = rand() % roll->dice[j].sides + 1;
        }
        printf("Roll %d: ", i + 1);
        for (int j = 0; j < roll->num_dice; j++) {
            printf("%d ", roll->dice[j].value);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int num_dice, sides;
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides on each die: ");
    scanf("%d", &sides);

    Roll roll;
    init_roll(&roll, num_dice, sides);

    int num_rolls;
    printf("Enter the number of rolls: ");
    scanf("%d", &num_rolls);

    roll_dice(&roll, num_rolls);

    return 0;
}