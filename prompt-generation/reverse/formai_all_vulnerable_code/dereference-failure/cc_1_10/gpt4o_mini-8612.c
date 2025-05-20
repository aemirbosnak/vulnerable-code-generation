//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 50

void *port_scanner(void *arg);
void print_usage(const char *progname);
int is_port_open(const char *ip, int port);

typedef struct {
    char *ip;
    int port;
} scanner_args;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + 9; // scan next 9 ports
    pthread_t threads[MAX_THREADS];
    scanner_args args[MAX_THREADS];
    int thread_count = 0;

    printf("Starting the surprise port scanner on IP: %s\n", ip);
    printf("Scanning ports from %d to %d...\n", start_port, end_port);

    for (int port = start_port; port <= end_port; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // reset count
        }

        args[thread_count].ip = ip;
        args[thread_count].port = port;
        
        if (pthread_create(&threads[thread_count], NULL, port_scanner, &args[thread_count]) != 0) {
            fprintf(stderr, "Error creating thread for port %d\n", port);
            return 1;
        }

        thread_count++;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning completed!\n");
    return 0;
}

void print_usage(const char *progname) {
    printf("Usage: %s <IP> <start_port>\n", progname);
    printf("Example: %s 192.168.1.1 80\n", progname);
}

void *port_scanner(void *arg) {
    scanner_args *params = (scanner_args *)arg;
    char *ip = params->ip;
    int port = params->port;

    if (is_port_open(ip, port)) {
        printf("Port %d is OPEN on %s!\n", port, ip);
    } else {
        printf("Port %d is CLOSED on %s.\n", port, ip);
    }

    return NULL;
}

int is_port_open(const char *ip, int port) {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 0;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    int result = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    close(sock);

    return (result == 0);
}