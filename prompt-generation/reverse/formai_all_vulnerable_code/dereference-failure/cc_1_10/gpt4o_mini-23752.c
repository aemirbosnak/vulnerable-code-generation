//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_PORT 65535
#define THREAD_NUM 100

typedef struct {
    char *ip_address;
    int port;
} ScanArgs;

void *scan_port(void *args) {
    ScanArgs *scan_args = (ScanArgs *)args;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sock < 0) {
        perror("Socket Error");
        return NULL;
    }
    
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(scan_args->port);
    inet_pton(AF_INET, scan_args->ip_address, &server.sin_addr);
    
    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (result == 0) {
        printf("Port %d: Open\n", scan_args->port);
    } else {
        printf("Port %d: Closed\n", scan_args->port);
    }

    close(sock);
    free(scan_args);
    return NULL;
}

int main() {
    char ip_address[16];
    int port;

    printf("Enter IP Address: ");
    scanf("%15s", ip_address);

    printf("Scanning ports on %s...\n", ip_address);
    
    pthread_t threads[THREAD_NUM];
    int thread_count = 0;

    for (port = 1; port <= MAX_PORT; port++) {
        ScanArgs *args = malloc(sizeof(ScanArgs));
        args->ip_address = strdup(ip_address);
        args->port = port;

        if (pthread_create(&threads[thread_count++], NULL, scan_port, args) != 0) {
            perror("Thread Error");
            free(args->ip_address);
            free(args);
            return 1;
        }

        if (thread_count >= THREAD_NUM) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;
        }
    }

    // Waiting for any remaining threads to complete
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning completed on %s.\n", ip_address);
    return 0;
}