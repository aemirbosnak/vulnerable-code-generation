//FormAI DATASET v1.0 Category: Interprocess communication ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main(void) {
  int shmid;
  key_t key;
  char *shm, *s, *msg;

  // generate a key to create a shared memory segment
  key = ftok(".", 'a');

  // create the shared memory segment using the key
  shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

  // shmat attaches the shared memory segment identified by shmid to 
  // the address space of the calling process and returns a pointer to it.
  shm = shmat(shmid, NULL, 0);

  // read message from user
  msg = malloc(SHM_SIZE);
  printf("Enter message: ");
  fgets(msg, SHM_SIZE, stdin);

  // copy message to shared memory
  s = shm;
  strcpy(s, msg);

  // indicate end of message
  s += strlen(msg);
  *s = '\0';

  // wait for receiver to read message
  printf("Waiting for receiver to read message...\n");
  while (*shm != '*')
    sleep(1);

  // print message read by receiver
  printf("Message read by receiver: %s\n", shm);

  // detach shared memory segment
  shmdt(shm);

  // delete shared memory segment
  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}