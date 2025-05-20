//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

#define PIPE_SIZE 100

void generate_random_number(int *number) {
  srand(time(NULL));
  *number = rand();
}

void create_message(char *message, int number) {
  snprintf(message, PIPE_SIZE, "Child process received number: %d", number);
}

int main() {
  int parent_fd[2], child_fd[2];
  int parent_num, child_num;
  pid_t child_pid;
  char parent_message[PIPE_SIZE], child_message[PIPE_SIZE];

  if (pipe(parent_fd) < 0 || pipe(child_fd) < 0) {
    perror("Pipe failed");
    exit(EXIT_FAILURE);
  }

  child_pid = fork();

  if (child_pid < 0) { // Error occurred
    perror("Fork failed");
    exit(EXIT_FAILURE);
  } else if (child_pid > 0) { // Parent process
    generate_random_number(&parent_num);

    write(parent_fd[1], &parent_num, sizeof(parent_num));
    close(parent_fd[0]);
    close(parent_fd[1]);

    waitpid(child_pid, NULL, 0);

    read(parent_fd[0], child_message, PIPE_SIZE);
    printf("Parent process received message: %s\n", child_message);
    close(parent_fd[0]);
  } else { // Child process
    close(parent_fd[1]);
    close(child_fd[0]);

    read(child_fd[0], &child_num, sizeof(child_num));
    close(child_fd[0]);

    create_message(child_message, child_num);

    write(parent_fd[1], child_message, strlen(child_message) + 1);
    close(parent_fd[0]);
    close(parent_fd[1]);

    exit(EXIT_SUCCESS);
  }

  return EXIT_SUCCESS;
}