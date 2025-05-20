//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_PORT 65535
#define MIN_PORT 1
#define THREAD_COUNT 100

typedef struct {
    char *ip;
    int start_port;
    int end_port;
} scan_data_t;

void *scan_port(void *args) {
    scan_data_t *data = (scan_data_t *)args;
    char *ip = data->ip;
    int port;

    for (port = data->start_port; port <= data->end_port; port++) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("Socket creation failed");
            return NULL;
        }

        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, ip, &server_addr.sin_addr);

        int result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (result == 0) {
            printf("Port %d is open\n", port);
        }

        close(sockfd);
    }

    free(data);
    return NULL;
}

void start_scan(char *ip) {
    pthread_t threads[THREAD_COUNT];
    int ports_per_thread = (MAX_PORT - MIN_PORT + 1) / THREAD_COUNT;
    
    for (int i = 0; i < THREAD_COUNT; i++) {
        scan_data_t *data = malloc(sizeof(scan_data_t));
        data->ip = ip;
        data->start_port = MIN_PORT + i * ports_per_thread;
        data->end_port = (i == THREAD_COUNT - 1) ? MAX_PORT : data->start_port + ports_per_thread - 1;

        pthread_create(&threads[i], NULL, scan_port, (void *)data);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
}

void display_intro() {
    printf("*********************************\n");
    printf("*         Port Scanner          *\n");
    printf("*********************************\n");
    printf("Enter IP address to scan (e.g., 192.168.1.1): ");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    display_intro();
    start_scan(ip);
    printf("Scanning complete.\n");

    return 0;
}