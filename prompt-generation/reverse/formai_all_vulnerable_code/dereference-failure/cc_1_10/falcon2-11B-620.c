//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char sendbuf[256], recvbuf[256];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(1);
    }

    // Get the server name and port number
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    portno = htons(5000); // port number

    // Store server's address and port number in a sockaddr_in structure
    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = portno;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Send a message to the server
    sprintf(sendbuf, "Hello from client");
    write(sockfd, sendbuf, strlen(sendbuf));

    // Read the server's response
    bzero(recvbuf, sizeof(recvbuf));
    n = read(sockfd, recvbuf, sizeof(recvbuf) - 1);
    recvbuf[n] = '\0';

    // Print the server's response
    printf("Server's response: %s\n", recvbuf);

    // Close the socket
    close(sockfd);
    return 0;
}