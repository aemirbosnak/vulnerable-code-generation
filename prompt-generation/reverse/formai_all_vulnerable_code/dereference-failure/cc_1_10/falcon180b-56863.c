//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int status;

    if (argc!= 3) {
        printf("Usage:./ping <IP Address> <Port Number>\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    status = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (status == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Connection closed by server\n");
            close(sockfd);
            return 0;
        }
        printf("Received message: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}