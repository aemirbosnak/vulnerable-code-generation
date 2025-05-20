//MISTRAL-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: multiplayer
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char const *argv[]) {
    int sockfd_server, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char buffer[BUFFER_SIZE];
    int player = 1;

    if ((sockfd_server = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        die("socket");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd_server, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        die("bind");

    listen(sockfd_server, 3);

    while (1) {
        client_len = sizeof(client_addr);
        new_sockfd = accept(sockfd_server, (struct sockaddr *)&client_addr, &client_len);

        if (new_sockfd < 0)
            die("accept");

        printf("Player %d connected\n", player++ % 2);

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            if (recv(new_sockfd, buffer, BUFFER_SIZE, 0) < 0) {
                if (errno != EAGAIN)
                    die("recv");
                break;
            }

            printf("Received: %s\n", buffer);

            if (send(new_sockfd, "Hello, Player!", 13, 0) < 0)
                die("send");
        }

        close(new_sockfd);
    }

    close(sockfd_server);
    return 0;
}