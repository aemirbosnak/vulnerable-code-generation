//Falcon-180B DATASET v1.0 Category: Error handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COMMAND_SIZE 100
#define MAX_FILE_NAME_LENGTH 500
#define MAX_ERROR_MESSAGE_LENGTH 100

typedef struct {
    char *command;
    char *file_name;
    int line_number;
} ErrorInfo;

void print_error_message(char *message, ErrorInfo *error_info) {
    char formatted_message[MAX_ERROR_MESSAGE_LENGTH];
    sprintf(formatted_message, "Error %d on line %d of file '%s': %s\n", error_info->line_number, error_info->line_number, error_info->file_name, message);
    fprintf(stderr, formatted_message);
}

void handle_error(int error_code, char *command, char *file_name, int line_number) {
    switch (error_code) {
        case EACCES:
            print_error_message("Permission denied", (ErrorInfo*)malloc(sizeof(ErrorInfo)));
            break;
        case ENOENT:
            print_error_message("File does not exist", (ErrorInfo*)malloc(sizeof(ErrorInfo)));
            break;
        case EINVAL:
            print_error_message("Invalid argument", (ErrorInfo*)malloc(sizeof(ErrorInfo)));
            break;
        default:
            print_error_message("Unknown error", (ErrorInfo*)malloc(sizeof(ErrorInfo)));
            break;
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char command[MAX_COMMAND_SIZE];
    char file_name[MAX_FILE_NAME_LENGTH];
    int line_number = 1;
    int error_code;

    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s file_name\n", argv[0]);
        return 1;
    }

    // Open the file for reading
    strncpy(file_name, argv[1], MAX_FILE_NAME_LENGTH);
    file = fopen(file_name, "r");
    if (file == NULL) {
        handle_error(errno, "fopen", file_name, line_number);
        return 1;
    }

    // Read each line from the file and execute the command
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        strncpy(command, line, MAX_COMMAND_SIZE);
        if (system(command)!= 0) {
            handle_error(errno, command, file_name, line_number);
            return 1;
        }
        line_number++;
    }

    // Close the file
    fclose(file);

    return 0;
}