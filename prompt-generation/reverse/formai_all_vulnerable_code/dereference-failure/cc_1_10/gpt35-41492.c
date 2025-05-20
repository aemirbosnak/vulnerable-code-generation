//FormAI DATASET v1.0 Category: Interprocess communication ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

#define READ_END 0
#define WRITE_END 1

int main(int argc, char *argv[]) {
   int parentToChildPipe[2], childToParentPipe[2];
   pid_t pid;
   char parentToChildMessage[100] = "Hi, child!";
   char childToParentMessage[100] = "";

   if (pipe(parentToChildPipe) == -1) {
      fprintf(stderr,"Parent-to-child pipe failed.\n");
      return 1;
   }

   if (pipe(childToParentPipe) == -1) {
      fprintf(stderr,"Child-to-parent pipe failed.\n");
      return 1;
   }

   pid = fork();

   if (pid < 0) {
      fprintf(stderr, "Fork failed.\n");
      return 1;
   }

   if (pid > 0) {
      // Parent process
      close(parentToChildPipe[READ_END]);
      close(childToParentPipe[WRITE_END]);

      write(parentToChildPipe[WRITE_END], parentToChildMessage, strlen(parentToChildMessage)+1);
      printf("Parent sent message to child: %s\n", parentToChildMessage);

      wait(NULL);

      read(childToParentPipe[READ_END], childToParentMessage, 100);

      printf("Parent received message from child: %s\n", childToParentMessage);

      close(parentToChildPipe[WRITE_END]);
      close(childToParentPipe[READ_END]);

   } else {
      // Child process
      close(parentToChildPipe[WRITE_END]);
      close(childToParentPipe[READ_END]);

      char receivedMessage[100] = "";

      read(parentToChildPipe[READ_END], receivedMessage, 100);
      printf("Child received message from parent: %s\n", receivedMessage);

      strcat(receivedMessage, " How are you?");

      write(childToParentPipe[WRITE_END], receivedMessage, strlen(receivedMessage)+1);
      printf("Child sent message to parent: %s\n", receivedMessage);

      close(parentToChildPipe[READ_END]);
      close(childToParentPipe[WRITE_END]);
   }

   return 0;
}