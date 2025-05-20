//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

int main() {
    int sockfd, portno, *new_sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char request[1024];

    // Setting up the request
    sprintf(request, "GET /love-letter.txt HTTP/1.1\r\nHost: localhost\r\nConnection: keep-alive\r\nUser-Agent: My-Love-Client/1.0\r\nAccept: text/plain\r\n\r\n");

    // Initializing socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    // Getting server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(5000);

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return 1;
    }

    // Sending the request
    write(sockfd, request, strlen(request));

    // Reading the response
    int bytes_received;
    while ((bytes_received = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        printf("%s", buffer);
        bzero(buffer, BUFFER_SIZE);
    }

    // Closing the connection
    close(sockfd);
    return 0;
}