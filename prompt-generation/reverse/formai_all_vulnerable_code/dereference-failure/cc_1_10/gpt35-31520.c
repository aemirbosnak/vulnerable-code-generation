//FormAI DATASET v1.0 Category: Port Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_PORT 65535
#define MAX_THREADS 100

/* Struct to pass arguments to threads */
struct scan_args {
    struct sockaddr_in server_addr;
    int start_port;
    int end_port;
};

/* Function to scan port */
bool scan_port(int sock, struct sockaddr_in server_addr) {
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        return true;
    }
    else {
        return false;
    }
}

/* Thread function to scan range of ports */
void *port_scanner(void* args) {
    struct scan_args *scan_args = (struct scan_args*)args;
    struct sockaddr_in server_addr = scan_args->server_addr;
    int start_port = scan_args->start_port;
    int end_port = scan_args->end_port;

    for (int port = start_port; port <= end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        server_addr.sin_port = htons(port);

        if (scan_port(sock, server_addr)) {
            printf("Port %d on %s is open!\n", port, inet_ntoa(server_addr.sin_addr));
        }

        close(sock); 
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <host> <threads>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = argv[1];
    int num_threads = atoi(argv[2]);
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (server_addr.sin_addr.s_addr == INADDR_NONE) {
        printf("Invalid IP address\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize the thread array */
    pthread_t threads[MAX_THREADS];
    int num_ports = MAX_PORT + 1;
    int ports_per_thread = num_ports / num_threads;
    int remainder = num_ports % num_threads;

    /* Distribute ports among threads */
    struct scan_args scan_args[num_threads];

    for (int i = 0; i < num_threads; i++) {
        int start_port = i * ports_per_thread + 1;
        int end_port = (i + 1) * ports_per_thread;

        /* Assign remainder ports to the last thread */
        if (i == num_threads - 1) {
            end_port += remainder;
        }

        scan_args[i].server_addr = server_addr;
        scan_args[i].start_port = start_port;
        scan_args[i].end_port = end_port;

        pthread_create(&threads[i], NULL, port_scanner, &scan_args[i]);
    }

    /* Wait for threads to finish */
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning complete\n");

    return 0;
}