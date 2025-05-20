//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <errno.h>

#define MAX_PORT 65535
#define MIN_PORT 1
#define NUM_THREADS 100

typedef struct {
    char *ip_address;
    int port;
} port_scan_task;

void *scan_port(void *arg) {
    port_scan_task *task = (port_scan_task *)arg;
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(task->port);
    inet_pton(AF_INET, task->ip_address, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is open\n", task->port);
    } else {
        // Uncomment the below line to see error messages for closed ports
        // printf("Port %d is closed: %s\n", task->port, strerror(errno));
    }

    close(sock);
    free(task);
    return NULL;
}

void create_threads(char *ip_address, int start_port, int end_port) {
    pthread_t threads[NUM_THREADS];
    int port;
    int index = 0;

    for (port = start_port; port <= end_port; port++) {
        port_scan_task *task = malloc(sizeof(port_scan_task));
        task->ip_address = ip_address;
        task->port = port;

        if (pthread_create(&threads[index], NULL, scan_port, task) != 0) {
            perror("Failed to create thread");
            free(task);
            continue;
        }

        index++;
        if (index >= NUM_THREADS) {
            // Wait for threads to finish before creating more
            for (int i = 0; i < NUM_THREADS; i++) {
                pthread_join(threads[i], NULL);
            }
            index = 0;
        }
    }

    // Wait for any remaining threads to finish
    for (int i = 0; i < index; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    create_threads(ip_address, MIN_PORT, MAX_PORT);

    return EXIT_SUCCESS;
}