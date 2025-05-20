//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port > end_port) {
        fprintf(stderr, "Invalid range: start_port (%d) > end_port (%d)\n", start_port, end_port);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server;
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(start_port);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (end_port - start_port > 0) {
        int new_sockfd = accept(sockfd, NULL, NULL);
        if (new_sockfd < 0) {
            perror("accept");
            exit(1);
        }

        struct sockaddr_in client;
        socklen_t client_len = sizeof(client);

        if (getsockname(new_sockfd, (struct sockaddr *)&client, &client_len) < 0) {
            perror("getsockname");
            exit(1);
        }

        printf("Port %d is %s\n", ntohs(client.sin_port), (connect(new_sockfd, (struct sockaddr *)&client, client_len) < 0? "unreachable" : "reachable"));

        close(new_sockfd);

        end_port--;
    }

    close(sockfd);
    return 0;
}