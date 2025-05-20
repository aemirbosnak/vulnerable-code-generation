//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MESSAGE_LENGTH 10
#define KEY_LENGTH 5
#define NUM_KEYS 10

typedef struct {
    char message[MESSAGE_LENGTH];
    int key_index;
} Voter;

void generate_keys(char keys[NUM_KEYS][KEY_LENGTH]);
void encode_message(Voter* voter, char key[KEY_LENGTH]);
void decode_message(Voter* voter, char key[KEY_LENGTH]);

int main() {
    srand(time(NULL));
    char keys[NUM_KEYS][KEY_LENGTH];
    generate_keys(keys);

    Voter sender = { .message = "1 0 1 0 1 1 0 1 0 1" };
    Voter receiver;

    printf("Sender's message: %s\n", sender.message);

    // Sender encodes the message using a random key
    int random_key_index = rand() % NUM_KEYS;
    encode_message(&sender, keys[random_key_index]);

    printf("Encoded message: %s\n", sender.message);
    printf("Key index: %d\n", sender.key_index);

    // Receiver decodes the message using the correct key
    strcpy(receiver.message, "1 1 1 0 1 0 1 1 0 1"); // This should be the correct message for the example
    receiver.key_index = random_key_index;
    decode_message(&receiver, keys[random_key_index]);

    if (strcmp(sender.message, receiver.message) == 0) {
        printf("Decoding successful!\n");
    } else {
        printf("Decoding failed!\n");
    }

    return 0;
}

void generate_keys(char keys[NUM_KEYS][KEY_LENGTH]) {
    for (int i = 0; i < NUM_KEYS; i++) {
        for (int j = 0; j < KEY_LENGTH; j++) {
            keys[i][j] = rand() % 2 + '0';
        }
    }
}

void encode_message(Voter* voter, char key[KEY_LENGTH]) {
    for (int i = 0; i < MESSAGE_LENGTH; i++) {
        voter->message[i] ^= key[i % KEY_LENGTH];
    }
}

void decode_message(Voter* voter, char key[KEY_LENGTH]) {
    for (int i = 0; i < MESSAGE_LENGTH; i++) {
        voter->message[i] ^= key[i % KEY_LENGTH];
    }
}