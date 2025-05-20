//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, numbytes, sent;
    char buffer[100];
    struct hostent *he;
    struct sockaddr_in server;

    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error connecting to host\n");
        exit(1);
    }

    printf("Connected to %s:%d\n", argv[1], ntohs(server.sin_port));

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        printf("Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);
        sent = send(sockfd, buffer, strlen(buffer), 0);
        if (sent < 0) {
            printf("Error sending message\n");
            exit(1);
        }
        numbytes = recv(sockfd, buffer, sizeof(buffer), 0);
        if (numbytes < 0) {
            printf("Error receiving message\n");
            exit(1);
        }
        printf("Received message: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}