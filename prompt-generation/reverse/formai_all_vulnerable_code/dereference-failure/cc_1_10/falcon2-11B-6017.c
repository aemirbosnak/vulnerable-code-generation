//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_IP "localhost"
#define SERVER_PORT 25

int main() {
    int sockfd, bytes_read;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    server = gethostbyname(SERVER_IP);

    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter your message: ");
        scanf("%s", buffer);
        bytes_read = send(sockfd, buffer, strlen(buffer), 0);

        if (bytes_read < 0) {
            perror("ERROR sending data");
            exit(1);
        }

        printf("Sent %d bytes\n", bytes_read);

        printf("Enter your message: ");
        bytes_read = recv(sockfd, buffer, 256, 0);

        if (bytes_read < 0) {
            perror("ERROR receiving data");
            exit(1);
        }

        printf("Received %d bytes\n", bytes_read);
    }

    close(sockfd);
    return 0;
}