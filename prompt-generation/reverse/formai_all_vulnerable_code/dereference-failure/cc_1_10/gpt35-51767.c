//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: scientific
/* 
    Building an HTTP Client Program
    Author: Chatbot
    
    This program demonstrates how to build a simple HTTP client using sockets in C programming language.
    It uses the TCP protocol to establish a connection with the server and HTTP requests and responses to 
    communicate with the server.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define HTTP_PORT 80
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    char *host;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char message[BUFSIZE], server_reply[BUFSIZE];
    
    // Check for command line arguments
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    } else {
        host = argv[1];
    }
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Cannot create socket\n");
        exit(EXIT_FAILURE);
    }
    
    // Resolve hostname to IP address
    server = gethostbyname(host);
    if (server == NULL) {
        printf("Cannot resolve hostname\n");
        exit(EXIT_FAILURE);
    }
    
    // Set up server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(HTTP_PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Cannot connect to server\n");
        exit(EXIT_FAILURE);
    }
    
    // Build HTTP GET request
    sprintf(message, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);
    
    // Send HTTP GET request
    if (send(sockfd, message, strlen(message), 0) < 0) {
        printf("Error sending HTTP request\n");
        exit(EXIT_FAILURE);
    }
    
    // Receive HTTP response
    if (recv(sockfd, server_reply, BUFSIZE, 0) < 0) {
        printf("Error receiving HTTP response\n");
        exit(EXIT_FAILURE);
    }
    
    // Print HTTP response
    printf("%s", server_reply);
    
    // Close socket
    close(sockfd);
    
    return 0;
}