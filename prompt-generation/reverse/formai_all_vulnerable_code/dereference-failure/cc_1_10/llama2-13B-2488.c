//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_RECORDS 1000
#define MAX_FIELDS 5

struct record {
    char name[20];
    int age;
    float salary;
    char address[50];
};

struct shm_segment {
    int shmid;
    struct record records[MAX_RECORDS];
};

int main() {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, sizeof(struct shm_segment), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Create a pointer to the shared memory segment
    struct shm_segment *shm = shmat(shmid, NULL, 0);
    if (shm == NULL) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Fill the shared memory with some records
    for (int i = 0; i < MAX_RECORDS; i++) {
        struct record *record = &shm->records[i];
        record->name[0] = 'A' + (i % 26);
        record->age = i % 10;
        record->salary = (float)i * 10.0;
        strcpy(record->address, "Street ");
        record->address[strlen(record->address)] = 'A' + (i % 26);
    }

    // Create a client process to access the shared memory
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        // Client process
        struct shm_segment *shm = shmat(shmid, NULL, 0);
        if (shm == NULL) {
            perror("shmat");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < MAX_RECORDS; i++) {
            struct record *record = &shm->records[i];
            printf("Client: Record %d: %s %d %f %s\n", i, record->name, record->age, record->salary, record->address);
        }
        exit(EXIT_SUCCESS);
    } else {
        // Server process
        wait(NULL);
    }

    // Remove the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}