//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100

void print_welcome_message() {
    printf("🌟🌈 Welcome to CheeryShell! 🌈🌟\n");
    printf("Type your commands below and let the fun begin!\n");
    printf("Type 'exit' to say goodbye! 🎉\n");
}

void trim_newline(char* input) {
    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }
}

void execute_command(char* input) {
    char* args[MAX_ARG_SIZE];
    char* token = strtok(input, " ");

    int i = 0;
    while (token != NULL && i < MAX_ARG_SIZE - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    if (strcmp(args[0], "exit") == 0) {
        printf("🌈😊 Bye! Have a wonderful day! 😊🌈\n");
        exit(0);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("🔴 Fork failed");
        return;
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("🔴 Execute failed");
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);
        printf("✨🎉 Command executed! Back to you! 🎉✨\n");
    }
}

int main() {
    char input[MAX_INPUT_SIZE];

    print_welcome_message();

    while (1) {
        printf("👾 CheeryShell> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("🔴 Failed to read input!\n");
            continue;
        }

        trim_newline(input);
        execute_command(input);
    }

    return 0;
}