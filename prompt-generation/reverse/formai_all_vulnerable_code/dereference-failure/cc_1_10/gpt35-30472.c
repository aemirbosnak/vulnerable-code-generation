//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main()
{
    char message[1024], buffer[1024];
    int sockfd, portno = 80, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname("www.example.com");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error Connecting");
        exit(1);
    }

    sprintf(message, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n");
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("Error sending message");
        exit(1);
    }

    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, n, stdout);
    }

    if (n < 0) {
        perror("Error receiving message");
        exit(1);
    }

    return 0;
}