//Falcon2-11B DATASET v1.0 Category: User Input Sanitizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void sanitize_input(char* input) {
    char output[MAX_LENGTH];
    char* clean_input = NULL;
    int i, length = strlen(input);

    if(length > MAX_LENGTH) {
        printf("Input string is too long, maximum length is %d\n", MAX_LENGTH);
        return;
    }

    clean_input = malloc(length + 1);
    for(i = 0; i < length; i++) {
        if(isalnum(input[i]) || input[i] == '_') {
            clean_input[i] = input[i];
        } else {
            clean_input[i] = '_';
        }
    }
    clean_input[i] = '\0';

    for(i = 0; i < length; i++) {
        if(clean_input[i] == '\0') {
            clean_input[i] = '_';
        }
    }

    strncpy(output, clean_input, length);
    free(clean_input);
    output[length] = '\0';

    printf("Sanitized input: %s\n", output);
}

int main() {
    char input[MAX_LENGTH];

    printf("Please enter a string:\n");
    fgets(input, MAX_LENGTH, stdin);

    sanitize_input(input);

    return 0;
}