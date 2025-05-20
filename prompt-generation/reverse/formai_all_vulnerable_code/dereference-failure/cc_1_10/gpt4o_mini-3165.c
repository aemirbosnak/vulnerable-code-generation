//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <unistd.h>

#define MAX_CLIENTS 5

// Struct to hold client state
typedef struct {
    int id;
    char evidence[256];
} Client;

// Shared resource
sem_t semaphore;
Client clients[MAX_CLIENTS];
int client_count = 0;

// Function to process evidence
void* process_evidence(void* arg) {
    Client* client = (Client*)arg;
    
    // Wait for access to the shared resource
    sem_wait(&semaphore);

    printf("Detective Holmes is analyzing evidence from Client %d: %s\n", client->id, client->evidence);
    sleep(2); // Simulate time taken to analyze the evidence

    printf("Client %d's evidence processed: %s\n", client->id, client->evidence);
    client_count--;
    
    // Release access to the shared resource
    sem_post(&semaphore);
    
    free(client); // Free the allocated client memory
    return NULL;
}

// Function to simulate receiving evidence
void receive_evidence(int id, const char* evidence) {
    if (client_count >= MAX_CLIENTS) {
        printf("Detective Holmes is currently busy. Client %d must wait!\n", id);
        return; // If maximum clients reached, return
    }

    // Allocate memory for new client
    Client* client = malloc(sizeof(Client));
    client->id = id;
    strncpy(client->evidence, evidence, sizeof(client->evidence));
    
    clients[client_count++] = *client;

    // Create a thread to process the evidence
    pthread_t tid;
    pthread_create(&tid, NULL, process_evidence, client);
    pthread_detach(tid); // Detach the thread so it can run independently
}

int main() {
    // Initialize semaphore for mutual exclusion
    sem_init(&semaphore, 0, 1);
    
    // Simulating clients
    receive_evidence(1, "Fingerprint from the crime scene.");
    receive_evidence(2, "A witness statement.");
    receive_evidence(3, "A piece of stolen jewelry.");
    receive_evidence(4, "Surveillance footage.");
    receive_evidence(5, "A mysterious letter.");
    receive_evidence(6, "Additional testimony from the baker."); // This will wait

    // Allow some time for threads to finish
    sleep(10);

    // Clean up
    sem_destroy(&semaphore);
    
    printf("All evidence has been processed by Detective Holmes. Case closed!\n");
    return 0;
}