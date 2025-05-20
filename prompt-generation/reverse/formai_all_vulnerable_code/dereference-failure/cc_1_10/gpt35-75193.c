//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef enum {
    false,
    true
} bool;

char *getInput() {
    char *buffer = malloc(BUFFER_SIZE * sizeof(char));
    printf("> ");
    fgets(buffer, BUFFER_SIZE, stdin);

    // remove new line character
    int len = strlen(buffer);
    if (buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    return buffer;
}

bool detectIntrusion(char *input) {
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '(' || input[i] == ')' || input[i] == ';' || input[i] == '|') {
            return true;
        }
    }

    return false;
}

int main() {
    while (true) {
        char *input = getInput();

        if (detectIntrusion(input)) {
            printf("Intrusion detected!\n");
        } else {
            printf("Input accepted.\n");
        }

        free(input);
    }

    return 0;
}