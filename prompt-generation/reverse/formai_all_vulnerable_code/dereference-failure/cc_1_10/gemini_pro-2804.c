//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <pthread.h>

#define MAX_HOSTS 100
#define MAX_PORTS 100

// Structure to represent a host
typedef struct host {
    char *hostname;
    struct in_addr ip_addr;
    int port;
    int status; // 0 for offline, 1 for online
    struct host *next;
} host_t;

// Structure to represent the network topology
typedef struct network {
    host_t *hosts;
    int num_hosts;
} network_t;

// Function to create a new host
host_t *create_host(char *hostname, struct in_addr ip_addr, int port) {
    host_t *host = (host_t *)malloc(sizeof(host_t));
    host->hostname = strdup(hostname);
    host->ip_addr = ip_addr;
    host->port = port;
    host->status = 0;
    host->next = NULL;
    return host;
}

// Function to add a host to the network
void add_host(network_t *network, host_t *host) {
    if (network->hosts == NULL) {
        network->hosts = host;
    } else {
        host_t *current = network->hosts;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = host;
    }
    network->num_hosts++;
}

// Function to create a new network
network_t *create_network() {
    network_t *network = (network_t *)malloc(sizeof(network_t));
    network->hosts = NULL;
    network->num_hosts = 0;
    return network;
}

// Function to free the memory allocated for a host
void free_host(host_t *host) {
    free(host->hostname);
    free(host);
}

// Function to free the memory allocated for a network
void free_network(network_t *network) {
    host_t *current = network->hosts;
    while (current != NULL) {
        host_t *next = current->next;
        free_host(current);
        current = next;
    }
    free(network);
}

// Function to get the IP address of a host
struct in_addr get_ip_addr(char *hostname) {
    struct hostent *host_entry = gethostbyname(hostname);
    if (host_entry == NULL) {
        perror("gethostbyname");
        exit(1);
    }
    return *(struct in_addr *)host_entry->h_addr_list[0];
}

// Function to check if a host is online
int is_host_online(host_t *host) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr = host->ip_addr;
    serv_addr.sin_port = htons(host->port);
    int conn = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (conn == -1) {
        close(sockfd);
        return 0;
    }
    close(sockfd);
    return 1;
}

// Function to scan the network for online hosts
void scan_network(network_t *network) {
    for (host_t *host = network->hosts; host != NULL; host = host->next) {
        if (is_host_online(host)) {
            host->status = 1;
        }
    }
}

// Function to print the network topology
void print_network(network_t *network) {
    printf("Network Topology:\n");
    for (host_t *host = network->hosts; host != NULL; host = host->next) {
        printf("%s (%s:%d) - ", host->hostname, inet_ntoa(host->ip_addr), host->port);
        if (host->status == 1) {
            printf("Online\n");
        } else {
            printf("Offline\n");
        }
    }
}

// Main function
int main() {
    // Create a new network
    network_t *network = create_network();

    // Add hosts to the network
    add_host(network, create_host("host1", get_ip_addr("192.168.1.101"), 80));
    add_host(network, create_host("host2", get_ip_addr("192.168.1.102"), 8080));
    add_host(network, create_host("host3", get_ip_addr("192.168.1.103"), 9000));

    // Scan the network for online hosts
    scan_network(network);

    // Print the network topology
    print_network(network);

    // Free the memory allocated for the network
    free_network(network);

    return 0;
}