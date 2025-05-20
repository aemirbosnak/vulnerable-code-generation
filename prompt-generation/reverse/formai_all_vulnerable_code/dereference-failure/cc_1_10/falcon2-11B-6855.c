//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>

int main() {
    int sockfd, portno, newsockfd, bytes_read, bytes_written;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1024];
    char *hostname = "www.example.com";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    printf("Connected to %s\n", inet_ntoa(serv_addr.sin_addr));

    bytes_read = read(sockfd, buffer, sizeof(buffer));
    if (bytes_read < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    buffer[bytes_read] = '\0';
    printf("Received data: %s\n", buffer);

    bytes_written = write(sockfd, buffer, strlen(buffer));
    if (bytes_written < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    printf("Sent data: %s\n", buffer);

    close(sockfd);
    return 0;
}