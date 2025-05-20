//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100

void parent(void);
void child(void);

int main(void) {
  pid_t pid;

  if ((pid = fork()) == 0) {
    child();
  } else {
    parent();
    wait(NULL);
  }

  return 0;
}

void parent(void) {
  char buffer[BUFFER_SIZE];
  int count = 0;

  while (1) {
    read(STDIN_FILENO, buffer, BUFFER_SIZE);
    count = write(STDOUT_FILENO, buffer, strlen(buffer));

    if (count == 0) {
      break;
    }
  }

  exit(0);
}

void child(void) {
  char buffer[BUFFER_SIZE];

  while (1) {
    read(STDIN_FILENO, buffer, BUFFER_SIZE);
    write(STDOUT_FILENO, buffer, strlen(buffer));
  }

  exit(0);
}