//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <utime.h>

#define MAX_STR_LEN 1024
#define MAX_PROCESS_NAME 32

// Global variables
int num_processes = 0;
pid_t *processes;

// Function to create a new process
void create_process(const char *cmd) {
  // Create a new process
  pid_t pid = fork();

  // Check if the fork failed
  if (pid < 0) {
    perror("fork failed");
    exit(EXIT_FAILURE);
  }

  // If the fork succeeded, set the parent process ID
  if (pid > 0) {
    processes = realloc(processes, (num_processes + 1) * sizeof(pid_t));
    processes[num_processes] = pid;
    num_processes++;
  }

  // If the fork failed, print an error message
  else {
    perror("fork failed");
  }
}

// Function to print a message to the console
void print_message(const char *msg) {
  printf("%s\n", msg);
}

// Function to wait for all processes to complete
void wait_for_processes() {
  printf("Waiting for all processes to complete...\n");

  // Wait for all processes to complete
  for (int i = 0; i < num_processes; i++) {
    wait(NULL);
  }

  printf("All processes have completed!\n");
}

int main() {
  // Initialize the global variables
  processes = calloc(1, sizeof(pid_t));
  num_processes = 0;

  // Create a new process to print a message
  create_process("echo 'Hello, world!'");

  // Create another new process to print another message
  create_process("echo 'Hello again!'");

  // Print a message to the console
  print_message("Starting program...");

  // Wait for all processes to complete
  wait_for_processes();

  // Print a final message to the console
  print_message("Program completed successfully!");

  return 0;
}