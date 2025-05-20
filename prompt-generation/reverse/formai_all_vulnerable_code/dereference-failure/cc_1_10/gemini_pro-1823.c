//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_HOSTS 1000
#define MAX_PORTS 100

// Structure to store host and port information
struct host_port {
    char *host;
    int port;
};

// Structure to store thread information
struct thread_info {
    int thread_id;
    struct host_port *hosts_ports;
    int num_hosts_ports;
};

// Function to scan a host for open ports
void *scan_host(void *arg) {
    struct thread_info *info = (struct thread_info *)arg;

    for (int i = 0; i < info->num_hosts_ports; i++) {
        // Create a socket
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket");
            exit(1);
        }

        // Set the socket timeout
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;
        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
            perror("setsockopt");
            exit(1);
        }

        // Connect to the host
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(info->hosts_ports[i].port);
        addr.sin_addr.s_addr = inet_addr(info->hosts_ports[i].host);
        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            close(sockfd);
            continue;
        }

        // Print the open port
        printf("Open port: %d\n", info->hosts_ports[i].port);

        // Close the socket
        close(sockfd);
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host file> <port file>\n", argv[0]);
        exit(1);
    }

    // Read the host file
    FILE *host_file = fopen(argv[1], "r");
    if (host_file == NULL) {
        perror("fopen");
        exit(1);
    }

    // Read the port file
    FILE *port_file = fopen(argv[2], "r");
    if (port_file == NULL) {
        perror("fopen");
        exit(1);
    }

    // Allocate memory for the hosts and ports
    struct host_port *hosts_ports = malloc(sizeof(struct host_port) * MAX_HOSTS * MAX_PORTS);
    if (hosts_ports == NULL) {
        perror("malloc");
        exit(1);
    }

    // Read the hosts and ports from the files
    int num_hosts_ports = 0;
    char line[1024];
    while (fgets(line, sizeof(line), host_file) != NULL) {
        char *host = strtok(line, "\n");
        while (fgets(line, sizeof(line), port_file) != NULL) {
            int port = atoi(strtok(line, "\n"));
            hosts_ports[num_hosts_ports].host = host;
            hosts_ports[num_hosts_ports].port = port;
            num_hosts_ports++;
        }
    }

    // Close the files
    fclose(host_file);
    fclose(port_file);

    // Create the thread pool
    pthread_t threads[MAX_THREADS];
    struct thread_info thread_info[MAX_THREADS];

    // Divide the hosts and ports among the threads
    int num_threads = (num_hosts_ports / MAX_HOSTS) + 1;
    for (int i = 0; i < num_threads; i++) {
        thread_info[i].thread_id = i;
        thread_info[i].hosts_ports = &hosts_ports[i * MAX_HOSTS];
        thread_info[i].num_hosts_ports = (i == num_threads - 1) ? num_hosts_ports - (i * MAX_HOSTS) : MAX_HOSTS;

        // Create the thread
        if (pthread_create(&threads[i], NULL, scan_host, &thread_info[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Join the threads
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }

    // Free the memory
    free(hosts_ports);

    return 0;
}