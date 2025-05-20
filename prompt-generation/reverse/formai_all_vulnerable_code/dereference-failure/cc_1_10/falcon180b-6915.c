//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];

    if (argc < 3) {
        printf("Usage:./smtp_client <server_address> <port_number>\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Unable to create socket\n");
        return 1;
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("Error: Unable to connect to server\n");
        return 1;
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\r\n")] = '\0';
        send(sockfd, buffer, strlen(buffer), 0);

        numbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (numbytes <= 0) {
            printf("Error: Unable to receive data\n");
            return 1;
        }

        printf("Received data: %s", buffer);
    }

    close(sockfd);

    return 0;
}