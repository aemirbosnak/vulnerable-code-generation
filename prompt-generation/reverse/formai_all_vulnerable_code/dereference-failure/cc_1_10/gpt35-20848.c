//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MY_PORT 8888
#define BUF_SIZE 4096

int is_valid_ip(char *ip_address)
{
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip_address, &(sa.sin_addr)) != 0;
}

int main(int argc, char **argv)
{
    int listen_sock, conn_sock;
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    char buffer[BUF_SIZE];
    ssize_t numbytes;

    if (argc != 2 || strcmp(argv[1], "--help") == 0)
    {
        fprintf(stderr, "Usage: %s <proxy-address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (!is_valid_ip(argv[1]))
    {
        fprintf(stderr, "Invalid IP address\n");
        exit(EXIT_FAILURE);
    }

    // Create a socket to listen for incoming connections.
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1)
    {
        fprintf(stderr, "Could not create socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Set socket options for reuse and listening.
    int opt = 1;
    if (setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        fprintf(stderr, "Error setting socket options: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a local address and port.
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(MY_PORT);
    if (bind(listen_sock, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        fprintf(stderr, "Could not bind socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections.
    if (listen(listen_sock, 10) == -1)
    {
        fprintf(stderr, "Error listening for connections: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Simple HTTP Proxy listening on %s:%d\n", inet_ntoa(addr.sin_addr), MY_PORT);
    printf("Proxy address: %s\n", argv[1]);

    while (1)
    {
        // Accept an incoming connection.
        conn_sock = accept(listen_sock, (struct sockaddr *)&addr, &addrlen);
        if (conn_sock == -1)
        {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            continue;
        }
        printf("Accepted connection from %s:%d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
        bzero(buffer, BUF_SIZE);
    
        // Read the HTTP request from the client.
        numbytes = read(conn_sock, buffer, BUF_SIZE);
        if (numbytes == -1)
        {
            fprintf(stderr, "Error reading from client socket: %s\n", strerror(errno));
            close(conn_sock);
            continue;
        }
        printf("Received %zd bytes from client:\n%s\n", numbytes, buffer);
  
        // Parse the HTTP request to get the request URL.
        char *host = strtok(buffer+11, "/");
        char *port = strtok(NULL, ":");
        if (port == NULL)
        {
            port = "80";
        }
        char *path = strtok(NULL, "\r\n");
        if (path == NULL)
        {
            path = "/";
        }
        printf("Parsed request: host=%s port=%s path=%s\n", host, port, path);
     
        // Resolve the request URL to an IP address.
        struct addrinfo hints, *res;
        bzero(&hints, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        if (getaddrinfo(host, port, &hints, &res) != 0)
        {
            fprintf(stderr, "Error resolving host %s:%s: %s\n", host, port, strerror(errno));
            close(conn_sock);
            continue;
        }
        struct sockaddr_in *server = (struct sockaddr_in *)res->ai_addr;
        char server_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &server->sin_addr, server_ip, INET_ADDRSTRLEN);
        printf("Resolved host %s:%s to IP address %s\n", host, port, server_ip);

        // Create a socket to connect to the remote server.
        int server_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sock == -1)
        {
            fprintf(stderr, "Could not create socket: %s\n", strerror(errno));
            close(conn_sock);
            continue;
        }

        // Connect to the remote server.
        if (connect(server_sock, (struct sockaddr *)server, sizeof(*server)) == -1)
        {
            fprintf(stderr, "Could not connect to server %s:%s: %s\n", server_ip, port, strerror(errno));
            close(server_sock);
            close(conn_sock);
            continue;
        }
        printf("Connected to server %s:%s\n", server_ip, port);

        // Forward the HTTP request to the remote server.
        if (write(server_sock, buffer, numbytes) == -1)
        {
            fprintf(stderr, "Error writing to server socket: %s\n", strerror(errno));
            close(server_sock);
            close(conn_sock);
            continue;
        }

        // Forward the response from the remote server to the client.
        bzero(buffer, BUF_SIZE);
        while ((numbytes = read(server_sock, buffer, BUF_SIZE)) > 0)
        {
            if (write(conn_sock, buffer, numbytes) == -1)
            {
                fprintf(stderr, "Error writing to client socket: %s\n", strerror(errno));
                close(server_sock);
                close(conn_sock);
                break;
            }
            bzero(buffer, BUF_SIZE);
        }

        // Clean up the sockets.
        close(server_sock);
        close(conn_sock);
    }

    return 0;
}