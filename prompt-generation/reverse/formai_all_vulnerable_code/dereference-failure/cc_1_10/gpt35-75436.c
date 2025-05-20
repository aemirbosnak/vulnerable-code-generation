//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: expert-level
// This is a custom Unix-like shell program implemented in C language
// It supports the execution of simple shell commands and piping of commands
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

#define MAX_ARGS 100
#define MAX_CMD_LEN 1000

void execute(char** args, char* input_file, char* output_file, int bg) {
    int pid, status, in, out;

    // create new process
    pid = fork();

    if (pid == 0) { // child process
        // handle input/output redirection if any
        if (input_file != NULL) {
            in = open(input_file, O_RDONLY);
            dup2(in, STDIN_FILENO);
            close(in);
        }
        if (output_file != NULL) {
            out = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            dup2(out, STDOUT_FILENO);
            close(out);
        }

        execvp(args[0], args);
        perror("execvp"); // if it returns, an error occurred
        _exit(EXIT_FAILURE); // exit with failure code
    } else if (pid < 0) { // error occurred
        perror("fork");
    } else { // parent process
        if (bg == 0) { // foreground process
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }
}

int main() {
    char input_buffer[MAX_CMD_LEN];
    char* args[MAX_ARGS];
    char* delim = " \t\n";
    char* input_file, * output_file;
    int bg, i;

    while (1) {
        printf("> "); // prompt
        fgets(input_buffer, MAX_CMD_LEN, stdin); // read input

        // handle empty input
        if (strcmp(input_buffer, "\n") == 0){
            continue;
        }

        // tokenize input
        args[0] = strtok(input_buffer, delim);
        i = 1;

        while ((args[i] = strtok(NULL, delim)) != NULL) {
            // handle input/output redirection and background processing flags
            if (strcmp(args[i], "<") == 0) {
                input_file = strtok(NULL, delim);
            } else if (strcmp(args[i], ">") == 0) {
                output_file = strtok(NULL, delim);
            } else if (strcmp(args[i], "&") == 0) {
                bg = 1;
                args[i] = NULL; // dont include flag in args
            }
            i++;
        }
        args[i] = NULL;

        if (strcmp(args[0], "exit") == 0) { // exit shell
            break;
        } else {
            execute(args, input_file, output_file, bg); // execute shell command
        }

        // reset input/output flags
        input_file = NULL;
        output_file = NULL;
        bg = 0;
    }

    return 0;
}