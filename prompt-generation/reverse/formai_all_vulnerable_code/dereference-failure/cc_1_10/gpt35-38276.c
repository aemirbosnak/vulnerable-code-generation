//FormAI DATASET v1.0 Category: Interprocess communication ; Style: shocked
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_SIZE 100

int main() {
   int shmid;
   key_t key;
   char *shared_memory, c;

   key = ftok("unique_key", 5);

   shmid = shmget(key, MAX_SIZE, IPC_CREAT | 0666);

   if (shmid < 0) {
      perror("shmget");
      exit(1);
   }

   shared_memory = shmat(shmid, NULL, 0);

   if (shared_memory == (char *) -1) {
      perror("shmat");
      exit(1);
   }

   printf("Enter some text: ");
   fgets(shared_memory, MAX_SIZE, stdin);

   printf("You entered: %s", shared_memory);

   printf("Press any key to fork...\n");
   getchar();

   pid_t pid = fork();

   if (pid == 0) {
      // Child process
      printf("Child process: Shared memory contains: %s\n", shared_memory);
      printf("Child process: Reversing the text...\n");

      // Reverse the text
      int len = strlen(shared_memory);
      char temp;
      for (int i = 0; i < len/2; i++) {
         temp = shared_memory[i];
         shared_memory[i] = shared_memory[len-i-1];
         shared_memory[len-i-1] = temp;
      }

      printf("Child process: Shared memory now contains: %s\n", shared_memory);
   }
   else if (pid > 0) {
      // Parent process
      printf("Parent process: Waiting for child to finish...\n");
      wait(NULL);
      printf("Parent process: Child finished executing.\n");
   }
   else {
      perror("fork");
      exit(1);
   }

   if (shmdt(shared_memory) == -1) {
      perror("shmdt");
      exit(1);
   }

   if (shmctl(shmid, IPC_RMID, NULL) == -1) {
      perror("shmctl");
      exit(1);
   }

   return 0;
}