//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char hostname[256];
    int port = atoi(argv[2]);
    strcpy(hostname, argv[1]);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    int yes = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));

    int on = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &on, sizeof(on));

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect");
        return 1;
    }

    char buffer[1024];
    while (1) {
        int n = read(sockfd, buffer, sizeof(buffer));
        if (n <= 0) {
            perror("read");
            break;
        }

        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}