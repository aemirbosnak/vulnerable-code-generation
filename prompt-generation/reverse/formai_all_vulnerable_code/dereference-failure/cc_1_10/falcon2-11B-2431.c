//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Check command line arguments
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Convert string to integer
    portno = atoi(argv[2]);

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // Create a server structure
    server = gethostbyname(argv[1]);

    // Fill the server structure with the IP address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send the echo request
    char buffer[1024];
    int numbytes;
    numbytes = write(sockfd, "Echo Request", 14);
    if (numbytes!= 14) {
        perror("write");
        exit(1);
    }
    numbytes = read(sockfd, buffer, 1024);
    printf("Received %d bytes from server: %s\n", numbytes, buffer);

    // Close the socket
    close(sockfd);

    return 0;
}