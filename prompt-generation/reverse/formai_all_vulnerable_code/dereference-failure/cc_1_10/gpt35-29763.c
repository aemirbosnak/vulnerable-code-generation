//FormAI DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define RANGE_SIZE 65535 // maximum number of ports to be scanned
#define MAX_THREADS 500 // maximum number of threads to be created for scanning

typedef struct {
    int start_port;
    int end_port;
    char *ip_addr;
} ScanRange;

void print_usage() {
    printf("Usage: ./portscan <ip_address> <start_port> <end_port>\n");
    printf("Example: ./portscan 127.0.0.1 1 65535\n");
}

void print_scan_result(int port, bool open) {
    if (open) {
        printf("Port %d is open.\n", port);
    } else {
        printf("Port %d is closed.\n", port);
    }
}

bool is_port_open(char *ip_addr, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_addr, &addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        close(sock);
        return false;
    }

    close(sock);
    return true;
}

void *scan_ports(void *arg) {
    ScanRange *range = (ScanRange *)arg;
    for (int port = range->start_port; port <= range->end_port; port++) {
        bool open = is_port_open(range->ip_addr, port);
        print_scan_result(port, open);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    char *ip_addr = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port || start_port < 1 || end_port > RANGE_SIZE) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    int num_threads = end_port - start_port + 1;
    if (num_threads > MAX_THREADS) {
        num_threads = MAX_THREADS;
    }

    int ports_per_thread = (end_port - start_port + 1) / num_threads;
    int remaining_ports = (end_port - start_port + 1) % num_threads;

    pthread_t threads[num_threads];
    ScanRange ranges[num_threads];

    int current_port = start_port;
    for (int i = 0; i < num_threads; i++) {
        ranges[i].ip_addr = ip_addr;
        ranges[i].start_port = current_port;
        current_port += ports_per_thread;
        if (i < remaining_ports) {
            current_port++;
        }
        ranges[i].end_port = current_port - 1;
        int res = pthread_create(&threads[i], NULL, scan_ports, (void *)&ranges[i]);
        if (res != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        int res = pthread_join(threads[i], NULL);
        if (res != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}