//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void send_request(int socket_fd, const char* request) {
    size_t request_len = strlen(request);
    size_t sent_len = 0;
    while (sent_len < request_len) {
        ssize_t nb = send(socket_fd, request + sent_len,
                          request_len - sent_len, 0);
        if (nb == -1) {
            perror("send");
            exit(EXIT_FAILURE);
        }
        sent_len += nb;
    }
}

void receive_response(int socket_fd, char* response, size_t response_size) {
    size_t received_len = 0;
    while (received_len < response_size) {
        ssize_t nb = recv(socket_fd, response + received_len, response_size - received_len, 0);
        if (nb == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
        if (nb == 0) {
            break;
        }
        received_len += nb;
    }
}

int connect_to_server(const char* hostname, const char* port) {
    struct addrinfo hints = {.ai_flags = 0, .ai_family = AF_UNSPEC,
                             .ai_socktype = SOCK_STREAM, .ai_protocol = 0,
                             .ai_canonname = NULL, .ai_addr = NULL,
                             .ai_next = NULL};
    struct addrinfo* addr_list;
    int ret = getaddrinfo(hostname, port, &hints, &addr_list);
    if (ret != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        exit(EXIT_FAILURE);
    }
    struct addrinfo* rp;
    int socket_fd = -1;
    for (rp = addr_list; rp != NULL; rp = rp->ai_next) {
        socket_fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (socket_fd == -1) {
            continue;
        }
        if (connect(socket_fd, rp->ai_addr, rp->ai_addrlen) != -1) {
            break;
        }
        close(socket_fd);
    }
    if (rp == NULL) {
        fprintf(stderr, "Could not connect to server %s:%s\n", hostname, port);
        exit(EXIT_FAILURE);
    }
    freeaddrinfo(addr_list);
    return socket_fd;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: pop3_client <hostname> <port> <username>\n");
        exit(EXIT_FAILURE);
    }
    char* hostname = argv[1];
    char* port = argv[2];
    char* username = argv[3];

    // Connect to server and get greeting message
    int socket_fd = connect_to_server(hostname, port);
    char response[BUFFER_SIZE];
    receive_response(socket_fd, response, sizeof(response));
    printf("%s", response);

    // Send USER command
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "USER %s\r\n", username);
    send_request(socket_fd, request);

    // Receive response and check if it is a positive reply
    receive_response(socket_fd, response, sizeof(response));
    printf("%s", response);
    if (response[0] != '+') {
        fprintf(stderr, "Server replied negatively to USER command: %s", response);
        exit(EXIT_FAILURE);
    }

    // Get password from user
    printf("Password: ");
    fflush(stdout);
    char* password = NULL;
    size_t password_size = 0;
    ssize_t nb = getline(&password, &password_size, stdin);
    if (nb == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }
    password[nb - 1] = '\0'; // Remove newline character

    // Send PASS command
    snprintf(request, sizeof(request), "PASS %s\r\n", password);
    send_request(socket_fd, request);

    // Receive response and check if it is a positive reply
    receive_response(socket_fd, response, sizeof(response));
    printf("%s", response);
    if (response[0] != '+') {
        fprintf(stderr, "Server replied negatively to PASS command: %s", response);
        exit(EXIT_FAILURE);
    }

    // Send STAT command
    send_request(socket_fd, "STAT\r\n");

    // Receive response and print number of messages and total size
    receive_response(socket_fd, response, sizeof(response));
    printf("%s", response);
    int num_messages, total_size;
    sscanf(response, "+OK %d %d", &num_messages, &total_size);
    printf("You have %d messages with a total size of %d bytes\n", num_messages, total_size);
    
    // Close connection to server
    close(socket_fd);
    return EXIT_SUCCESS;
}