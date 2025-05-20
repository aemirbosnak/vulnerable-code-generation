//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Initialize variables
    int sockfd, portno, newsockfd, bytes_read;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    // Error handling
    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    // Set up server address struct
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return 1;
    }
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("ERROR connecting");
        return 1;
    }

    // Transfer file
    printf("Enter filename: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    printf("Enter hostname: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    printf("Enter port: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    // Send command
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending command");
        return 1;
    }

    // Read response
    if ((bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("ERROR reading response");
        return 1;
    }
    printf("%s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}