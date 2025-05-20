//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256
#define HIST_SIZE 10

char history[HIST_SIZE][MAX_CMD_LEN];
int hist_pos = 0;

void cmd_line(char **argv)
{
    char cmd_line[MAX_CMD_LEN];
    int cmd_len = 0;

    printf("$ ");
    fgets(cmd_line, MAX_CMD_LEN, stdin);

    // Strip newline character
    cmd_line[strcspn(cmd_line, "\n")] = '\0';

    // Check if command is history
    for (int i = 0; i < hist_pos; i++)
    {
        if (strcmp(cmd_line, history[i]) == 0)
        {
            printf("Command found: %s\n", history[i]);
            return;
        }
    }

    // Add command to history
    strcpy(history[hist_pos], cmd_line);
    hist_pos++;

    // Execute command
    execvp(argv[0], argv);
}

int main()
{
    char **argv = NULL;

    while (1)
    {
        cmd_line(argv);
    }

    return 0;
}