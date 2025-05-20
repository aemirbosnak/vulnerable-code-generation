//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: complex
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

#define MAX_SOCKETS 10

int main(int argc, char* argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    int client_len = sizeof(client_addr);
    char buffer[1024];
    int num_sockets = MAX_SOCKETS;
    int i;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_fd, num_sockets) < 0) {
        perror("listen");
        exit(1);
    }

    while (num_sockets > 0) {
        client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
        if (client_fd < 0) {
            perror("accept");
            exit(1);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            if (recv(client_fd, buffer, sizeof(buffer), 0) < 0) {
                perror("recv");
                exit(1);
            }

            printf("Received message: %s\n", buffer);

            if (strstr(buffer, "admin")!= NULL) {
                printf("Suspicious activity detected!\n");
                close(client_fd);
                exit(1);
            }
        }
    }

    close(server_fd);
    return 0;
}