//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

struct client {
    int sockfd;
    struct sockaddr_in addr;
    socklen_t addr_len;
};

struct server {
    int sockfd;
    struct sockaddr_in addr;
    socklen_t addr_len;
};

int create_client_socket(char *host, int port)
{
    int sockfd;
    struct hostent *host_info;
    struct sockaddr_in addr;

    host_info = gethostbyname(host);
    if (host_info == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", host);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: Could not create socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *(struct in_addr *)host_info->h_addr_list[0];

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Error: Could not connect to server");
        exit(1);
    }

    return sockfd;
}

struct server *create_server_socket(int port)
{
    struct server *server;
    int sockfd;
    struct sockaddr_in addr;

    server = malloc(sizeof(struct server));
    if (server == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for server\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: Could not create socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Error: Could not bind socket");
        exit(1);
    }

    if (listen(sockfd, 5) == -1) {
        perror("Error: Could not listen on socket");
        exit(1);
    }

    server->sockfd = sockfd;
    server->addr = addr;
    server->addr_len = sizeof(addr);

    return server;
}

void handle_client(struct client *client)
{
    char buffer[1024];
    int n;

    while (1) {
        n = recv(client->sockfd, buffer, sizeof(buffer), 0);
        if (n == -1) {
            perror("Error: Could not receive data from client");
            break;
        } else if (n == 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("Received %d bytes from client\n", n);

        // Parse the HTTP request
        char *method = strtok(buffer, " ");
        char *path = strtok(NULL, " ");
        char *version = strtok(NULL, "\r\n");

        printf("Method: %s\n", method);
        printf("Path: %s\n", path);
        printf("Version: %s\n", version);

        // Check if the path is valid
        if (strcmp(path, "/") != 0) {
            send(client->sockfd, "HTTP/1.1 404 Not Found\r\n\r\n", 28, 0);
            break;
        }

        // Create a new socket to connect to the server
        int server_sockfd = create_client_socket("example.com", 80);

        // Send the HTTP request to the server
        send(server_sockfd, buffer, n, 0);

        // Receive the HTTP response from the server
        while (1) {
            n = recv(server_sockfd, buffer, sizeof(buffer), 0);
            if (n == -1) {
                perror("Error: Could not receive data from server");
                break;
            } else if (n == 0) {
                printf("Server disconnected\n");
                break;
            }

            // Send the HTTP response to the client
            send(client->sockfd, buffer, n, 0);
        }

        close(server_sockfd);
    }

    close(client->sockfd);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    // Create a server socket
    struct server *server = create_server_socket(port);

    // Listen for incoming client connections
    while (1) {
        struct client client;

        client.addr_len = sizeof(client.addr);
        client.sockfd = accept(server->sockfd, (struct sockaddr *)&client.addr, &client.addr_len);
        if (client.sockfd == -1) {
            perror("Error: Could not accept client connection");
            continue;
        }

        printf("Client connected from %s:%d\n", inet_ntoa(client.addr.sin_addr), ntohs(client.addr.sin_port));

        // Handle the client in a separate thread
        pthread_t thread;
        pthread_create(&thread, NULL, (void *(*)(void *))handle_client, &client);
    }

    close(server->sockfd);
    free(server);

    return 0;
}