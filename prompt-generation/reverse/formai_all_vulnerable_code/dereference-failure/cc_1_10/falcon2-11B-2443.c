//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    char sendbuf[100];
    char recvbuf[100];
    char host[100];
    struct hostent *server;

    // Get the hostname from the command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    strcpy(host, argv[1]);

    // Convert the hostname to an IPv4 address
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error: Unknown host\n");
        exit(1);
    }

    portno = htons(80); // Default port for HTTP

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Fill in the servaddr structure with the server's address
    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = portno;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send a request to the server
    bzero(sendbuf, 100);
    sprintf(sendbuf, "GET / HTTP/1.0\r\n\r\n");
    if (send(sockfd, sendbuf, strlen(sendbuf), 0) < 0) {
        perror("ERROR sending request");
        exit(1);
    }

    // Receive the server's response
    bzero(recvbuf, 100);
    n = recv(sockfd, recvbuf, 100, 0);
    if (n <= 0) {
        perror("ERROR receiving response");
        exit(1);
    }

    // Print the server's response
    printf("%s\n", recvbuf);

    // Close the socket
    close(sockfd);

    return 0;
}