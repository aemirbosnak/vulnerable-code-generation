//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
/*
 * Alien Language Translator
 *
 * This program translates English text into an alien language.
 * The alien language is a simple substitution cipher, where each
 * English letter is replaced by a corresponding alien character.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * The English alphabet.
 */
char english_alphabet[] = "abcdefghijklmnopqrstuvwxyz";

/*
 * The alien alphabet.
 */
char alien_alphabet[] = "zxcvbnmlkjhgfdsaqwertyuiop";

/*
 * Translates an English string into an alien string.
 */
char *translate(char *english) {
    /* Allocate memory for the alien string. */
    char *alien = malloc(strlen(english) + 1);

    /* Translate each character in the English string. */
    for (int i = 0; i < strlen(english); i++) {
        char c = english[i];
        for (int j = 0; j < strlen(english_alphabet); j++) {
            if (c == english_alphabet[j]) {
                alien[i] = alien_alphabet[j];
                break;
            }
        }
    }

    /* Null-terminate the alien string. */
    alien[strlen(english)] = '\0';

    /* Return the alien string. */
    return alien;
}

/*
 * Main program.
 */
int main() {
    /* Get the English text from the user. */
    char english[1000];
    printf("Enter English text: ");
    gets(english);

    /* Translate the English text into an alien string. */
    char *alien = translate(english);

    /* Print the alien string. */
    printf("Alien text: %s\n", alien);

    /* Free the memory allocated for the alien string. */
    free(alien);

    return 0;
}