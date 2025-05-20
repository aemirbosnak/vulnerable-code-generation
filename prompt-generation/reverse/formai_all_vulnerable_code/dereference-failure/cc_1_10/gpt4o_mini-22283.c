//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ctype.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int create_socket(const char* hostname, const char* port) {
    struct addrinfo hints, *res;
    int sockfd;
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC; // Allow IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP
    
    if (getaddrinfo(hostname, port, &hints, &res) != 0) {
        error("getaddrinfo failed");
    }
    
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        freeaddrinfo(res);
        error("socket creation failed");
    }
    
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        close(sockfd);
        freeaddrinfo(res);
        error("socket connection failed");
    }
    
    freeaddrinfo(res);
    return sockfd;
}

void send_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error("send command failed");
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") != NULL || strstr(buffer, "NO") != NULL || strstr(buffer, "BAD") != NULL) {
            break;
        }
    }
    
    if (bytes_received < 0) {
        error("receive response failed");
    }
}

void login(int sockfd, const char* username, const char* password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A001 LOGIN \"%s\" \"%s\"", username, password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_mailboxes(int sockfd) {
    send_command(sockfd, "A002 LIST \"\" \"*\"");
    receive_response(sockfd);
}

void select_mailbox(int sockfd, const char* mailbox) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A003 SELECT \"%s\"", mailbox);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void fetch_message(int sockfd, const char* message_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A004 FETCH %s BODY[]", message_number);
    send_command(sockfd, command);
    receive_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = create_socket(hostname, "993");
    
    // Receive server ready response
    receive_response(sockfd);

    // Login to the IMAP server
    login(sockfd, username, password);

    // List Mailboxes
    printf("Mailboxes:\n");
    list_mailboxes(sockfd);

    // Select INBOX
    select_mailbox(sockfd, "INBOX");

    // Fetch the first message
    fetch_message(sockfd, "1");

    // Close the socket
    close(sockfd);
    return 0;
}