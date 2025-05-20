//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SHM_SIZE sizeof(struct RamUsage)
#define MAX_CLIENTS 5

// Structure to hold RAM usage data
struct RamUsage {
    int client_count;
    float ram_usage;
};

// Function to simulate RAM usage calculation
void* ram_monitor(void* arg) {
    int shmid = *(int*)arg;
    struct RamUsage* ram_data;

    ram_data = (struct RamUsage*)shmat(shmid, NULL, 0);
    if (ram_data == (void*) -1) {
        perror("shmat");
        exit(1);
    }

    while (1) {
        // Simulate memory usage between 0 and 100
        ram_data->ram_usage = (rand() % 100);
        
        // Update client count
        ram_data->client_count = ram_data->client_count > MAX_CLIENTS ? MAX_CLIENTS : ram_data->client_count;

        // Print current RAM usage
        printf("Current RAM Usage: %.2f%% | Active Clients: %d\n", ram_data->ram_usage, ram_data->client_count);
        sleep(1); // Update every second
    }

    shmdt(ram_data);
    return NULL;
}

// Client function to simulate a user connecting
void* client_session(void* arg) {
    int shmid = *(int*)arg;
    struct RamUsage* ram_data;

    ram_data = (struct RamUsage*)shmat(shmid, NULL, 0);
    if (ram_data == (void*) -1) {
        perror("shmat");
        exit(1);
    }

    // Simulate Client Session
    sleep(rand() % 5 + 1); // Random delay for client session

    // Increment client count on connect
    ram_data->client_count++;
    printf("Client connected! Total clients: %d\n", ram_data->client_count);

    // Wait for the session to end
    sleep(rand() % 10 + 5); // Random session length

    // Decrement client count on disconnect
    ram_data->client_count--;
    printf("Client disconnected! Total clients: %d\n", ram_data->client_count);

    shmdt(ram_data);
    return NULL;
}

int main() {
    srand(time(NULL));

    // Create shared memory
    int shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    struct RamUsage* ram_data;
    ram_data = (struct RamUsage*)shmat(shmid, NULL, 0);
    if (ram_data == (void*) -1) {
        perror("shmat");
        exit(1);
    }

    ram_data->client_count = 0; // Initialize client count
    ram_data->ram_usage = 0.0; // Initialize RAM usage

    pthread_t monitor_thread;
    pthread_create(&monitor_thread, NULL, ram_monitor, &shmid);

    pthread_t clients[MAX_CLIENTS];
    for (int i = 0; i < MAX_CLIENTS; i++) {
        pthread_create(&clients[i], NULL, client_session, &shmid);
        sleep(1); // Allow clients to connect at 1 second intervals
    }

    // Wait for all clients to finish
    for (int i = 0; i < MAX_CLIENTS; i++) {
        pthread_join(clients[i], NULL);
    }

    // Clean up
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}