//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LENGTH 1000

void encrypt(char *message, char *key) {
    int i, j;
    char encrypted_message[MAX_LENGTH] = {0};

    for (i = 0; i < strlen(message); i++) {
        char current_char = message[i];
        char key_char = key[(i % strlen(key))];

        if (isalpha(current_char)) {
            if (isupper(current_char)) {
                current_char = (char)(((int)current_char - 65 + (int)key_char - 65) % 26 + 65);
            } else {
                current_char = (char)(((int)current_char - 97 + (int)key_char - 97) % 26 + 97);
            }
        }

        encrypted_message[i] = current_char;
    }

    strcat(encrypted_message, "\nThis message has been encrypted using The Enchanted Quill.\n");

    FILE *file = fopen("encrypted_message.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    fprintf(file, "%s", encrypted_message);
    fclose(file);

    printf("Message encrypted successfully.\n");
}

int main() {
    char message[MAX_LENGTH] = {0};
    char key[MAX_LENGTH] = {"apple"}; // Change this key for different encryption results

    printf("Welcome, brave adventurer, to The Enchanted Quill.\n");
    printf("Please input the message you wish to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character

    printf("The message you entered was: %s\n", message);

    printf("Prepare yourself, as the power of The Enchanted Quill shall now transform your message into an encrypted form.\n");

    encrypt(message, key);

    return 0;
}