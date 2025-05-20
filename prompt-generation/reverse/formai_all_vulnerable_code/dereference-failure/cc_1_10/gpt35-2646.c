//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFF_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {

    int proxy_port, client_socket_fd, server_socket_fd, client_len;
    char buffer[BUFF_SIZE];
    struct sockaddr_in server_addr, client_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <proxy_port> <server_hostname:server_port>\n", argv[0]);
        exit(1);
    }

    proxy_port = atoi(argv[1]);

    /* Create socket for client */
    client_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket_fd < 0) {
        error("ERROR creating client socket");
    }

    /* Bind socket to client */
    bzero((char *) &client_addr, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = INADDR_ANY;
    client_addr.sin_port = htons(proxy_port);

    if (bind(client_socket_fd, (struct sockaddr *) &client_addr, sizeof(client_addr)) < 0) {
        error("ERROR binding client socket");
    }

    /* Listen for incoming connections */
    listen(client_socket_fd, 1);

    /* Accept incoming connection */
    client_len = sizeof(client_addr);
    server_socket_fd = accept(client_socket_fd, (struct sockaddr *) &client_addr, &client_len);
    if (server_socket_fd < 0) {
        error("ERROR accepting client connection");
    }

    /* Connect to server */
    server = gethostbyname(strtok(argv[2], ":"));
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    int server_port = atoi(strtok(NULL, ":"));

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(server_port);

    if (connect(server_socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting to server");
    }

    /* Forward requests from client to server and responses from server to client */
    while (1) {
        bzero(buffer, BUFF_SIZE);
        int n = read(server_socket_fd, buffer, BUFF_SIZE - 1);
        if (n < 0) {
            error("ERROR reading from server socket");
        }
        if (n == 0) {
            break;
        }
        printf("Received message from server: %s\n", buffer);

        n = write(client_socket_fd, buffer, strlen(buffer));
        if (n < 0) {
            error("ERROR writing to client socket");
        }

        bzero(buffer, BUFF_SIZE);
        n = read(client_socket_fd, buffer, BUFF_SIZE - 1);
        if (n < 0) {
            error("ERROR reading from client socket");
        }
        if (n == 0) {
            break;
        }
        printf("Received message from client: %s\n", buffer);

        n = write(server_socket_fd, buffer, strlen(buffer));
        if (n < 0) {
            error("ERROR writing to server socket");
        }
    }

    close(server_socket_fd);
    close(client_socket_fd);

    return 0;
}