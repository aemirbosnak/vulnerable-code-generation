//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

#define BUF_SIZE 512
#define PORT 8080

// Structure to hold the client's information
typedef struct {
    int client_fd;
    char client_ip[INET_ADDRSTRLEN];
    char request[BUF_SIZE];
    char response[BUF_SIZE];
    int response_len;
} ClientInfo;

// Handler for SIGINT signal
void handle_sigint(int sig) {
    printf("Received SIGINT, exiting...\n");
    exit(0);
}

void handle_client_connection(ClientInfo* client) {
    int n;
    char response[BUF_SIZE];
    char* hello = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    char* index = "<html><body><h1>Hello, World!</h1></body></html>";

    // Send response
    n = send(client->client_fd, hello, strlen(hello), 0);
    if (n < 0) {
        perror("send");
        exit(1);
    }
    n = send(client->client_fd, index, strlen(index), 0);
    if (n < 0) {
        perror("send");
        exit(1);
    }

    // Receive request
    memset(client->request, 0, sizeof(client->request));
    n = recv(client->client_fd, client->request, sizeof(client->request), 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }
    client->response_len = snprintf(client->response, sizeof(client->response), "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n%s", index);

    // Send response
    n = send(client->client_fd, client->response, client->response_len, 0);
    if (n < 0) {
        perror("send");
        exit(1);
    }

    // Close client connection
    close(client->client_fd);
}

int main() {
    int server_fd, listen_fd, client_fd, n;
    struct sockaddr_in server_addr, client_addr;
    char* hostname = "127.0.0.1";
    int opt = 1;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(hostname);
    server_addr.sin_port = htons(PORT);

    // Bind server socket
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for client connections
    if (listen(server_fd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept client connections
    while (1) {
        // Accept client connection
        if ((client_fd = accept(listen_fd, (struct sockaddr*)&client_addr, (socklen_t*)&n)) < 0) {
            perror("accept");
            exit(1);
        }

        // Create client structure
        ClientInfo* client = (ClientInfo*)malloc(sizeof(ClientInfo));
        client->client_fd = client_fd;
        strcpy(client->client_ip, inet_ntoa(client_addr.sin_addr));
        memset(client->request, 0, sizeof(client->request));
        memset(client->response, 0, sizeof(client->response));
        client->response_len = 0;

        // Handle client connection
        handle_client_connection(client);

        // Clean up client structure
        free(client);
    }

    return 0;
}