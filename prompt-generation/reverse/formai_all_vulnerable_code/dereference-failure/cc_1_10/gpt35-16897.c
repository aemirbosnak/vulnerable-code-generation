//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <errno.h>

#define MAX_IFACE 32
#define BUFFER_SIZE 1024

void get_local_ip(char *ip_address) {
    struct ifaddrs *if_addrs, *ifa;
    void *addr_ptr;
    char *addr = NULL;
    
    getifaddrs(&if_addrs);
    
    for (ifa = if_addrs; ifa != NULL; ifa = ifa->ifa_next) {
        if (!ifa->ifa_addr) {
            continue;
        }
        if (ifa->ifa_addr->sa_family == AF_INET) {
            addr_ptr = &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            addr = (char*)malloc(INET_ADDRSTRLEN);
            inet_ntop(AF_INET, addr_ptr, addr, INET_ADDRSTRLEN);
            if (strcmp(ifa->ifa_name, "lo") != 0) {
              strcpy(ip_address, addr);
              freeifaddrs(if_addrs);
              free(addr);
              return;
           }
           free(addr);
        }
    }
    freeifaddrs(if_addrs);
    return;
}

int main(int argc, char *argv[]) {
    struct hostent *host;
    struct in_addr **addr_list;
    struct sockaddr_in server;
    int sockfd, i;
    char ip_address[INET_ADDRSTRLEN];
    char read_buffer[BUFFER_SIZE] = {0};
    char send_buffer[BUFFER_SIZE] = {0};
    
    get_local_ip(ip_address);
    
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if ((host = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }
    
    addr_list = (struct in_addr**) host->h_addr_list;
    
    for (i = 0; addr_list[i] != NULL; i++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket");
            exit(EXIT_FAILURE);
        }
        
        memcpy(&server.sin_addr, addr_list[i], sizeof(struct in_addr));
        server.sin_family = AF_INET;
        server.sin_port = htons(80);
        
        if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
            if (errno != EINPROGRESS) {
                perror("connect");
                close(sockfd);
                continue;
            }
        }
        
        sprintf(send_buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
        if (send(sockfd, send_buffer, strlen(send_buffer), 0) < 0) {
            perror("send");
            close(sockfd);
            continue;
        }
        
        if (recv(sockfd, read_buffer, BUFFER_SIZE, 0) < 0) {
            perror("recv");
            close(sockfd);
            continue;
        }
        
        printf("IP address %s responded to HTTP request.\n", inet_ntoa(*addr_list[i]));
        
        close(sockfd);
    }
    
    return 0;
}