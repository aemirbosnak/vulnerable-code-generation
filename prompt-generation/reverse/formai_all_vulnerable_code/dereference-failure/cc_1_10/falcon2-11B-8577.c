//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: synchronous
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buf[1024];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        sockfd = accept(sockfd, (struct sockaddr *)&serv_addr, (socklen_t *)&n);
        if (sockfd < 0) {
            perror("accept");
            exit(1);
        }

        printf("Connected by client (%s, %d)\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

        while ((n = recv(sockfd, buf, sizeof(buf), 0)) > 0) {
            printf("Received message: %s\n", buf);
            send(sockfd, buf, n, 0);
        }

        close(sockfd);
        printf("Client (%s, %d) disconnected\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));
    }

    close(sockfd);
    return 0;
}