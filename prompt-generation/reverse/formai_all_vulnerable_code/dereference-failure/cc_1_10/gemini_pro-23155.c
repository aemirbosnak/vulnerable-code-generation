//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 10
#define MAX_FILE_SIZE 1024

typedef struct {
    int sockfd;
    char ip[INET_ADDRSTRLEN];
    char filename[100];
} client_info_t;

client_info_t clients[MAX_CLIENTS];
int num_clients = 0;

void handle_client(client_info_t *client) {
    int n;
    char buffer[MAX_FILE_SIZE];

    // Receive the filename from the client
    n = recv(client->sockfd, client->filename, 100, 0);
    if (n <= 0) {
        perror("recv");
        close(client->sockfd);
        return;
    }

    // Open the file for writing
    FILE *fp = fopen(client->filename, "w");
    if (fp == NULL) {
        perror("fopen");
        close(client->sockfd);
        return;
    }

    // Receive the file data from the client
    while ((n = recv(client->sockfd, buffer, MAX_FILE_SIZE, 0)) > 0) {
        fwrite(buffer, 1, n, fp);
    }

    if (n < 0) {
        perror("recv");
    }

    // Close the file
    fclose(fp);

    // Send a message to the client to indicate that the file has been received
    n = send(client->sockfd, "File received", 13, 0);
    if (n < 0) {
        perror("send");
    }

    // Close the client socket
    close(client->sockfd);
}

int main() {
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    // Create the server socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind the server socket to the address
    if (bind(server_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections
    while (1) {
        client_addr_len = sizeof(client_addr);
        client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_sockfd < 0) {
            perror("accept");
            continue;
        }

        // Add the client to the list of clients
        if (num_clients < MAX_CLIENTS) {
           clients[num_clients].sockfd = client_sockfd;
           strcpy(clients[num_clients].ip, inet_ntoa(client_addr.sin_addr));
           num_clients++;

           // Handle the client in a separate thread
           pthread_t thread;
           pthread_create(&thread, NULL, (void *) handle_client, (void *) &clients[num_clients]);
        } else {
            // Send a message to the client to indicate that the server is full
            int n = send(client_sockfd, "Server is full", 14, 0);
            if (n < 0) {
                perror("send");
            }

            // Close the client socket
            close(client_sockfd);
        }
    }

    // Close the server socket
    close(server_sockfd);

    return 0;
}