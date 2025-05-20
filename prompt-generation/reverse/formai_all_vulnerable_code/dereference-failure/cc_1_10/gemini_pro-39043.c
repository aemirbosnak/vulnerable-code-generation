//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Define the maximum number of players
#define MAX_PLAYERS 4

// Define the maximum word length
#define MAX_WORD_LENGTH 20

// Define the dictionary file
#define DICTIONARY_FILE "dictionary.txt"

// Define the player struct
typedef struct Player {
    char name[20];
    int score;
    char word[MAX_WORD_LENGTH];
} Player;

// Define the game struct
typedef struct Game {
    Player players[MAX_PLAYERS];
    int num_players;
    int current_player;
    char word_to_guess[MAX_WORD_LENGTH];
} Game;

// Create a new game
Game* new_game() {
    // Allocate memory for the game
    Game* game = malloc(sizeof(Game));

    // Set the number of players to 0
    game->num_players = 0;

    // Set the current player to -1
    game->current_player = -1;

    // Set the word to guess to an empty string
    strcpy(game->word_to_guess, "");

    // Return the game
    return game;
}

// Add a player to the game
void add_player(Game* game, char* name) {
    // Check if the game is full
    if (game->num_players >= MAX_PLAYERS) {
        printf("The game is full!\n");
        return;
    }

    // Add the player to the game
    strcpy(game->players[game->num_players].name, name);
    game->players[game->num_players].score = 0;
    game->num_players++;
}

// Start the game
void start_game(Game* game) {
    // Check if there are enough players
    if (game->num_players < 2) {
        printf("There must be at least two players to start the game!\n");
        return;
    }

    // Set the current player to the first player
    game->current_player = 0;

    // Generate a random word to guess
    FILE* dictionary = fopen(DICTIONARY_FILE, "r");
    int num_words = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(dictionary, "%s", word) != EOF) {
        num_words++;
    }
    fclose(dictionary);

    srand(time(NULL));
    int random_word = rand() % num_words;

    dictionary = fopen(DICTIONARY_FILE, "r");
    int i = 0;
    while (fscanf(dictionary, "%s", word) != EOF) {
        if (i == random_word) {
            strcpy(game->word_to_guess, word);
            break;
        }
        i++;
    }
    fclose(dictionary);

    // Display the word to guess
    printf("The word to guess is: %s\n", game->word_to_guess);
}

// Get the next player
int next_player(Game* game) {
    // Increment the current player
    game->current_player++;

    // Wrap around to the first player if necessary
    if (game->current_player >= game->num_players) {
        game->current_player = 0;
    }

    // Return the next player
    return game->current_player;
}

// Check if a word is correct
int is_correct(char* word, char* word_to_guess) {
    // Check if the words are the same length
    if (strlen(word) != strlen(word_to_guess)) {
        return 0;
    }

    // Check if the words are the same
    for (int i = 0; i < strlen(word); i++) {
        if (tolower(word[i]) != tolower(word_to_guess[i])) {
            return 0;
        }
    }

    // The words are the same
    return 1;
}

// Play the game
void play_game(Game* game) {
    // Start the game
    start_game(game);

    // Loop until a player guesses the word
    while (strlen(game->word_to_guess) > 0) {
        // Get the current player
        int current_player = game->current_player;

        // Get the player's guess
        printf("%s, guess a word: ", game->players[current_player].name);
        scanf("%s", game->players[current_player].word);

        // Check if the guess is correct
        if (is_correct(game->players[current_player].word, game->word_to_guess)) {
            // The guess is correct
            printf("Correct!\n");

            // Add 1 point to the player's score
            game->players[current_player].score++;

            // Reset the word to guess
            strcpy(game->word_to_guess, "");

            // Generate a new word to guess
            FILE* dictionary = fopen(DICTIONARY_FILE, "r");
            int num_words = 0;
            char word[MAX_WORD_LENGTH];
            while (fscanf(dictionary, "%s", word) != EOF) {
                num_words++;
            }
            fclose(dictionary);

            srand(time(NULL));
            int random_word = rand() % num_words;

            dictionary = fopen(DICTIONARY_FILE, "r");
            int i = 0;
            while (fscanf(dictionary, "%s", word) != EOF) {
                if (i == random_word) {
                    strcpy(game->word_to_guess, word);
                    break;
                }
                i++;
            }
            fclose(dictionary);

            // Display the word to guess
            printf("The word to guess is: %s\n", game->word_to_guess);
        } else {
            // The guess is incorrect
            printf("Incorrect!\n");
        }

        // Get the next player
        next_player(game);
    }

    // The game is over
    printf("Game over!\n");

    // Print the scores
    for (int i = 0; i < game->num_players; i++) {
        printf("%s: %d points\n", game->players[i].name, game->players[i].score);
    }
}

// Free the game
void free_game(Game* game) {
    // Free the players
    for (int i = 0; i < game->num_players; i++) {
        free(game->players[i].name);
    }

    // Free the game
    free(game);
}

// Main function
int main() {
    // Create a new game
    Game* game = new_game();

    // Add players to the game
    add_player(game, "Player 1");
    add_player(game, "Player 2");
    add_player(game, "Player 3");
    add_player(game, "Player 4");

    // Play the game
    play_game(game);

    // Free the game
    free_game(game);

    return 0;
}