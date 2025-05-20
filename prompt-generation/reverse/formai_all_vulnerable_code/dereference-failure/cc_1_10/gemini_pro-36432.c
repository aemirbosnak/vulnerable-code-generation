//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **generate_key(int num_chars, int num_keys) {
    char **keys = malloc(sizeof(char *) * num_keys);
    for (int i = 0; i < num_keys; i++) {
        keys[i] = malloc(sizeof(char) * num_chars);
        for (int j = 0; j < num_chars; j++) {
            keys[i][j] = rand() % 26 + 'a';
        }
    }
    return keys;
}

char **generate_encoded_messages(char **messages, char **keys, int num_messages, int num_chars, int num_keys) {
    char **encoded_messages = malloc(sizeof(char *) * num_messages);
    for (int i = 0; i < num_messages; i++) {
        encoded_messages[i] = malloc(sizeof(char) * num_chars);
        for (int j = 0; j < num_chars; j++) {
            encoded_messages[i][j] = (messages[i][j] + keys[i % num_keys][j] - 2 * 'a') % 26 + 'a';
        }
    }
    return encoded_messages;
}

void decode_and_print_messages(char **messages, char **keys, int num_messages, int num_chars, int num_keys) {
    for (int i = 0; i < num_messages; i++) {
        for (int j = 0; j < num_chars; j++) {
            printf("%c", (messages[i][j] - keys[i % num_keys][j] + 26) % 26 + 'a');
        }
        printf("\n");
    }
}

char **generate_messages(int num_messages, int num_chars) {
    char **messages = malloc(sizeof(char *) * num_messages);
    for (int i = 0; i < num_messages; i++) {
        messages[i] = malloc(sizeof(char) * num_chars);
        for (int j = 0; j < num_chars; j++) {
            messages[i][j] = rand() % 26 + 'a';
        }
    }
    return messages;
}

int main() {
    int num_messages = 10;
    int num_chars = 10;
    int num_keys = 3;

    char **messages = generate_messages(num_messages, num_chars);
    char **keys = generate_key(num_chars, num_keys);
    char **encoded_messages = generate_encoded_messages(messages, keys, num_messages, num_chars, num_keys);

    decode_and_print_messages(encoded_messages, keys, num_messages, num_chars, num_keys);

    return 0;
}