//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100 // maximum command length
#define MAX_NUM_ARGUMENTS 10 // maximum number of arguments

int main()
{
  char *command; // command to execute
  char *arguments[MAX_NUM_ARGUMENTS]; // array of arguments
  char command_buffer[MAX_COMMAND_LENGTH]; // buffer to hold command

  while(1) // infinite loop
  {
    printf("grateful-shell> "); // prompt
    fgets(command_buffer, MAX_COMMAND_LENGTH, stdin); // read input

    if(strlen(command_buffer) > 1) // if command is not empty or only contains newline
    {
      command_buffer[strlen(command_buffer) - 1] = '\0'; // remove newline character

      command = strtok(command_buffer, " "); // get first word as command

      int i = 0;
      while(command != NULL && i < MAX_NUM_ARGUMENTS - 1)
      {
        arguments[i++] = command; // store command argument
        command = strtok(NULL, " "); // get next word as argument
      }
      arguments[i] = NULL; // set last argument as NULL for execvp()

      pid_t child_pid = fork(); // fork child process
      if(child_pid == 0) // if child process
      {
        int result = execvp(arguments[0], arguments); // execute command
        if(result < 0) // if error
        {
          printf("%s: %s\n", arguments[0], strerror(errno)); // print error message
          exit(1);
        }
      }
      else // if parent process
      {
        waitpid(child_pid, NULL, 0); // wait for child process to finish
      }
    }
  }

  return 0; // never reaches
}