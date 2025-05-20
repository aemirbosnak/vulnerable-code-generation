//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_PLAYERS 5
#define WORD_LENGTH 20
#define PLAYER_NAME_LENGTH 20

typedef struct {
    char word[WORD_LENGTH];
    char guessed[WORD_LENGTH];
    int players_count;
    char players[MAX_PLAYERS][PLAYER_NAME_LENGTH];
    pthread_mutex_t lock;
    int guesses;
} GameData;

GameData game_data;

void* player_thread(void* arg) {
    char player_name[PLAYER_NAME_LENGTH];
    strcpy(player_name, (char*)arg);
    int player_index = 0;

    pthread_mutex_lock(&game_data.lock);
    if (game_data.players_count < MAX_PLAYERS) {
        strcpy(game_data.players[game_data.players_count++], player_name);
        player_index = game_data.players_count - 1;
        printf("%s has joined the game!\n", player_name);
    } else {
        printf("Game room full! %s couldn't join.\n", player_name);
        pthread_mutex_unlock(&game_data.lock);
        return NULL;
    }
    pthread_mutex_unlock(&game_data.lock);

    char guess;
    while (1) {
        printf("%s, enter a letter to guess (or 'exit' to leave): ", player_name);
        scanf(" %c", &guess);

        if (guess == 'e' || guess == 'x') { // 'exit' condition
            printf("%s has left the game.\n", player_name);
            break;
        }

        if (!isalpha(guess) || strlen(game_data.guessed) >= strlen(game_data.word)) {
            printf("Invalid guess! Try again.\n");
            continue;
        }

        pthread_mutex_lock(&game_data.lock);
        game_data.guessed[game_data.guesses++] = tolower(guess);
        game_data.guessed[game_data.guesses] = '\0'; // Null terminate guessed string
        printf("%s guessed: '%c'\n", player_name, guess);
        pthread_mutex_unlock(&game_data.lock);
        
        int complete = 1;
        for (int i = 0; i < strlen(game_data.word); i++) {
            if (strchr(game_data.guessed, game_data.word[i]) == NULL) {
                complete = 0;
                break;
            }
        }
        if (complete) {
            printf("Player %s has won the game! The word was: %s\n", player_name, game_data.word);
            break;
        }
    }
    return NULL;
}

void initialize_game(const char* word) {
    strcpy(game_data.word, word);
    game_data.guessed[0] = '\0'; // Initialize guessed letters
    game_data.players_count = 0; // Reset players
    game_data.guesses = 0; // Reset guesses
    pthread_mutex_init(&game_data.lock, NULL);
}

int main() {
    pthread_t players[MAX_PLAYERS];
    char player_name[PLAYER_NAME_LENGTH];
    char word[WORD_LENGTH];

    printf("Welcome to the Multiplayer Word Guessing Game!\n");
    printf("Enter the word to be guessed: ");
    scanf("%s", word);
    initialize_game(word);

    while (1) {
        printf("Enter your name to join the game (or 'exit' to quit): ");
        scanf("%s", player_name);
        if (strcmp(player_name, "exit") == 0) {
            break; // Exit the main loop
        }

        int idx = game_data.players_count - 1;
        pthread_create(&players[idx], NULL, player_thread, strdup(player_name));
        sleep(1); // Small delay to simulate asynchronous player joining
    }

    for (int i = 0; i < game_data.players_count; i++) {
        pthread_join(players[i], NULL); // Ensure all threads finish before exiting
    }

    pthread_mutex_destroy(&game_data.lock);
    printf("Game over!\n");
    return 0;
}