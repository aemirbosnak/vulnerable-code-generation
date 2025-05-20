//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int buf_size = 0;
    int word_count = 0;
    char *buf = string;
    char **words = NULL;

    while (*buf) {
        if (strchr(DELIM, *buf)) {
            *buf = '\0';
            word_count++;
        }
        buf++;
    }

    buf_size = word_count + 1;
    words = malloc(buf_size * sizeof(char *));

    buf = string;
    word_count = 0;
    while (*buf) {
        if (strchr(DELIM, *buf)) {
            *(words + word_count) = buf;
            word_count++;
            buf++;
            while (strchr(DELIM, *buf)) {
                buf++;
            }
        }
        buf++;
    }

    *(words + word_count) = NULL;

    return words;
}

pid_t launch_shell(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        // Error forking
        perror("fork");
        exit(1);
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));
    }

    return pid;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    args = split_string(input);

    pid = launch_shell(args);

    waitpid(pid, NULL, 0);
}

int main(void) {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    loop();

    return 0;
}