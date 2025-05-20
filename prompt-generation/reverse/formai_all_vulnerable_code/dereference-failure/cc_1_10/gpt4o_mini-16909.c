//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 50
#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535

// Structure to hold thread data
typedef struct {
    char *ip_address;
    int port;
} thread_data;

// Function to check if a port is open
void *check_port(void *data) {
    thread_data *t_data = (thread_data *)data;
    struct sockaddr_in target;
    
    // Clear the structure and set its values
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(t_data->ip_address);
    target.sin_port = htons(t_data->port);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        free(data);
        return NULL;
    }

    // Try to connect to the target
    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
        printf("Yay! Port %d is open on %s 😄\n", t_data->port, t_data->ip_address);
    } else {
        // Uncomment to see closed ports in a sad style
        // printf("Oh no! Port %d is closed on %s 😭\n", t_data->port, t_data->ip_address);
    }

    close(sock);
    free(data);
    return NULL;
}

// Main function to start the port scanning
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <target_ip>\n", argv[0]);
        return 1;
    }
    
    char *target_ip = argv[1];
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    printf("Starting port scan for %s...\n\n", target_ip);

    // Loop through the defined port range
    for (int port = PORT_RANGE_START; port <= PORT_RANGE_END; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;
        }

        // Dynamically allocate memory for thread data
        thread_data *data = malloc(sizeof(thread_data));
        data->ip_address = target_ip;
        data->port = port;

        // Create a new thread 
        if (pthread_create(&threads[thread_count], NULL, check_port, data) != 0) {
            perror("Failed to create thread");
            free(data);
            continue;
        }
        
        thread_count++;
        // Add a small delay to reduce load on the target
        usleep(100); // Sleep for 100 microseconds
    }

    // Join any remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nPort scan complete! 🎉\n");
    return 0;
}