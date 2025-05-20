//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_input(void) {
    int len;
    char* input = (char*) malloc(sizeof(char) * 100);
    printf("What do you want to do? ");
    fgets(input, 100, stdin);
    len = strlen(input);
    input[len - 1] = '\0';
    return input;
}

void process_input(char* input) {
    char* token;
    char* action = NULL;
    char* verb = NULL;
    char* noun = NULL;

    token = strtok(input, " ");
    if (token!= NULL) {
        action = strtok(NULL, " ");
        if (action!= NULL) {
            token = strtok(NULL, " ");
            verb = strtok(NULL, " ");
            if (verb!= NULL) {
                token = strtok(NULL, " ");
                noun = strtok(NULL, " ");
                if (noun!= NULL) {
                    printf("You %s the %s with a %s.\n", action, noun, verb);
                } else {
                    printf("You %s the %s.\n", action, verb);
                }
            } else {
                printf("You %s the %s.\n", action, verb);
            }
        } else {
            printf("You %s.\n", action);
        }
    } else {
        printf("Invalid input.\n");
    }
}

int main(void) {
    char* input;
    char* output;
    while (1) {
        input = read_input();
        process_input(input);
        output = (char*) malloc(sizeof(char) * 100);
        sprintf(output, "Type 'quit' to exit the game.");
        printf("%s\n", output);
        free(output);
    }
    return 0;
}