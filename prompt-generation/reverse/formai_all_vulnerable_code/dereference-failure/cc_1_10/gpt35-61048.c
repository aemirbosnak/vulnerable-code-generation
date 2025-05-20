//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    char hostname[MAX_DATA_SIZE], request[MAX_DATA_SIZE], buffer[MAX_DATA_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Check if the user has provided the required input arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port request\n", argv[0]);
        exit(0);
    }
    strcpy(hostname, argv[1]);
    portno = atoi(argv[2]);
    strcpy(request, argv[3]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Get server information
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    // Establish connection
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send request
    n = write(sockfd, request, strlen(request));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read repsonse
    bzero(buffer, MAX_DATA_SIZE);
    n = read(sockfd, buffer, MAX_DATA_SIZE);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // Print response
    printf("Response:\n%s\n", buffer);

    // Clean up
    close(sockfd);
    return 0;
}