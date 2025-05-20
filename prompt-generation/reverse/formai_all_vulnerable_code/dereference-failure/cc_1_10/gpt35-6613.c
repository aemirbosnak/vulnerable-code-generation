//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80
#define MAX_HISTORY 10

char* history[MAX_HISTORY];
int history_count = 0;

void execute(char* args[])
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if(pid == 0) // child process
    {
        if(execvp(args[0], args) == -1)
        {
            printf("Error: command not found\n");
        }
        exit(EXIT_FAILURE);
    }
    else if(pid < 0) // fork failed
    {
        printf("Error: fork failed\n");
    }
    else // parent process
    {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void add_to_history(char* cmd)
{
    if(history_count == MAX_HISTORY)
    {
        free(history[0]);
        for(int i = 0; i < MAX_HISTORY - 1; i++)
        {
            history[i] = history[i+1];
        }
        history[MAX_HISTORY - 1] = strdup(cmd);
    }
    else
    {
        history[history_count] = strdup(cmd);
        history_count++;
    }
}

void print_history()
{
    for(int i = 0; i < history_count; i++)
    {
        printf("%d: %s\n", i+1, history[i]);
    }
}

void clear_history()
{
    for(int i = 0; i < history_count; i++)
    {
        free(history[i]);
    }
    history_count = 0;
}

int main(void)
{
    char* args[MAX_LINE/2 + 1];
    char input[MAX_LINE + 1];
    int should_run = 1;

    printf("Welcome to MyShell!\n");

    while(should_run)
    {
        printf(">> ");

        fflush(stdout);

        memset(input, 0, sizeof(input)); // clear input buffer
        fgets(input, MAX_LINE, stdin);

        if(input[strlen(input)-1] == '\n') // clean new line character
        {
            input[strlen(input)-1] = '\0';
        }

        if(strcmp(input, "exit") == 0) // exit command
        {
            should_run = 0;
            printf("Goodbye!\n");
        }
        else if(strcmp(input, "history") == 0) // print command history
        {
            print_history();
        }
        else if(strcmp(input, "clear") == 0) // clear command history
        {
            clear_history();
        }
        else if(input[0] == '!') // execute command from history
        {
            if(history_count == 0)
            {
                printf("Error: no commands in history\n");
            }
            else if(input[1] == '!')
            {
                execute(args);
            }
            else if(input[1] > '0' && input[1] <= '9')
            {
                int index = input[1] - '0';
                if(index > history_count)
                {
                    printf("Error: invalid command index\n");
                }
                else
                {
                    strcpy(input, history[index-1]);
                    printf("%s\n", input);
                    add_to_history(input);
                    char* token = strtok(input, " ");
                    int i = 0;
                    while(token != NULL)
                    {
                        args[i] = token;
                        token = strtok(NULL, " ");
                        i++;
                    }
                    args[i] = NULL;
                    execute(args);
                }
            }
            else 
            {
                printf("Error: invalid input\n");
            }
        }
        else // execute command
        {
            add_to_history(input);
            char* token = strtok(input, " ");
            int i = 0;
            while(token != NULL)
            {
                args[i] = token;
                token = strtok(NULL, " ");
                i++;
            }
            args[i] = NULL;
            execute(args);
        }

    }

    return 0;
}