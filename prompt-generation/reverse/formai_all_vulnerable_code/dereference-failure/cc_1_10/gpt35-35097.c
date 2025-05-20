//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_LINE 80
#define MAX_HISTORY 10

char* history[MAX_HISTORY]; //array to keep track of history
int history_count = 0; //count of commands executed so far

void show_history() { //function to display history
  printf("\nCommand History:\n");
  for(int i = 0; i < history_count; i++) {
    printf("%d. %s\n", i+1, history[i]);
  }
}

int main() {
  char* args[MAX_LINE/2 + 1]; //to store command arguments
  int should_run = 1;

  while(should_run) {
    fflush(stdout);
    printf("retro-shell$ ");
    fflush(stdout);

    char buffer[MAX_LINE];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    history[history_count % MAX_HISTORY] = strdup(buffer); //adding command to history
    history_count++;

    int arg_num = 0;
    char* token = strtok(buffer, " ");
    while(token != NULL) {
      args[arg_num] = token;
      arg_num++;
      token = strtok(NULL, " ");
    }
    args[arg_num] = NULL; //marking end of argument list

    if(strcmp(args[0], "exit") == 0) {
      should_run = 0;
    }
    else if(strcmp(args[0], "history") == 0) {
      show_history();
    }
    else {
      pid_t pid = fork(); //creating a child process
      if(pid == 0) { //child process
        execvp(args[0], args);
        exit(0);
      }
      else { //parent process
        wait(NULL); //wait for child process to finish
      }
    }
  }

  return 0;
}