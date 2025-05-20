//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[256];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s on port %d\n", argv[1], portno);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        printf("Enter a message to send: ");
        fgets(buffer, sizeof(buffer), stdin);

        if (strcmp(buffer, "quit\n") == 0) {
            break;
        }

        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("send");
            exit(1);
        }

        memset(buffer, 0, sizeof(buffer));
        if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
            perror("recv");
            exit(1);
        }

        printf("Server says: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}