//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_MESSAGE_LENGTH 100

void print_usage() {
    printf("Usage: %s <message>\n", __FILE__);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return 1;
    }

    char message[MAX_MESSAGE_LENGTH];
    strcpy(message, argv[1]);

    int message_length = strlen(message);
    if (message_length > MAX_MESSAGE_LENGTH) {
        printf("Error: message too long\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < message_length; i++) {
        char current_char = message[i];
        int key;

        if (isdigit(current_char)) {
            key = rand() % 10 + 1;
        } else if (isalpha(current_char)) {
            bool is_upper = isupper(current_char);
            key = (is_upper ? 'Z' : 'z') - current_char + 1;
            key %= 26;
            if (is_upper) {
                key += 'A';
            }
        } else {
            continue;
        }

        char encrypted_char = current_char;
        if (isalpha(current_char)) {
            encrypted_char = (current_char + key - 'A' + 26) % 26 + 'A';
        } else if (isdigit(current_char)) {
            encrypted_char = (current_char + key - '0' + 10) % 10 + '0';
        }

        message[i] = encrypted_char;
    }

    printf("Encrypted message: %s\n", message);

    return 0;
}