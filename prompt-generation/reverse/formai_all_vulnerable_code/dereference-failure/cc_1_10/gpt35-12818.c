//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    struct hostent *server;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    int socket_fd, port_number, return_code;

    // check if host and port are provided
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // get server info
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        perror("Error: cannot resolve server hostname");
        exit(EXIT_FAILURE);
    }

    // create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error: cannot create socket");
        exit(EXIT_FAILURE);
    }

    // set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);

    // connect to server
    return_code = connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address));
    if (return_code < 0) {
        perror("Error: cannot connect to server");
        exit(EXIT_FAILURE);
    }

    // receive connection message
    bzero(buffer, BUFFER_SIZE);
    return_code = read(socket_fd, buffer, BUFFER_SIZE);
    if (return_code < 0) {
        perror("Error: cannot read from socket");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // send message
    sprintf(buffer, "HELO localhost\r\n");
    return_code = write(socket_fd, buffer, strlen(buffer));
    if (return_code < 0) {
        perror("Error: cannot write to socket");
        exit(EXIT_FAILURE);
    }

    // receive ack message
    bzero(buffer, BUFFER_SIZE);
    return_code = read(socket_fd, buffer, BUFFER_SIZE);
    if (return_code < 0) {
        perror("Error: cannot read from socket");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // send quit message
    sprintf(buffer, "QUIT\r\n");
    return_code = write(socket_fd, buffer, strlen(buffer));
    if (return_code < 0) {
        perror("Error: cannot write to socket");
        exit(EXIT_FAILURE);
    }

    // close socket
    close(socket_fd);
    return 0;
}