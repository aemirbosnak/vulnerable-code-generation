//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100

int open_ports[65536];
int thread_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* scan_port(void* arg) {
    int port = *(int*)arg;
    struct sockaddr_in server;
    int sock;

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with target IP address

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    int result = connect(sock, (struct sockaddr*)&server, sizeof(server));
    
    pthread_mutex_lock(&mutex);
    if (result == 0) {
        printf("Port %d is open\n", port);
        open_ports[port] = 1; // Mark port as open
    }
    pthread_mutex_unlock(&mutex);

    close(sock);
    return NULL;
}

void create_threads(int start, int end) {
    pthread_t threads[MAX_THREADS];

    for (int port = start; port <= end; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;
        }
        
        int* arg = malloc(sizeof(*arg));
        *arg = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, arg) != 0) {
            perror("Could not create thread");
            free(arg);
            return;
        }
        
        thread_count++;
        free(arg);
    }

    // Wait for any remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Port range must be between 1 and 65535 and start port must be <= end port.\n");
        return EXIT_FAILURE;
    }

    printf("Scanning ports from %d to %d...\n", start_port, end_port);
    
    create_threads(start_port, end_port);

    printf("Port scanning completed.\n");
    
    return EXIT_SUCCESS;
}