//FormAI DATASET v1.0 Category: Log analysis ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000
#define MAX_NUM_PLAYERS 10

typedef struct {
    char player_name[50];
    int num_kills;
    int num_deaths;
} Player;

int get_player_index(Player players[], int num_players, char name[]);
void add_or_update_player(Player players[], int *num_players, char name[]);

int main() {
    FILE *log_file = fopen("game.log", "r");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        exit(1);
    }

    Player players[MAX_NUM_PLAYERS];
    int num_players = 0;
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, log_file) != NULL) {
        char *delim = " ";
        char *token = strtok(line, delim);
        if (strcmp(token, "KILL") == 0) {
            char *killer = strtok(NULL, delim);
            char *victim = strtok(NULL, delim);
            if (strcmp(killer, victim) != 0) {
                add_or_update_player(players, &num_players, killer);
                add_or_update_player(players, &num_players, victim);
                int killer_idx = get_player_index(players, num_players, killer);
                int victim_idx = get_player_index(players, num_players, victim);
                players[killer_idx].num_kills++;
                players[victim_idx].num_deaths++;
            }
        }
    }
    fclose(log_file);

    printf("%-20s %-20s %-20s\n", "Name", "Kills", "Deaths");
    for (int i = 0; i < num_players; i++) {
        printf("%-20s %-20d %-20d\n", players[i].player_name, players[i].num_kills, players[i].num_deaths);
    }

    return 0;
}

int get_player_index(Player players[], int num_players, char name[]) {
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].player_name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_or_update_player(Player players[], int *num_players, char name[]) {
    int idx = get_player_index(players, *num_players, name);
    if (idx == -1) {
        strcpy(players[*num_players].player_name, name);
        players[*num_players].num_kills = 0;
        players[*num_players].num_deaths = 0;
        (*num_players)++;
    }
}