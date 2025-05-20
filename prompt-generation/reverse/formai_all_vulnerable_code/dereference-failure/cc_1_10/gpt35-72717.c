//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h> 
#include <sys/socket.h>
#include <netinet/in.h> 
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

// Structure to store information about a host
struct HostInfo {
    char ip[INET_ADDRSTRLEN]; // stores the IP address of the host
    int port; // stores the port on which the host is listening
};

// Maximum number of threads
#define MAXTHREADS 100

// Array to store the information about all hosts
struct HostInfo hosts[MAXTHREADS];
int num_hosts = 0; // stores the number of hosts discovered so far

struct ThreadArgs {
    int id; // stores the id of the thread
    struct in_addr ip_start; // stores the starting IP address
    struct in_addr ip_end; // stores the ending IP address
};

// Function to scan a range of IP addresses
void *scan(void *args) {
    struct ThreadArgs *thread_args = (struct ThreadArgs *)args;
    int id = thread_args->id;
    struct in_addr ip_start = thread_args->ip_start;
    struct in_addr ip_end = thread_args->ip_end;

    int sock, conn;
    struct sockaddr_in server_addr;

    // Loop through all IP addresses in the given range
    for (uint32_t i = ntohl(ip_start.s_addr); i <= ntohl(ip_end.s_addr); i++) {
        struct in_addr ip;
        ip.s_addr = htonl(i);

        // Create a socket to connect to the host
        sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sock < 0) {
            printf("Thread %d: Error creating socket: %s\n", id, strerror(errno));
            continue;
        }

        // Set the socket options to timeout after 1 second
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;
        if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
            printf("Thread %d: Error setting socket options: %s\n", id, strerror(errno));
            close(sock);
            continue;
        }

        // Connect to the host on port 80 (HTTP)
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        server_addr.sin_addr = ip;
        conn = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

        // If the connection is successful, add the host to the hosts array
        if (conn == 0) {
            struct HostInfo host;
            strncpy(host.ip, inet_ntoa(ip), INET_ADDRSTRLEN);
            host.port = 80;
            hosts[num_hosts] = host;
            num_hosts++;
        }

        close(sock);
    }

    printf("Thread %d: Finished scanning range %s - %s\n", id, inet_ntoa(ip_start), inet_ntoa(ip_end));
}

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: %s [start IP address] [end IP address]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse the arguments
    struct in_addr ip_start, ip_end;
    if (inet_aton(argv[1], &ip_start) == 0 || inet_aton(argv[2], &ip_end) == 0) {
        printf("Invalid IP address\n");
        exit(EXIT_FAILURE);
    }

    // Divide the IP range into equal parts for each thread
    int num_threads = MAXTHREADS;
    uint32_t range_size = (ntohl(ip_end.s_addr) - ntohl(ip_start.s_addr) + 1) / num_threads;

    pthread_t threads[num_threads];
    struct ThreadArgs thread_args[num_threads];

    // Start each thread with its own range of IP addresses to scan
    for (int i = 0; i < num_threads; i++) {
        thread_args[i].id = i;
        thread_args[i].ip_start.s_addr = htonl(ntohl(ip_start.s_addr) + (i * range_size));
        thread_args[i].ip_end.s_addr = htonl(ntohl(ip_start.s_addr) + ((i+1) * range_size) - 1);

        pthread_create(&threads[i], NULL, scan, (void *)&thread_args[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print all the hosts discovered
    printf("Discovered %d hosts:\n", num_hosts);
    for (int i = 0; i < num_hosts; i++) {
        printf("%s:%d\n", hosts[i].ip, hosts[i].port);
    }

    return 0;
}