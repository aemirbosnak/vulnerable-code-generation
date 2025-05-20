//FormAI DATASET v1.0 Category: Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for player information
struct Player {
    char *name;
    int score;
};

// function to read player names and scores from file
void read_players(struct Player *players, int num_players) {
    FILE *fp;
    char line[100];
    char *name;
    int score;
    int i = 0;

    fp = fopen("players.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        name = strtok(line, ",");
        score = atoi(strtok(NULL, ","));

        players[i].name = strdup(name);
        players[i].score = score;

        i++;
    }

    fclose(fp);
}

// function to print player names and scores
void print_players(struct Player *players, int num_players) {
    printf("Player Name\t\tScore\n");
    printf("------------------------------\n");
    for (int i = 0; i < num_players; i++) {
        printf("%-20s\t\t%d\n", players[i].name, players[i].score);
    }
    printf("------------------------------\n");
}

// main game function
void play_game(struct Player *players, int num_players) {
    int num_rounds = 3;
    int round_scores[num_rounds][num_players];
    int player_score;

    printf("Starting game...\n");

    // loop through rounds
    for (int i = 0; i < num_rounds; i++) {
        printf("Round %d\n", i+1);

        // loop through players
        for (int j = 0; j < num_players; j++) {
            printf("%s's turn\n", players[j].name);

            // get player score for round
            scanf("%d", &player_score);

            // save player score for round
            round_scores[i][j] = player_score;

            // add player score to total score
            players[j].score += player_score;
        }
    }

    // print final scores
    printf("Final scores\n");
    print_players(players, num_players);

    // print round scores
    printf("Round scores\n");
    printf("------------------------------\n");
    for (int i = 0; i < num_rounds; i++) {
        printf("Round %d\n", i+1);
        printf("------------------------------\n");
        for (int j = 0; j < num_players; j++) {
            printf("%-20s\t\t%d\n", players[j].name, round_scores[i][j]);
        }
        printf("------------------------------\n");
    }
}

int main() {
    // read number of players from file
    FILE *fp;
    char line[100];
    int num_players;

    fp = fopen("num_players.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fgets(line, sizeof(line), fp);
    num_players = atoi(line);

    fclose(fp);

    // allocate memory for player information
    struct Player *players = (struct Player*) malloc(num_players * sizeof(struct Player));

    // read player information from file
    read_players(players, num_players);

    // print player information
    print_players(players, num_players);

    // start game
    play_game(players, num_players);

    // free memory
    for (int i = 0; i < num_players; i++) {
        free(players[i].name);
    }
    free(players);

    return 0;
}