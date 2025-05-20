//FormAI DATASET v1.0 Category: Interprocess communication ; Style: invasive
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define SHMSIZE 1024       // shared memory size

int main() {
   int shmid;
   key_t key;
   char *shm, *s;

   // create a unique key
   key = ftok(".", 'a');

   // create a shared memory segment
   shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666);
   if (shmid < 0) {
      perror("shmget");
      exit(1);
   }

   // attach the shared memory segment to our data space
   shm = shmat(shmid, NULL, 0);
   if (shm == (char *) -1) {
      perror("shmat");
      exit(1);
   }

   // put some data into the shared memory
   sprintf(shm, "Hello, World!");

   // update the pointer to point after the message we just wrote
   s = shm + strlen("Hello, World!");

   // pause for a second to give the other process a chance to read the message
   sleep(1);

   // write some more data into the shared memory
   strncpy(s, "This message is from the first process.\n", SHMSIZE - strlen("Hello, World!") - 1);

   // detach the shared memory segment
   shmdt(shm);

   // pause for a second before forking the second process
   sleep(1);

   // fork a new process to read the shared memory and write a message to it
   if (fork() == 0) {
      // get the existing shared memory segment
      shmid = shmget(key, SHMSIZE, 0666);
      if (shmid < 0) {
         perror("shmget");
         exit(1);
      }

      // attach the shared memory segment to our data space
      shm = shmat(shmid, NULL, 0);
      if (shm == (char *) -1) {
         perror("shmat");
         exit(1);
      }

      // read the message from the first process
      printf("Message read from first process: %s", shm);

      // write a message to the shared memory
      sprintf(shm, "This message is from the second process.");

      // detach the shared memory segment
      shmdt(shm);

      // exit the process
      exit(0);
   }

   // wait for the second process to exit 
   wait(NULL);

   // get the existing shared memory segment
   shmid = shmget(key, SHMSIZE, 0666);
   if (shmid < 0) {
      perror("shmget");
      exit(1);
   }

   // attach the shared memory segment to our data space
   shm = shmat(shmid, NULL, 0);
   if (shm == (char *) -1) {
      perror("shmat");
      exit(1);
   }

   // print the final message from the first process
   printf("\nFinal message from first process: %s\n", shm);

   // detach the shared memory segment
   shmdt(shm);

   // destroy the shared memory segment
   shmctl(shmid, IPC_RMID, NULL);

   return 0;
}