//FormAI DATASET v1.0 Category: Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_STRING_LENGTH 100

void encrypt(char* input_string, int key) {
    int len = strlen(input_string);
    for (int i = 0; i < len; i++) {
        input_string[i] = ((input_string[i] + key) % 256);
    }
}

void send_encrypted_message(char* message, int key, int sender_id, int* recipient_ids, int num_recipients) {
    char encrypted_message[MAX_STRING_LENGTH];
    strcpy(encrypted_message, message);
    encrypt(encrypted_message, key);

    printf("Player %d sends encrypted message to", sender_id);
    for (int i = 0; i < num_recipients; i++) {
        printf(" %d", recipient_ids[i]);
    }
    printf(": %s\n", encrypted_message);
}

int main() {
    srand(time(NULL));
    int num_players = rand() % MAX_PLAYERS + 1;
    printf("%d players join the game!\n", num_players);

    // initialize random keys for each player
    int player_keys[num_players];
    for (int i = 0; i < num_players; i++) {
        player_keys[i] = rand() % 256;
    }

    // generate random message to send
    char message[MAX_STRING_LENGTH];
    printf("Enter message to send: ");
    fgets(message, MAX_STRING_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0;

    // randomly choose sender and recipients
    int sender_id = rand() % num_players;
    int num_recipients = rand() % (num_players - 1) + 1;
    int recipient_ids[num_recipients];
    for (int i = 0; i < num_recipients; i++) {
        int recipient_id = rand() % num_players;
        while (recipient_id == sender_id || strchr(recipient_ids, recipient_id)) {
            recipient_id = rand() % num_players;
        }
        recipient_ids[i] = recipient_id;
    }

    // send the encrypted message
    send_encrypted_message(message, player_keys[sender_id], sender_id, recipient_ids, num_recipients);

    return 0;
}