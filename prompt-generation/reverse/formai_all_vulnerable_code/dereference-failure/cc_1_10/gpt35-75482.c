//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_DOMAIN_NAME_LENGTH 255

void scan_network_topology(char* ip_address, int range);

int main(int argc, char** argv) {
    if(argc != 3) {
        printf("Invalid number of arguments\n");
        exit(1);
    }
    char* ip_address = argv[1];
    int range = atoi(argv[2]);
    printf("Scanning network topology for IP Address %s with range %d\n", ip_address, range);
    scan_network_topology(ip_address, range);
    printf("Scanning completed\n");
    return 0;
}

void scan_network_topology(char* ip_address, int range) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error in creating socket");
        exit(1);
    }
    int enable = 1;
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) < 0) {
        perror("Error in setting socket option");
        exit(1);
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    printf("Starting network topology mapping\n");
    for(int i=1; i<=range; i++) {
        server_addr.sin_port = htons(i);
        if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            printf("Port %d is closed\n", i);
            continue;
        }
        printf("Port %d is open\n", i);
        char buffer[MAX_BUFFER_SIZE];
        memset(buffer, 0, MAX_BUFFER_SIZE);
        ssize_t bytes_read = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
        if(bytes_read < 0) {
            perror("Error in reading data from socket");
            continue;
        }
        printf("%s\n", buffer);
        close(sockfd);
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd < 0) {
            perror("Error in creating socket");
            exit(1);
        }
        if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) < 0) {
            perror("Error in setting socket option");
            exit(1);
        }
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(ip_address);
    }
    close(sockfd);
}