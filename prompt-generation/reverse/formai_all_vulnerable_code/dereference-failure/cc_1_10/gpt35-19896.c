//FormAI DATASET v1.0 Category: Interprocess communication ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <signal.h>

#define SHM_SIZE 1024
#define KEY 1234

int main()
{
    int shmid;
    char *data;
    pid_t pid;

    shmid = shmget(KEY, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid == -1)
    {
        fprintf(stderr, "shmget failed: %d\n", errno);
        exit(1);
    }

    data = shmat(shmid, NULL, 0);

    if (data == (char *)(-1))
    {
        fprintf(stderr, "shmat failed\n");
        exit(1);
    }

    printf("Chat Program Started\n\n");

    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork failed.\n");
        exit(1);
    }
    else if (pid == 0)
    {
        while (1)
        {
            char message[SHM_SIZE];

            printf("Enter a message to send to the other process: ");
            fgets(message, SHM_SIZE, stdin);

            strncpy(data, message, SHM_SIZE - 1);
            printf("\nYou: %s\n", message);
        }
    }
    else
    {
        signal(SIGINT, SIG_IGN);

        while (1)
        {
            sleep(1);

            if (strncmp(data, "exit", 4) == 0)
            {
                printf("\nOther User: %s\n", data);
                printf("\nExited Program\n");
                break;
            }

            printf("\nOther User: %s", data);
        }
    }

    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}