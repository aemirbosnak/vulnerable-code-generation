//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ 27

void *sender(void *arg);
void *receiver(void *arg);

char *shm, *s;

int main()
{
    int shmid;
    key_t key = 5678;

    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    pthread_t sender_t, receiver_t;

    pthread_create(&sender_t, NULL, sender, NULL);
    pthread_create(&receiver_t, NULL, receiver, NULL);

    pthread_join(sender_t, NULL);
    pthread_join(receiver_t, NULL);

    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

void *sender(void *arg)
{
    char message[SHMSZ];
    while (1) {
        printf("Sender: ");
        fgets(message, SHMSZ, stdin);

        s = shm;
        for (char *p = message; *p != '\0'; p++) {
            *s++ = *p;
        }
        *s = '*';
    }
    pthread_exit(NULL);
}

void *receiver(void *arg)
{
    while (1) {
        sleep(1);
        printf("Receiver: ");
        for (s = shm; *s != '*'; s++) {
            putchar(*s);
        }
        putchar('\n');
        *shm = '\0';
    }
    pthread_exit(NULL);
}