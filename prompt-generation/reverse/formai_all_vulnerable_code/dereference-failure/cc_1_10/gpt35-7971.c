//FormAI DATASET v1.0 Category: Interprocess communication ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
  pid_t pid1, pid2;
  int fd[2];
  char buffer[256];
  struct stat st;

  if(pipe(fd) == -1) {
    perror("Creation of pipe failed");
    return 1;
  }

  pid1 = fork();

  if(pid1 == -1) {
    perror("Creation of first child process failed");
    return 1;
  } else if(pid1 == 0) { // First child process
    char* message = "This is a message from child process one";
    close(fd[0]);
    write(fd[1], message, strlen(message)+1);
    exit(0);
  } else { // Parent process
    wait(NULL);

    pid2 = fork();

    if(pid2 == -1) {
      perror("Creation of second child process failed");
      return 1;
    } else if(pid2 == 0) { // Second child process
      close(fd[1]);
      read(fd[0], buffer, sizeof(buffer));
      printf("Message from child process one: %s\n", buffer);

      // Write to a file and print its permissions
      int file = open("example_file.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
      write(file, buffer, strlen(buffer)+1);
      stat("example_file.txt", &st);
      printf("File Permissions: %o\n", st.st_mode & 0777);
      
      exit(0);
    } else { // Parent process
      wait(NULL);
    }
  }

  return 0;
}