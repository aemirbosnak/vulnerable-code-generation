//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in server;
    bzero(&server, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Error binding to port");
        return 1;
    }

    listen(sockfd, 5);

    while (1) {
        struct sockaddr_in client;
        socklen_t len = sizeof(client);

        int clientfd = accept(sockfd, (struct sockaddr*)&client, &len);
        if (clientfd < 0) {
            perror("Error accepting client connection");
            return 1;
        }

        char buf[256];
        int n = recv(clientfd, buf, sizeof(buf), 0);
        if (n < 0) {
            perror("Error receiving data from client");
            close(clientfd);
            continue;
        }

        printf("Received message from client: %s\n", buf);

        char msg[256];
        scanf("%s", msg);
        if (send(clientfd, msg, strlen(msg), 0) < 0) {
            perror("Error sending message to client");
            close(clientfd);
        }

        close(clientfd);
    }

    close(sockfd);
    return 0;
}