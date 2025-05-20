//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;

typedef struct {
    char name[20];
    int age;
    int score;
} Player;

typedef struct {
    char name[20];
    int numPlayers;
    Player players[4];
} Table;

bool addPlayer(Table *table, Player player) {
    if (table->numPlayers >= 4) {
        return false;
    }

    table->players[table->numPlayers] = player;
    table->numPlayers++;

    return true;
}

void printTable(Table table) {
    printf("Table name: %s\n", table.name);
    printf("Number of players: %d\n", table.numPlayers);

    for (int i = 0; i < table.numPlayers; i++) {
        printf("Player %d:\n", i + 1);
        printf("\tName: %s\n", table.players[i].name);
        printf("\tAge: %d\n", table.players[i].age);
        printf("\tScore: %d\n", table.players[i].score);
    }
}

int main() {
    Table table;
    strcpy(table.name, "My Table");

    Player player1;
    strcpy(player1.name, "John");
    player1.age = 25;
    player1.score = 100;

    Player player2;
    strcpy(player2.name, "Jane");
    player2.age = 27;
    player2.score = 150;

    addPlayer(&table, player1);
    addPlayer(&table, player2);

    printTable(table);

    return 0;
}