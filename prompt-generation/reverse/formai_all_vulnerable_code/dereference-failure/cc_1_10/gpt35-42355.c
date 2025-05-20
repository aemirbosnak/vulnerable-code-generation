//FormAI DATASET v1.0 Category: Networking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 256

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    char* port = argv[1];
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("Failed to create socket");
        exit(1);
    }

    int opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(atoi(port));

    if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0)
    {
        perror("Failed to bind socket");
        exit(1);
    }

    if (listen(sock, 5) < 0)
    {
        perror("Failed to listen on socket");
        exit(1);
    }

    while(1)
    {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0)
        {
            perror("Failed to accept client connection");
            exit(1);
        }

        char buf[BUF_SIZE];
        ssize_t bytes_read = read(client_sock, buf, BUF_SIZE - 1);
        if (bytes_read < 0)
        {
            perror("Failed to read data from client socket");
            exit(1);
        }

        buf[bytes_read] = '\0';
        printf("Received message from client: %s\n", buf);

        char* response = "Hello from server!";
        ssize_t bytes_written = write(client_sock, response, strlen(response));
        if (bytes_written < 0)
        {
            perror("Failed to write response to client socket");
            exit(1);
        }

        close(client_sock);
    }

    close(sock);

    return 0;
}