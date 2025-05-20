//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>

int main() {
  printf("Oh my gosh, I can't believe I just stumbled upon this amazing C interprocess communication example program!\n");

  int pid = fork();

  if (pid == -1) {
    printf("Oops, something went wrong while forking the process!\n");
    exit(1);
  } else if (pid == 0) {
    printf("Wow, I'm a child process now! Time to create the shared memory...\n");

    int shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
      printf("Uh oh, failed to create shared memory region!\n");
      exit(1);
    }

    int* sharedVar = (int*) shmat(shmid, NULL, 0);

    if (sharedVar == (int*) -1) {
      printf("Oh no, failed to attach shared memory!\n");
      exit(1);
    }

    printf("Awesome, shared memory created and attached! Now let's write to it...\n");

    *sharedVar = 42;

    printf("Value written to shared memory: %d\n", *sharedVar);

    printf("Alright, let's detach and exit the child process now...\n");

    shmdt(sharedVar);
    exit(0);
  } else {
    printf("Woohoo, I'm the parent process! Time to wait for the child...\n");

    wait(NULL);

    printf("Great, child process is done! Let's read the shared memory...\n");

    int shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);

    if (shmid == -1) {
      printf("Oops, failed to create shared memory region!\n");
      exit(1);
    }

    int* sharedVar = (int*) shmat(shmid, NULL, 0);

    if (sharedVar == (int*) -1) {
      printf("Oops, failed to attach to shared memory!\n");
      exit(1);
    }

    printf("Value read from shared memory: %d\n", *sharedVar);

    printf("Alright, let's detach and destroy the shared memory region...\n");

    shmdt(sharedVar);
    shmctl(shmid, IPC_RMID, NULL);
  }

  printf("Wow, that was so exciting! I can't wait to use interprocess communication in more of my programs!\n");
  return 0;
}