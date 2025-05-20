//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/tcp.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server_ip> <message>\n", argv[0]);
        return 1;
    }

    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, portno;
    char buffer[BUF_SIZE];
    char *message = argv[2];

    if ((server = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "No such host\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(25);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Socket creation failed\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Connection failed\n");
        return 1;
    }

    printf("Connected to %s\n", argv[1]);

    if (send(sockfd, message, strlen(message), 0) < 0) {
        fprintf(stderr, "Error sending message\n");
        return 1;
    }

    if (recv(sockfd, buffer, BUF_SIZE, 0) < 0) {
        fprintf(stderr, "Error receiving message\n");
        return 1;
    }

    printf("Received message: %s\n", buffer);

    close(sockfd);
    return 0;
}