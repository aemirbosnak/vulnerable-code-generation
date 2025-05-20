//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

void die(const char *error)
{
    perror(error);
    exit(EXIT_FAILURE);
}

int main()
{
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[BUFFER_SIZE];
    int opt = TRUE;
    int client_count = 0;

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1)
        die("socket failed");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        die("bind failed");

    if (listen(listen_socket, BACKLOG) == -1)
        die("listen failed");

    while (opt)
    {
        addr_size = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addr_size);
        if (client_socket == -1)
        {
            if (errno == EINTR)
                continue;
            else
                die("accept failed");
        }
        printf("Client %d connected\n", ++client_count);
        send(client_socket, "Welcome to the server\n", strlen("Welcome to the server\n"), 0);
        close(client_socket);
    }

    close(listen_socket);
    return 0;
}