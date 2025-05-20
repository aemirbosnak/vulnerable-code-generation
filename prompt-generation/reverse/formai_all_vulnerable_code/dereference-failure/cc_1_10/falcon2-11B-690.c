//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    // Create a TCP socket
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }
    
    // Connect to server
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("ERROR connecting to server");
        return 1;
    }
    
    // Send request to server
    char request[100];
    sprintf(request, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n");
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("ERROR sending request");
        return 1;
    }
    
    // Receive response from server
    char response[100];
    int nbytes;
    nbytes = recv(sockfd, response, sizeof(response), 0);
    if (nbytes < 0) {
        perror("ERROR receiving response");
        return 1;
    }
    
    // Close the socket
    close(sockfd);
    
    // Print the response
    printf("Response from server:\n%s\n", response);
    
    return 0;
}