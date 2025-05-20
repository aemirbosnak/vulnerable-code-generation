//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

// Parse the command line input and tokenize it
void tokenize(char* line, char** tokens, int* num_tokens) {
    line[strlen(line) - 1] = '\0'; // remove newline character
    char* token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    *num_tokens = i;
}

int main() {
    char line[MAX_INPUT_SIZE];           
    char* tokens[MAX_NUM_TOKENS];  
    int num_tokens = 0;

    while (1) {
        printf(">> ");
        fgets(line, MAX_INPUT_SIZE, stdin);

        tokenize(line, tokens, &num_tokens);

        pid_t pid = fork();
        if (pid < 0) {
            printf("Error: Fork failed.\n");
            return 1;
        }
        else if (pid == 0) {
            // Child process
            int ret = execvp(tokens[0], tokens);
            if (ret == -1) {
                printf("Error: Command not found.\n");
                return 1;
            }
        }
        else {
            // Parent process
            wait(NULL);
        }
    }
    return 0;
}