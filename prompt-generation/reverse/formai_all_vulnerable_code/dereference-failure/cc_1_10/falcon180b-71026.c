//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        close(sockfd);
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    char buffer[BUF_SIZE];
    while (1) {
        int bytes_received = recv(sockfd, buffer, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            close(sockfd);
            return 1;
        }

        char *token = strtok(buffer, " ");
        if (token == NULL) {
            continue;
        }

        if (strcmp(token, "QoS") == 0) {
            token = strtok(NULL, " ");
            printf("QoS: %s\n", token);
        }
    }

    close(sockfd);
    return 0;
}