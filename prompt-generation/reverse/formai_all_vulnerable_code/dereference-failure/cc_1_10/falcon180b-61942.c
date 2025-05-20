//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, n;
    struct sockaddr_in serv_addr, cli_addr;
    char send_buffer[BUFFER_SIZE], recv_buffer[BUFFER_SIZE];
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    server = gethostbyname("example.com");

    if (server == NULL) {
        printf("Error getting host by name\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(send_buffer, 0, BUFFER_SIZE);
        memset(recv_buffer, 0, BUFFER_SIZE);

        printf("Enter command: ");
        fgets(send_buffer, BUFFER_SIZE, stdin);

        n = send(sockfd, send_buffer, strlen(send_buffer), 0);

        if (n < 0) {
            printf("Error sending data\n");
            exit(1);
        }

        n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);

        if (n < 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        printf("Server response: %s", recv_buffer);
    }

    close(sockfd);

    return 0;
}