//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

  printf("Welcome to the Surrealist Shell!\n");
  printf("Type 'help' to see the available commands.\n");

  while(1) {

    // Get the current user and host name
    char hostname[1024];
    gethostname(hostname, 1024);
    char* username = getenv("USER");

    // Prompt the user for input
    printf("%s@%s:$ ", username, hostname);
    fflush(stdout);

    // Read the input from the user
    char input[1024];
    fgets(input, 1024, stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = 0;

    // Split the input into tokens
    char* tokens[1024];
    int numTokens = 0;
    char* token = strtok(input, " ");
    while(token != NULL) {
      tokens[numTokens++] = token;
      token = strtok(NULL, " ");
    }
    tokens[numTokens] = NULL;

    // Check for built-in commands
    if(strcmp(tokens[0], "help") == 0) {
      printf("This is the Surrealist Shell!\n");
      printf("Available commands:\n");
      printf("  help      : Show this help message\n");
      printf("  ls        : List directory contents\n");
      printf("  whoami    : Print the current user\n");
      printf("  date      : Print the current date\n");
      printf("  cowsay    : Print a cow saying something surreal\n");
    }
    else if(strcmp(tokens[0], "ls") == 0) {
      system("ls");
    }
    else if(strcmp(tokens[0], "whoami") == 0) {
      printf("%s\n", username);
    }
    else if(strcmp(tokens[0], "date") == 0) {
      system("date +%A,%B %d,%Y");
    }
    else if(strcmp(tokens[0], "cowsay") == 0) {
      if(numTokens < 2) {
        printf("Please specify what you want the cow to say...\n");
      }
      else {
        char command[1024];
        sprintf(command, "cowsay -f turtle \"%s\"", tokens[1]);
        system(command);
      }
    }
    else {
      printf("I don't know how to \"%s\"...\n", tokens[0]);
    }

  }

  return 0;
}