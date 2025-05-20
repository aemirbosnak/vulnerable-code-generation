//Falcon-180B DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 64
#define MAX_ARGUMENTS 10
#define MAX_ARG_LENGTH 64

void print_error(int error_code, const char *message) {
    char buffer[1024];
    strerror_r(error_code, buffer, sizeof(buffer));
    fprintf(stderr, "Error %d: %s\n", error_code, message);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [arguments]\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    char *arguments[MAX_ARGUMENTS];
    int num_arguments = 0;

    char *token = strtok(command, " ");
    while (token!= NULL) {
        if (num_arguments >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments\n");
            return 1;
        }
        arguments[num_arguments] = token;
        num_arguments++;
        token = strtok(NULL, " ");
    }

    if (num_arguments == 0) {
        fprintf(stderr, "No arguments provided\n");
        return 1;
    }

    FILE *pipe = popen(command, "r");
    if (pipe == NULL) {
        print_error(errno, "Failed to execute command");
        return 1;
    }

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, sizeof(buffer), pipe)!= NULL) {
        printf("%s", buffer);
    }

    if (pclose(pipe)!= 0) {
        print_error(errno, "Failed to close pipe");
        return 1;
    }

    return 0;
}