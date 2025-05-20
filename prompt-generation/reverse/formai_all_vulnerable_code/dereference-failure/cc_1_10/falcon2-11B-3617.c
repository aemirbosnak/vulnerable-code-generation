//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Get server information
    if ((server = gethostbyname("localhost")) == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(1234);

    // Bind to the port
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(sockfd, 1);

    // Accept incoming connections
    while ((portno = accept(sockfd, NULL, NULL)) > 0) {
        char buffer[256];
        int n;

        // Read data from the client
        n = read(portno, buffer, 256);
        if (n < 0) {
            perror("read failed");
            exit(EXIT_FAILURE);
        }

        // Send a message back to the client
        write(portno, "Thank you for connecting!\n", 22);
        close(portno);
    }

    return 0;
}