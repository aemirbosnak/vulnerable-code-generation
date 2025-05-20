//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_PLAYERS 5
#define BUFFER_SIZE 256

typedef struct {
    int player_id;
    char command[BUFFER_SIZE];
} Player;

Player players[MAX_PLAYERS];
int current_player_count = 0;
pthread_mutex_t lock;

void *process_commands(void *arg) {
    Player *p = (Player *)arg;
    char result[BUFFER_SIZE];

    while (1) {
        pthread_mutex_lock(&lock);
        if (strlen(p->command) > 0) {
            if (strncmp(p->command, "reverse", 7) == 0) {
                int len = strlen(p->command) - 8; // account for 'reverse '
                for (int i = 0; i < len; i++) {
                    result[i] = p->command[len + 8 - 1 - i];
                }
                result[len] = '\0';
                printf("Player %d: Reversed text: %s\n", p->player_id, result);
            } else if (strncmp(p->command, "uppercase", 9) == 0) {
                int len = strlen(p->command) - 10; // account for 'uppercase '
                for (int i = 0; i < len; i++) {
                    result[i] = toupper(p->command[i + 10]);
                }
                result[len] = '\0';
                printf("Player %d: Uppercase text: %s\n", p->player_id, result);
            } else if (strncmp(p->command, "lowercase", 9) == 0) {
                int len = strlen(p->command) - 10; // account for 'lowercase '
                for (int i = 0; i < len; i++) {
                    result[i] = tolower(p->command[i + 10]);
                }
                result[len] = '\0';
                printf("Player %d: Lowercase text: %s\n", p->player_id, result);
            } else if (strncmp(p->command, "length", 6) == 0) {
                int len = strlen(p->command) - 7; // account for 'length '
                printf("Player %d: Length of text: %d\n", p->player_id, len);
            } else {
                printf("Player %d: Invalid command.\n", p->player_id);
            }
            p->command[0] = '\0'; // Clear the command after processing
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void *player_input(void *arg) {
    Player *p = (Player *)arg;

    while (1) {
        printf("Player %d, enter command: ", p->player_id);
        fgets(p->command, BUFFER_SIZE, stdin);
        p->command[strcspn(p->command, "\n")] = 0; // Remove the newline character
    }
    return NULL;
}

int main() {
    pthread_t threads[MAX_PLAYERS];
    pthread_mutex_init(&lock, NULL);

    printf("Welcome to the Multiplayer Text Processing Game!\n");

    while (current_player_count < MAX_PLAYERS) {
        players[current_player_count].player_id = current_player_count + 1;
        players[current_player_count].command[0] = '\0'; // Initialize command

        // Create threads for player input and command processing
        pthread_create(&threads[current_player_count], NULL, player_input, &players[current_player_count]);
        pthread_create(&threads[current_player_count + MAX_PLAYERS], NULL, process_commands, &players[current_player_count]);

        current_player_count++;
    }

    // Wait for all threads to finish (they never will in this game)
    for (int i = 0; i < current_player_count; i++) {
        pthread_join(threads[i], NULL);
        pthread_join(threads[i + MAX_PLAYERS], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}