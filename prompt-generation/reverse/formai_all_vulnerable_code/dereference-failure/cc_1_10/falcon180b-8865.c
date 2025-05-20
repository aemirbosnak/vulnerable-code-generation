//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <server_address> <port_number> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        fprintf(stderr, "Error connecting to server\n");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    if (send(sockfd, argv[3], strlen(argv[3]), 0) == -1) {
        fprintf(stderr, "Error sending message\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        if ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) == -1) {
            fprintf(stderr, "Error receiving data\n");
            exit(EXIT_FAILURE);
        }
        printf("Received data: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}