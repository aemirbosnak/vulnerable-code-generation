//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    // Check command line arguments
    if (argc!= 2) {
        printf("Usage: %s <target IP address>\n", argv[0]);
        return 1;
    }

    // Convert IP address to a dotted-quad representation
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: Unknown host\n");
        return 1;
    }

    // Create a socket connection
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    // Set up the server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // Send a request to the server
    sprintf(buffer, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", argv[1]);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive a response from the server
    bzero(buffer, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        perror("Error receiving data from server");
        return 1;
    }

    // Check if the server responded with an OK status code
    if (buffer[0] == '1') {
        printf("Server responded with status code 200\n");
    } else {
        printf("Server responded with status code %d\n", n);
    }

    // Clean up the socket connection
    close(sockfd);

    return 0;
}