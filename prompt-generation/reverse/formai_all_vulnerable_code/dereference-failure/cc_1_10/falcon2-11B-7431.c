//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: happy
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define SERVER_PORT 5000

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 1);

    while (1) {
        sockfd = accept(sockfd, NULL, NULL);
        if (sockfd < 0) {
            perror("accept");
            continue;
        }

        printf("Connected by client\n");
        bzero(buffer, 256);
        n = read(sockfd, buffer, 256);
        if (n <= 0) {
            perror("read");
            close(sockfd);
            continue;
        }
        buffer[n] = '\0';
        printf("Received: %s\n", buffer);
        bzero(buffer, 256);
        n = write(sockfd, buffer, 256);
        if (n <= 0) {
            perror("write");
            close(sockfd);
            continue;
        }
        printf("Sent: %s\n", buffer);
        close(sockfd);
    }

    return 0;
}