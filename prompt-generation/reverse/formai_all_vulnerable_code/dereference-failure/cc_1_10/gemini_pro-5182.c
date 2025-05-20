//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFSIZE 4096

// Default configuration
#define PROXY_PORT 8080
#define MAX_CLIENTS 10

// Customizable configuration struct
typedef struct {
    int proxy_port;
    int max_clients;
} config_t;

// Global configuration
config_t config = {
    .proxy_port = PROXY_PORT,
    .max_clients = MAX_CLIENTS,
};

// Function to handle client connections
void *handle_client(void *arg) {
    int client_sock = (int)arg;

    char buf[BUFSIZE];
    int recv_len;

    // Read HTTP request from client
    recv_len = recv(client_sock, buf, BUFSIZE, 0);
    if (recv_len <= 0) {
        perror("recv");
        close(client_sock);
        return NULL;
    }

    // Parse HTTP request to get destination host and path
    char *host_start = strstr(buf, "Host: ");
    if (!host_start) {
        fprintf(stderr, "Invalid HTTP request: missing Host header\n");
        close(client_sock);
        return NULL;
    }

    char *host_end = strchr(host_start, '\r');
    if (!host_end) {
        fprintf(stderr, "Invalid HTTP request: missing Host header terminator\n");
        close(client_sock);
        return NULL;
    }

    char host[host_end - host_start];
    strncpy(host, host_start + 6, host_end - host_start - 6);

    char *path_start = strstr(buf, "GET ");
    if (!path_start) {
        fprintf(stderr, "Invalid HTTP request: missing GET method\n");
        close(client_sock);
        return NULL;
    }

    char *path_end = strchr(path_start, ' ');
    if (!path_end) {
        fprintf(stderr, "Invalid HTTP request: missing GET path terminator\n");
        close(client_sock);
        return NULL;
    }

    char path[path_end - path_start];
    strncpy(path, path_start + 4, path_end - path_start - 4);

    // Connect to destination host
    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(80);
    dest_addr.sin_addr.s_addr = inet_addr(host);

    int dest_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (dest_sock == -1) {
        perror("socket");
        close(client_sock);
        return NULL;
    }

    if (connect(dest_sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) == -1) {
        perror("connect");
        close(client_sock);
        close(dest_sock);
        return NULL;
    }

    // Forward HTTP request to destination host
    send(dest_sock, buf, recv_len, 0);

    // Receive HTTP response from destination host
    while ((recv_len = recv(dest_sock, buf, BUFSIZE, 0)) > 0) {
        send(client_sock, buf, recv_len, 0);
    }

    if (recv_len == -1) {
        perror("recv");
    }

    // Close connections
    close(client_sock);
    close(dest_sock);

    return NULL;
}

// Main function
int main(int argc, char **argv) {
    // Parse command-line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-p") == 0) {
            config.proxy_port = atoi(argv[i + 1]);
            i++;
        } else if (strcmp(argv[i], "-c") == 0) {
            config.max_clients = atoi(argv[i + 1]);
            i++;
        } else {
            fprintf(stderr, "Invalid argument: %s\n", argv[i]);
            return 1;
        }
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Bind socket to address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(config.proxy_port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        close(sockfd);
        return 1;
    }

    // Listen for connections
    if (listen(sockfd, config.max_clients) == -1) {
        perror("listen");
        close(sockfd);
        return 1;
    }

    // Accept connections and spawn threads to handle them
    while (1) {
        int client_sock = accept(sockfd, NULL, NULL);
        if (client_sock == -1) {
            perror("accept");
            continue;
        }

        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, (void *)client_sock) != 0) {
            perror("pthread_create");
            close(client_sock);
            continue;
        }
    }

    // Close socket
    close(sockfd);

    return 0;
}