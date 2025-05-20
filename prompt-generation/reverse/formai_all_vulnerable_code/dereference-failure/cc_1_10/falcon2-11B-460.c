//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 80

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in server;
    struct hostent *host;

    // Check command line arguments
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    // Convert hostname to IP address
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: Unknown host\n");
        exit(1);
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket");
        exit(1);
    }

    // Initialize server address structure
    bzero((char *) &server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr = *(struct in_addr *) host->h_addr;

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("Connect");
        exit(1);
    }

    // Send SYN packet
    int len = sizeof(server);
    if (sendto(sockfd, &len, sizeof(len), 0, (struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("Send");
        exit(1);
    }

    // Close socket
    close(sockfd);

    return 0;
}