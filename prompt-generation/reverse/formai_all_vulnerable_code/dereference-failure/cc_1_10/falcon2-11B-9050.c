//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

// Function to get internet speed
double getInternetSpeed(const char *host, int port) {
    double result = 0.0;
    int sockfd;
    struct hostent *server;
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Get the server information
    if ((server = gethostbyname(host)) == NULL) {
        perror("ERROR, no such host");
        exit(EXIT_FAILURE);
    }

    // Store the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, *(long *)server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, addr_len) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    // Read the response from the server
    char buffer[1024];
    int n;
    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        result += (double)n / 1024; // In KB/s
    }

    // Close the socket
    close(sockfd);

    return result;
}

int main() {
    const char *host = "www.google.com";
    int port = 80;
    double speed = getInternetSpeed(host, port);
    printf("Internet speed: %f KB/s\n", speed);
    return 0;
}