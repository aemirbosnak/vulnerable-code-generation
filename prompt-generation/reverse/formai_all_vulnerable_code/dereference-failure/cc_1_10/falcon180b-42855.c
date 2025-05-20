//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024

int main(int argc, char *argv[]) {
    int i;
    char *command = NULL;
    char *delimiter = " ";
    char *token;

    // check if the correct number of arguments are provided
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    // allocate memory for the command string
    command = malloc(MAX_COMMAND_LENGTH);
    if (command == NULL) {
        printf("Error: could not allocate memory for command\n");
        return 1;
    }

    // copy the command string
    strcpy(command, argv[1]);

    // tokenize the command string
    token = strtok(command, delimiter);

    // execute each command in the tokenized string
    while (token!= NULL) {
        for (i = 0; i < strlen(token); i++) {
            if (token[i] == '>') {
                // redirect output to a file
                char *output_file = strchr(token, '>');
                if (output_file!= NULL) {
                    *output_file = '\0';
                    output_file++;
                    FILE *fp = fopen(output_file, "w");
                    if (fp == NULL) {
                        printf("Error: could not open output file %s\n", output_file);
                        return 1;
                    }
                    dup2(fileno(fp), 1);
                    fclose(fp);
                }
            }
        }
        // execute the command
        system(token);

        // wait for the command to complete
        token = strtok(NULL, delimiter);
    }

    // free the memory allocated for the command string
    free(command);

    return 0;
}