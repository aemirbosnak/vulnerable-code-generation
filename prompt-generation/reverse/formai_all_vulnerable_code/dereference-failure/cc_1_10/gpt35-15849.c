//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_NUM_ARGUMENTS 10

char *history[MAX_NUM_ARGUMENTS];
int history_count = 0;

void print_history() 
{
  for(int i = 0; i < history_count; i++)
  {
      printf("%d. %s\n", i+1, history[i]);
  }
}

int main()
{
  char *cmd_str = (char*) malloc( MAX_COMMAND_LENGTH );
  int child_process_count = 0;

  while( 1 )
  {
    printf("mish> ");

    fgets(cmd_str, MAX_COMMAND_LENGTH, stdin);

    if(strcmp(cmd_str, "exit\n") == 0)
    {
        printf("Exiting mish! Bye!\n");
        break;
    }

    char *token[MAX_NUM_ARGUMENTS];

    int token_count = 0;
    char *arg_ptr;
    char *working_str = strdup(cmd_str);

    while (((arg_ptr = strsep(&working_str, " \t\n")) != NULL) && (token_count < MAX_NUM_ARGUMENTS))
    {
        token[token_count] = strndup(arg_ptr, MAX_COMMAND_LENGTH);

        if(strlen(token[token_count]) == 0)
        {
            token[token_count] = NULL;
        }

        token_count++;
    }

    if(token[0] != NULL)
    {
        if(strcmp(token[0], "cd") == 0)
        {
            if(token[1] == NULL)
            {
                printf("cd command needs a directory path!\n");
            }
            else
            {
                chdir(token[1]);
            }
        }
        else if(strcmp(token[0], "history") == 0)
        {
            print_history();
        }
        else
        {
            int pid = fork();

            if(pid == 0)
            {
                if(execvp(token[0], token) == -1)
                {
                    printf("%s command not found!\n", token[0]);
                }

                _Exit(EXIT_FAILURE);
            }
            else if(pid < 0)
            {
                printf("Error: Failed to fork child process!\n");
            }
            else
            {
                child_process_count++;

                if(child_process_count > 10)
                {
                    wait(NULL);
                    child_process_count--;
                }
                else
                {
                    int wstatus;
                    waitpid(pid, &wstatus, 0);
                }

                history[history_count] = strdup(cmd_str);
                history_count++;
            }
        }
    }

    free(working_str);
  }

  free(cmd_str);

  for(int i = 0; i < history_count; i++)
  {
      free(history[i]);
  }

  return 0;
}