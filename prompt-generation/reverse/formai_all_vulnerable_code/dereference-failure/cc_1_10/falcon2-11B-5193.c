//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define MAX_MSG_SIZE 1000

int main()
{
    int shmid, n, msg_size;
    char *msg;

    if ((shmid = shmget(IPC_PRIVATE, MAX_MSG_SIZE, IPC_CREAT | 0666)) < 0)
    {
        perror("shmget error");
        return 1;
    }

    if ((msg = (char *) shmat(shmid, NULL, 0)) == (char *) -1)
    {
        perror("shmat error");
        return 1;
    }

    n = read(STDIN_FILENO, msg, MAX_MSG_SIZE);
    msg_size = n > MAX_MSG_SIZE? MAX_MSG_SIZE : n;

    if (write(STDOUT_FILENO, msg, msg_size) < 0)
    {
        perror("write error");
        return 1;
    }

    if (shmdt(msg) == -1)
    {
        perror("shmdt error");
        return 1;
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("shmctl error");
        return 1;
    }

    return 0;
}