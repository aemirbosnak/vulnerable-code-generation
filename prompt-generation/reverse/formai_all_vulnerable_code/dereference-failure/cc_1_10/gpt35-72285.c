//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER "www.google.com"
#define PORT 80

int main(int argc, char *argv[]) {
    int sockfd, bytes_sent, bytes_recv;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char message[4096], response[4096];
    bzero(message, 4096); // Set message buffer to all zeroes
    bzero(response, 4096); // Set response buffer to all zeroes
    sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create a TCP socket
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    server = gethostbyname(SERVER); // Get IP address of server
    if (server == NULL) {
        perror("Error getting IP address");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr)); // Set server address buffer to all zeroes
    serv_addr.sin_family = AF_INET; // Set address family to IPv4
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length); // Copy server IP address into server address buffer
    serv_addr.sin_port = htons(PORT); // Set server port number
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) { // Connect to server
        perror("Error connecting to server");
        exit(1);
    }
    sprintf(message, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", SERVER); // Construct HTTP request message
    bytes_sent = send(sockfd, message, strlen(message), 0); // Send HTTP request message to server
    if (bytes_sent < 0) {
        perror("Error sending message to server");
        exit(1);
    }
    bytes_recv = recv(sockfd, response, 4096, 0); // Receive HTTP response message from server
    if (bytes_recv < 0) {
        perror("Error receiving message from server");
        exit(1);
    }
    printf("Response received from server:\n%s", response); // Print HTTP response from server
    close(sockfd); // Close TCP connection
    return 0;
}