//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define SHM_SIZE 4096
#define MSG_SIZE 256

typedef struct {
    int id;
    char name[20];
} shared_data_t;

void *shm_addr;
int shm_id;

void create_shm(void) {
    key_t key = IPC_PRIVATE;
    shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0600);
    shm_addr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_id, 0);
}

void send_message(int id, char *message) {
    shared_data_t *data = shm_addr;
    data->id = id;
    strcpy(data->name, message);
    mprotect(shm_addr, SHM_SIZE, PROT_READ | PROT_WRITE);
}

char *receive_message(int *id) {
    shared_data_t *data = shm_addr;
    *id = data->id;
    return data->name;
}

int main() {
    create_shm();

    // Process 1
    int id1 = 1;
    char message1[] = "Hello from Process 1!";
    send_message(id1, message1);

    // Process 2
    int id2 = 2;
    char message2[] = "Hello from Process 2!";
    send_message(id2, message2);

    // Receive message in Process 1
    char *message = receive_message(&id1);
    printf("Received message from Process 2: %s\n", message);

    // Receive message in Process 2
    message = receive_message(&id2);
    printf("Received message from Process 1: %s\n", message);

    return 0;
}