//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 8196

void receive(int sockfd, char* buffer, int buffer_size) {
    int received_bytes = 0;
    int total_received_bytes = 0;
    char* cursor = buffer;

    while (total_received_bytes < buffer_size) {
        received_bytes = recv(sockfd, cursor, buffer_size - total_received_bytes, 0);
        if (received_bytes <= 0) {
            break;
        }

        cursor += received_bytes;
        total_received_bytes += received_bytes;
    }
}

void send_command(int sockfd, const char* command) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "%s\r\n", command);
    send(sockfd, buffer, strlen(buffer), 0);
}

int main(int argc, char** argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <host> <port> <username>\n", argv[0]);
        return 1;
    }

    char* host = argv[1];
    int port = atoi(argv[2]);
    char* username = argv[3];

    struct hostent* server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Failed to resolve host %s\n", host);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Failed to create socket\n");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Failed to connect to server %s:%d\n", host, port);
        return 1;
    }

    // Log in to the server
    char login_command[BUFFER_SIZE];
    snprintf(login_command, BUFFER_SIZE, "LOGIN %s *", username);
    send_command(sockfd, login_command);

    // Wait for login response
    char buffer[BUFFER_SIZE];
    receive(sockfd, buffer, BUFFER_SIZE);
    printf("Server response: %s", buffer);

    // List available mailboxes
    send_command(sockfd, "LIST \"\" *");

    // Wait for mailbox listing response
    memset(buffer, 0, BUFFER_SIZE);
    receive(sockfd, buffer, BUFFER_SIZE);
    printf("Server response: %s", buffer);

    // Log out and close connection
    send_command(sockfd, "LOGOUT");
    close(sockfd);

    return 0;
}