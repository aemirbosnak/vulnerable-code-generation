//FormAI DATASET v1.0 Category: Memory management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    int score;
} Player;

Player **players;
int num_players = 0;

void add_player(char *name, int age) {
    if (num_players >= MAX_PLAYERS) {
        printf("No more players can be added.\n");
        return;
    }

    Player *new_player = malloc(sizeof(Player));
    strcpy(new_player->name, name);
    new_player->age = age;
    new_player->score = 0;

    players[num_players] = new_player;
    num_players++;
}

void remove_player(int index) {
    if (index < 0 || index >= num_players) {
        printf("Invalid player index.\n");
        return;
    }

    Player *player_to_remove = players[index];
    free(player_to_remove);

    for (int i = index; i < num_players - 1; i++) {
        players[i] = players[i+1];
    }

    num_players--;
}

void print_players() {
    printf("Current players:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%d. %s - Age: %d - Score: %d\n", i+1, players[i]->name, players[i]->age, players[i]->score);
    }
}

void update_scores() {
    srand(time(NULL));
    for (int i = 0; i < num_players; i++) {
        int rand_num = rand() % 101;
        players[i]->score += rand_num;
    }
}

int main() {
    players = malloc(MAX_PLAYERS * sizeof(Player*));

    add_player("John", 25);
    add_player("Sarah", 30);
    add_player("Mike", 20);
    add_player("Emily", 28);

    print_players();
    update_scores();
    print_players();

    remove_player(2);
    print_players();
    
    free(players);
    return 0;
}