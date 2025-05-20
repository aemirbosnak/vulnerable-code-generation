//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define PARANOID_MODE 1

void clear_buffer(char* buffer, int size) {
    memset(buffer, 0, size);
}

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void receive_response(int socket_fd, char* response) {
    int n = recv(socket_fd, response, BUF_SIZE, 0);
    if (n < 0) {
        error("Error receiving response from server.");
    }
}

void send_request(int socket_fd, char* request) {
    int n = send(socket_fd, request, strlen(request), 0);
    if (n < 0) {
        error("Error sending request to server.");
    }
}

void print_response(char* response) {
    if (PARANOID_MODE) {
        printf("Server response:\n");
        printf("%s\n", response);
    }
}

void build_request(char* request, char* command, char* username, char* password) {
    sprintf(request, "%s %s %s\r\n", command, username, password);
    if (PARANOID_MODE) {
        printf("Sending request to server:\n");
        printf("%s", request);
    }
}

void login(int socket_fd, char* username, char* password) {
    char buffer[BUF_SIZE];
    clear_buffer(buffer, BUF_SIZE);
    receive_response(socket_fd, buffer);

    char request[BUF_SIZE];
    build_request(request, "USER", username, password);
    send_request(socket_fd, request);
    clear_buffer(request, BUF_SIZE);
    receive_response(socket_fd, buffer);
    print_response(buffer);

    build_request(request, "PASS", username, password);
    send_request(socket_fd, request);
    clear_buffer(request, BUF_SIZE);
    receive_response(socket_fd, buffer);
    print_response(buffer);
}

void list(int socket_fd) {
    char request[BUF_SIZE];
    build_request(request, "LIST", "", "");
    send_request(socket_fd, request);
    char buffer[BUF_SIZE];
    clear_buffer(buffer, BUF_SIZE);
    receive_response(socket_fd, buffer);
    print_response(buffer);
}

void quit(int socket_fd) {
    char request[BUF_SIZE];
    build_request(request, "QUIT", "", "");
    send_request(socket_fd, request);
    char buffer[BUF_SIZE];
    clear_buffer(buffer, BUF_SIZE);
    receive_response(socket_fd, buffer);
    print_response(buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        error("Usage: pop3_client hostname port username password");
    }

    struct hostent* server = gethostbyname(argv[1]);
    if (server == NULL) {
        error("Error finding host.");
    }

    int port_number = atoi(argv[2]);
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy(server->h_addr, &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(port_number);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        error("Error opening socket.");
    }

    if (connect(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        error("Error connecting to server.");
    }

    login(socket_fd, argv[3], argv[4]);
    list(socket_fd);
    quit(socket_fd);

    close(socket_fd);
    return 0;
}