//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: lively
/*
 * BrainyOS - a Unix-like shell in C with a twist
 *
 * Copyright (c) 2023, Lukas Blum
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 16

// Built-in commands
const char *builtins[] = {"exit", "cd", "help", "echo", "pwd", "ls", "cat", "grep", "wc", NULL};

// Function prototypes
int execute(char *args[]);
char **parse(char *line);
int builtin_command(char **args);
void print_prompt();

// Main function
int main()
{
  char line[MAX_CMD_LEN];
  char **args;
  int status;

  // Run the shell until the user exits
  while (1)
  {
    print_prompt();

    // Get the user's input
    fgets(line, MAX_CMD_LEN, stdin);

    // Parse the user's input into individual arguments
    args = parse(line);

    // Execute the command
    status = execute(args);

    // Free the memory allocated for the arguments
    free(args);

    // Exit the shell if the user entered the "exit" command
    if (status == -1)
      break;
  }

  return 0;
}

// Function to execute a command
int execute(char *args[])
{
  // Check if the command is a built-in command
  int built_in_index = builtin_command(args);
  if (built_in_index != -1)
    return built_in_index;

  // Fork a new process to execute the command
  pid_t pid = fork();
  if (pid == 0)
  {
    // Child process
    if (execvp(args[0], args) == -1)
      perror("execvp");
    exit(EXIT_FAILURE);
  }
  else if (pid > 0)
  {
    // Parent process
    int status;
    waitpid(pid, &status, 0);
    return status;
  }
  else
  {
    // Fork failed
    perror("fork");
    return -1;
  }
}

// Function to parse a command line into individual arguments
char **parse(char *line)
{
  // Allocate memory for the arguments
  char **args = malloc(sizeof(char *) * MAX_ARGS);

  // Tokenize the command line
  char *token = strtok(line, " ");

  // Parse the command line into individual arguments
  int i = 0;
  while (token != NULL)
  {
    args[i] = token;
    i++;
    token = strtok(NULL, " ");
  }

  // Terminate the array of arguments with a NULL pointer
  args[i] = NULL;

  // Return the array of arguments
  return args;
}

// Function to execute a built-in command
int builtin_command(char **args)
{
  // Check if the command is a built-in command
  for (int i = 0; builtins[i] != NULL; i++)
  {
    if (strcmp(args[0], builtins[i]) == 0)
      return i;
  }

  // Not a built-in command
  return -1;
}

// Function to print the prompt
void print_prompt()
{
  // Get the current working directory
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));

  // Print the prompt
  printf("[BrainyOS] %s > ", cwd);
}