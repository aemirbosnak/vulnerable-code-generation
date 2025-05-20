//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_COMMAND_BUFFER_SIZE 1024
#define MAX_NUMBER_OF_COMMAND_ARGS 64
#define MAX_COMMAND_DELIMITER " \t\r\n\a"

char* read_input() {
    char* input_buffer = NULL;
    size_t buffer_size = 0;
    getline(&input_buffer, &buffer_size, stdin);
    return input_buffer;
}

char** parse_command(char* command_line) {
    int command_buffer_size = MAX_NUMBER_OF_COMMAND_ARGS;
    char** command_args_buffer = malloc(sizeof(char*) * command_buffer_size);
    char* command_arg = strtok(command_line, MAX_COMMAND_DELIMITER);
    int command_arg_index = 0;

    while (command_arg != NULL) {
        command_args_buffer[command_arg_index] = command_arg;

        ++command_arg_index;

        if (command_arg_index >= command_buffer_size) {
            command_buffer_size *= 2;
            command_args_buffer = realloc(command_args_buffer, sizeof(char*) * command_buffer_size);

            if (!command_args_buffer) {
                fprintf(stderr, "Error while allocating memory.\n");
                exit(EXIT_FAILURE);
            }
        }

        command_arg = strtok(NULL, MAX_COMMAND_DELIMITER);
    }

    command_args_buffer[command_arg_index] = NULL;
    return command_args_buffer;
}

int execute_command(char** command_args) {
    pid_t process_id;
    int process_status;

    process_id = fork();

    if (process_id == 0) {
        if (execvp(command_args[0], command_args) == -1) {
            fprintf(stderr, "Command could not be executed.\n");
            exit(EXIT_FAILURE);
        }
    }
    else if (process_id < 0) {
        fprintf(stderr, "Error while forking.\n");
    }
    else {
        do {
            waitpid(process_id, &process_status, WUNTRACED);
        } while (!WIFEXITED(process_status) && !WIFSIGNALED(process_status));
    }

    return 1;
}

int main(int argc, char const *argv[]) {
    char* command_input;
    char** command_args;
    int should_continue = 1;

    while (should_continue) {
        printf("> ");
        command_input = read_input();
        command_args = parse_command(command_input);

        should_continue = execute_command(command_args);

        free(command_input);
        free(command_args);
    }

    return 0;
}