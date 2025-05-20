//Falcon2-11B DATASET v1.0 Category: Networking ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in serv_addr, cli_addr;
    int addrlen = sizeof(serv_addr);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&serv_addr, addrlen) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(server_fd, 5);

    if ((new_socket = accept(server_fd, (struct sockaddr *)&cli_addr, &addrlen)) < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    printf("Connected to %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    char buffer[256];
    int n;

    while ((n = recv(new_socket, buffer, sizeof(buffer), 0)) > 0) {
        printf("Received %d bytes: %s\n", n, buffer);
        send(new_socket, buffer, n, 0);
    }

    printf("Connection closed\n");

    close(new_socket);
    close(server_fd);

    return 0;
}