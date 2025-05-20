//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_HOSTS 100
#define MAX_IP_ADDR_LEN 16

typedef struct {
    char hostname[100];
    char ip_address[MAX_IP_ADDR_LEN];
} Host;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname1 [hostname2 ...]\n", argv[0]);
        return 1;
    }
    
    Host hosts[MAX_HOSTS];
    int num_hosts = argc - 1;
    struct addrinfo hints, *res, *p;
    char ip_address_buf[MAX_IP_ADDR_LEN];
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
    for (int i = 0; i < num_hosts; i++) {
        memset(ip_address_buf, 0, MAX_IP_ADDR_LEN);
        strncpy(hosts[i].hostname, argv[i + 1], sizeof(hosts[i].hostname));
        
        if (getaddrinfo(argv[i + 1], NULL, &hints, &res) != 0) {
            fprintf(stderr, "Unable to resolve hostname %s\n", argv[i + 1]);
            return 1;
        }
        
        for (p = res; p != NULL; p = p->ai_next) {
            void *addr;
            char *ipver;
            
            if (p->ai_family == AF_INET) {
                struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
                addr = &(ipv4->sin_addr);
                ipver = "IPv4";
            }
            else {
                struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
                addr = &(ipv6->sin6_addr);
                ipver = "IPv6";
            }
            
            inet_ntop(p->ai_family, addr, ip_address_buf, MAX_IP_ADDR_LEN);
            strncpy(hosts[i].ip_address, ip_address_buf, MAX_IP_ADDR_LEN);
        }
        
        freeaddrinfo(res);
    }
    
    printf("Number of hosts found: %d\n", num_hosts);
    
    for (int i = 0; i < num_hosts; i++) {
        printf("Host %d - Name: %s, IP: %s\n", i + 1, hosts[i].hostname, hosts[i].ip_address);
    }
    
    return 0;
}