//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Structure to store the network topology
typedef struct topology_node {
    char *ip_address;
    char *hostname;
    struct topology_node *next;
} topology_node;

// Structure to store the discovered hosts
typedef struct discovered_host {
    char *ip_address;
    char *hostname;
    struct discovered_host *next;
} discovered_host;

// Function to get the IP address of a hostname
char *get_ip_address(char *hostname) {
    struct hostent *host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        return NULL;
    }

    return inet_ntoa(*((struct in_addr *) host_info->h_addr_list[0]));
}

// Function to ping a host and return its status
int ping_host(char *ip_address) {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Could not create socket");
        return -1;
    }

    // Set the timeout to 1 second
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    // Set the destination IP address
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(ip_address);

    // Send a ping request
    char packet[1024];
    memset(packet, 0, sizeof(packet));
    packet[0] = 8; // ICMP type: echo request
    packet[1] = 0; // ICMP code: 0
    packet[2] = 0; // ICMP checksum
    packet[3] = 0; // ICMP identifier
    packet[4] = 0; // ICMP sequence number

    // Calculate the ICMP checksum
    int checksum = 0;
    for (int i = 0; i < sizeof(packet); i++) {
        checksum += packet[i];
    }
    checksum = (checksum & 0xffff) + (checksum >> 16);
    checksum = (checksum & 0xffff) + (checksum >> 16);
    packet[2] = (checksum & 0xff);
    packet[3] = (checksum >> 8);

    if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *) &dest_addr, sizeof(dest_addr)) < 0) {
        perror("Could not send ping request");
        close(sockfd);
        return -1;
    }

    // Receive the ping response
    char response[1024];
    memset(response, 0, sizeof(response));
    int response_len = recvfrom(sockfd, response, sizeof(response), 0, NULL, NULL);

    // Close the socket
    close(sockfd);

    if (response_len < 0) {
        // No response received
        return -1;
    } else {
        // Response received
        return 0;
    }
}

// Function to discover the hosts in a network
discovered_host *discover_hosts(topology_node *network_topology) {
    discovered_host *discovered_hosts = NULL;

    while (network_topology != NULL) {
        // Get the IP address of the host
        char *ip_address = get_ip_address(network_topology->ip_address);
        if (ip_address == NULL) {
            // Could not resolve the hostname
            fprintf(stderr, "Could not resolve the hostname %s\n", network_topology->ip_address);
            network_topology = network_topology->next;
            continue;
        }

        // Ping the host
        int ping_status = ping_host(ip_address);
        if (ping_status == -1) {
            // Could not ping the host
            fprintf(stderr, "Could not ping the host %s\n", ip_address);
            network_topology = network_topology->next;
            continue;
        }

        // Host is alive
        discovered_host *new_discovered_host = malloc(sizeof(discovered_host));
        new_discovered_host->ip_address = strdup(ip_address);
        new_discovered_host->hostname = strdup(network_topology->hostname);
        new_discovered_host->next = NULL;

        // Add the host to the list of discovered hosts
        if (discovered_hosts == NULL) {
            discovered_hosts = new_discovered_host;
        } else {
            discovered_host *current_discovered_host = discovered_hosts;
            while (current_discovered_host->next != NULL) {
                current_discovered_host = current_discovered_host->next;
            }
            current_discovered_host->next = new_discovered_host;
        }

        network_topology = network_topology->next;
    }

    return discovered_hosts;
}

// Function to free the memory used by the network topology
void free_network_topology(topology_node *network_topology) {
    while (network_topology != NULL) {
        topology_node *next = network_topology->next;
        free(network_topology->ip_address);
        free(network_topology->hostname);
        free(network_topology);
        network_topology = next;
    }
}

// Function to free the memory used by the discovered hosts
void free_discovered_hosts(discovered_host *discovered_hosts) {
    while (discovered_hosts != NULL) {
        discovered_host *next = discovered_hosts->next;
        free(discovered_hosts->ip_address);
        free(discovered_hosts->hostname);
        free(discovered_hosts);
        discovered_hosts = next;
    }
}

// Main function
int main() {
    // Create the network topology
    topology_node *network_topology = NULL;

    // Add the first host to the network topology
    topology_node *new_topology_node = malloc(sizeof(topology_node));
    new_topology_node->ip_address = strdup("192.168.1.1");
    new_topology_node->hostname = strdup("host1");
    new_topology_node->next = NULL;
    if (network_topology == NULL) {
        network_topology = new_topology_node;
    } else {
        topology_node *current_topology_node = network_topology;
        while (current_topology_node->next != NULL) {
            current_topology_node = current_topology_node->next;
        }
        current_topology_node->next = new_topology_node;
    }

    // Add the second host to the network topology
    new_topology_node = malloc(sizeof(topology_node));
    new_topology_node->ip_address = strdup("192.168.1.2");
    new_topology_node->hostname = strdup("host2");
    new_topology_node->next = NULL;
    if (network_topology == NULL) {
        network_topology = new_topology_node;
    } else {
        topology_node *current_topology_node = network_topology;
        while (current_topology_node->next != NULL) {
            current_topology_node = current_topology_node->next;
        }
        current_topology_node->next = new_topology_node;
    }

    // Discover the hosts in the network
    discovered_host *discovered_hosts = discover_hosts(network_topology);

    // Print the discovered hosts
    printf("Discovered hosts:\n");
    discovered_host *current_discovered_host = discovered_hosts;
    while (current_discovered_host != NULL) {
        printf("  %s (%s)\n", current_discovered_host->hostname, current_discovered_host->ip_address);
        current_discovered_host = current_discovered_host->next;
    }

    // Free the memory used by the network topology
    free_network_topology(network_topology);

    // Free the memory used by the discovered hosts
    free_discovered_hosts(discovered_hosts);

    return 0;
}