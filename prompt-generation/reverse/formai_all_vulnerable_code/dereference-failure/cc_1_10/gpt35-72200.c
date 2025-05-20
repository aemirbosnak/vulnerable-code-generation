//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define HOSTNAME "www.example.com"
#define PORT 80
#define REQUEST "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n"

int main() {
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, bytes, total_bytes = 0;
    char buffer[1024];

    /* Create a socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    
    /* Get the server's IP address */
    server = gethostbyname(HOSTNAME);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host '%s'\n", HOSTNAME);
        exit(1);
    }
    
    /* Set the address */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    
    /* Connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }
    
    /* Send the HTTP request */
    bytes = send(sockfd, REQUEST, strlen(REQUEST), 0);
    if (bytes < 0) {
        perror("Error sending request");
        exit(1);
    }
    
    /* Receive the response */
    while ((bytes = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        total_bytes += bytes;
        fwrite(buffer, 1, bytes, stdout);
    }
    
    if (bytes < 0) {
        perror("Error receiving response");
        exit(1);
    }
    
    printf("\nTotal bytes received: %d\n", total_bytes);

    /* Close the socket */
    close(sockfd);

    return 0;
}