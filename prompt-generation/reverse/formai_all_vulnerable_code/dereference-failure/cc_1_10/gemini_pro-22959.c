//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

// Structure to hold information about a host
typedef struct {
    char *hostname;
    char *ip_address;
    int port;
} Host;

// Function to print the host information
void print_host(Host *host) {
    printf("Hostname: %s\n", host->hostname);
    printf("IP Address: %s\n", host->ip_address);
    printf("Port: %d\n\n", host->port);
}

// Function to map the network topology
void map_network_topology() {
    // Get the hostname of the local host
    char hostname[1024];
    gethostname(hostname, sizeof(hostname));

    // Get the IP address of the local host
    struct hostent *host_info = gethostbyname(hostname);
    struct in_addr *ip_address = (struct in_addr *)host_info->h_addr;

    // Create a table to store the hosts
    Host hosts[10];
    int num_hosts = 0;

    // Add the local host to the table
    hosts[num_hosts].hostname = hostname;
    hosts[num_hosts].ip_address = inet_ntoa(*ip_address);
    hosts[num_hosts].port = 80;
    num_hosts++;

    // Iterate over the IP addresses in the subnet
    for (int i = 1; i <= 254; i++) {
        // Construct the IP address
        char ip_address[16];
        sprintf(ip_address, "%s.%d", hosts[0].ip_address, i);

        // Create a socket
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);

        // Connect to the host
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(80);
        addr.sin_addr.s_addr = inet_addr(ip_address);
        int result = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));

        // If the connection was successful, add the host to the table
        if (result == 0) {
            hosts[num_hosts].hostname = hostname;
            hosts[num_hosts].ip_address = inet_ntoa(addr.sin_addr);
            hosts[num_hosts].port = 80;
            num_hosts++;
        }

        // Close the socket
        close(sockfd);
    }

    // Print the table of hosts
    for (int i = 0; i < num_hosts; i++) {
        print_host(&hosts[i]);
    }
}

int main() {

    // Map the network topology
    map_network_topology();

    return 0;
}