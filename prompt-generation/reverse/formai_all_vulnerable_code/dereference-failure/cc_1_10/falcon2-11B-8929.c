//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

// Function to print IP address and subnet mask for a given host
void print_ip_subnet(struct sockaddr_in* addr, struct in_addr* subnet) {
    printf("%s/%d\n", inet_ntoa(*(struct in_addr*)&addr->sin_addr), subnet->s_addr & ~addr->sin_addr.s_addr);
}

// Function to check if IP address is valid
int is_valid_ip(char* ip) {
    struct sockaddr_in addr;
    if (inet_pton(AF_INET, ip, &(addr.sin_addr)) <= 0) {
        return 0;
    }
    return 1;
}

// Function to get hostname for a given IP address
char* get_hostname(char* ip) {
    struct hostent* host = gethostbyaddr((const void*)&(ip[0]), strlen(ip), AF_INET);
    if (host == NULL) {
        return NULL;
    }
    return host->h_name;
}

// Function to get hostname for a given hostname
char* get_ip(char* hostname) {
    struct hostent* host = gethostbyname(hostname);
    if (host == NULL) {
        return NULL;
    }
    return inet_ntoa(*(struct in_addr*)host->h_addr_list[0]);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <ip> <hostname>\n", argv[0]);
        return 1;
    }

    char* ip = argv[1];
    char* hostname = argv[2];

    struct in_addr subnet;
    inet_aton(argv[1], &subnet);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr = subnet;

    struct hostent* host;
    host = gethostbyaddr((const void*)&(addr.sin_addr), strlen(ip), AF_INET);
    if (host == NULL) {
        fprintf(stderr, "Invalid IP address: %s\n", ip);
        return 1;
    }

    char* hostname_ = get_hostname(ip);
    if (hostname_ == NULL) {
        fprintf(stderr, "Invalid hostname: %s\n", ip);
        return 1;
    }

    char* ip_ = get_ip(hostname_);
    if (ip_ == NULL) {
        fprintf(stderr, "Invalid hostname: %s\n", hostname);
        return 1;
    }

    print_ip_subnet(&addr, &subnet);
    printf("%s -> %s\n", ip_, hostname_);

    return 0;
}