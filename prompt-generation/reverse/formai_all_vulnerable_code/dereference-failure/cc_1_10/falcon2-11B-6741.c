//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <proxy_port> <target_host> <target_port>\n", argv[0]);
        return 1;
    }

    int proxy_port = atoi(argv[1]);
    char *target_host = argv[2];
    int target_port = atoi(argv[3]);

    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addrlen;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(proxy_port);
    server_addr.sin_addr.s_addr = inet_addr(target_host);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    listen(sockfd, 5);

    while (1) {
        addrlen = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addrlen);
        if (newsockfd == -1) {
            perror("accept");
            continue;
        }

        if (fork() == 0) {
            close(sockfd);
            dup2(newsockfd, STDOUT_FILENO);
            dup2(newsockfd, STDIN_FILENO);
            execlp("nc", "nc", target_host, "target_port", NULL);
            exit(1);
        }

        close(newsockfd);
    }

    return 0;
}