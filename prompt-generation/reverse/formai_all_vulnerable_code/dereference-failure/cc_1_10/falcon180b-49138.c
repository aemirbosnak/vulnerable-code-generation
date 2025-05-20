//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, addrlen, bytes_received;
    char buffer[MAX_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    char *message = "PING";

    if (argc!= 3) {
        printf("Usage: %s <server_address> <port_number>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    printf("Connecting to %s on port %d...\n", argv[1], portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        printf("Failed to create socket.\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Failed to connect to %s on port %d.\n", argv[1], portno);
        exit(0);
    }

    printf("Connected successfully to %s on port %d.\n", argv[1], portno);

    while (1) {
        send(sockfd, message, strlen(message), 0);
        bytes_received = recv(sockfd, buffer, MAX_SIZE, 0);
        buffer[bytes_received] = '\0';
        printf("Received %d bytes of data: %s\n", bytes_received, buffer);
    }

    close(sockfd);
    return 0;
}