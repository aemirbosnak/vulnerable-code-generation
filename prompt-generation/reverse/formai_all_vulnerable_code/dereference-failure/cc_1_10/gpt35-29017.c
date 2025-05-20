//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
#define SERVER_PORT 143

typedef struct imap_session {
    int socket_fd;
    char* buffer;
    size_t buffer_size;
    char* username;
    char* password;
} imap_session;

int send_message(imap_session* session, const char* message) {
    if (send(session->socket_fd, message, strlen(message), 0) < 0) {
        perror("send");
        return -1;
    }
    return 0;
}

int receive_response(imap_session* session) {
    ssize_t size = recv(session->socket_fd, session->buffer, session->buffer_size, 0);
    if (size < 0) {
        perror("recv");
        return -1;
    }
    session->buffer[size] = '\0';
    printf("%s\n", session->buffer);
    return 0;
}

int login(imap_session* session) {
    char login_message[BUFFER_SIZE];
    sprintf(login_message, "1 LOGIN %s %s\r\n", session->username, session->password);

    if (send_message(session, login_message) < 0) {
        return -1;
    }

    return receive_response(session);
}

int logout(imap_session* session) {
    if (send_message(session, "1 LOGOUT\r\n") < 0) {
        return -1;
    }

    return receive_response(session);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int socket_fd;
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);

    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    if (connect(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    imap_session session;
    session.socket_fd = socket_fd;
    session.buffer = malloc(BUFFER_SIZE);
    session.buffer_size = BUFFER_SIZE;
    session.username = argv[2];
    session.password = argv[3];

    if (login(&session) < 0) {
        perror("login");
        exit(EXIT_FAILURE);
    }

    if (logout(&session) < 0) {
        perror("logout");
        exit(EXIT_FAILURE);
    }

    free(session.buffer);
    close(socket_fd);

    exit(EXIT_SUCCESS);
}