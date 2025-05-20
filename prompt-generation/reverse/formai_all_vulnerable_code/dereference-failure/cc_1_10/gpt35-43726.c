//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_IP_ADDRS 10
#define MAX_DEV_NAME 20

int main() {
    struct ifaddrs *ifap, *ifa;
    struct sockaddr_in *sa;
    char *addr;
    char ip_addrs[MAX_IP_ADDRS][INET_ADDRSTRLEN];
    char dev_name[MAX_DEV_NAME];
    int socket_fd, status;
    int num_ip_addrs = 0;

    // Get list of network interfaces
    if(getifaddrs(&ifap) == -1) {
        perror("Error getting network interface list");
        exit(EXIT_FAILURE);
    }

    // Iterate over network interfaces
    for(ifa = ifap; ifa != NULL; ifa = ifa->ifa_next) {
        if(ifa->ifa_addr == NULL) continue;

        // Get IP address of interface
        if(ifa->ifa_addr->sa_family == AF_INET) {
            sa = (struct sockaddr_in*) ifa->ifa_addr;
            addr = inet_ntoa(sa->sin_addr);

            // Store IP address in array
            strncpy(ip_addrs[num_ip_addrs], addr, INET_ADDRSTRLEN);
            num_ip_addrs++;
        }
    }

    // Free allocated memory for network interface list
    freeifaddrs(ifap);

    // Iterate over IP addresses and perform traceroute to each one
    for(int i = 0; i < num_ip_addrs; i++) {
        printf("Tracing route to %s\n", ip_addrs[i]);

        // Create raw socket
        socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
        if(socket_fd < 0) {
            perror("Error creating socket");
            exit(EXIT_FAILURE);
        }

        // Set options for raw socket
        status = setsockopt(socket_fd, IPPROTO_IP, IP_HDRINCL, &(int){1}, sizeof(int));
        if(status < 0) {
            perror("Error setting socket options");
            exit(EXIT_FAILURE);
        }

        close(socket_fd);
    }

    return 0;
}