//FormAI DATASET v1.0 Category: Simple Web Server ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>

#define PORT_NUM 8080
#define MAX_CONN 64
#define BUF_SIZE 512

int main()
{
    int server_fd, conn_fd, n;
    char buffer[BUF_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    memset(buffer, 0, sizeof(buffer));

    // Create a socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0)
    {
        fprintf(stderr, "Failed to create socket. Error code: %s\n", strerror(errno));
        exit(-1);
    }

    // Set socket options for reusability
    int option = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option)))
    {
        perror("setsockopt failed");
        exit(1);
    }

    // Set server address parameters
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT_NUM);

    // Bind socket to IP Address and Port Number
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        fprintf(stderr, "Failed to bind. Error code: %s\n", strerror(errno));
        exit(-1);
    }

    // Listen for connections
    if (listen(server_fd, MAX_CONN) < 0)
    {
        fprintf(stderr, "Failed to listen. Error code: %s\n", strerror(errno));
        exit(-1);
    }

    printf("Server is listening at port %d...\n", PORT_NUM);

    while (1)
    {
        // Accept incoming connections
        conn_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);

        if (conn_fd < 0)
        {
            fprintf(stderr, "Failed to accept. Error code: %s\n", strerror(errno));
            exit(-1);
        }

        memset(buffer, 0, sizeof(buffer));

        // Read incoming client requests
        n = read(conn_fd, buffer, sizeof(buffer));

        if (n < 0)
        {
            fprintf(stderr, "Failed to read. Error code: %s\n", strerror(errno));
            exit(-1);
        }

        // Print client request message
        printf("Request Message: %s\n", buffer);

        // Send response message
        char *message = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, World!</h1>";
        write(conn_fd, message, strlen(message));

        // Close client socket connection
        close(conn_fd);
    }

    // Close server socket connection
    close(server_fd);

    return 0;
}