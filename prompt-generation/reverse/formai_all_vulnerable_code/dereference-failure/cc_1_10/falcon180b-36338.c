//Falcon-180B DATASET v1.0 Category: Error handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 64

enum {
    OK = 0,
    FAILURE = 1
};

void print_error(int error_code) {
    switch(error_code) {
        case FAILURE:
            printf("Error: Failed to execute command\n");
            break;
        default:
            printf("Error: Unknown error\n");
    }
}

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    char command_buffer[MAX_COMMAND_LENGTH];
    char *token;
    int command_length;
    int status;

    while(1) {
        printf("> ");
        fgets(input_buffer, MAX_LINE_LENGTH, stdin);

        // Remove newline character from input buffer
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        // Copy input buffer to command buffer
        strcpy(command_buffer, input_buffer);

        // Tokenize input buffer
        token = strtok(command_buffer, " ");
        command_length = strlen(token);

        // Check if command is valid
        if(command_length == 0 || command_length > MAX_COMMAND_LENGTH) {
            print_error(FAILURE);
            continue;
        }

        // Execute command
        if(strcmp(token, "exit") == 0) {
            printf("Exiting program...\n");
            break;
        } else if(strcmp(token, "ls") == 0) {
            status = system("ls");
            if(status == -1) {
                print_error(FAILURE);
            }
        } else if(strcmp(token, "cd") == 0) {
            token = strtok(NULL, " ");
            if(token == NULL) {
                print_error(FAILURE);
            } else {
                status = chdir(token);
                if(status == -1) {
                    print_error(FAILURE);
                }
            }
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}