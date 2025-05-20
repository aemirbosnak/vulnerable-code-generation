//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PLAYER_1 1
#define PLAYER_2 2

#define SECRET_KEY "super_secret_key"

// Structure to store player information
typedef struct {
    int player_id;
    int shift;
} player_info_t;

// Function to generate a random shift value for each player
void generate_shift(player_info_t *player) {
    player->shift = rand() % 26 + 1;
}

// Function to encrypt a message using the Caesar cipher
void encrypt(player_info_t *player, char *message) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        message[i] = (message[i] + player->shift - 'a') % 26 + 'a';
    }
}

// Function to decrypt a message using the Caesar cipher
void decrypt(player_info_t *player, char *message) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        message[i] = (message[i] - player->shift + 'a') % 26 + 'a';
    }
}

// Function to handle player input and encryption/decryption
void handle_input(player_info_t *player, char *message) {
    printf("Player %d: Enter a message to encrypt/decrypt: ", player->player_id);
    fgets(message, 100, stdin);

    if (player->player_id == PLAYER_1) {
        encrypt(player, message);
    } else {
        decrypt(player, message);
    }

    printf("Encrypted message: %s\n", message);
}

int main() {
    player_info_t player1, player2;

    // Generate random shift values for each player
    generate_shift(&player1);
    generate_shift(&player2);

    // Print the secret key
    printf("Secret key: %s\n", SECRET_KEY);

    // Loop until both players have finished
    while (1) {
        // Player 1 encrypts and sends message to player 2
        handle_input(&player1, "Message from player 1");

        // Player 2 decrypts and sends message to player 1
        handle_input(&player2, "Message from player 2");
    }

    return 0;
}