//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: Ken Thompson
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <port> <username>\n", argv[0]);
        return 1;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname %s\n", argv[1]);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    char buffer[1024];
    while (true) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }

        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("send");
            break;
        }

        if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
            perror("recv");
            break;
        }

        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}