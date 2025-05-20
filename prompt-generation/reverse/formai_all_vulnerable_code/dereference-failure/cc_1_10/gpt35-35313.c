//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAX_LINE 80 // maximum length of a command
#define HISTORY_SIZE 10 // maximum history size

char history[HISTORY_SIZE][MAX_LINE]; // stores the command history
int history_count = 0; // keeps track of the number of commands in history

// function declarations
void execute(char **args);
int get_input(char *input);
void add_to_history(char *command);
void display_history();

// implementation of execute command
void execute(char **args) {
  pid_t pid; // process ID
  int status; // process status

  // create a child process
  pid = fork();

  // handle error in creating child process
  if (pid < 0) {
    printf("Error occured in forking child process...");
    exit(1);
  }
  // child process execution code
  else if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      printf("Error in executing command...");
    }
    exit(1);
  }
  // parent process execution code
  else {
    do {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
}

// implementation of getting user command
int get_input(char *input) {
  printf("> ");
  fgets(input, MAX_LINE, stdin);

  // remove trailing newline character
  input[strlen(input)-1] = '\0';
  
  // add command to history
  add_to_history(input);

  // return non-zero value if input is not empty
  return strlen(input) != 0;
}

// implementation of adding command to history
void add_to_history(char *command) {
  // if maximum history size is reached, shift all commands by 1 and add the new command at the beginning
  if (history_count == HISTORY_SIZE) {
    for (int i = 1; i < HISTORY_SIZE; i++) {
      strcpy(history[i-1], history[i]);
    }
    strcpy(history[HISTORY_SIZE-1], command);
  } 
  // add command to history and increment history_count
  else {
    strcpy(history[history_count], command);
    history_count++;
  }
}

// implementation of displaying command history
void display_history() {
  printf("Command history:\n");
  for (int i = 0; i < history_count; i++) {
    printf("%d. %s\n", i+1, history[i]);
  }
}

int main() {
  char *args[MAX_LINE/2 + 1]; // maximum 40 arguments

  while (1) {
    char input[MAX_LINE]; // to store user input
    int should_run = get_input(input); // get user input

    // tokenize the input and store in args array
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL) {
      args[i] = token;
      i++;
      token = strtok(NULL, " ");
    }
    args[i] = NULL;

    // execute command if input is not empty
    if (should_run) {
      // check if user wants to display history
      if (strcmp(args[0], "history") == 0) {
        display_history();
      } else {
        execute(args);
      }
    }
  }
  return 0;
}