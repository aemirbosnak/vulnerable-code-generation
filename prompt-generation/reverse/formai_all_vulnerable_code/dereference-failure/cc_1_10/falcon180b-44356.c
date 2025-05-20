//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        return 1;
    }

    char server[100];
    strcpy(server, argv[1]);
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        printf("Error getting host\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr*)host->h_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    char from[100];
    strcpy(from, "user@example.com");
    char to[100];
    strcpy(to, "recipient@example.com");
    char subject[100];
    strcpy(subject, "Test Email");
    char body[BUFFER_SIZE];
    strcpy(body, "Hello, world!");

    char message[BUFFER_SIZE];
    sprintf(message, "FROM: %s\r\nTO: %s\r\nSUBJECT: %s\r\n\r\n%s", from, to, subject, body);

    if (send(sockfd, message, strlen(message), 0) == -1) {
        printf("Error sending message\n");
        return 1;
    }

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);
    if (recv(sockfd, response, BUFFER_SIZE, 0) == -1) {
        printf("Error receiving response\n");
        return 1;
    }

    printf("Response: %s\n", response);

    close(sockfd);
    return 0;
}