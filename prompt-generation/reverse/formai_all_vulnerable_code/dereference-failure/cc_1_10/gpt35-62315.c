//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"

/*
 * Function declarations for built-in shell commands
 */
int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);

/*
 * List of built-in shell commands,
 * followed by their corresponding functions.
 */
char *builtin_command_names[] = {
    "cd",
    "help",
    "exit"
};

int (*builtin_command_functions[])(char **) = {
    &shell_cd,
    &shell_help,
    &shell_exit
};

/*
 * Get the number of builtin commands.
 */
int num_builtin_commands() {
    return sizeof(builtin_command_names) / sizeof(char *);
}

/*
 * Change the current working directory.
 */
int shell_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "shell: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("shell");
        }
    }
    return 1;
}

/*
 * Print the help message for the shell.
 */
int shell_help(char **args) {
    printf("Welcome to the shell! Here are some built-in commands:\n");

    for (int i = 0; i < num_builtin_commands(); i++) {
        printf("  %s\n", builtin_command_names[i]);
    }

    printf("Use man command_name for information about other commands.\n");
    return 1;
}

/*
 * Exit the shell.
 */
int shell_exit(char **args) {
    return 0;
}

/*
 * Execute a shell command.
 */
int shell_execute(char **args) {
    if (args[0] == NULL) {
        return 1;
    }

    for (int i = 0; i < num_builtin_commands(); i++) {
        if (strcmp(args[0], builtin_command_names[i]) == 0) {
            return (*builtin_command_functions[i])(args);
        }
    }

    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("shell");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

/*
 * Read a line of input from the user.
 */
char *shell_read_line(void) {
    int buffer_size = BUFFER_SIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * buffer_size);
    int c;

    if (!buffer) {
        fprintf(stderr, "shell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Read a character
        c = getchar();

        // If we hit EOF, replace it with a null character and return.
        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            // If we have exceeded the buffer, reallocate.
            if (position >= buffer_size) {
                buffer_size += BUFFER_SIZE;
                buffer = realloc(buffer, buffer_size);
                if (!buffer) {
                    fprintf(stderr, "shell: allocation error\n");
                    exit(EXIT_FAILURE);
                }
            }
            buffer[position] = c;
            position++;
        }
    }
}

/*
 * Split the line of input into a list of arguments.
 */
char **shell_split_line(char *line) {
    int buffer_size = BUFFER_SIZE;
    int position = 0;
    char **tokens = malloc(buffer_size * sizeof(char *));
    char *token;

    if (!tokens) {
        fprintf(stderr, "shell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOKEN_DELIMITERS);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= buffer_size) {
            buffer_size += BUFFER_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "shell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_DELIMITERS);
    }

    tokens[position] = NULL;
    return tokens;
}

/*
 * The main loop for the shell.
 */
void shell_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = shell_read_line();
        args = shell_split_line(line);
        status = shell_execute(args);

        free(line);
        free(args);
    } while (status);
}

/*
 * The entry point for the shell program.
 */
int main(int argc, char **argv) {
    // Start the shell loop
    shell_loop();

    return EXIT_SUCCESS;
}