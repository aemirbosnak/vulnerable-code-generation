//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

int target_port;
char *target_ip;
int total_ports;
int found_ports[MAX_THREADS];
int found_count = 0;
pthread_mutex_t lock;

void *scan_port(void *arg) {
    int sockfd;
    struct sockaddr_in target;
    
    // Setting up the target address structure
    target.sin_family = AF_INET;
    target.sin_port = htons(target_port);
    target.sin_addr.s_addr = inet_addr(target_ip);

    // Creating a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Set the timeout for connecting
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof(tv));

    // Attempt to connect to the target port
    if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) == 0) {
        // Port is open
        pthread_mutex_lock(&lock);
        found_ports[found_count++] = target_port;
        pthread_mutex_unlock(&lock);
    }

    close(sockfd);
    return NULL;
}

void usage(const char *progname) {
    fprintf(stderr, "Usage: %s <target_ip> <start_port> <end_port>\n", progname);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
    }

    target_ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    total_ports = end_port - start_port + 1;

    pthread_t threads[total_ports];
    pthread_mutex_init(&lock, NULL);
    
    for (target_port = start_port; target_port <= end_port; target_port++) {
        if (pthread_create(&threads[target_port - start_port], NULL, scan_port, NULL) != 0) {
            perror("Could not create thread");
        }
    }

    for (int i = 0; i < total_ports; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display results
    printf("Open ports on %s:\n", target_ip);
    for (int i = 0; i < found_count; i++) {
        printf("Port %d is open\n", found_ports[i]);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}