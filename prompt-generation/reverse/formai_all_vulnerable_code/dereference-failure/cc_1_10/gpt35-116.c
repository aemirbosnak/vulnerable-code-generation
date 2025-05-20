//FormAI DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024     // Shared memory size

int main(void) {
   int shmid;            // Shared memory id
   char *shmaddr;        // Shared memory address
   int status = 0;       // Status of child process
   pid_t pid;            // Process id

   // Create a shared memory block
   if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
      perror("shmget");
      exit(1);
   }

   // Attach shared memory
   if ((shmaddr = shmat(shmid, NULL, 0)) == (char *) -1) {
      perror("shmat");
      exit(1);
   }

   // Start child process
   if ((pid = fork()) == -1) {
      perror("fork");
      exit(1);
   }

   // Child process
   if (pid == 0) {
      printf("Child process running...\n");

      // Write to shared memory
      strcpy(shmaddr, "Hello, world!");

      printf("Child process writing to shared memory...\n");
      printf("Child process done writing to shared memory...\n");

      exit(0);
   }
   // Parent process
   else {
      printf("Parent process running...\n");

      // Wait for child process to finish
      wait(&status);

      printf("Parent process reading from shared memory...\n");

      // Print message read from shared memory
      printf("Message: %s\n", shmaddr);

      // Detach shared memory
      if (shmdt(shmaddr) == -1) {
         perror("shmdt");
         exit(1);
      }

      // Delete shared memory
      if (shmctl(shmid, IPC_RMID, NULL) == -1) {
         perror("shmctl");
         exit(1);
      }
      
      printf("Parent process done reading from shared memory...\n");
      exit(0);
   }
}