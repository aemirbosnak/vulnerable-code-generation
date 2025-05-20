//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

char cmd_line[MAX_CMD_LEN];

void parse_command(char **argv)
{
    char *p, *q;
    int i = 0;

    p = cmd_line;
    q = argv[0] = strchr(p, ' ');
    if (q)
    {
        *q = '\0';
        argv[i++] = p;
    }

    while ((q = strchr(p, ' ')) && i < MAX_CMD_LEN - 1)
    {
        *q = '\0';
        argv[i++] = p;
        p = q + 1;
    }

    argv[i] = NULL;
}

int main()
{
    char **argv;

    printf("Prompt: $ ");
    fgets(cmd_line, MAX_CMD_LEN, stdin);

    parse_command(&argv);

    if (argv[0] && !strcmp(argv[0], "exit"))
    {
        exit(0);
    }

    // Execute remaining commands
    system(argv[0]);

    return 0;
}