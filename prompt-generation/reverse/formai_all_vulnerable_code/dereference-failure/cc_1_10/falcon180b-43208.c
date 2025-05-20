//Falcon-180B DATASET v1.0 Category: Networking ; Style: sophisticated
/* This program demonstrates a simple client-server communication using sockets in C.
   The server listens on a port and echoes back any message it receives from the client.
   The client sends a message to the server and prints out the response.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_MSG_SIZE 1024
#define SERVER_PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_MSG_SIZE];
    socklen_t clilen;
    char *message = "Hello, server! This is the client speaking.";

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    portno = atoi(argv[2]);

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    send(sockfd, message, strlen(message), 0);

    while (1) {
        bzero(buffer, MAX_MSG_SIZE);
        clilen = sizeof(cli_addr);
        recv(sockfd, buffer, MAX_MSG_SIZE, 0);
        printf("Server response: %s\n", buffer);

        close(sockfd);
        exit(0);
    }

    return 0;
}