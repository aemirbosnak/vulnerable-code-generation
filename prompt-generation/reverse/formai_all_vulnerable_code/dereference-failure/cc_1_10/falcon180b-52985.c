//Falcon-180B DATASET v1.0 Category: Networking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error_handling(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(void) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error_handling("Error opening socket");

    portno = 8080;

    server = gethostbyname("localhost");
    if (server == NULL)
        error_handling("Error locating server");

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error_handling("Error connecting to server");

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
        if (strcmp(buffer, "exit\n") == 0) {
            close(sockfd);
            exit(EXIT_SUCCESS);
        }
        bzero(buffer, BUFFER_SIZE);
        recv(sockfd, buffer, BUFFER_SIZE, 0);
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}