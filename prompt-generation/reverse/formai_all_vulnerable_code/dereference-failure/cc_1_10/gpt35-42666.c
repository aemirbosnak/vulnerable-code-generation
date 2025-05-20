//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

// This function takes a hostname and returns a list of IP addresses for that host
int get_ip_addresses(char* hostname, char* ips[], int max_ips) {
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int s;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;   
    hints.ai_socktype = SOCK_STREAM; 

    s = getaddrinfo(hostname, NULL, &hints, &result);
    if (s != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        return -1;
    }
    
    int i = 0;
    for (rp = result; rp != NULL && i < max_ips; rp = rp->ai_next) {
        void* addr;
        if (rp->ai_family == AF_INET) {
            struct sockaddr_in* ipv4 = (struct sockaddr_in*) rp->ai_addr;
            addr = &(ipv4->sin_addr);
        } else {
            struct sockaddr_in6* ipv6 = (struct sockaddr_in6*) rp->ai_addr;
            addr = &(ipv6->sin6_addr);
        }
        
        char ip[INET6_ADDRSTRLEN];
        inet_ntop(rp->ai_family, addr, ip, sizeof(ip));
        ips[i] = strdup(ip);
        i++;
    }

    freeaddrinfo(result);
    return i;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    char* hostname = argv[1];
    char* ips[10];
    int num_ips = get_ip_addresses(hostname, ips, 10);

    printf("Found %d IP addresses for %s:\n", num_ips, hostname);
    for (int i = 0; i < num_ips; i++) {
        printf("\t%s\n", ips[i]);
    }

    return 0;
}