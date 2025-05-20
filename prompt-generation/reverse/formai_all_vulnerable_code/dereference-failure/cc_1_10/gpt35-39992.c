//FormAI DATASET v1.0 Category: Email Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define PORT 80

int main(int argc, char *argv[]) {
    // Initialize socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Socket creation error");
        return -1;
    }

    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Get server details
    server = gethostbyname(argv[1]);
    if(server == NULL) {
        perror("Error getting host details");
        return -1;
    }

    // Initialize server details
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to server
    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection error");
        return -1;
    }

    char request[500], buffer[1000];
    bzero(request, sizeof(request));
    bzero(buffer, sizeof(buffer));

    // Send request to server
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    if(send(sockfd, request, strlen(request), 0) < 0) {
        perror("Error sending request to server");
        return -1;
    }

    // Receive response from server
    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error receiving response from server");
        return -1;
    }

    // Print response from server
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}