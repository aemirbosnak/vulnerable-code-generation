//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_MESSAGE_LEN 1024
#define SHM_KEY 0xdeadbeef

struct message {
    char name[10];
    int age;
};

void* shm_create(size_t size) {
    int shmid = shmget(SHM_KEY, size, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget() failed");
        return NULL;
    }
    return mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
}

void shm_send(void* shm, const struct message* message) {
    int len = sizeof(*message);
    if (write(shm, message, len) != len) {
        perror("write() failed");
    }
}

struct message* shm_recv(void* shm) {
    int len = sizeof(*(struct message*)shm);
    if (read(shm, (void*)shm, len) != len) {
        perror("read() failed");
        return NULL;
    }
    return (struct message*)shm;
}

int main() {
    void* shm = shm_create(sizeof(struct message));
    if (shm == MAP_FAILED) {
        perror("shm_create() failed");
        return 1;
    }

    struct message message = {
        .name = "Alice",
        .age = 25,
    };
    shm_send(shm, &message);

    // Sleep for a bit to ensure the message is received
    sleep(1);

    struct message* received_message = shm_recv(shm);
    if (received_message == NULL) {
        perror("shm_recv() failed");
        return 1;
    }

    printf("Received message: %s %d\n", received_message->name, received_message->age);

    munmap(shm, sizeof(struct message));
    return 0;
}