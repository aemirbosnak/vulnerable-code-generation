//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080

int main()
{
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("bind failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 10) < 0) {
        printf("listen failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while (1) {
        int connfd, len, n;
        char buffer[1024];

        len = sizeof(cliaddr);
        connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
        if (connfd < 0) {
            printf("accept failed: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        n = read(connfd, buffer, 1024);
        buffer[n] = '\0';
        printf("Message from client: %s", buffer);

        char *message = "Hello from server\n";
        write(connfd, message, strlen(message));

        close(connfd);
    }

    close(sockfd);
    return 0;
}