//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the buffer size
#define BUF_SIZE 4096

// The HTTP proxy function
void http_proxy(int client_sockfd) {
    char buffer[BUF_SIZE], reqbuffer[BUF_SIZE], respbuffer[BUF_SIZE];
    int read_size, sent_size;

    // Receive the request from the client
    read_size = recv(client_sockfd, reqbuffer, BUF_SIZE, 0);
    if (read_size <= 0) {
        return;
    }

    // Parse the request to get the hostname and port number
    char *start_line = strtok(reqbuffer, "\r\n");
    char *method = strtok(start_line, " ");
    char *path = strtok(NULL, " ");
    char *protocol = strtok(NULL, " ");
    char *host, *port;
    while (1) {
        char *header_line = strtok(NULL, "\r\n");
        if (header_line == NULL) {
            break;
        }
        if (memcmp(header_line, "Host:", 5) == 0) {
            host = strtok(header_line + 5, ": ");
            port = strtok(NULL, "");
            break;
        }
    }

    // Connect to the host
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(host);
    server_addr.sin_port = htons(atoi(port));
    if (connect(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0) {
        return;
    }

    // Send the request to the server
    sent_size = send(server_sockfd, reqbuffer, read_size, 0);

    // Receive the response from the server
    read_size = recv(server_sockfd, respbuffer, BUF_SIZE, 0);

    // Send the response to the client
    sent_size = send(client_sockfd, respbuffer, read_size, 0);

    // Close the sockets
    close(server_sockfd);
    close(client_sockfd);
}

// The main function
int main(int argc, char *argv[]) {
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_address, client_address;
    bzero(&server_address, sizeof(server_address));
    bzero(&client_address, sizeof(client_address));

    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR: Cannot open socket");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[1]));
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("ERROR: Cannot bind socket");
        exit(1);
    }

    if (listen(server_sockfd, 128) < 0) {
        perror("ERROR: Cannot listen to socket");
        exit(1);
    }

    // Accept clients and start the HTTP proxy
    while (1) {
        socklen_t client_len = sizeof(client_address);
        if ((client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, &client_len)) < 0) {
            continue;
        }
        http_proxy(client_sockfd);
    }

    return 0;
}