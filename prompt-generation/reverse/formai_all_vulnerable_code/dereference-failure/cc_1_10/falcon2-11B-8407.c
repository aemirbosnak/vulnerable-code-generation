//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define PORT 8080

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serveraddr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Unknown host %s\n", argv[1]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    char buffer[256];
    int nbytes = read(sockfd, buffer, sizeof(buffer));
    if (nbytes <= 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Received %d bytes: %s\n", nbytes, buffer);

    n = snprintf(buffer, sizeof(buffer), "Hello, %s!", argv[1]);
    if (n < 0 || n >= sizeof(buffer)) {
        fprintf(stderr, "Message too long\n");
        exit(1);
    }
    if (write(sockfd, buffer, n) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    printf("Sent %d bytes\n", n);

    close(sockfd);
    return 0;
}