//Falcon2-11B DATASET v1.0 Category: Networking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[256];
    strcpy(hostname, argv[1]);

    int sockfd, newsockfd, portno;
    struct sockaddr_in serveraddr, clientaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(80); // Default HTTP port
    serveraddr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    char request[512];
    strcpy(request, "GET / HTTP/1.1\r\nHost: ");
    strcat(request, hostname);
    strcat(request, "\r\n\r\n");

    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("ERROR sending request");
        exit(1);
    }

    if (recv(sockfd, request, sizeof(request), 0) < 0) {
        perror("ERROR receiving response");
        exit(1);
    }

    printf("Received response:\n%s\n", request);

    close(sockfd);
    return 0;
}