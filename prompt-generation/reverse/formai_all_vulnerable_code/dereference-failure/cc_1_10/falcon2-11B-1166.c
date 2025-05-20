//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: satisfied
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "www.google.com"
#define SERVER_PORT 80
#define BUFFER_SIZE 1024

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation error");
        exit(1);
    }

    // Set up the server address
    server = gethostbyname(SERVER_IP);
    if (server == NULL) {
        fprintf(stderr, "Hostname could not be resolved\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    // Send GET request
    n = write(sockfd, "GET / HTTP/1.1\r\n\r\n", 31);
    if (n < 0) {
        perror("Write error");
        exit(1);
    }

    // Read response
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Read error");
        exit(1);
    }

    printf("Received %d bytes: %s\n", n, buffer);

    // Close socket
    close(sockfd);

    return 0;
}