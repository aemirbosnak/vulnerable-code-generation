//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024

#define DELIM " \t\r\n\a"

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char *argv[MAX_ARGUMENTS];
    int argc = 0;
    int i = 0;
    int j = 0;
    char *token;
    char *delim = " ";

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strlen(input) == 1 && input[0] == '\n') {
            continue;
        }

        argv[argc] = strtok_r(input, delim, &token);
        while (argv[argc]!= NULL) {
            argc++;
            argv[argc] = strtok_r(NULL, delim, &token);
        }

        for (i = 0; i < argc; i++) {
            if (strcmp(argv[i], "exit") == 0) {
                break;
            }
        }

        if (i == argc) {
            system(input);
        }

        argc = 0;
    }

    return 0;
}