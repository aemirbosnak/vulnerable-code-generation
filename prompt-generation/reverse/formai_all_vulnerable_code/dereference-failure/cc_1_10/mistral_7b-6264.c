//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 26
#define ALPHABET_SIZE 26

// Romantic alphabet
const char romantic_alphabet[] = "äöéìåíüèòôïúàæô";

void print_usage(void) {
    printf("Usage: love_letter_encrypt [message] [output_file]\n");
}

void encrypt_letter(char *letter, int *index) {
    *letter = romantic_alphabet[*index % KEY_SIZE];
}

void encrypt(const char *message, char *encrypted_message, int message_length) {
    int index = 0;

    for (int i = 0; i < message_length; ++i) {
        if (isalpha(message[i])) {
            encrypt_letter((char*)&encrypted_message[i], &index);
        } else {
            encrypted_message[i] = message[i];
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    const char *message = argv[1];
    char *encrypted_message = malloc(strlen(message) + 1);

    int message_length = strlen(message);
    encrypt(message, encrypted_message, message_length);

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        free(encrypted_message);
        return 1;
    }

    fwrite(encrypted_message, message_length + 1, sizeof(char), output_file);
    fclose(output_file);

    free(encrypted_message);

    printf("Encrypted message saved to [%s]\n", argv[2]);

    return 0;
}