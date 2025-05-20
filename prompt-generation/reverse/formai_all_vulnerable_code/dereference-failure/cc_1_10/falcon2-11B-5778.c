//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <email>\n", argv[0]);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    struct sockaddr_in server;
    int socket_fd, n;

    bzero((char *)&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(socket_fd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect");
        exit(1);
    }

    if (send(socket_fd, argv[1], strlen(argv[1]), 0) == -1) {
        perror("send");
        exit(1);
    }

    while ((n = recv(socket_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("%s\n", buffer);
        bzero(buffer, BUFFER_SIZE);
    }

    close(socket_fd);
    return 0;
}