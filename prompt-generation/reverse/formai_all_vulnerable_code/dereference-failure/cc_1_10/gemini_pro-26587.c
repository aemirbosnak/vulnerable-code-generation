//GEMINI-pro DATASET v1.0 Category: Networking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

struct client_info {
    int sockfd;
    struct sockaddr_in addr;
};

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int clients = 0;

void *handle_client(void *arg) {
    struct client_info *client = (struct client_info *)arg;
    char buffer[1024];

    while (1) {
        // Read data from client
        int n = read(client->sockfd, buffer, sizeof(buffer));

        // Check for errors or if the client closed the connection
        if (n == 0) {
            // Client closed the connection
            pthread_mutex_lock(&lock);
            clients--;
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&lock);
            close(client->sockfd);
            free(client);
            return NULL;
        } else if (n < 0) {
            // Error reading data
            perror("read");
            close(client->sockfd);
            free(client);
            return NULL;
        }

        // Process data received from client

        // Write data back to client
        n = write(client->sockfd, buffer, n);

        // Check for errors or if the client closed the connection
        if (n == 0) {
            // Client closed the connection
            pthread_mutex_lock(&lock);
            clients--;
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&lock);
            close(client->sockfd);
            free(client);
            return NULL;
        } else if (n < 0) {
            // Error writing data
            perror("write");
            close(client->sockfd);
            free(client);
            return NULL;
        }
    }

    return NULL;
}

int main() {
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    pthread_t tid;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    // Bind the socket to an address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Start listening for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    // Main loop
    while (1) {
        // Accept an incoming connection
        client_addr_len = sizeof(client_addr);
        new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (new_sockfd < 0) {
            perror("accept");
            continue;
        }

        // Create a new thread to handle the client
        struct client_info *client = malloc(sizeof(struct client_info));
        client->sockfd = new_sockfd;
        client->addr = client_addr;
        pthread_create(&tid, NULL, handle_client, (void *)client);

        // Update client count
        pthread_mutex_lock(&lock);
        clients++;
        pthread_mutex_unlock(&lock);
    }

    // Close the server socket
    close(sockfd);

    return 0;
}