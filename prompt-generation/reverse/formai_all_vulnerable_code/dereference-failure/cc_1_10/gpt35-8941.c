//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUF_SIZE 4096 /* Maximum buffer size */

void handle_error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

/* Function to create a socket and return file descriptor */
int create_socket() {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    /* Check for errors */
    if (sock_fd == -1) {
        handle_error("Failed to create socket");
    }

    return sock_fd;
}

/* Function to connect to server and return file descriptor */
int connect_to_server(char *ip, int port) {
    int sock_fd = create_socket();

    /* Create socket address */
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(port);

    /* Connect to server */
    if (connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        handle_error("Failed to connect to server");
    }

    return sock_fd;
}

/* Function to handle incoming client requests */
void handle_client(int client_fd, char *ip, int port) {
    char buf[BUF_SIZE];
    memset(buf, 0, BUF_SIZE);

    /* Connect to server */
    int server_fd = connect_to_server(ip, port);

    /* Forward client request to server */
    while (1) {
        int bytes_read = read(client_fd, buf, BUF_SIZE);

        if (bytes_read == -1) {
            handle_error("Failed to read client request");
        }
        else if (bytes_read == 0) {
            break;
        }
        else {
            int bytes_sent = send(server_fd, buf, bytes_read, 0);

            if (bytes_sent == -1) {
                handle_error("Failed to send request to server");
            }
        }
    }

    /* Handle server response and forward to client */
    while (1) {
        int bytes_read = recv(server_fd, buf, BUF_SIZE, 0);

        if (bytes_read == -1) {
            handle_error("Failed to receive server response");
        }
        else if (bytes_read == 0) {
            break;
        }
        else {
            int bytes_sent = send(client_fd, buf, bytes_read, 0);

            if (bytes_sent == -1) {
                handle_error("Failed to send response to client");
            }
        }
    }

    /* Close sockets */
    close(client_fd);
    close(server_fd);
}

int main(int argc, char *argv[]) {
    /* Check for correct number of arguments */
    if (argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Parse command line arguments */
    char *ip = argv[1];
    int port = atoi(argv[2]);

    /* Create socket address */
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    /* Create listening socket */
    int sock_fd = create_socket();

    /* Bind to socket address */
    if (bind(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        handle_error("Failed to bind socket");
    }

    /* Listen for incoming client requests */
    if (listen(sock_fd, SOMAXCONN) == -1) {
        handle_error("Failed to listen for incoming requests");
    }

    while (1) {
        /* Accept incoming client request */
        struct sockaddr_in cli_addr;
        socklen_t cli_addr_len = sizeof(cli_addr);
        int cli_fd = accept(sock_fd, (struct sockaddr *) &cli_addr, &cli_addr_len);

        if (cli_fd == -1) {
            handle_error("Failed to accept client request");
        }

        /* Handle client request */
        handle_client(cli_fd, ip, port);
    }

    /* Close listening socket */
    close(sock_fd);

    return 0;
}