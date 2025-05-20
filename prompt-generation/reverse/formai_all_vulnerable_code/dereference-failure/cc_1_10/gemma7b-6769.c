//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

char cmd_buf[MAX_CMD_LEN];

void parse_cmd(char **argv)
{
    char *ptr = cmd_buf;
    char *arg = NULL;

    *argv = NULL;

    // Eat spaces before the command
    while (*ptr && isspace(*ptr))
    {
        ptr++;
    }

    // Get the command and arguments
    arg = strsep(ptr, " ");

    while (arg)
    {
        *argv++ = strdup(arg);
        arg = strsep(NULL, " ");
    }

    *argv = NULL;
}

int main()
{
    char **argv = NULL;

    // Loop until the user enters "quit"
    while (1)
    {
        // Get the command
        printf("$ ");
        fgets(cmd_buf, MAX_CMD_LEN, stdin);

        // Parse the command
        parse_cmd(&argv);

        // Check if the command is "quit"
        if (strcmp(argv[0], "quit") == 0)
        {
            break;
        }

        // Execute the command
        system(argv[0]);

        // Free the memory allocated for arguments
        free(argv);
    }

    return 0;
}