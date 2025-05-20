//FormAI DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHMSZ 27

int main()
{
   int shmid;
   key_t key;
   char *shm, *s;
   pid_t pid;

   /* generate a key for shared memory */
   key = ftok(".", 'M');

   /* create a shared memory segment */
   shmid = shmget(key, SHMSZ, IPC_CREAT | 0666);
   if (shmid < 0) {
      perror("shmget");
      exit(1);
   }

   /* attach the shared memory segment */
   shm = shmat(shmid, NULL, 0);
   if (shm == (char *) -1) {
      perror("shmat");
      exit(1);
   }

   /* fork a child process */
   pid = fork();

   if (pid < 0) {
      perror("fork");
      exit(1);
   }

   if (pid == 0) {  /* child process */
      /* write a message to the shared memory segment */
      strcpy(shm, "Hello, world!");

      /* exit the child process */
      exit(0);
   }
   else { /* parent process */
      /* wait for the child to finish */
      wait(NULL);

      /* read from the shared memory segment */
      for (s = shm; *s != NULL; s++)
         putchar(*s);

      putchar('\n');

      /* detach the shared memory segment */
      if (shmdt(shm) == -1) {
         perror("shmdt");
         exit(1);
      }

      /* remove the shared memory segment */
      if (shmctl(shmid, IPC_RMID, NULL) == -1) {
         perror("shmctl");
         exit(1);
      }
   }

   return 0;
}