//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERVER_PORT 110

int main() {
    int sockfd, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;

    printf("Connecting to POP3 server\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");

    if (server == NULL) {
        printf("Error, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Connected to POP3 server\n");

    char buffer[1024];
    n = read(sockfd, buffer, sizeof(buffer));

    while (n > 0) {
        printf("%s", buffer);
        n = read(sockfd, buffer, sizeof(buffer));
    }

    close(sockfd);

    return 0;
}