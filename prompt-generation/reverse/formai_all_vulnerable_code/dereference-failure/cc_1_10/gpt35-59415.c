//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surprised
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

int main() {
  printf("OMG! I can't believe this is happening. I just thought of an amazing interprocess communication program!\n");

  int shm_id;
  char* data;
  key_t key;
  pid_t pid;

  printf("First, let's create a shared memory segment using IPC_PRIVATE and the shmget() function.\n");

  key = IPC_PRIVATE;
  shm_id = shmget(key, 1024, 0644 | IPC_CREAT);

  printf("Uh-oh, looks like something went wrong and we got an error message. Let me check what it says...\n");

  if(shm_id == -1) {
    printf("Error: %s\n", strerror(errno));
    printf("I can't believe it, we have to abort the whole program?\n");
    exit(EXIT_FAILURE);
  }

  printf("Phew, that was a close one. Now let's attach the shared memory segment to our process using shmat().\n");

  data = shmat(shm_id, (void*)0, 0);

  printf("Wow, this is really working! Now let's fork our process to create a child process.\n");

  pid = fork();

  if(pid == -1) {
    printf("Error: %s\n", strerror(errno));
    printf("Oh no, what do we do now? Should we just give up?\n");
    exit(EXIT_FAILURE);
  }

  if(pid == 0) {
    printf("Cool, we're in the child process! Let's print out the data from the shared memory segment.\n");
    printf("Data: %s\n", data);
    printf("Now let's modify the data in the shared memory segment!\n");

    strcpy(data, "Hello from the child process!");

    printf("Done! Now let's detach the shared memory segment using shmdt().\n");

    if(shmdt(data) == -1) {
      printf("Error: %s\n", strerror(errno));
      printf("Oh no, we failed to detach the shared memory segment. Should we just return -1 and hope for the best?\n");
      return -1;
    }

    printf("All done here! Exiting child process now.\n");
    exit(EXIT_SUCCESS);
  }

  else {
    printf("Awesome, we're in the parent process! Let's wait for the child process to finish.\n");

    if(waitpid(pid, NULL, 0) == -1) {
      printf("Error: %s\n", strerror(errno));
      printf("Uh-oh, we failed to wait for the child process. Should we just return -1 and hope for the best?\n");
      return -1;
    }

    printf("Child process has finished! Let's print out the data from the shared memory segment again.\n");
    printf("Data: %s\n", data);
    printf("Now let's modify the data in the shared memory segment again!\n");

    strcpy(data, "Hello from the parent process!");

    printf("Done! Now let's detach the shared memory segment using shmdt().\n");

    if(shmdt(data) == -1) {
      printf("Error: %s\n", strerror(errno));
      printf("Oh no, we failed to detach the shared memory segment. Should we just return -1 and hope for the best?\n");
      return -1;
    }

    printf("All done here! Exiting parent process now.\n");
    exit(EXIT_SUCCESS);
  }

  printf("Wow, that was intense! I can't believe we just created an amazing interprocess communication program.\n");

  return 0;
}