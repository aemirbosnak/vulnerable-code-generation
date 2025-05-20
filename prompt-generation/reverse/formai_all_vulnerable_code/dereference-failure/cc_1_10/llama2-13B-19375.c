//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <fcntl.h>

#define SHM_KEY 0x12345678
#define MSG_SIZE 1024

typedef struct {
    char name[50];
    int age;
} person_t;

void *shm_create(void) {
    key_t key = SHM_KEY;
    size_t size = sizeof(person_t) * 2;
    int shmid = shmget(key, size, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    return mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
}

void shm_send(int shmid, const char *msg) {
    size_t len = strlen(msg);
    if (msgsnd(shmid, msg, len, 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }
}

void *shm_recv(int shmid) {
    void *ptr = mmap(NULL, MSG_SIZE, PROT_READ, MAP_SHARED, shmid, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

int main() {
    int shmid1 = shm_create();
    person_t *p1 = shm_recv(shmid1);
    p1->name[0] = 'A';
    p1->age = 25;
    shm_send(shmid1, "Hello, world!");
    person_t *p2 = shm_recv(shmid1);
    printf("Received message: %s\n", p2->name);
    return 0;
}