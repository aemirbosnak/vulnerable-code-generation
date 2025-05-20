//FormAI DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_MIN 1
#define PORT_MAX 65535
#define THREADS_MAX 100

void* scan(void *data);
void scan_port(int port, char* ip);

struct sockaddr_in addr;
bool port_scanned[PORT_MAX + 1];
pthread_mutex_t lock;

int main(int argc, char *argv[]) {
    int start_port, end_port, i;
    char *ip_address;
    pthread_t threads[THREADS_MAX];

    if (argc != 4) {
        printf("Usage: portscanner <ip_address> <starting_port> <ending_port>\n");
        printf("Example: portscanner 127.0.0.1 1 100\n");
        exit(EXIT_FAILURE);
    }

    ip_address = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    if (start_port < PORT_MIN || end_port > PORT_MAX || start_port > end_port) {
        printf("Invalid port range provided.\n");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    for (i = 0; i < THREADS_MAX; i++) {
        pthread_create(&threads[i], NULL, scan, (void*)ip_address);
    }

    for (i = start_port; i <= end_port; i++) {
        pthread_mutex_lock(&lock);
        if (!port_scanned[i]) {
            pthread_mutex_unlock(&lock);
            scan_port(i, ip_address);
        }
        pthread_mutex_unlock(&lock);
    }

    for (i = 0; i < THREADS_MAX; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void* scan(void *data) {
    char *ip_address = (char*)data;
    int port;

    while (true) {
        pthread_mutex_lock(&lock);
        for (port = PORT_MIN; port <= PORT_MAX; port++) {
            if (!port_scanned[port]) {
                port_scanned[port] = true;
                pthread_mutex_unlock(&lock);
                scan_port(port, ip_address);
                pthread_mutex_lock(&lock);
            }
        }
        pthread_mutex_unlock(&lock);
    }
}

void scan_port(int port, char *ip) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open at IP address %s.\n", port, ip);
    }

    close(sock);
}