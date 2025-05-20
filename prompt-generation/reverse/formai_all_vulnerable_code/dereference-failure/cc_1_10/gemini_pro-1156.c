//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>

#define SHM_SIZE 1024

int main(int argc, char *argv[])
{
  key_t key = ftok("prog.c", 'a');
  int shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
  if (shm_id == -1)
  {
    perror("shmget");
    exit(1);
  }

  void *shm_addr = shmat(shm_id, NULL, 0);
  if (shm_addr == (void *)-1)
  {
    perror("shmat");
    exit(1);
  }

  char *shm_data = (char *)shm_addr;

  int pid = fork();
  if (pid == 0)
  {
    // Child process
    while (1)
    {
      printf("Child: %s\n", shm_data);
      sleep(1);
    }
  }
  else
  {
    // Parent process
    while (1)
    {
      printf("Parent: ");
      fgets(shm_data, SHM_SIZE, stdin);
      if (strcmp(shm_data, "exit\n") == 0)
      {
        break;
      }
    }

    shmdt(shm_addr);
    shmctl(shm_id, IPC_RMID, NULL);
  }

  return 0;
}