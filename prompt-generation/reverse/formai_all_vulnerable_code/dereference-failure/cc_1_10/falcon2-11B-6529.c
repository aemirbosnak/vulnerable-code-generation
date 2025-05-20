//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *server;
    int n;

    // Check command line arguments
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    // Convert IP address to a struct in_addr
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: Unknown host\n");
        exit(1);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(5000); // Replace 5000 with your desired port number

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error: Failed to create socket\n");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "Error: Failed to connect to server\n");
        exit(1);
    }

    printf("Connection established to %s on port %d\n", inet_ntoa(servaddr.sin_addr), ntohs(servaddr.sin_port));

    // Read data from the server
    if ((n = read(sockfd, &servaddr, sizeof(servaddr))) < 0) {
        fprintf(stderr, "Error: Failed to read from server\n");
        exit(1);
    }
    printf("Received data from server: %s\n", inet_ntoa(servaddr.sin_addr));

    // Send data to the server
    if ((n = write(sockfd, "Hello, server!", 14)) < 0) {
        fprintf(stderr, "Error: Failed to write to server\n");
        exit(1);
    }
    printf("Sent data to server: Hello, server!\n");

    // Close the socket
    close(sockfd);

    return 0;
}