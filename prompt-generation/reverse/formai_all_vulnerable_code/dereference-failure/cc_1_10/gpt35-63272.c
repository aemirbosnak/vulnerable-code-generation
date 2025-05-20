//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_IP_LEN 16
#define MAX_HOSTNAME_LEN 128

void die(char *error_message) {
    perror(error_message);
    exit(1);
}

int main(int argc, char *argv[]) {

    if(argc != 3) {
        printf("Usage: %s <IP address> <network mask>\n", argv[0]);
        exit(1);
    }

    char ip_address[MAX_IP_LEN];
    char network_mask[MAX_IP_LEN];
    strncpy(ip_address, argv[1], MAX_IP_LEN);
    strncpy(network_mask, argv[2], MAX_IP_LEN);

    // Convert IP address and network mask from string to binary format
    struct in_addr binary_ip_address, binary_network_mask;
    if(inet_pton(AF_INET, ip_address, &binary_ip_address) <= 0)
        die("Error: Invalid IP address");
    if(inet_pton(AF_INET, network_mask, &binary_network_mask) <= 0)
        die("Error: Invalid network mask");

    // Extract the network address from the IP address and network mask
    unsigned long int network_address = binary_ip_address.s_addr & binary_network_mask.s_addr;

    // Get the host name for each device in the network using reverse DNS lookup
    char hostname[MAX_HOSTNAME_LEN];
    struct hostent *host_info;
    struct in_addr address;

    int i;
    for(i = 1; i <= 255; i++) {
        address.s_addr = htonl(network_address + i);
        if((host_info = gethostbyaddr(&address, sizeof(address), AF_INET)) != NULL) {
            strncpy(hostname, host_info->h_name, MAX_HOSTNAME_LEN);
            printf("%s\n", hostname);
        }
    }

    return 0;
}