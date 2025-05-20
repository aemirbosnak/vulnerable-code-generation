//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define BUFFER_SIZE 4096
#define DEFAULT_PORT 8080
#define MAX_CONNECTIONS 1024

void *handle_http_request(void *arg);
void handle_client_request(int client_sockfd);
int establish_server_socket(in_addr_t addr, in_port_t port);
int establish_client_socket(in_addr_t addr, in_port_t port);
void send_data(int sockfd, const char *buf, size_t len);
ssize_t receive_data(int sockfd, char *buf, size_t len, int flags);

int main(int argc, char *argv[]) {
    // Parse command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <proxy-server-addr>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get proxy server IP address
    struct hostent *host_info = gethostbyname(argv[1]);
    if (host_info == NULL) {
        fprintf(stderr, "Error looking up IP address for %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Get server and client sockets
    in_addr_t server_addr = ((struct in_addr *) host_info->h_addr_list[0])->s_addr;
    in_port_t server_port = DEFAULT_PORT;
    int server_sockfd = establish_server_socket(INADDR_ANY, server_port);
    if (server_sockfd == -1) {
        fprintf(stderr, "Error establishing server socket!\n");
        return EXIT_FAILURE;
    }

    printf("HTTP proxy server running on port %d...\n", server_port);

    // Accept incoming connections
    int client_sockfd;
    pthread_t thread_id;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    while ((client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, &client_addr_len)) != -1) {
        printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle client request in a separate thread
        if (pthread_create(&thread_id, NULL, handle_http_request, (void *) client_sockfd) != 0) {
            fprintf(stderr, "Error creating thread to handle HTTP request!\n");
            close(client_sockfd);
        }
    }

    fprintf(stderr, "Error accepting incoming connection!\n");
    return EXIT_FAILURE;
}

void *handle_http_request(void *arg) {
    int client_sockfd = (int) arg;
    handle_client_request(client_sockfd);
    close(client_sockfd);
    pthread_exit(NULL);
}

void handle_client_request(int client_sockfd) {
    // Receive client request
    char request_buf[BUFFER_SIZE];
    ssize_t request_len = receive_data(client_sockfd, request_buf, BUFFER_SIZE, 0);
    if (request_len == -1 || request_len == 0) {
        fprintf(stderr, "Error receiving client request!\n");
        return;
    }

    // Parse client request
    char method_buf[BUFFER_SIZE], url_buf[BUFFER_SIZE], version_buf[BUFFER_SIZE];
    if (sscanf(request_buf, "%s %s %s", method_buf, url_buf, version_buf) != 3) {
        fprintf(stderr, "Error parsing client request!\n");
        return;
    }

    // Remove "http://" prefix from URL
    char host_buf[BUFFER_SIZE], path_buf[BUFFER_SIZE];
    if (sscanf(url_buf, "http://%s", host_buf) == 1) {
        strcpy(path_buf, url_buf + 7);
    }
    else {
        strcpy(host_buf, url_buf);
        strcpy(path_buf, "/");
    }

    // Get server IP address
    struct hostent *host_info = gethostbyname(host_buf);
    if (host_info == NULL) {
        fprintf(stderr, "Error looking up IP address for %s\n", host_buf);
        return;
    }
    in_addr_t server_addr = ((struct in_addr *) host_info->h_addr_list[0])->s_addr;

    // Get server socket
    in_port_t server_port = 80;
    int server_sockfd = establish_client_socket(server_addr, server_port);
    if (server_sockfd == -1) {
        fprintf(stderr, "Error establishing server socket!\n");
        return;
    }

    // Forward client request to server
    send_data(server_sockfd, request_buf, request_len);

    // Receive server response
    char response_buf[BUFFER_SIZE];
    ssize_t response_len = receive_data(server_sockfd, response_buf, BUFFER_SIZE, 0);
    if (response_len == -1 || response_len == 0) {
        fprintf(stderr, "Error receiving server response!\n");
        return;
    }

    // Forward server response to client
    send_data(client_sockfd, response_buf, response_len);
}

int establish_server_socket(in_addr_t addr, in_port_t port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return -1;
    }

    struct sockaddr_in addr_info;
    memset(&addr_info, 0, sizeof(addr_info));
    addr_info.sin_family = AF_INET;
    addr_info.sin_addr.s_addr = htonl(addr);
    addr_info.sin_port = htons(port);

    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        return -1;
    }

    if (bind(sockfd, (struct sockaddr *) &addr_info, sizeof(addr_info)) == -1) {
        return -1;
    }

    if (listen(sockfd, MAX_CONNECTIONS) == -1) {
        return -1;
    }

    return sockfd;
}

int establish_client_socket(in_addr_t addr, in_port_t port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return -1;
    }

    struct sockaddr_in addr_info;
    memset(&addr_info, 0, sizeof(addr_info));
    addr_info.sin_family = AF_INET;
    addr_info.sin_addr.s_addr = htonl(addr);
    addr_info.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &addr_info, sizeof(addr_info)) == -1) {
        return -1;
    }

    return sockfd;
}

void send_data(int sockfd, const char *buf, size_t len) {
    ssize_t bytes_sent = 0;
    while (bytes_sent < len) {
        ssize_t ret = send(sockfd, buf + bytes_sent, len - bytes_sent, 0);
        if (ret == -1) {
            fprintf(stderr, "Error sending data!\n");
            return;
        }
        bytes_sent += ret;
    }
}

ssize_t receive_data(int sockfd, char *buf, size_t len, int flags) {
    ssize_t bytes_received = 0;
    while (bytes_received < len) {
        ssize_t ret = recv(sockfd, buf + bytes_received, len - bytes_received, flags);
        if (ret == -1) {
            fprintf(stderr, "Error receiving data!\n");
            break;
        }
        else if (ret == 0) {
            fprintf(stderr, "Connection closed by peer!\n");
            break;
        }
        bytes_received += ret;
    }
    return bytes_received;
}