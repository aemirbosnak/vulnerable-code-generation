//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0xdeadbeef
#define SHM_SIZE 1024

typedef struct {
    char name[10];
    int age;
} person_t;

void *shm_create(void) {
    key_t key = SHM_KEY;
    size_t size = SHM_SIZE;
    int shmid = shmget(key, size, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    void *shm = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    return shm;
}

void shm_write(void *shm, person_t *person) {
    char *ptr = shm;
    memcpy(ptr, person, sizeof(person_t));
}

person_t *shm_read(void *shm) {
    person_t *person = shm;
    return person;
}

int main() {
    void *shm = shm_create();
    person_t person = {.name = "Alice", .age = 25};
    shm_write(shm, &person);
    person_t *read_person = shm_read(shm);
    printf("Read person: %s, %d\n", read_person->name, read_person->age);
    munmap(shm, SHM_SIZE);
    return 0;
}