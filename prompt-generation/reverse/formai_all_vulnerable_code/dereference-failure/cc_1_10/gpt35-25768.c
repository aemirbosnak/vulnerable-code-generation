//FormAI DATASET v1.0 Category: Email Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s domain port\n", argv[0]);
        return 0;
    }

    int sockfd, n;
    char buffer[MAX_BUFFER];

    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        perror("Error opening socket");

    // Get the server information and validate it
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error, no such host.\n");
        return 0;
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        perror("Error connecting");

    // Receive data from server
    bzero(buffer, MAX_BUFFER);
    n = read(sockfd, buffer, MAX_BUFFER - 1);
    if (n < 0)
        perror("Error reading from socket");
    printf("Received: %s\n", buffer);

    // Send data to server
    bzero(buffer, MAX_BUFFER);
    printf("Enter command: ");
    fgets(buffer, MAX_BUFFER -1, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        perror("Error writing to socket");

    // Receive data from server
    bzero(buffer, MAX_BUFFER);
    n = read(sockfd, buffer, MAX_BUFFER - 1);
    if (n < 0)
        perror("Error reading from socket");
    printf("Received: %s\n", buffer);

    close(sockfd);
    
    return 0;
}