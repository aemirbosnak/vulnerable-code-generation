//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int nbytes;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);
        nbytes = send(sockfd, buffer, strlen(buffer), 0);

        if (nbytes == -1) {
            printf("Error sending data\n");
            exit(1);
        }

        nbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (nbytes == -1) {
            printf("Error receiving data\n");
            exit(1);
        }

        printf("Received message: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}