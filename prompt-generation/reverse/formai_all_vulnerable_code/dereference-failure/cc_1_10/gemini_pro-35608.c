//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define BUFSIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} client_t;

void* handle_client(void* arg) {
    client_t* client = (client_t*)arg;
    int clientfd = client->sockfd;
    struct sockaddr_in* clientaddr = &client->addr;

    char buf[BUFSIZE];
    int nread;

    while ((nread = read(clientfd, buf, BUFSIZE)) > 0) {
        // Parse the HTTP request
        char* method = strtok(buf, " ");
        char* path = strtok(NULL, " ");
        char* http_version = strtok(NULL, "\r\n");

        // Check if the request is valid
        if (strcmp(method, "GET") != 0 || strcmp(http_version, "HTTP/1.1") != 0) {
            // Send a 400 Bad Request response
            char* response = "HTTP/1.1 400 Bad Request\r\nContent-Length: 0\r\n\r\n";
            write(clientfd, response, strlen(response));
            break;
        }

        // Extract the hostname from the path
        char* hostname = strtok(path, "/");

        // Connect to the remote server
        int remotefd = socket(AF_INET, SOCK_STREAM, 0);
        if (remotefd == -1) {
            // Send a 500 Internal Server Error response
            char* response = "HTTP/1.1 500 Internal Server Error\r\nContent-Length: 0\r\n\r\n";
            write(clientfd, response, strlen(response));
            break;
        }

        struct sockaddr_in remoteaddr;
        memset(&remoteaddr, 0, sizeof(remoteaddr));
        remoteaddr.sin_family = AF_INET;
        remoteaddr.sin_port = htons(80);
        if (inet_pton(AF_INET, hostname, &remoteaddr.sin_addr) <= 0) {
            // Send a 404 Not Found response
            char* response = "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n";
            write(clientfd, response, strlen(response));
            break;
        }

        if (connect(remotefd, (struct sockaddr*)&remoteaddr, sizeof(remoteaddr)) == -1) {
            // Send a 500 Internal Server Error response
            char* response = "HTTP/1.1 500 Internal Server Error\r\nContent-Length: 0\r\n\r\n";
            write(clientfd, response, strlen(response));
            break;
        }

        // Forward the request to the remote server
        write(remotefd, buf, nread);

        // Read the response from the remote server
        while ((nread = read(remotefd, buf, BUFSIZE)) > 0) {
            // Forward the response to the client
            write(clientfd, buf, nread);
        }

        // Close the connection to the remote server
        close(remotefd);
    }

    // Close the connection to the client
    close(clientfd);

    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);

    // Create a listening socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Bind the listening socket to the specified port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Start listening for incoming connections
    if (listen(sockfd, SOMAXCONN) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept incoming connections and handle them in a separate thread
    while (1) {
        client_t client;
        socklen_t addrlen = sizeof(client.addr);
        client.sockfd = accept(sockfd, (struct sockaddr*)&client.addr, &addrlen);
        if (client.sockfd == -1) {
            perror("accept");
            continue;
        }

        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, &client) != 0) {
            perror("pthread_create");
            close(client.sockfd);
            continue;
        }

        pthread_detach(tid);
    }

    // Close the listening socket
    close(sockfd);

    return EXIT_SUCCESS;
}