//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char message[1000];
    char translated_message[1000];
    char key[1000];
    int i, j, k, n;
    int alphabet_size = 26;
    int key_size;

    printf("Enter the message to be translated: ");
    fgets(message, 1000, stdin);
    printf("Enter the key: ");
    fgets(key, 1000, stdin);

    key_size = strlen(key);

    for (i = 0; i < alphabet_size; i++) {
        for (j = 0; j < alphabet_size; j++) {
            if (key[i % key_size] == 'a' + j) {
                n = i * alphabet_size + j;
                break;
            }
        }
        if (j == alphabet_size) {
            printf("Error: Invalid key.\n");
            return 1;
        }
    }

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                k = (int) message[i] - 65;
            } else {
                k = (int) message[i] - 97;
            }
            translated_message[i] = (char) (((k - n - 1) % alphabet_size) + 65);
        } else {
            translated_message[i] = message[i];
        }
    }

    printf("Translated message: %s\n", translated_message);

    return 0;
}