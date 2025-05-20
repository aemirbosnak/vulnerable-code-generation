//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    listen(server_fd, 5);

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&cli_addr, (socklen_t*)&valread);
        if (new_socket < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connected by client with address: %s\n", inet_ntoa(cli_addr.sin_addr));

        char buffer[1024];
        valread = read(new_socket, buffer, sizeof(buffer));
        printf("Received: %s\n", buffer);

        valread = write(new_socket, "Hello from server!", 18);
        if (valread < 0) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        close(new_socket);
    }

    return 0;
}