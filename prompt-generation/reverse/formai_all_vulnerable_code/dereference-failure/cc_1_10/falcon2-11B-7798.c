//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int server_fd, port_no, new_socket;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t len;

    if (argc!= 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port_no = atoi(argv[1]);
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_no);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(1);
    }

    len = sizeof(client_addr);
    new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &len);

    if (new_socket < 0) {
        perror("accept");
        exit(1);
    }

    char buffer[1024];
    int bytes_read = 0;

    while (1) {
        bytes_read = recv(new_socket, buffer, sizeof(buffer), 0);

        if (bytes_read < 0) {
            perror("recv");
            exit(1);
        }

        printf("Client: %s\n", buffer);

        memset(buffer, 0, sizeof(buffer));
        bytes_read = send(new_socket, buffer, sizeof(buffer), 0);

        if (bytes_read < 0) {
            perror("send");
            exit(1);
        }

        printf("Server: %s\n", buffer);
    }

    return 0;
}