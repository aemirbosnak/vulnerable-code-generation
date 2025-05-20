//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(0);
}

void clear_buffer(char *buffer) {
    memset(buffer, 0, BUFFER_SIZE);
}

int main(int argc, char *argv[]) {
    int client_socket, port_number, n;
    struct sockaddr_in server_address;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    port_number = atoi(argv[2]);

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        error("Error opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error, no such host\n");
        exit(0);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        error("Error connecting");
    }

    char buffer[BUFFER_SIZE];
    clear_buffer(buffer);

    n = read(client_socket, buffer, BUFFER_SIZE);
    if (n < 0) {
        error("Error reading from socket");
    }

    printf("Server message: %s\n", buffer);

    printf("Sending command USER\n");
    sprintf(buffer, "USER %s\r\n", "my_username");
    n = write(client_socket, buffer, strlen(buffer));
    if (n < 0) {
        error("Error writing to socket");
    }

    clear_buffer(buffer);

    n = read(client_socket, buffer, BUFFER_SIZE);
    if (n < 0) {
        error("Error reading from socket");
    }

    printf("Server message: %s\n", buffer);

    printf("Sending command PASS\n");
    sprintf(buffer, "PASS %s\r\n", "my_password");
    n = write(client_socket, buffer, strlen(buffer));
    if (n < 0) {
        error("Error writing to socket");
    }

    clear_buffer(buffer);

    n = read(client_socket, buffer, BUFFER_SIZE);
    if (n < 0) {
        error("Error reading from socket");
    }

    printf("Server message: %s\n", buffer);

    printf("Sending command LIST\n");
    sprintf(buffer, "LIST\r\n");
    n = write(client_socket, buffer, strlen(buffer));
    if (n < 0) {
        error("Error writing to socket");
    }

    clear_buffer(buffer);

    n = read(client_socket, buffer, BUFFER_SIZE);
    if (n < 0) {
        error("Error reading from socket");
    }

    printf("Server message: %s\n", buffer);

    printf("Sending command RETR\n");
    sprintf(buffer, "RETR %d\r\n", 1);
    n = write(client_socket, buffer, strlen(buffer));
    if (n < 0) {
        error("Error writing to socket");
    }

    clear_buffer(buffer);

    n = read(client_socket, buffer, BUFFER_SIZE);
    if (n < 0) {
        error("Error reading from socket");
    }

    printf("Server message: %s\n", buffer);

    close(client_socket);
    return 0;
}