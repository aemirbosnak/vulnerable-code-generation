//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <time.h>

// Symbolize the forgotten whispers of surreal creatures
#define SHM_SIZE 256

void connect_to_universe(int *shm_id, char **shared_mem) {
    *shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (*shm_id < 0) {
        perror("Alas, the universe is unkind!");
        exit(1);
    }
    *shared_mem = (char *)shmat(*shm_id, NULL, 0);
    if (*shared_mem == (char *)-1) {
        perror("The threads of fate are tangled!");
        exit(1);
    }
}

void producer(int shm_id, char *shared_mem) {
    const char *subliminal_messages[] = {
        "The moon sings at dawn.",
        "Whales dance with the stars.",
        "Time is a river of dreams.",
        "Trees whisper secrets of the earth.",
        "The sky wears a coat of shadows."
    };
    
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        sprintf(shared_mem, "%s", subliminal_messages[rand() % 5]);
        printf("Producer sent: %s\n", shared_mem);
        sleep(2); // simulate time to prepare another message
    }
    sprintf(shared_mem, "END");
    shmdt(shared_mem);
}

void consumer(int shm_id, char *shared_mem) {
    char message[SHM_SIZE];
    
    while (1) {
        strcpy(message, shared_mem);
        if (strcmp(message, "END") == 0) {
            printf("Consumer acknowledges the end of existence.\n");
            break;
        } else {
            printf("Consumer received: %s\n", message);
        }
        sleep(3); // reverie time between messages
    }
    shmdt(shared_mem);
    shmctl(shm_id, IPC_RMID, NULL); // release the memory back to the cosmos
}

int main() {
    int shm_id;
    char *shared_mem;

    // Connect to the universe of shared memory
    connect_to_universe(&shm_id, &shared_mem);

    pid_t pid = fork();
    if (pid < 0) {
        perror("The fabric of reality tore apart!");
        exit(1);
    } else if (pid == 0) {
        // Child process becomes the producer
        producer(shm_id, shared_mem);
        exit(0);
    } else {
        // Parent process becomes the consumer
        consumer(shm_id, shared_mem);
        wait(NULL); // wait for the child to finish
    }

    return 0;
}