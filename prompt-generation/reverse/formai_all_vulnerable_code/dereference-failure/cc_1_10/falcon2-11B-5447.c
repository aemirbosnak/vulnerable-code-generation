//Falcon2-11B DATASET v1.0 Category: QR code generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_fd, new_socket, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("ERROR opening socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("ERROR on binding");
        return 1;
    }

    if (listen(sockfd, MAX_CLIENTS) == -1) {
        perror("ERROR on listen");
        return 1;
    }

    while (1) {
        addr_size = sizeof(client_addr);
        conn_fd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_size);
        if (conn_fd == -1) {
            perror("ERROR on accept");
            continue;
        }

        printf("New connection from %s\n", inet_ntoa(client_addr.sin_addr));
        fgets(buffer, BUFFER_SIZE, stdin);
        send(conn_fd, buffer, strlen(buffer), 0);
        close(conn_fd);
    }

    close(sockfd);
    return 0;
}