//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_ROWS 10
#define TABLE_COLS 10
#define MAX_PLAYERS 4

typedef struct player {
    char name[50];
    int score;
} player;

typedef struct table {
    player players[TABLE_ROWS][TABLE_COLS];
} table;

table *create_table(void) {
    table *t = malloc(sizeof(table));
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            t->players[i][j].name[0] = '\0';
            t->players[i][j].score = 0;
        }
    }
    return t;
}

void add_player(table *t, char *name) {
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            if (strcmp(t->players[i][j].name, "") == 0) {
                strcpy(t->players[i][j].name, name);
                t->players[i][j].score = 0;
                return;
            }
        }
    }
    printf("Error: Table is full. Please try again later.\n");
}

void roll_dice(table *t) {
    int dice_roll = rand() % 6 + 1;
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            t->players[i][j].score += dice_roll;
            printf("Player %s rolled %d\n", t->players[i][j].name, dice_roll);
        }
    }
}

void print_table(table *t) {
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            printf("%s scored %d\n", t->players[i][j].name, t->players[i][j].score);
        }
    }
}

int main(void) {
    srand(time(NULL));
    table *t = create_table();
    char *players[MAX_PLAYERS][50];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d: ", i + 1);
        fgets(players[i], 50, stdin);
    }
    for (int i = 0; i < MAX_PLAYERS; i++) {
        add_player(t, players[i]);
    }
    for (int i = 0; i < 10; i++) {
        roll_dice(t);
    }
    print_table(t);
    return 0;
}