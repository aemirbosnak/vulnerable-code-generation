//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

// function to split the user input into tokens
int tokenize_input(char *input, char **tokens)
{
    int i = 0;
    char *token = strtok(input, " \t\n");
    while (token != NULL)
    {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " \t\n");
    }
    tokens[i] = NULL;
    return i;
}

// function to execute a command with its arguments
int execute_command(char **tokens)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        printf("Error: Unable to fork child process.\n");
        return -1;
    }
    else if (pid == 0)
    {
        if (execvp(tokens[0], tokens) == -1)
        {
            printf("%s: command not found.\n", tokens[0]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        int status;
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 0;
}

int main()
{
    char *input = calloc(MAX_INPUT_SIZE, sizeof(char));
    char *tokens[MAX_NUM_TOKENS];
    while (1)
    {
        printf("> ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        int num_tokens = tokenize_input(input, tokens);
        if (num_tokens == 0)
        {
            continue;
        }
        if (strcmp(tokens[0], "exit") == 0)
        {
            printf("Shell exiting...\n");
            break;
        }
        else if (strcmp(tokens[0], "multiplayer") == 0)
        {
            printf("Entering multiplayer mode...\n");
            printf("Type 'exit' to leave multiplayer mode.\n");
            int player = 1;
            while (1)
            {
                printf("Player %d> ", player);
                fgets(input, MAX_INPUT_SIZE, stdin);
                int num_tokens = tokenize_input(input, tokens);
                if (num_tokens == 0)
                {
                    continue;
                }
                if (strcmp(tokens[0], "exit") == 0)
                {
                    printf("Leaving multiplayer mode...\n");
                    break;
                }
                printf("Player %d's command: %s", player, input);
                player = (player % 2) + 1;
            }
        }
        else
        {
            execute_command(tokens);
        }
        memset(input, 0, MAX_INPUT_SIZE);
        memset(tokens, 0, MAX_NUM_TOKENS * sizeof(char *));
    }
    free(input);
    return 0;
}