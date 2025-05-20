//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check if the program is being called as a shell.
    if (argc > 1 && strcmp(argv[1], "-s") == 0)
    {
        // Start the shell.
        while (1)
        {
            // Print the prompt.
            printf("$> ");

            // Read the command line.
            char line[1024];
            fgets(line, sizeof(line), stdin);

            // Parse the command line.
            char *tokens[1024];
            int numTokens = 0;
            char *token = strtok(line, " ");
            while (token != NULL)
            {
                tokens[numTokens++] = token;
                token = strtok(NULL, " ");
            }

            // Execute the command.
            if (numTokens > 0)
            {
                pid_t pid = fork();
                if (pid == 0)
                {
                    // Child process.
                    execvp(tokens[0], tokens);
                    exit(EXIT_FAILURE);
                }
                else if (pid > 0)
                {
                    // Parent process.
                    waitpid(pid, NULL, 0);
                }
                else
                {
                    // Error.
                    perror("fork");
                }
            }
        }
    }
    else
    {
        // Print the usage message.
        printf("Usage: %s [-s]\n", argv[0]);
        printf("  -s: Start the shell.\n");
    }

    return 0;
}