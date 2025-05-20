//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

typedef struct {
    int id;
    int data[SIZE];
} MyStruct;

int main() {
    key_t key;
    int shmid;
    MyStruct *ptr;

    // Allocate shared memory
    key = ftok("shmfile", 123);
    shmid = shmget(key, sizeof(MyStruct), 0666 | IPC_CREAT);

    // Attach to shared memory
    ptr = (MyStruct *)shmat(shmid, NULL, 0);

    // Initialize data structure
    ptr->id = 42;
    for (int i = 0; i < SIZE; i++) {
        ptr->data[i] = i * 2;
    }

    // Print data structure in an ephemeral style
    printf("\n[===] Data Structure [===]\n");
    printf("ID: %d\n", ptr->id);
    printf("Data: [");
    for (int i = 0; i < SIZE; i++) {
        printf("%d%s", ptr->data[i], (i == SIZE - 1) ? "" : ", ");
    }
    printf("]\n");

    // Detach from shared memory
    shmdt(ptr);

    // Destroy shared memory
    shmctl(shmid, IPC_RMID, 0);

    return 0;
}