//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    // Check if user provided enough arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Parse arguments
    char *hostname = argv[1];
    int portno = atoi(argv[2]);
    
    // Get host IP address
    struct hostent *host;
    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "ERROR: no such host\n");
        exit(EXIT_FAILURE);
    }
    
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR: cannot create socket\n");
        exit(EXIT_FAILURE);
    }
    
    // Connect to host
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr = *((struct in_addr *) host->h_addr);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR: cannot connect to host\n");
        exit(EXIT_FAILURE);
    }
    
    // Prepare HTTP request
    char request[BUFSIZE];
    snprintf(request, BUFSIZE, "GET / HTTP/1.1\r\n"
                               "Host: %s:%d\r\n"
                               "Connection: close\r\n\r\n", hostname, portno);
    
    // Send HTTP request
    int bytes_sent = send(sockfd, request, strlen(request), 0);
    if (bytes_sent < 0) {
        fprintf(stderr, "ERROR: cannot send HTTP request\n");
        exit(EXIT_FAILURE);
    }
    
    // Receive HTTP response
    char response[BUFSIZE];
    int bytes_received = 0;
    int total_bytes_received = 0;
    while ((bytes_received = recv(sockfd, response + total_bytes_received, BUFSIZE, 0)) > 0) {
        total_bytes_received += bytes_received;
    }
    if (bytes_received < 0) {
        fprintf(stderr, "ERROR: cannot receive HTTP response\n");
        exit(EXIT_FAILURE);
    }
    
    // Print HTTP response
    printf("%s\n", response);
    
    // Close socket and exit
    close(sockfd);
    exit(EXIT_SUCCESS);
}