//FormAI DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>

#define SHMSIZE 100  //Size of Shared Memory Segment
#define KEY 12345  //Key for Shared Memory Segment creation

int *shared_memory; //Pointer to Shared Memory Segment

void signal_handler(int sig) {  //Signal Handler Function
  printf("\nReceived Signal: %d\n", sig); //Print received signal number
  shmdt(shared_memory);  //Detach Shared Memory Segment
  shmctl(shmget(KEY, SHMSIZE, IPC_CREAT | IPC_EXCL | 0666), IPC_RMID, NULL); //Remove Shared Memory Segment
  exit(0);  //Exit program
}

int main() {
  signal(SIGINT, signal_handler);  //Register Signal Handler Function

  int shm_id = shmget(KEY, SHMSIZE, IPC_CREAT | IPC_EXCL | 0666);  //Create Shared Memory Segment
  if (shm_id < 0) {  //If Shared Memory Segment already exists
    perror("shmget");
    exit(1);
  }

  printf("Shared Memory Segment Created\n");

  shared_memory = shmat(shm_id, NULL, 0);  //Attach Shared Memory Segment
  if (shared_memory == (int*)-1) {  //If Shared Memory Segment Attach fails
    perror("shmat");
    exit(1);
  }

  printf("Shared Memory Segment Attached\n");

  int pid = fork();  //Create Child Process
  if (pid == 0) {  //Child Process
    while (1) {  //Loop to write to Shared Memory Segment
      printf("Enter a number: ");
      int num;
      scanf("%d", &num);
      *shared_memory = num;  //Write number to Shared Memory Segment
    }
    exit(0);  //Exit Child Process
  } else if (pid < 0) {  //If Child Creation fails
    perror("fork");
    exit(1);
  } else {  //Parent Process
    while (1) {  //Loop to read from Shared Memory Segment
      printf("Memory Value: %d\n", *shared_memory);  //Read number from Shared Memory Segment
      sleep(1);
    }
    exit(0);  //Exit Parent Process
  }

  return 0;
}