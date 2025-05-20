//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: introspective
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char sendBuf[1024];
    char recvBuf[1024];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    // Get the IP address of the host and the port number
    server = gethostbyname("www.google.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return 2;
    }

    portno = htons(80);

    // Set the address struct for the server
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return 3;
    }

    printf("Connected to server\n");

    // Send a ping request
    strcpy(sendBuf, "GET / HTTP/1.1\r\nHost: google.com\r\n\r\n");
    send(sockfd, sendBuf, strlen(sendBuf), 0);

    // Receive the response
    bzero(recvBuf, 1024);
    n = recv(sockfd, recvBuf, 1024, 0);
    if (n < 0) {
        perror("ERROR receiving data");
        return 4;
    }

    printf("Received %d bytes: %s\n", n, recvBuf);

    return 0;
}