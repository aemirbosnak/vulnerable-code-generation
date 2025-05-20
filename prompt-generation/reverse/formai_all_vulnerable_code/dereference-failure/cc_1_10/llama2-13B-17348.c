//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE (1024 * 1024)
#define SHM_KEY 0x12345678

typedef struct {
    char name[64];
    int age;
} person_t;

void *shm_create(void) {
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget");
        return NULL;
    }

    void *shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        shmctl(shmid, IPC_RMID, 0);
        return NULL;
    }

    return shm;
}

void shm_write(void *shm, person_t *person) {
    char *ptr = shm;
    memcpy(ptr, person, sizeof(person_t));
    ptr += sizeof(person_t);
    write(1, ptr, sizeof(char) * (1024 - sizeof(person_t)));
}

person_t *shm_read(void *shm) {
    person_t *person = (person_t *)shm;
    char *ptr = (char *)person;
    read(0, ptr, sizeof(char) * (1024 - sizeof(person_t)));
    return person;
}

int main(void) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process
        person_t person = {
            .name = "Alice",
            .age = 25
        };
        void *shm = shm_create();
        shm_write(shm, &person);
        sleep(1);
        person_t *read_person = shm_read(shm);
        printf("Child: %s %d\n", read_person->name, read_person->age);
    } else {
        // Parent process
        void *shm = shm_create();
        person_t person = {
            .name = "Bob",
            .age = 30
        };
        shm_write(shm, &person);
        sleep(2);
        person_t *read_person = shm_read(shm);
        printf("Parent: %s %d\n", read_person->name, read_person->age);
    }

    return 0;
}