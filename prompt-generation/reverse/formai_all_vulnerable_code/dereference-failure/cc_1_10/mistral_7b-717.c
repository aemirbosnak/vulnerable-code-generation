//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define _GNU_SOURCE
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <alloca.h>

typedef struct riddle {
    char *question;
    char *answer;
    struct riddle *next;
} riddle_t;

void print_riddle(riddle_t *riddle) {
    if (riddle) {
        write(STDOUT_FILENO, riddle->question, strlen(riddle->question));
        write(STDOUT_FILENO, ": ", 2);
        write(STDOUT_FILENO, riddle->answer, strlen(riddle->answer));
        write(STDOUT_FILENO, "\n", 1);
        print_riddle(riddle->next);
    }
}

riddle_t *create_riddle(char *question, char *answer) {
    riddle_t *new_riddle = (riddle_t *)calloc(1, sizeof(riddle_t));

    if (new_riddle) {
        new_riddle->question = strdup(question);
        new_riddle->answer = strdup(answer);
        new_riddle->next = NULL;
    }

    return new_riddle;
}

void solve_riddles(int argc, char **argv) {
    riddle_t *riddles = NULL;
    int status;
    pid_t pid;
    char *input;
    size_t len;

    if (argc < 2) {
        print_riddle(riddles);
        exit(EXIT_SUCCESS);
    }

    while (*++argv) {
        riddle_t *new_riddle = create_riddle(*argv, argv[0]);
        riddles = realloc(riddles, sizeof(riddle_t) * (1 + strlen(argv[0]) / 2));
        riddles[strlen(argv[0]) / 2] = *new_riddle;
    }

    while (riddles) {
        printf("Solve this riddle:\n");
        print_riddle(&riddles[0]);

        input = alloca(1024);
        fgets(input, sizeof(input), STDIN_FILENO);
        len = strlen(input) - 1;

        if (input[len] == '\n')
            input[len] = '\0';

        pid = fork();

        if (pid == 0) {
            execlp("/bin/sh", "sh", "-c", input, NULL);
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }

        wait(&status);

        if (WIFEXITED(status)) {
            if (WEXITSTATUS(status) == 0)
                printf("Correct answer! Moving on to the next riddle.\n");
            else
                printf("Incorrect answer! Try again.\n");
        } else
            perror("Error waiting for child process");

        riddles = &riddles[strlen(argv[0]) / 2 + 1];
    }
}

int main(int argc, char **argv) {
    if (argc > 1)
        solve_riddles(argc, argv);
    else
        printf("Usage: %s <riddle question> <riddle answer>\n", argv[0]);

    return EXIT_SUCCESS;
}