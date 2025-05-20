//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_NUM_ARGUMENTS 64
#define TRUE 1

int main()
{
  char *args[MAX_NUM_ARGUMENTS];
  char command[MAX_COMMAND_LENGTH];
  int status;
  
  while(TRUE)
  {
    printf("my_shell: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    
    // Remove newline character from string
    command[strlen(command) - 1] = '\0';
    
    // Parse input into different arguments
    char *token = strtok(command, " ");
    int i = 0;
    
    while(token != NULL)
    {
      args[i] = token;
      token = strtok(NULL, " ");
      i++;
    }
    
    // Add NULL to end of argument list for execvp
    args[i] = NULL;
    
    if(strcmp(args[0], "cd") == 0)
    {
      // Change directory - handle error if argument is invalid
      if(chdir(args[1]) != 0)
      {
        printf("Invalid directory\n");
      }
    }
    else if(strcmp(args[0], "exit") == 0)
    {
      // Exit shell
      break;
    }
    else
    {
      // Fork process and execute command
      pid_t pid = fork();
      
      if(pid == 0)
      {
        // Child process - execute command
        execvp(args[0], args);
        
        // Terminate child process if execvp fails
        printf("Invalid command\n");
        exit(1);
      }
      else
      {
        // Parent process - wait for child to complete
        waitpid(pid, &status, 0);
      }
    }
  }
  
  return 0;
}