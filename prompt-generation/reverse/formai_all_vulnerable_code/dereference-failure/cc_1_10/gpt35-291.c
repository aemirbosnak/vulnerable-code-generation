//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFSIZE 4096

char* SERVER_IP;
int SERVER_PORT;
int CLIENT_PORT;

// A struct to hold client data
struct client_struct {
    int client_sockfd;
    struct sockaddr_in client_addr;
};

// Function to handle client connection
void* handle_client(void* client_ptr) {
    int client_sockfd = ((struct client_struct*)client_ptr)->client_sockfd;
    struct sockaddr_in client_addr = ((struct client_struct*)client_ptr)->client_addr;
    free(client_ptr);

    char buffer[BUFSIZE];
    memset(buffer, 0, BUFSIZE);

    // Create server socket
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("Error creating socket");
        close(client_sockfd);
        return NULL;
    }

    // Connect to server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        close(client_sockfd);
        close(server_sockfd);
        return NULL;
    }

    // Forward data between client and server
    while (true) {
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(client_sockfd, &fds);
        FD_SET(server_sockfd, &fds);

        int max_fd = client_sockfd > server_sockfd ? client_sockfd : server_sockfd;

        if (select(max_fd + 1, &fds, NULL, NULL, NULL) < 0) {
            perror("Error in select()");
            break;
        }

        if (FD_ISSET(client_sockfd, &fds)) {
            ssize_t bytes_received = recv(client_sockfd, buffer, BUFSIZE, 0);
            if (bytes_received <= 0) {
                break;
            }
            send(server_sockfd, buffer, bytes_received, 0);
        }

        if (FD_ISSET(server_sockfd, &fds)) {
            ssize_t bytes_received = recv(server_sockfd, buffer, BUFSIZE, 0);
            if (bytes_received <= 0) {
                break;
            }
            send(client_sockfd, buffer, bytes_received, 0);
        }
    }

    close(client_sockfd);
    close(server_sockfd);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <server_ip> <server_port> <client_port>\n", argv[0]);
        return 1;
    }

    SERVER_IP = argv[1];
    SERVER_PORT = atoi(argv[2]);
    CLIENT_PORT = atoi(argv[3]);

    // Create client listening socket
    int client_listen_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_listen_sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Bind to client port
    struct sockaddr_in client_listen_addr;
    memset(&client_listen_addr, 0, sizeof(client_listen_addr));
    client_listen_addr.sin_family = AF_INET;
    client_listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    client_listen_addr.sin_port = htons(CLIENT_PORT);

    if (bind(client_listen_sockfd, (struct sockaddr*)&client_listen_addr, sizeof(client_listen_addr)) < 0) {
        perror("Error binding to port");
        return 1;
    }

    // Listen for incoming connections
    if (listen(client_listen_sockfd, 5) < 0) {
        perror("Error listening for connections");
        return 1;
    }

    printf("Proxy running on port %d\n", CLIENT_PORT);

    // Accept incoming connections indefinitely and spawn threads to handle them
    while (true) {
        int client_sockfd = accept(client_listen_sockfd, NULL, NULL);
        if (client_sockfd < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Spawn thread to handle client
        pthread_t thread;
        struct client_struct* client_ptr = malloc(sizeof(struct client_struct));
        client_ptr->client_sockfd = client_sockfd;
        client_ptr->client_addr = client_listen_addr;

        if (pthread_create(&thread, NULL, handle_client, client_ptr) != 0) {
            perror("Error creating thread");
            free(client_ptr);
            close(client_sockfd);
        }
    }

    close(client_listen_sockfd);
    return 0;
}