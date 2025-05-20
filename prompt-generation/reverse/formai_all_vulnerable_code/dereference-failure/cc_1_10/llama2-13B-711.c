//LLAMA2-13B DATASET v1.0 Category: Database querying ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_NAME_LEN 256
#define MAX_ADDRESS 4096

typedef struct {
    char name[MAX_NAME_LEN];
    char address[MAX_ADDRESS];
} person_t;

#define SHM_NAME "my_shm"

int main() {
    key_t key = ftok("my_file.txt", 'P');
    int shmid = shmget(key, sizeof(person_t), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    person_t *ptr = mmap(NULL, sizeof(person_t), PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    printf("Current address: %p\n", ptr);

    // Protected querying
    if (strcmp(ptr->name, "John Doe") == 0) {
        printf("Found John Doe\n");
    } else if (strcmp(ptr->name, "Jane Doe") == 0) {
        printf("Found Jane Doe\n");
    } else {
        printf("Not found\n");
    }

    // Unprotected querying
    printf("Address: %s\n", ptr->address);

    munmap(ptr, sizeof(person_t));
    shmctl(shmid, IPC_RMID, 0);
    return 0;
}