//MISTRAL-7B DATASET v1.0 Category: Chat server ; Style: rigorous
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define MAXLINE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAXLINE] = {0};
    char *hello = "Welcome to C Chat Server!\n";

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <Port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        error("socket failed");

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt)))
        error("setsockopt");

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
        error("bind failed");

    if (listen(server_fd, 3) < 0)
        error("listen");

    printf("Server listening on port %s\n", argv[1]);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t *)&addrlen)) < 0) {
            error("accept");
        }

        valread = read(new_socket, buffer, MAXLINE);
        buffer[valread] = '\0';
        printf("Client: %s", buffer);

        send(new_socket, hello, strlen(hello), 0);
        printf("Server: %s", hello);

        close(new_socket);
    }

    return 0;
}