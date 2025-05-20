//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

// Function to perform a DNS lookup
struct addrinfo* get_server_info(const char* hostname, const char* port) {
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, port, &hints, &res) != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }
    return res;
}

// Function to create a socket and connect to the server
int connect_to_server(struct addrinfo* res) {
    int sockfd = -1;
    for (struct addrinfo* p = res; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }
        break; // Successfully connected
    }
    freeaddrinfo(res);
    if (sockfd == -1) {
        fprintf(stderr, "Could not connect to server\n");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Function to send commands to the IMAP server
void send_command(int sockfd, const char* command) {
    send(sockfd, command, strlen(command), 0);
}

// Function to receive responses from the IMAP server
void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") || strstr(buffer, "NO") || strstr(buffer, "BAD")) {
            break; // End of response
        }
    }
    if (bytes_received < 0) {
        perror("recv");
    }
}

// Function to login to the IMAP server
void imap_login(int sockfd, const char* username, const char* password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A001 LOGIN %s %s\r\n", username, password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

// Function to select a mailbox
void imap_select_mailbox(int sockfd, const char* mailbox) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A002 SELECT \"%s\"\r\n", mailbox);
    send_command(sockfd, command);
    receive_response(sockfd);
}

// Function to fetch email headers
void imap_fetch_headers(int sockfd) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A003 FETCH 1:* (ENVELOPE)\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);
}

// Function to logout from the IMAP server
void imap_logout(int sockfd) {
    send_command(sockfd, "A004 LOGOUT\r\n");
    receive_response(sockfd);
    close(sockfd);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* hostname = argv[1];
    const char* port = argv[2];
    const char* username = argv[3];
    const char* password = argv[4];

    struct addrinfo* server_info = get_server_info(hostname, port);
    int sockfd = connect_to_server(server_info);

    receive_response(sockfd); // Initial server greeting
    imap_login(sockfd, username, password);
    imap_select_mailbox(sockfd, "INBOX");
    imap_fetch_headers(sockfd);
    imap_logout(sockfd);

    return 0;
}