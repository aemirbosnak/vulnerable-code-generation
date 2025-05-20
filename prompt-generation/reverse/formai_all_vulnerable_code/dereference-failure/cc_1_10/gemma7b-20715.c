//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

char cmd_buffer[MAX_CMD_LEN];

void parse_cmd(char **argv)
{
  int i = 0;
  char *p = cmd_buffer;

  // Strip leading and trailing whitespaces
  while (*p && isspace(*p))
    p++;

  // Allocate memory for argv
  argv = malloc(MAX_CMD_LEN);

  // Tokenize the command
  while (*p)
  {
    argv[i++] = p;
    while (*p && !isspace(*p))
      p++;
  }

  // Null-terminate argv
  argv[i] = NULL;
}

int main()
{
  char *argv[MAX_CMD_LEN];

  // Enter the shell prompt
  printf("$ ");

  // Get the command line input
  fgets(cmd_buffer, MAX_CMD_LEN, stdin);

  // Parse the command
  parse_cmd(argv);

  // Execute the command
  execvp(argv[0], argv);

  // Error if execvp fails
  perror("Error executing command");

  return 1;
}