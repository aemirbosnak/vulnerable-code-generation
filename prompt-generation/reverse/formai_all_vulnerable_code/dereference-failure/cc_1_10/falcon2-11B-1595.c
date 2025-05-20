//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ioctl.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, new_socket, ch, n;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    if (argc!= 3) {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting to server");
        exit(1);
    }

    bzero(&client_addr, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(PORT);
    client_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
        perror("ERROR binding socket");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        new_socket = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (new_socket < 0) {
            perror("ERROR accepting connection");
            exit(1);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        ch = fork();
        if (ch < 0) {
            perror("ERROR forking");
            exit(1);
        } else if (ch == 0) {
            close(sockfd);
            dup2(new_socket, 0);
            dup2(new_socket, 1);
            dup2(new_socket, 2);
            close(new_socket);
            execvp(argv[1], argv);
            perror("ERROR executing client");
            exit(1);
        }
    }

    return 0;
}