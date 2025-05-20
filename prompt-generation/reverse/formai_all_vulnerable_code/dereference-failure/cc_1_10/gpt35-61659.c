//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

#define MAX_COMMAND_LENGTH 100 // maximum length of a command
#define MAX_NUM_ARGUMENTS 10  // maximum number of arguments a command can have

int main()
{
  char command[MAX_COMMAND_LENGTH];
  char *args[MAX_NUM_ARGUMENTS];
  
  while(1) // While loop to keep the shell running until 'exit' is entered
  {
    printf("myShell >> ");
    fgets(command, MAX_COMMAND_LENGTH, stdin); // Read input command from user
    command[strcspn(command, "\n")] = '\0';    // Remove trailing newline
    
    // Tokenize the command into individual arguments
    char *token = strtok(command, " ");
    int num_args = 0;
    
    while(token != NULL)
    {
      args[num_args] = token;
      token = strtok(NULL, " ");
      num_args++;
    }
    args[num_args] = NULL; // Set the last argument to NULL
    
    // Check if user entered 'exit'
    if(strcmp(args[0], "exit") == 0)
    {
      exit(0);
    }
    
    pid_t pid = fork(); // Create a child process
    
    if(pid == -1) // Error forking
    {
      perror("fork failed");
      exit(1);
    }
    else if(pid == 0) // Child process
    {
      execvp(args[0], args); // Run the command with the arguments provided
      
      // execvp returns only if it fails
      perror("execvp failed");
      exit(1);
    }
    else // Parent process
    {
      waitpid(pid, NULL, 0); // Wait for child process to complete
    }
  }
  
  return 0;
}