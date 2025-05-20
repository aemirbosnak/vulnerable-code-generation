//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#include <string.h>

#define SHM_SIZE 256
#define BLACKSMITH "Blacksmith"
#define MERCHANT "Merchant"

typedef struct {
    char message[SHM_SIZE];
} shared_data;

void *blacksmith_routine(void *arg) {
    int shmid = *((int *)arg);
    shared_data *data = (shared_data *)shmat(shmid, NULL, 0);
    
    // Blacksmith forges weapons
    for (int i = 0; i < 5; i++) {
        snprintf(data->message, SHM_SIZE, "Blacksmith has forged weapon %d", i + 1);
        printf("%s\n", data->message);
        sleep(2); // Simulating time taken to forge a weapon
    }
    
    // Signal completion
    snprintf(data->message, SHM_SIZE, "Blacksmith has finished forging weapons.");
    printf("%s\n", data->message);
    shmdt(data);
    return NULL;
}

void *merchant_routine(void *arg) {
    int shmid = *((int *)arg);
    shared_data *data = (shared_data *)shmat(shmid, NULL, 0);
    
    // Merchant awaits weapons
    while (1) {
        if (strlen(data->message) > 0) { // Check if there's a message
            printf("Merchant hears: %s\n", data->message);
            if (strcmp(data->message, "Blacksmith has finished forging weapons.") == 0) {
                break;
            }
            sleep(1); // Simulating time taken to purchase a weapon
        }
    }
    
    printf("Merchant rejoices as he has acquired all weapons!\n");
    shmdt(data);
    return NULL;
}

int main() {
    int shmid;
    shared_data *data;

    // Create a unique key for the shared memory
    key_t key = ftok("shmfile", 65);
    
    // Allocate shared memory
    shmid = shmget(key, sizeof(shared_data), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("Failed to create shared memory");
        exit(1);
    }

    // Initialize the shared structure
    data = (shared_data *)shmat(shmid, NULL, 0);
    if (data == (shared_data *)(-1)) {
        perror("Failed to attach shared memory");
        exit(1);
    }
    memset(data->message, 0, SHM_SIZE); // Clear the message

    // Create the blacksmith and merchant threads
    pthread_t blacksmith_thread, merchant_thread;
    
    pthread_create(&blacksmith_thread, NULL, blacksmith_routine, &shmid);
    pthread_create(&merchant_thread, NULL, merchant_routine, &shmid);

    // Join the threads back
    pthread_join(blacksmith_thread, NULL);
    pthread_join(merchant_thread, NULL);
    
    // Destroy the shared memory
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}