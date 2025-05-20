//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    char *port_range = argv[2];

    int start_port = atoi(port_range);
    int end_port = start_port + MAX_PORTS - 1;

    struct addrinfo *server_info;
    getaddrinfo(ip_address, NULL, NULL, &server_info);

    int sockfd = socket(server_info->ai_family, SOCK_STREAM, 0);

    if(sockfd == -1) {
        printf("Error: Could not create socket.\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    for(int i = start_port; i <= end_port; i++) {
        if(connect(sockfd, server_info->ai_addr, server_info->ai_addrlen) == 0) {
            sprintf(buffer, "Port %d is open.\n", i);
            write(sockfd, buffer, strlen(buffer));
            close(sockfd);
        } else {
            sprintf(buffer, "Port %d is closed.\n", i);
            write(sockfd, buffer, strlen(buffer));
        }
    }

    close(sockfd);
    freeaddrinfo(server_info);

    return 0;
}