//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define BACKLOG 5
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, new_socket;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(cli_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("socket failed");
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        error("no such host");
    }

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("bind failed");
    }

    listen(sockfd, BACKLOG);

    while (1) {
        new_socket = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            error("accept");
        }
        printf("New connection\n");
        send(new_socket, "Welcome to the server\n", strlen("Welcome to the server\n"), 0);
        close(new_socket);
    }

    return 0;
}