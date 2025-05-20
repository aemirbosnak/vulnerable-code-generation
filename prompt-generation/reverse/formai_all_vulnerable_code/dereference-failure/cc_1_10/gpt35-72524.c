//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: single-threaded
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <time.h>

#define SERVER_PORT 8888
#define BUFFER_SIZE 1024
#define TIMEOUT_SECS 5

int main(int argc, char **argv) {
    int client_socket_fd;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    struct timeval timeout;
    fd_set read_fds;

    // Create client socket
    if ((client_socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address details
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);

    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("ERROR, no such host\n");
        exit(0);
    }
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to server
    if (connect(client_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }

    // Check readability of socket for timeout seconds
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        timeout.tv_sec = TIMEOUT_SECS;
        timeout.tv_usec = 0;
        FD_ZERO(&read_fds);
        FD_SET(client_socket_fd, &read_fds);

        if (select(client_socket_fd + 1, &read_fds, NULL, NULL, &timeout) < 0) {
            perror("Select failed");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(client_socket_fd, &read_fds)) {
            if (read(client_socket_fd, buffer, BUFFER_SIZE) < 0) {
                perror("Read from server failed");
                exit(EXIT_FAILURE);
            } else {
                printf("Received: %s\n", buffer);
                break;
            }
        } else {
            printf("Timeout occurred, server not responding\n");
            break;
        }
    }

    close(client_socket_fd);
    return 0;
}