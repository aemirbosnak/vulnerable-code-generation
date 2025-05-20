//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define DEFAULT_PORT "80"

// Thread argument structure
struct thread_args {
    char *ip_address;
    int port_number;
};

// Thread function to scan a single port
void *scan_port(void *args) {
    struct thread_args *arg = (struct thread_args *)args;

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        pthread_exit(NULL);
    }

    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt");
        pthread_exit(NULL);
    }

    // Connect to the target IP address and port
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(arg->port_number);
    serv_addr.sin_addr.s_addr = inet_addr(arg->ip_address);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        // Port is closed
        pthread_exit(NULL);
    }

    // Port is open
    char port_str[16];
    sprintf(port_str, "%d", arg->port_number);
    printf("Port %s on %s is open\n", port_str, arg->ip_address);

    // Close the socket
    close(sockfd);
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    // Check arguments
    if (argc < 2) {
        printf("Usage: %s <IP address> [port number]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the IP address
    char *ip_address = argv[1];

    // Get the port number
    int port_number = DEFAULT_PORT;
    if (argc >= 3) {
        port_number = atoi(argv[2]);
    }

    // Create a thread pool
    pthread_t threads[100];
    int thread_count = 0;

    // Create a thread for each port number
    for (int i = 1; i <= port_number; i++) {
        struct thread_args *arg = malloc(sizeof(struct thread_args));
        arg->ip_address = ip_address;
        arg->port_number = i;

        if (pthread_create(&threads[thread_count], NULL, scan_port, (void *)arg) != 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }

        thread_count++;
    }

    // Join all threads
    for (int i = 0; i < thread_count; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}