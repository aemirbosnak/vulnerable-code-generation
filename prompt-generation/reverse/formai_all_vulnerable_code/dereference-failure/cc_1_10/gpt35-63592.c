//FormAI DATASET v1.0 Category: Syntax parsing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_LINE_LENGTH 256
#define MAX_ARGS 10

typedef struct {
    char command[MAX_LINE_LENGTH];
    char *args[MAX_ARGS];
    int num_args;
} Input;

typedef struct {
    char name[MAX_LINE_LENGTH];
    int score;
} Player;

int num_players = 0;
Player players[MAX_PLAYERS];

void parse_input(char *line, Input *input) {
    char *token = strtok(line, " ");
    strcpy(input->command, token);
    input->num_args = 0;
    while((token = strtok(NULL, " ")) != NULL) {
        input->args[input->num_args++] = token;
    }
}

void start_game() {
    printf("Starting game with %d players:\n", num_players);
    for(int i = 0; i < num_players; i++) {
        printf("%s\n", players[i].name);
    }
    // Game logic goes here
}

void add_player(char *name) {
    if(num_players == MAX_PLAYERS) {
        printf("Cannot add more than %d players\n", MAX_PLAYERS);
        return;
    }
    Player player;
    strcpy(player.name, name);
    player.score = 0;
    players[num_players++] = player;
    printf("Added player: %s\n", name);
}

int main() {
    printf("Welcome to the game!\n");
    printf("Enter commands in the format: [command] [arg1] [arg2] ...\n");
    printf("Available commands: add_player, start_game, quit\n");

    char line[MAX_LINE_LENGTH];
    Input input;

    while(1) {
        printf("> ");
        fgets(line, MAX_LINE_LENGTH, stdin);
        line[strlen(line) - 1] = '\0'; // remove newline character
        parse_input(line, &input);

        if(strcmp(input.command, "add_player") == 0) {
            if(input.num_args < 1) {
                printf("Usage: add_player [name]\n");
                continue;
            }
            add_player(input.args[0]);
        } else if(strcmp(input.command, "start_game") == 0) {
            start_game();
            break;
        } else if(strcmp(input.command, "quit") == 0) {
            printf("Goodbye!\n");
            exit(EXIT_SUCCESS);
        } else {
            printf("Unknown command: %s\n", input.command);
        }
    }

    return 0;
}