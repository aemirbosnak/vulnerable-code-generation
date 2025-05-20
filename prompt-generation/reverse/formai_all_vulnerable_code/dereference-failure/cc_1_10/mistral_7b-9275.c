//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: surrealist
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define DREAM_SIZE 256
#define DREAM_KEY 0x1234

typedef struct Dream {
    char name[50];
    char dream[DREAM_SIZE];
} Dream;

void TheDreamer(int shmid) {
    Dream *dream = (Dream *) shmat(shmid, NULL, 0);

    strcpy(dream->name, "The Dreamer");

    printf("%s: Closing eyes...\n", dream->name);
    sleep(3);

    strcpy(dream->dream, "Flying on a pink flamingo in the land of chocolate mountains...");

    printf("%s: Dreaming...\n", dream->name);
    sleep(5);

    printf("%s: Waking up and sharing dream with The Dream...\n", dream->name);

    shmdt(dream);
    shmctl(shmid, IPC_RMID, NULL);
}

void TheDream(int argc, char **argv) {
    int shmid;

    shmid = shmget(DREAM_KEY, sizeof(Dream), IPC_CREAT | 0666);

    Dream *dream = (Dream *) shmat(shmid, NULL, 0);

    while (strcmp(dream->name, "The Dreamer") != 0) {
        printf("The Dream: Awaiting The Dreamer...\n");
        sleep(1);
    }

    printf("The Dream: Received dream from The Dreamer: %s\n", dream->dream);

    shmdt(dream);
    shmctl(shmid, IPC_RMID, NULL);
}

int main() {
    pid_t pid;
    int shmid;

    pid = fork();

    if (pid < 0) {
        perror("Fork Failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        TheDreamer(shmid);
        exit(EXIT_SUCCESS);
    }

    TheDream(0, NULL);

    exit(EXIT_SUCCESS);
}