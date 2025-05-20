//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_HOSTNAME_LEN 1024  // Maximum length of hostname
#define MAX_IP_LEN 16  // Maximum length of IP address

// Function to resolve hostname to IP address
int resolve_hostname(char *hostname, char *ip_address) {
    struct addrinfo hints, *res;
    int status;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if ((status = getaddrinfo(hostname, NULL, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 1;
    }
    struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;
    inet_ntop(AF_INET, &(ipv4->sin_addr), ip_address, INET_ADDRSTRLEN);
    freeaddrinfo(res);
    return 0;
}

// Function to print topology map
void print_topology_map(char **hostnames, int num_hosts, char **ip_addresses) {
    printf("***** Network Topology Map *****\n");
    for (int i = 0; i < num_hosts; i++) {
        printf("%s (%s)\n", hostnames[i], ip_addresses[i]);
    }
    printf("*******************************\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname1> <hostname2> ... <hostnameN>\n", argv[0]);
        return 1;
    }
    int num_hosts = argc - 1;
    char **hostnames = (char **)malloc(num_hosts * sizeof(char **));
    char **ip_addresses = (char **)malloc(num_hosts * sizeof(char **));
    for (int i = 0; i < num_hosts; i++) {
        hostnames[i] = (char *)malloc(MAX_HOSTNAME_LEN * sizeof(char));
        ip_addresses[i] = (char *)malloc(MAX_IP_LEN * sizeof(char));
        strncpy(hostnames[i], argv[i+1], MAX_HOSTNAME_LEN-1);
        hostnames[i][MAX_HOSTNAME_LEN-1] = '\0';
        if (resolve_hostname(hostnames[i], ip_addresses[i]) != 0) {
            fprintf(stderr, "Error resolving hostname\n");
            return 1;
        }
    }
    print_topology_map(hostnames, num_hosts, ip_addresses);
    // Free allocated memory
    for (int i = 0; i < num_hosts; i++) {
        free(hostnames[i]);
        free(ip_addresses[i]);
    }
    free(hostnames);
    free(ip_addresses);
    return 0;
}