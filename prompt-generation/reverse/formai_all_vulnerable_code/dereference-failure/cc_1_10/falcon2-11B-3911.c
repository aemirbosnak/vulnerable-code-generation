//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        return 1;
    }

    struct sockaddr_in client;
    socklen_t len = sizeof(client);

    int newsockfd = accept(sockfd, (struct sockaddr *)&client, &len);
    if (newsockfd < 0) {
        perror("accept");
        return 1;
    }

    char buffer[1024];
    int n = recv(newsockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }
    printf("Received message: %s\n", buffer);

    char *response = "Echo: ";
    int m = snprintf(buffer, sizeof(buffer), "%s", response);
    if (m < 0 || m >= sizeof(buffer)) {
        perror("snprintf");
        return 1;
    }

    n = send(newsockfd, buffer, m, 0);
    if (n < 0) {
        perror("send");
        return 1;
    }

    close(newsockfd);
    return 0;
}