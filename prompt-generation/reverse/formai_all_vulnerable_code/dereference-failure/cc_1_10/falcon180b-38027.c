//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert text to Morse code
void text_to_morse(char* message) {
    char* morse_message = malloc(strlen(message) * 2 + 1);
    if (morse_message == NULL) {
        printf("Error: Unable to allocate memory.\n");
        exit(1);
    }

    strcpy(morse_message, "");
    char* word = strtok(message, " ");
    while (word!= NULL) {
        char* morse_word = malloc(strlen(word) * 2 + 1);
        if (morse_word == NULL) {
            printf("Error: Unable to allocate memory.\n");
            exit(1);
        }

        strcpy(morse_word, "");
        char* letter = strtok(word, "");
        while (letter!= NULL) {
            if (isalpha(letter[0])) {
                if (isupper(letter[0])) {
                    strcat(morse_word, "-");
                } else {
                    strcat(morse_word, ". ");
                }
            } else if (isdigit(letter[0])) {
                strcat(morse_word, "-----");
            }
            letter = strtok(NULL, "");
        }

        strcat(morse_message, morse_word);
        strcat(morse_message, " ");
        free(morse_word);
        word = strtok(NULL, " ");
    }

    printf("Morse code: %s\n", morse_message);
    free(morse_message);
}

int main() {
    char message[1000];
    printf("Enter a message to convert to Morse code: ");
    fgets(message, sizeof(message), stdin);
    text_to_morse(message);
    return 0;
}