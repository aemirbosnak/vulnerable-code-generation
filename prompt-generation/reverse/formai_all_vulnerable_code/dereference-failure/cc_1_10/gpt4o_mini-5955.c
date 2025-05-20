//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

typedef struct {
    int client_id;
    char request[BUFFER_SIZE];
} client_request_t;

void *handle_request(void *arg) {
    client_request_t *client_request = (client_request_t *)arg;
    printf("Client %d connected, processing request: %s\n", client_request->client_id, client_request->request);
    
    // Simulate I/O operation
    sleep(rand() % 3 + 1); // Simulate delay for handling request
    
    // Respond to client
    printf("Response to Client %d: Request '%s' processed successfully.\n", client_request->client_id, client_request->request);
    
    free(client_request);
    return NULL;
}

int main() {
    pthread_t threads[MAX_CLIENTS];
    int client_count = 0;

    srand(time(NULL));

    while (client_count < MAX_CLIENTS) {
        client_request_t *new_request = malloc(sizeof(client_request_t));
        new_request->client_id = client_count;
        snprintf(new_request->request, BUFFER_SIZE, "Request from client %d", client_count);

        // Create a new thread to handle the client request
        if (pthread_create(&threads[client_count], NULL, handle_request, new_request) != 0) {
            perror("Failed to create thread");
            free(new_request);
            continue;
        }

        client_count++;
        // Optional: Adding a small delay to simulate new incoming requests.
        usleep(100000); // sleep for 100 milliseconds
    }

    // Wait for all threads to complete
    for (int i = 0; i < client_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All client requests have been processed.\n");
    return 0;
}