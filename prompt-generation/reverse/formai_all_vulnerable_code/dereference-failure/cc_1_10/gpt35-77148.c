//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT "8080" // Port number for proxy server

void proxy(int client_fd);

int main()
{
    int server_fd, client_fd;
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET; // Use IPv4
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(NULL, PORT, &hints, &res) != 0)
    {
        fprintf(stderr, "getaddrinfo failed\n");
        exit(1);
    }

    server_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (server_fd == -1)
    {
        fprintf(stderr, "socket failed\n");
        exit(1);
    }

    if (bind(server_fd, res->ai_addr, res->ai_addrlen) == -1)
    {
        fprintf(stderr, "bind failed\n");
        exit(1);
    }

    if (listen(server_fd, 10) == -1) // Maximum 10 connections 
    {
        fprintf(stderr, "listen failed\n");
        exit(1);
    }

    printf("Proxy server running on port %s\n", PORT);

    while (1) // Infinite loop to keep listening
    {
        struct sockaddr_storage client_addr;
        socklen_t client_addr_len = sizeof client_addr;
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);

        if (client_fd == -1)
        {
            fprintf(stderr, "accept failed\n");
            continue;
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(client_addr.ss_family, &(((struct sockaddr_in *)&client_addr)->sin_addr), client_ip, sizeof client_ip);
        printf("New connection from %s on socket %d\n", client_ip, client_fd);

        // Fork a new process to handle client's request
        if (fork() == 0)
        {
            close(server_fd);
            proxy(client_fd);
            close(client_fd);
            exit(0);
        }

        close(client_fd);
    }

    return 0;
}

void proxy(int client_fd)
{
    char buffer[1024], request[1024], response[1024];

    if (recv(client_fd, buffer, sizeof buffer, 0) == -1)
    {
        fprintf(stderr, "recv failed\n");
        return;
    }

    sscanf(buffer, "%s", request);

    if (strcmp(request, "GET") != 0 && strcmp(request, "POST") != 0)
    {
        fprintf(stderr, "Unsupported HTTP method\n");
        return;
    }

    // Find the server's IP address
    char *url = strtok(buffer, " ");
    url = strtok(NULL, " ");
    char *server_ip;
    struct hostent *he;
    he = gethostbyname(url);
    if (he == NULL)
    {
        fprintf(stderr, "gethostbyname failed\n");
        return;
    }
    server_ip = inet_ntoa(*(struct in_addr *)he->h_addr);

    // Create a new socket to connect to server
    int server_fd;
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // Port 80 for HTTP
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        fprintf(stderr, "socket failed\n");
        return;
    }

    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof server_addr) == -1)
    {
        fprintf(stderr, "connect failed\n");
        return;
    }

    // Forward the client's request to server
    if (send(server_fd, buffer, strlen(buffer), 0) == -1)
    {
        fprintf(stderr, "send failed\n");
        return;
    }

    // Receive server's response and forward it to client
    while (recv(server_fd, response, sizeof response, 0) > 0)
    {
        if (send(client_fd, response, strlen(response), 0) == -1)
        {
            fprintf(stderr, "send failed\n");
            return;
        }
    }

    close(server_fd);
}