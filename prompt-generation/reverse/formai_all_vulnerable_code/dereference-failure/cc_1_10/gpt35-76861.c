//FormAI DATASET v1.0 Category: Port Scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

typedef struct {
    int sockfd;
    struct sockaddr_in remote_addr;
} thread_arg;

void *scan_port(void *arg) {
    // Get the socket file descriptor and remote address from the argument
    thread_arg *t_arg = (thread_arg *) arg;
    int sockfd = t_arg->sockfd;
    struct sockaddr_in remote_addr = t_arg->remote_addr;

    // Try to connect to the remote port
    if (connect(sockfd, (struct sockaddr*) &remote_addr, sizeof(remote_addr)) == 0) {
        printf("Port %d is open.\n", ntohs(remote_addr.sin_port));
    }

    // close the socket file descriptor and free the memory used by the argument
    close(sockfd);
    free(arg);
    return 0;
}

int main(int argc, char **argv) {
    // Check command line arguments
    if (argc < 2) {
        printf("Usage: ./port_scanner <ip_address>\n");
        return 1;
    }

    // Parse the IP address
    struct in_addr ip_addr;
    if (inet_aton(argv[1], &ip_addr) == 0) {
        printf("Invalid IP address.\n");
        return 1;
    }

    // Create a socket file descriptor
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // Initialize the remote address
    struct sockaddr_in remote_addr;
    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr = ip_addr;

    // Scan all ports from 1 to 65535 using multithreading
    for (int port = 1; port <= 65535; port++) {
        // Set the port number in the remote address
        remote_addr.sin_port = htons(port);

        // Create an argument for the thread and start the thread
        thread_arg *arg = malloc(sizeof(thread_arg));
        arg->sockfd = sockfd;
        arg->remote_addr = remote_addr;
        pthread_t thread;
        pthread_create(&thread, NULL, scan_port, (void *) arg);
        pthread_detach(thread);
    }

    return 0;
}