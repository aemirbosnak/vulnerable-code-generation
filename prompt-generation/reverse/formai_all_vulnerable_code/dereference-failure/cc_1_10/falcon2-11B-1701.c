//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define MAX_CONN 5

int main(int argc, char *argv[])
{
    int server_fd, new_socket, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    int opt = 1;

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("socket failed");
        exit(1);
    }

    // Force re-use of port number
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        perror("setsockopt");
        exit(1);
    }

    // Force re-use of port number
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt)) < 0)
    {
        perror("setsockopt");
        exit(1);
    }

    // Initialize server address struct
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind to the port
    if (bind(server_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    listen(server_fd, MAX_CONN);

    // Accept incoming connections
    while (1)
    {
        cli_addr.sin_family = AF_INET;
        cli_addr.sin_addr.s_addr = INADDR_ANY;
        cli_addr.sin_port = htons(0);

        // Accept new connections
        new_socket = accept(server_fd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
        if (new_socket < 0)
        {
            perror("accept failed");
            exit(1);
        }

        // Handle incoming requests
        printf("New connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        // Handle requests
        int c = 0;
        char *request = (char *) malloc(1024);
        read(new_socket, request, 1024);
        printf("Received request: %s\n", request);

        // Handle responses
        char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>";
        write(new_socket, response, strlen(response));
        free(request);
        close(new_socket);
    }

    return 0;
}