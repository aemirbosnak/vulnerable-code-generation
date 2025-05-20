//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 21

int main(int argc, char *argv[])
{
    int sockfd, connfd, n;
    struct sockaddr_in servaddr;
    struct hostent *server;

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: Unknown host\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting");
        return 1;
    }

    char buffer[1024];
    printf("Enter the command: ");
    fgets(buffer, sizeof(buffer), stdin);

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending command");
        return 1;
    }

    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error receiving response");
        return 1;
    }

    printf("%s\n", buffer);

    close(sockfd);
    return 0;
}