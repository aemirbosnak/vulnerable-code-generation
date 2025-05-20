//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Linus Torvalds
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define SHMSZ 27

int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    key = 5678;

    shmid = shmget(key, SHMSZ, IPC_CREAT | 0666);

    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0);

    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    s = shm;

    printf("Enter message to be sent: ");

    while ((c = getchar()) != '\n')
        *s++ = c;

    *s = '\0';

    printf("Message sent!\n");

    while (*shm != '*')
        sleep(1);

    printf("Message received: ");

    for (s = shm; *s != '\0'; s++)
        putchar(*s);

    putchar('\n');

    *shm = '!';

    shmdt(shm);
    shmctl(shmid, IPC_RMID, 0);

    return 0;
}