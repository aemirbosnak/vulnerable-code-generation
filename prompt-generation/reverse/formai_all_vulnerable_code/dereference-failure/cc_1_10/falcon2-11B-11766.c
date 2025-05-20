//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024

int main() {

    int sockfd, new_socket;
    struct sockaddr_in serv_addr, cli_addr;
    int addrlen;
    char buff[BUFF_SIZE];
    char *msg;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    listen(sockfd, 5);

    addrlen = sizeof(cli_addr);
    new_socket = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);
    if (new_socket < 0) {
        perror("Error on accepting");
        exit(1);
    }

    while (1) {
        bzero(buff, BUFF_SIZE);
        bzero(&cli_addr, sizeof(cli_addr));

        recv(new_socket, buff, BUFF_SIZE, 0);
        msg = strtok(buff, "\n");

        printf("Client: %s\n", msg);
        msg = strtok(NULL, "\n");

        if (!strcmp(msg, "quit")) {
            close(new_socket);
            break;
        }

        send(new_socket, buff, BUFF_SIZE, 0);
    }

    close(new_socket);
    close(sockfd);

    return 0;
}