//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

// Function to scan a single port
void *scan_port(void *arg) {
    int sock = *(int *) arg;
    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons((unsigned short) *(int *) &arg[sizeof(int)]);
    target.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *) &target, sizeof(target)) == 0) {
        printf("Port %d is open\n", ntohs(target.sin_port));
        close(sock);
    } else {
        printf("Port %d is closed\n", ntohs(target.sin_port));
        close(sock);
    }

    return NULL;
}

// Function to scan multiple ports
void scan_ports(int start_port, int end_port) {
    pthread_t threads[end_port - start_port + 1];
    int socks[end_port - start_port + 1];
    for (int i = 0; i < end_port - start_port + 1; i++) {
        socks[i] = socket(AF_INET, SOCK_STREAM, 0);
        if (socks[i] == -1) {
            printf("Error creating socket: %s\n", strerror(errno));
            exit(1);
        }
    }

    for (int i = 0; i < end_port - start_port + 1; i++) {
        pthread_create(&threads[i], NULL, scan_port, (void *) &socks[i]);
    }

    for (int i = 0; i < end_port - start_port + 1; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < end_port - start_port + 1; i++) {
        close(socks[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port > end_port) {
        printf("Invalid port range\n");
        exit(1);
    }

    scan_ports(start_port, end_port);

    return 0;
}