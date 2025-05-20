//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_PORT 1024
#define NUM_THREADS 10

// Struct to hold data for each thread
typedef struct {
    char *ip;
    int port;
} thread_data;

// Function to check if a port is open
void *check_port(void *arg) {
    thread_data *data = (thread_data *)arg;
    int sock;
    struct sockaddr_in server;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Define the server address
    server.sin_family = AF_INET;
    server.sin_port = htons(data->port);
    inet_pton(AF_INET, data->ip, &server.sin_addr);

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is OPEN! 🎉\n", data->port);
    } else {
        printf("Port %d is CLOSED. 😞\n", data->port);
    }

    close(sock);
    free(data);
    return NULL;
}

// Maximum number of threads
int active_threads = 0;

void *thread_limit_check() {
    while(1) {
        if (active_threads < NUM_THREADS) {
            sleep(1); // Sleep for a bit before checking again
        }
    }
}

int main() {
    char target[16];
    printf("Welcome to the Exciting C Port Scanner! 🚀\n");
    printf("Enter the target IP address: ");
    scanf("%15s", target);

    pthread_t limit_check_thread;
    pthread_create(&limit_check_thread, NULL, thread_limit_check, NULL);

    // Scan all ports from 1 to MAX_PORT
    for (int port = 1; port <= MAX_PORT; port++) {
        thread_data *data = malloc(sizeof(thread_data));
        data->ip = strdup(target);
        data->port = port;

        pthread_t thread_id;
        active_threads++;

        if (pthread_create(&thread_id, NULL, check_port, (void *)data) != 0) {
            printf("Failed to create thread for port %d! 😟\n", port);
            free(data);
            active_threads--;
        } else {
            pthread_detach(thread_id);
        }

        // Simple limit to avoid too many simultaneous threads
        if (active_threads >= NUM_THREADS) {
            sleep(1); // Wait until there is space for new threads
        }
    }

    // Wait for all threads to complete (simplified)
    sleep(5);
    printf("Scanning complete! 🎉\n");

    return 0;
}