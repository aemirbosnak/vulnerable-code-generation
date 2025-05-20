//FormAI DATASET v1.0 Category: Port Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define THREADS_COUNT 5

// Helper function to scan port and check if it is open
int scan_port(char *ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) >= 0) {
        close(sock);
        return 1;
    } else {
        close(sock);
        return 0;
    }
}

// Thread function to scan a range of ports
void *scan_ports(void *thread_data) {
    char *ip = ((char **)thread_data)[0];
    int start_port = *((int *)(((char **)thread_data)[1]));
    int end_port = *((int *)(((char **)thread_data)[2]));
    for (int port = start_port; port <= end_port; port++) {
        if (scan_port(ip, port)) {
            printf("Port %d on %s is open\n", port, ip);
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return -1;
    }
    char *ip = argv[1];
    pthread_t threads[THREADS_COUNT];
    int ports_per_thread = 65536 / THREADS_COUNT;
    for (int i = 0; i < THREADS_COUNT; i++) {
        int *start_port = malloc(sizeof(int));
        *start_port = i * ports_per_thread + 1;
        int *end_port = malloc(sizeof(int));
        *end_port = *start_port + ports_per_thread - 1;
        if (i == THREADS_COUNT - 1) {
            *end_port = 65535;
        }
        char **thread_data = malloc(sizeof(char *) * 3);
        thread_data[0] = ip;
        thread_data[1] = (char *)start_port;
        thread_data[2] = (char *)end_port;
        pthread_create(&threads[i], NULL, scan_ports, thread_data);
    }
    for (int i = 0; i < THREADS_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}