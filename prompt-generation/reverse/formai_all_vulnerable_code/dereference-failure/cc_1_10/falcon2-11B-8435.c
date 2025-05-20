//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

int main() {
    int sockfd, numBytes, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Resolve server address
    if ((server = gethostbyname("localhost")) == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    // Initialize server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80); // Default port for HTTP

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send HTTP request
    n = sprintf(buffer, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n");
    if (send(sockfd, buffer, n, 0) < 0) {
        perror("ERROR sending request");
        exit(1);
    }

    // Receive response
    while ((numBytes = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        // Check for intrusion (e.g., unexpected content type)
        if (strstr(buffer, "text/html")!= NULL) {
            printf("Intrusion detected: HTML content received!\n");
            exit(1);
        }
    }

    // Close socket
    close(sockfd);

    return 0;
}