//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <ifaddrs.h>

#define MAX_IPADDR_LEN 46 // IPv6 string length
#define MAX_HOSTNAME_LEN 256 // Maximum length of a hostname

// Define a struct for holding network information
typedef struct {
    char hostname[MAX_HOSTNAME_LEN];
    char ipaddr[MAX_IPADDR_LEN];
    int port;
} NetworkNode;

// Define a function for obtaining the local IP address of the system
void get_local_ip_address(char* ipaddr) {
    struct ifaddrs *interfaces = NULL;
    struct ifaddrs *temp = NULL;
    int success = 0;

    // Get the list of all network interfaces
    success = getifaddrs(&interfaces);
    if (success == 0) {
        // Loop through the list of interfaces until we find the one that is active
        temp = interfaces;
        while (temp != NULL) {
            if (temp->ifa_addr->sa_family == AF_INET) {
                // Extract the IP address of the interface
                struct sockaddr_in *addr = (struct sockaddr_in *)temp->ifa_addr;
                char *ip = inet_ntoa(addr->sin_addr);
                strcpy(ipaddr, ip);
                break;
            }
            temp = temp->ifa_next;
        }
    }

    // Free the list of interfaces
    freeifaddrs(interfaces);
}

int main() {
    NetworkNode nodes[10];
    int num_nodes = 0;

    // Get the local IP address
    char local_ip[MAX_IPADDR_LEN];
    get_local_ip_address(local_ip);

    // Scan the network for hosts
    printf("Scanning network for hosts...\n");
    for (int i = 1; i <= 255; i++) {
        // Construct the IP address of the host to ping
        char ipaddr[MAX_IPADDR_LEN];
        sprintf(ipaddr, "%s.%d", strtok(local_ip, "."), i);

        // Attempt to connect to the host on a specific port
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(80);
        inet_pton(AF_INET, ipaddr, &addr.sin_addr);
        int rc = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));

        if (rc == 0) {
            // The host is online
            struct hostent *host = gethostbyaddr(&addr.sin_addr, sizeof(addr.sin_addr), AF_INET);
            if (host != NULL) {
                // Hostname is available, use it
                strcpy(nodes[num_nodes].hostname, host->h_name);
            } else {
                // Hostname is not available, use IP address instead
                strcpy(nodes[num_nodes].hostname, ipaddr);
            }
            // Save the IP address of the host
            strcpy(nodes[num_nodes].ipaddr, ipaddr);
            // Save the port number that was used to connect to the host
            nodes[num_nodes].port = 80;

            num_nodes++;
        }
        close(sockfd);
    }

    // Print out the list of hosts that were discovered
    printf("Hosts discovered on network:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d. %s (%s:%d)\n", i+1, nodes[i].hostname, nodes[i].ipaddr, nodes[i].port);
    }

    return 0;
}