//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535

typedef struct {
    int socket;
    char *ip_address;
    int port;
} port_scan_info;

void *scan_port(void *arg) {
    port_scan_info *info = (port_scan_info *)arg;
    unsigned short port = info->port;

    // Struct for the sockaddr_in
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, info->ip_address, &addr.sin_addr);

    // Attempt to connect to the port
    if (connect(info->socket, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open on %s\n", port, info->ip_address);
    }

    // Closing the socket
    close(info->socket);
    free(info); // Free the allocated memory for port scan info
    return NULL;
}

void print_header() {
    printf("-----------------------------------------------------\n");
    printf("     Welcome to the Sherlock Holmes Port Scanner     \n");
    printf("-----------------------------------------------------\n");
    printf("This tool meticulously examines the ports of a host.\n");
    printf("Detect open ports like a detective finding clues.\n");
    printf("-----------------------------------------------------\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        return EXIT_FAILURE;
    }

    print_header();

    char *ip_address = argv[1];
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    int port;

    // Scanning the range of ports
    for (port = PORT_RANGE_START; port <= PORT_RANGE_END; port++) {
        if (thread_count >= MAX_THREADS) {
            // Wait for all threads to finish
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset after joining
        }

        // Create a new socket for each port
        int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_fd < 0) {
            perror("Socket creation failed");
            continue;
        }

        // Allocate memory for holding port and IP info
        port_scan_info *info = malloc(sizeof(port_scan_info));
        info->socket = socket_fd;
        info->ip_address = ip_address;
        info->port = port;

        // Create a new thread for scanning the port
        if (pthread_create(&threads[thread_count], NULL, scan_port, info) != 0) {
            perror("Failed to create thread");
            free(info);  // Free as failed to create thread
            continue;
        }

        thread_count++;
    }

    // Final wait for any remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning completed for %s. Be vigilant, for every clue counts!\n", ip_address);
    printf("-----------------------------------------------------\n");

    return EXIT_SUCCESS;
}