//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main() {
    int sockfd, portno, n;
    char buffer[256];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    printf("Welcome to the HTTP client program!\n");
    printf("Enter the server hostname: ");
    memset(buffer, 0, sizeof(buffer));
    fgets(buffer, sizeof(buffer), stdin);
    server = gethostbyname(buffer);
    if (server == NULL) {
        printf("Error: no such host.\n");
        return 1;
    }

    printf("Enter the server port number: ");
    memset(buffer, 0, sizeof(buffer));
    fgets(buffer, sizeof(buffer), stdin);
    portno = atoi(buffer);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: could not create socket.\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr = *((struct in_addr*)server->h_addr);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: could not connect to server.\n");
        return 1;
    }

    printf("Enter the HTTP request: ");
    memset(buffer, 0, sizeof(buffer));
    fgets(buffer, sizeof(buffer), stdin);

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error: could not write to socket.\n");
        return 1;
    }

    printf("Waiting for server response...\n");

    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        printf("Error: could not read from socket.\n");
        return 1;
    }

    printf("Server response:\n%s\n", buffer);

    close(sockfd);

    return 0;
}