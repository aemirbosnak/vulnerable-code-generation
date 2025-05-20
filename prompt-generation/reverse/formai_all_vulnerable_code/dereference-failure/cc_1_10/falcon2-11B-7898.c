//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: satisfied
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <net/if.h>

// Global variables
int sockfd;
struct sockaddr_in serveraddr;
struct hostent *server;
int portno;
int addrlen;
char buffer[4096];

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "usage: %s hostname\n", argv[0]);
        exit(1);
    }

    // Parse command line arguments
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Host not found\n");
        exit(1);
    }
    portno = htons(80); // Default port

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(portno);
    memcpy((char *)&serveraddr.sin_addr, (char *)server->h_addr, server->h_length);
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send a GET request
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive and print response
    while (1) {
        if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
            perror("recv");
            exit(1);
        }
        printf("%s\n", buffer);
    }

    return 0;
}