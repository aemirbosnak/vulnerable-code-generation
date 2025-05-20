//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[50];
    int i, len;

    printf("Greetings, traveler! What is your name?\n");
    fgets(input, sizeof(input), stdin);

    len = strlen(input);

    // Check for invalid characters
    for (i = 0; i < len; i++) {
        if (input[i] == ';' || input[i] == '<' || input[i] == '>' || input[i] == '|' || input[i] == '&') {
            printf("I'm sorry, but those characters are not allowed.\n");
            printf("Your input has been sanitized.\n");
            return 0;
        }
    }

    printf("Welcome, %s! What brings you to our kingdom?\n", input);

    fgets(input, sizeof(input), stdin);
    len = strlen(input);

    // Remove trailing newline character
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }

    // Replace invalid characters with spaces
    for (i = 0; i < len; i++) {
        if (input[i] == ';' || input[i] == '<' || input[i] == '>' || input[i] == '|' || input[i] == '&') {
            input[i] = ' ';
        }
    }

    printf("Ah, %s. A noble quest indeed!\n", input);

    printf("Now, tell me, what is your quest?\n");

    fgets(input, sizeof(input), stdin);
    len = strlen(input);

    // Remove trailing newline character
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }

    // Replace invalid characters with underscores
    for (i = 0; i < len; i++) {
        if (input[i] == ';' || input[i] == '<' || input[i] == '>' || input[i] == '|' || input[i] == '&') {
            input[i] = '_';
        }
    }

    printf("A valiant quest, %s! Good luck on your journey.\n", input);

    return 0;
}