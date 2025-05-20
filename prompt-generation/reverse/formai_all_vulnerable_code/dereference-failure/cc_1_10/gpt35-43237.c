//FormAI DATASET v1.0 Category: Port Scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define THREADS 32 // Maximum number of threads
#define TIMEOUT 5 // Timeout value for socket connections in seconds

typedef struct { // Structure for storing socket information
    int sockfd;
    struct sockaddr_in addr;
} tcpsock;

// Function for opening a new TCP socket
int open_tcp_socket() {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR: Failed to create socket");
        exit(1);
    }
    return sockfd;
}

// Function for scanning a single port on a target IP address
void *scan_port(void *param) {
    tcpsock *sock = (tcpsock *)param;
    if (connect(sock->sockfd, (struct sockaddr *)&sock->addr, sizeof(sock->addr)) == 0) {
        printf("Port %d is open\n", ntohs(sock->addr.sin_port));
    }
    close(sock->sockfd);
    free(sock);
    return NULL;
}

// Main function for scanning a range of ports on a target IP address
void scan_range(char *target, int start_port, int end_port) {
    int i, sockfd;
    pthread_t tids[THREADS];
    struct sockaddr_in addr;
    tcpsock *sock;

    addr.sin_family = AF_INET;
    inet_aton(target, &addr.sin_addr);

    for (i = start_port; i <= end_port; i++) {
        sockfd = open_tcp_socket();
        addr.sin_port = htons(i);
        sock = (tcpsock *)malloc(sizeof(tcpsock));
        sock->sockfd = sockfd;
        sock->addr = addr;
        pthread_create(&tids[i%THREADS], NULL, &scan_port, sock);
        usleep(10000);
    }
    for (i = 0; i < THREADS; i++) {
        pthread_join(tids[i], NULL);
    }
}

// Function for printing out usage instructions
void print_usage(char *program_name) {
    printf("Usage: %s <IP address> <start_port> <end_port>\n\n", program_name);
    printf("Example: %s 127.0.0.1 1 65535\n", program_name);
}

// Main function for parsing command line arguments and starting the scanning process
int main(int argc, char *argv[]) {
    char *target;
    int start_port, end_port;

    if (argc != 4) {
        print_usage(argv[0]);
        exit(1);
    }

    target = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    if (start_port <= 0 || end_port <= 0 || start_port > 65535 || end_port > 65535) {
        printf("Error: Invalid port range\n");
        print_usage(argv[0]);
        exit(1);
    }

    printf("Scanning ports %d-%d on %s...\n", start_port, end_port, target);
    scan_range(target, start_port, end_port);
    printf("Scan complete\n");

    return 0;
}