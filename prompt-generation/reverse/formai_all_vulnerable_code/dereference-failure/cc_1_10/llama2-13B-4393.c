//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define SHM_SIZE 1024
#define MSG_SIZE 1024

typedef struct {
    char name[10];
    int age;
} person_t;

void* shm_create(void) {
    int shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    void* shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }

    return shm;
}

void shm_send(int shmid, const char* message) {
    char* shm = (char*)shm_create();
    strcpy(shm, message);
    if (msync(shm, strlen(message), MS_ASYNC) == -1) {
        perror("msync() failed");
    }

    if (shmdt(shm) == -1) {
        perror("shmdt() failed");
    }
}

int shm_recv(int shmid, char* message) {
    char* shm = (char*)shm_create();
    if (msync(shm, SHM_SIZE, MS_ASYNC) == -1) {
        perror("msync() failed");
    }

    if (shmdt(shm) == -1) {
        perror("shmdt() failed");
    }

    strcpy(message, shm);
    return strlen(message);
}

int main() {
    int shmid1, shmid2;
    person_t person;

    shmid1 = shmget(IPC_PRIVATE, sizeof(person_t), IPC_CREAT | 0644);
    if (shmid1 < 0) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    person.name[0] = 'A';
    person.age = 25;

    shm_send(shmid1, &person);

    shmid2 = shmget(IPC_PRIVATE, sizeof(person_t), IPC_CREAT | 0644);
    if (shmid2 < 0) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    person.name[0] = 'B';
    person.age = 30;

    shm_send(shmid2, &person);

    char message[MSG_SIZE];
    int len = shm_recv(shmid1, message);
    printf("%s\n", message);

    len = shm_recv(shmid2, message);
    printf("%s\n", message);

    return 0;
}