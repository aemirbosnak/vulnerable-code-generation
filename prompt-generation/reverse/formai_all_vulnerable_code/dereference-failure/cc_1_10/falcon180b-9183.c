//Falcon-180B DATASET v1.0 Category: Error handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_COMMAND_LENGTH 100
#define MAX_ERROR_MESSAGE_LENGTH 200

/* Function prototypes */
void handle_error(int error_code, const char* function_name);
void print_usage(const char* program_name);
int process_command(const char* command);

int main(int argc, char** argv) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    int command_index = 1;
    while (argv[command_index]!= NULL) {
        int result = process_command(argv[command_index]);
        if (result!= 0) {
            return result;
        }
        command_index++;
    }

    return 0;
}

void handle_error(int error_code, const char* function_name) {
    char error_message[MAX_ERROR_MESSAGE_LENGTH];

    switch (error_code) {
        case EINVAL:
            sprintf(error_message, "Invalid argument: %s", function_name);
            break;
        case ENOENT:
            sprintf(error_message, "File not found: %s", function_name);
            break;
        case EPERM:
            sprintf(error_message, "Operation not permitted: %s", function_name);
            break;
        case ENOMEM:
            sprintf(error_message, "Out of memory: %s", function_name);
            break;
        default:
            sprintf(error_message, "Unknown error: %s", function_name);
            break;
    }

    fprintf(stderr, "Error: %s\n", error_message);
    exit(1);
}

void print_usage(const char* program_name) {
    fprintf(stderr, "Usage: %s command [args...]\n", program_name);
    exit(1);
}

int process_command(const char* command) {
    int argc = 0;
    char* argv[MAX_COMMAND_LENGTH];
    char* token = strtok(command, " ");

    while (token!= NULL) {
        if (argc >= MAX_COMMAND_LENGTH) {
            handle_error(EINVAL, "process_command");
        }

        argv[argc++] = token;
        token = strtok(NULL, " ");
    }

    if (argc == 0) {
        handle_error(EINVAL, "process_command");
    }

    if (strcmp(argv[0], "echo") == 0) {
        if (argc < 2) {
            handle_error(EINVAL, "echo");
        }

        for (int i = 1; i < argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
        return 0;
    } else if (strcmp(argv[0], "mkdir") == 0) {
        if (argc < 2) {
            handle_error(EINVAL, "mkdir");
        }

        int result = mkdir(argv[1], 0777);
        if (result!= 0) {
            handle_error(errno, "mkdir");
        }
        return 0;
    } else {
        handle_error(EINVAL, "process_command");
    }
}