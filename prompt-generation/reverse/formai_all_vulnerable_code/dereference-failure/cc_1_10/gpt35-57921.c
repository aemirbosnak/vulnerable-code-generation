//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Romeo and Juliet
/* Romeo and Juliet's Simple HTTP Proxy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void die(char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char **argv) {
    // Check args
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <proxy port> <destination address>\n", argv[0]);
        exit(1);
    }

    // Set up proxy socket
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        die("socket()");
    }

    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));

    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY); // Accept any incoming IP
    proxy_addr.sin_port = htons(atoi(argv[1])); // Listen on specified port

    if (bind(proxy_socket, (struct sockaddr*) &proxy_addr, sizeof(proxy_addr)) < 0) {
        die("bind()");
    }

    if (listen(proxy_socket, 10) < 0) { // Listen for incoming connections
        die("listen()");
    }

    // Connect to destination
    int dest_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (dest_socket < 0) {
        die("socket()");
    }

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));

    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(argv[2]); // Connect to specified destination
    dest_addr.sin_port = htons(80);

    if (connect(dest_socket, (struct sockaddr*) &dest_addr, sizeof(dest_addr)) < 0) {
        die("connect()");
    }

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    char client_buffer[BUFFER_SIZE];
    char dest_buffer[BUFFER_SIZE];

    while (1) {
        int client_socket = accept(proxy_socket, (struct sockaddr*) &client_addr, &client_len);
        if (client_socket < 0) {
            die("accept()");
        }

        // Read from client
        memset(client_buffer, 0, BUFFER_SIZE);
        if (read(client_socket, client_buffer, BUFFER_SIZE - 1) < 0) {
            die("read()");
        }

        // Write to destination
        if (write(dest_socket, client_buffer, strlen(client_buffer)) < 0) {
            die("write()");
        }

        // Read from destination
        memset(dest_buffer, 0, BUFFER_SIZE);
        if (read(dest_socket, dest_buffer, BUFFER_SIZE - 1) < 0) {
            die("read()");
        }

        // Write to client
        if (write(client_socket, dest_buffer, strlen(dest_buffer)) < 0) {
            die("write()");
        }

        close(client_socket); // Close client connection
    }

    close(proxy_socket); // Close proxy socket
    close(dest_socket); // Close destination socket

    return 0;
}