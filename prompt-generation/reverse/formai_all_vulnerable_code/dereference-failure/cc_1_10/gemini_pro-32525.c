//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Get the hostname and port number from the command line arguments.
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket for connecting to the server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Get the IP address of the server.
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // Create a sockaddr_in structure for the server's address.
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send a request to the server.
    char *request = "GET / HTTP/1.1\r\nHost: " 
        "example.com\r\n\r\n";
    int request_len = strlen(request);
    if (send(sockfd, request, request_len, 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive a response from the server.
    char buffer[1024];
    int response_len = recv(sockfd, buffer, sizeof(buffer) 
        - 1, 0);
    if (response_len == -1) {
        perror("recv");
        return 1;
    }

    // Print the response.
    printf("%s", buffer);

    // Close the socket.
    close(sockfd);

    return 0;
}