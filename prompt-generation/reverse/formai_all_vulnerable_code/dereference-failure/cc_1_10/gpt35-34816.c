//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 100 // Maximum length of a command
#define MAX_ARGS 10 // Maximum number of arguments in a command
#define MAX_PLAYERS 5 // Maximum number of players in the game

int num_players = 0; // Number of players currently in the game
int player_ids[MAX_PLAYERS]; // IDs of the players in the game

void handle_signal(int signal) {
    // Ignore a signal
}

void add_player(int player_id) {
    if (num_players == MAX_PLAYERS) {
        printf("Cannot add player %d - maximum number of players reached.\n", player_id);
        return;
    }
    player_ids[num_players++] = player_id;
    printf("Added player %d to the game.\n", player_id);
}

void remove_player(int player_id) {
    int i;
    for (i = 0; i < num_players; i++) {
        if (player_ids[i] == player_id) {
            break;
        }
    }
    if (i == num_players) {
        printf("Cannot remove player %d - player not found.\n", player_id);
        return;
    }
    for (; i < num_players - 1; i++) {
        player_ids[i] = player_ids[i+1];
    }
    num_players--;
    printf("Removed player %d from the game.\n", player_id);
}

void print_players() {
    printf("Players in the game:\n");
    int i;
    for (i = 0; i < num_players; i++) {
        printf("Player %d\n", player_ids[i]);
    }
}

void run_game(char *input[]) {
    int i, status;
    pid_t pid, wait_pid;
    signal(SIGINT, handle_signal);
    for (i = 0; i < num_players; i++) {
        pid = fork();
        if (pid == 0) {
            // Child
            printf("Player %d is now playing the game.\n", player_ids[i]);
            sleep(5);
            printf("Player %d has finished the game.\n", player_ids[i]);
            exit(0);
        } else if (pid < 0) {
            // Error
            printf("Could not fork child process for player %d\n", player_ids[i]);
            return;
        }
    }
    // Parent
    while ((wait_pid = wait(&status)) > 0) {
        printf("Child process %d terminated with status %d\n", wait_pid, WEXITSTATUS(status));
    }
}

int main() {
    char cmd[MAX_CMD_LENGTH];
    char *args[MAX_ARGS];
    int i;
    while (1) {
        printf("Enter a command: ");
        fgets(cmd, MAX_CMD_LENGTH, stdin);
        // Remove newline character from end of command
        if (cmd[strlen(cmd)-1] == '\n') {
            cmd[strlen(cmd)-1] = '\0';
        }
        // Split command into arguments
        args[0] = strtok(cmd, " ");
        for (i = 1; i < MAX_ARGS; i++) {
            args[i] = strtok(NULL, " ");
            if (args[i] == NULL) {
                break;
            }
        }
        // Execute command
        if (strcmp(args[0], "add_player") == 0) {
            add_player(atoi(args[1]));
        } else if (strcmp(args[0], "remove_player") == 0) {
            remove_player(atoi(args[1]));
        } else if (strcmp(args[0], "print_players") == 0) {
            print_players();
        } else if (strcmp(args[0], "run_game") == 0) {
            run_game(args);
        } else if (strcmp(args[0], "exit") == 0) {
            printf("Exiting...\n");
            exit(0);
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}