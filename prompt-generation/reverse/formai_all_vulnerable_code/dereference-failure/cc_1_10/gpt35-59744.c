//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: relaxed
/*
 * Simple HTTP Proxy in C
 *
 * A simple HTTP proxy that listens on a user-defined port, accepts HTTP
 * requests from a client, forwards them to a server, accepts the server's
 * response and forwards it back to the client.
 *
 * Written by John Smith.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

/* Constants */
#define DEFAULT_PORT 8080
#define MAX_REQUEST_SIZE 8192
#define MAX_RESPONSE_SIZE 65536

/* Function declarations */
int create_listen_socket(int port);
int process_client_request(int client_fd, const char* server_name, int server_port);
int send_request_to_server(int server_fd, const char* buffer, int length);
int read_response_from_server(int server_fd, char* buffer, int max_size);

/* Signal handler */
void handle_sigint(int sig)
{
    printf("Caught SIGINT, shutting down...\n");
    exit(0);
}

/* Main function */
int main(int argc, char** argv)
{
    int listen_fd, client_fd, server_fd, port;
    struct sockaddr_storage client_addr;
    socklen_t client_len = sizeof(client_addr);
    char client_ip[INET6_ADDRSTRLEN];
    char request_buffer[MAX_REQUEST_SIZE], response_buffer[MAX_RESPONSE_SIZE];
    int bytes_read;
    pid_t pid;
    struct hostent* server_info;

    /* Register signal handler */
    signal(SIGINT, handle_sigint);

    /* Parse command-line arguments */
    if (argc < 2) {
        port = DEFAULT_PORT;
    } else {
        port = atoi(argv[1]);
    }

    /* Create listening socket */
    listen_fd = create_listen_socket(port);
    printf("Listening on port %d...\n", port);

    /* Main loop */
    while (true) {
        /* Accept incoming connections */
        client_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_len);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        /* Fork a new process to handle the request */
        pid = fork();
        if (pid == -1) {
            perror("fork");
            close(client_fd);
            continue;
        } else if (pid == 0) {
            /* Child process */
            close(listen_fd);

            /* Get client IP address */
            if (client_addr.ss_family == AF_INET) {
                inet_ntop(AF_INET, &(((struct sockaddr_in*)&client_addr)->sin_addr),
                        client_ip, INET_ADDRSTRLEN);
            } else {
                inet_ntop(AF_INET6, &(((struct sockaddr_in6*)&client_addr)->sin6_addr),
                        client_ip, INET6_ADDRSTRLEN);
            }

            /* Read client request */
            bytes_read = read(client_fd, request_buffer, MAX_REQUEST_SIZE);
            if (bytes_read == -1) {
                perror("read");
                close(client_fd);
                exit(1);
            }

            /* Process client request */
            server_info = gethostbyname("www.google.com");
            server_fd = process_client_request(client_fd, server_info->h_name, 80);

            /* Send request to server */
            if (send_request_to_server(server_fd, request_buffer, bytes_read) == -1) {
                perror("send");
                close(server_fd);
                close(client_fd);
                exit(1);
            }

            /* Read response from server */
            bytes_read = read_response_from_server(server_fd, response_buffer, MAX_RESPONSE_SIZE);
            if (bytes_read == -1) {
                perror("read");
                close(server_fd);
                close(client_fd);
                exit(1);
            }

            /* Send response to client */
            if (write(client_fd, response_buffer, bytes_read) == -1) {
                perror("write");
                close(server_fd);
                close(client_fd);
                exit(1);
            }

            /* Close sockets and exit */
            close(server_fd);
            close(client_fd);
            exit(0);
        } else {
            /* Parent process */
            close(client_fd);
        }
    }

    return 0;
}

/* Helper function to create listening socket */
int create_listen_socket(int port)
{
    int listen_fd, optval = 1;
    struct sockaddr_in addr;

    /* Create socket */
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        exit(1);
    }

    /* Set SO_REUSEADDR option */
    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    /* Bind to address and port */
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    if (bind(listen_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    /* Listen for incoming connections */
    if (listen(listen_fd, SOMAXCONN) == -1) {
        perror("listen");
        exit(1);
    }

    return listen_fd;
}

/* Helper function to process client request */
int process_client_request(int client_fd, const char* server_name, int server_port)
{
    int server_fd;
    struct sockaddr_in server_addr;
    struct hostent* server_info;

    /* Look up server address */
    server_info = gethostbyname(server_name);
    if (server_info == NULL) {
        fprintf(stderr, "Unknown host %s\n", server_name);
        exit(1);
    }

    /* Create socket */
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(1);
    }

    /* Connect to server */
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, server_info->h_addr, server_info->h_length);
    server_addr.sin_port = htons(server_port);
    if (connect(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    return server_fd;
}

/* Helper function to send request to server */
int send_request_to_server(int server_fd, const char* buffer, int length)
{
    int bytes_sent = 0;

    while (bytes_sent < length) {
        ssize_t ret = send(server_fd, buffer + bytes_sent, length - bytes_sent, 0);
        if (ret == -1) {
            if (errno == EINTR) {
                /* Interrupted by signal, try again */
                continue;
            } else {
                /* Error occurred */
                return -1;
            }
        } else {
            /* Bytes sent successfully */
            bytes_sent += ret;
        }
    }

    return 0;
}

/* Helper function to read response from server */
int read_response_from_server(int server_fd, char* buffer, int max_size)
{
    int bytes_read = 0;

    while (bytes_read < max_size) {
        ssize_t ret = recv(server_fd, buffer + bytes_read, max_size - bytes_read, 0);
        if (ret == -1) {
            if (errno == EINTR) {
                /* Interrupted by signal, try again */
                continue;
            } else {
                /* Error occurred */
                return -1;
            }
        } else if (ret == 0) {
            /* Connection closed by server */
            break;
        } else {
            /* Bytes received successfully */
            bytes_read += ret;
        }
    }

    return bytes_read;
}