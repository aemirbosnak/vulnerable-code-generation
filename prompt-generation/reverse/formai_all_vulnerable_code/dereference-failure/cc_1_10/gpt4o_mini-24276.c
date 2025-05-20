//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_START 1
#define PORT_END 65535

typedef struct {
    char *ip_address;
    int port;
} port_scan_t;

void *scan_port(void *arg) {
    port_scan_t *scan_info = (port_scan_t *)arg;
    int sock;
    struct sockaddr_in target;

    target.sin_family = AF_INET;
    target.sin_port = htons(scan_info->port);
    inet_pton(AF_INET, scan_info->ip_address, &target.sin_addr);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        free(scan_info);
        return NULL;
    }

    int connection_status = connect(sock, (struct sockaddr *)&target, sizeof(target));
    
    if (connection_status == 0) {
        printf("Port %d is open.\n", scan_info->port);
    } else {
        // Port closed or not reachable
    }

    close(sock);
    free(scan_info);
    return NULL;
}

void print_usage() {
    printf("Usage: ./port_scanner <IP address>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = PORT_START; port <= PORT_END; port++) {
        port_scan_t *scan_info = malloc(sizeof(port_scan_t));
        scan_info->ip_address = ip_address;
        scan_info->port = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, scan_info) != 0) {
            perror("Failed to create thread");
            free(scan_info);
        } else {
            thread_count++;
            if (thread_count >= MAX_THREADS) {
                for (int i = 0; i < thread_count; i++) {
                    pthread_join(threads[i], NULL);
                }
                thread_count = 0; // reset thread count after joining
            }
        }
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning completed for %s.\n", ip_address);
    return EXIT_SUCCESS;
}