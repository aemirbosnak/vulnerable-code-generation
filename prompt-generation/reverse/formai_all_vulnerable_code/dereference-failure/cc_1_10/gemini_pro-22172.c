//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

// Define the maximum number of hosts to scan
#define MAX_HOSTS 100

// Structure to store host information
typedef struct {
    char *hostname;
    int port;
    int status;
} host_t;

// Function to scan a host
void *scan_host(void *arg) {
    // Get the host information
    host_t *host = (host_t *)arg;

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Resolve the hostname
    struct hostent *hostent = gethostbyname(host->hostname);
    if (hostent == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Connect to the host
    struct sockaddr_in sockaddr_in;
    sockaddr_in.sin_family = AF_INET;
    sockaddr_in.sin_port = htons(host->port);
    sockaddr_in.sin_addr = *(struct in_addr *)hostent->h_addr;
    if (connect(sockfd, (struct sockaddr *)&sockaddr_in, sizeof(sockaddr_in)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Check if the host is up
    char buf[1];
    if (send(sockfd, buf, 1, 0) == -1) {
        perror("send");
        host->status = -1;
    } else {
        if (recv(sockfd, buf, 1, 0) == -1) {
            perror("recv");
            host->status = -1;
        } else {
            host->status = 0;
        }
    }

    // Close the socket
    close(sockfd);

    return NULL;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the number of arguments is valid
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <network address> <port> <number of hosts>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the network address, port, and number of hosts
    char *network_address = argv[1];
    int port = atoi(argv[2]);
    int num_hosts = atoi(argv[3]);

    // Create an array of hosts
    host_t hosts[MAX_HOSTS];

    // Initialize the hosts
    for (int i = 0; i < num_hosts; i++) {
        hosts[i].hostname = malloc(strlen(network_address) + 1);
        strcpy(hosts[i].hostname, network_address);
        hosts[i].port = port;
        hosts[i].status = -1;
    }

    // Create a thread for each host
    pthread_t threads[MAX_HOSTS];
    for (int i = 0; i < num_hosts; i++) {
        char *hostname = malloc(strlen(network_address) + 1);
        strcpy(hostname, network_address);
        hostname[strlen(hostname) - i] = '\0';
        hosts[i].hostname = hostname;

        pthread_create(&threads[i], NULL, scan_host, (void *)&hosts[i]);
    }

    // Join the threads
    for (int i = 0; i < num_hosts; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the results
    for (int i = 0; i < num_hosts; i++) {
        if (hosts[i].status == 0) {
            printf("%s:%d is up\n", hosts[i].hostname, hosts[i].port);
        } else {
            printf("%s:%d is down\n", hosts[i].hostname, hosts[i].port);
        }
    }

    return EXIT_SUCCESS;
}