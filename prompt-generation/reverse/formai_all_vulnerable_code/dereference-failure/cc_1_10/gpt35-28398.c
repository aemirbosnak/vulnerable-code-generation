//FormAI DATASET v1.0 Category: Interprocess communication ; Style: excited
// Get ready to be amazed with this incredible C Interprocess communication example program!
// This program will use shared memory to communicate between two processes.
// It's going to be so exciting, you won't believe your eyes!

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>

// First, we'll create some variables to store the shared memory segment ID and a pointer to the memory.
int shmid;
char *shm;

// Let's also create a function to display some fancy text before we begin.
void show_intro() {
  printf("Get ready to witness the power of Interprocess communication!\n");
  printf("This program will create two processes and use shared memory to communicate between them.\n");
  printf("Are you excited yet? Let's get started!\n");
}

int main() {
  // Time to show off our fancy intro!
  show_intro();

  // Next, we'll create a shared memory segment and get the ID.
  shmid = shmget(1234, sizeof(char)*1024, 0666|IPC_CREAT);
  if(shmid == -1) {
    printf("Uh-oh, something went wrong creating the shared memory segment...\n");
    exit(EXIT_FAILURE);
  }

  // Now we'll attach the memory segment to our program.
  shm = shmat(shmid, NULL, 0);

  // Let's fork our process to create another one to communicate with.
  pid_t pid = fork();

  if(pid == -1) {
    printf("Uh-oh, something went wrong with the fork...\n");
    exit(EXIT_FAILURE);
  } else if(pid == 0) {
    // This is the child process, which will receive the message.
    printf("Child process waiting for message...\n");

    // We'll wait for the message to be written to shared memory.
    while(*shm == ' ');

    printf("Child process received message: %s\n", shm);

    // Finally, we'll detach the memory segment and exit.
    shmdt(shm);
    exit(EXIT_SUCCESS);
  } else {
    // This is the parent process, which will write the message.
    printf("Parent process writing message...\n");

    // Let's write a message to the shared memory segment.
    sprintf(shm, "Hello from the parent process!");

    // Wait for the child to finish receiving the message.
    wait(NULL);

    // Finally, we'll detach and remove the shared memory segment.
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    printf("Interprocess communication successful! Thanks for watching!\n");
    exit(EXIT_SUCCESS);
  }

  // And that's it, folks! Interprocess communication in C using shared memory. How cool is that?
  return 0;
}