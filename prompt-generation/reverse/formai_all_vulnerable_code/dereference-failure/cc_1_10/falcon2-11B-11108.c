//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: portable
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[256];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        return 1;
    }

    listen(sockfd, 5);

    while (1) {
        sockfd = accept(sockfd, (struct sockaddr *)NULL, NULL);
        if (sockfd < 0) {
            perror("accept");
            return 1;
        }

        printf("Connection from %s port %d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));
        fflush(stdout);

        recv(sockfd, buffer, sizeof(buffer), 0);
        printf("Received: %s\n", buffer);
        fflush(stdout);

        send(sockfd, "Hello, world!", 14, 0);
        fflush(stdout);

        close(sockfd);
        break;
    }

    return 0;
}