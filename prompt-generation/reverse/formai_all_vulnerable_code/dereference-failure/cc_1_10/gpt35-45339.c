//FormAI DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main(int argc, char *argv[]) {

   int shmid;
   char *shm_address;
   char buffer[SHM_SIZE];

   shmid = shmget(IPC_PRIVATE, SHM_SIZE, 0666 | IPC_CREAT);
   if (shmid < 0) {
      perror("shmget");
      exit(1);
   }
   printf("Shared memory segment created with id: %d\n", shmid);

   shm_address = shmat(shmid, NULL, 0);
   if (shm_address == (char *) -1) {
      perror("shmat");
      exit(1);
   }
   printf("Shared memory segment attached at address: %p\n", shm_address);

   if (fork() == 0) {
      printf("Child process waiting for data in shared memory...\n");

      while (1) {
         if (strcmp(shm_address, "quit") == 0) {
            break;
         }

         if (strcmp(shm_address, buffer) != 0) {
            strcpy(buffer, shm_address);
            printf("Child received data: %s\n", buffer);
         }

         sleep(1);
      }
      printf("Child process exiting...\n");
      exit(0);

   } else {
      printf("Parent process writing data in shared memory...\n");
      strcpy(shm_address, "Hello World!");

      sleep(1);

      printf("Parent process updating shared memory...\n");
      strcpy(shm_address, "Greetings from the parent!");

      sleep(1);

      printf("Parent process updating shared memory once again...\n");
      strcpy(shm_address, "quit");

      printf("Parent process waiting for child to exit...\n");
      wait(NULL);

      printf("Parent process exiting...\n");
   }

   if (shmdt(shm_address) == -1) {
      perror("shmdt");
      exit(1);
   }

   if (shmctl(shmid, IPC_RMID, NULL) == -1) {
      perror("shmctl");
      exit(1);
   }

   return 0;
}