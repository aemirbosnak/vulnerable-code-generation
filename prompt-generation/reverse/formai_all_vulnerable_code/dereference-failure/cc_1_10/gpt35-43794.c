//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
  printf("Oh my goodness, I can't believe I get to write an interprocess communication program!\n");

  // create shared memory segment
  int shm_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | IPC_EXCL | 0666);
  if (shm_id < 0) {
    printf("Uh oh, something went wrong with creating the shared memory segment.");
    exit(1);
  }

  // attach to shared memory segment
  int* shared_int = (int*)shmat(shm_id, NULL, 0);
  if (shared_int == (int*)-1) {
    printf("Oops, couldn't attach to the shared memory segment.");
    exit(1);
  }

  // set initial value in shared memory segment
  *shared_int = 42;
  printf("I'm setting the initial value in shared memory segment to %d.\n", *shared_int);

  // fork process
  int pid = fork();
  if (pid < 0) {
    printf("Yikes, couldn't fork the process!");
    exit(1);
  }

  // child process
  if (pid == 0) {
    printf("Wow, I'm the child process! I'm going to read from the shared memory segment.\n");
    printf("The value in shared memory segment is %d.\n", *shared_int);

    *shared_int = 99;
    printf("I'm setting the value in shared memory segment to %d.\n", *shared_int);

    // detach from shared memory segment
    if (shmdt(shared_int) == -1) {
      printf("Oh no, something went wrong with detaching from the shared memory segment.");
      exit(1);
    }

    // exit child process
    exit(0);
  }

  // parent process
  else {
    printf("Amazing, I'm the parent process! I'm going to wait for the child process to finish.\n");

    int status;
    int child_pid = wait(&status);

    if (status == 0) {
      printf("The child process has finished successfully!\n");
      printf("The final value in shared memory segment is %d.\n", *shared_int);
    }
    else {
      printf("Uh oh, the child process didn't finish successfully.");
    }

    // detach and remove shared memory segment
    if (shmdt(shared_int) == -1) {
      printf("Oh no, something went wrong with detaching from the shared memory segment.");
      exit(1);
    }

    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
      printf("Oops, couldn't remove the shared memory segment.");
      exit(1);
    }
  }

  return 0;
}