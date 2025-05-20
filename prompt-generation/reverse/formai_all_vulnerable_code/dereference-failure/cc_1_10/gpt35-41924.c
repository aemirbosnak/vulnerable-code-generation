//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char input[256];
    char dir[1024];

    while (1)
    {
        getcwd(dir, sizeof(dir));
        printf("\033[1;32m%s> \033[0m", dir);
        fgets(input, 256, stdin);

        if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't')
            break;

        pid_t pid = fork();
        if (pid == 0)
        {
            char *args[256];
            char *arg = strtok(input, " \n");
            int i = 0;
            while (arg != NULL)
            {
                args[i++] = arg;
                arg = strtok(NULL, " \n");
            }
            args[i] = NULL;

            if (strcmp(args[0], "h3x") == 0 && strcmp(args[1], "0k") == 0)
            {
                printf("\033[1;31mH3X 0K!\033[0m\n");
            }
            else
            {
                execvp(args[0], args);
                printf("\033[1;31mCommand not found\033[0m\n");
            }
            exit(0);
        }
        else
        {
            wait(NULL);
        }
    }

    printf("\033[1;31mGoodbye!\033[0m\n");
    return 0;
}