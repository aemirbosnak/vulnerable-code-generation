//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_addr.sin_port = htons(POP3_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(sockfd);
        error("ERROR connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0);  // RFC 1939 requires CRLF ending
}

void receive_response(int sockfd, char *buffer, size_t size) {
    memset(buffer, 0, size);
    recv(sockfd, buffer, size - 1, 0);
}

void authenticate(int sockfd, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];

    // Receive server greeting
    receive_response(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Send USER command
    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "USER %s", username);
    send_command(sockfd, cmd);
    receive_response(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Send PASS command
    snprintf(cmd, sizeof(cmd), "PASS %s", password);
    send_command(sockfd, cmd);
    receive_response(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);
}

void list_messages(int sockfd) {
    char buffer[BUFFER_SIZE];

    send_command(sockfd, "LIST");
    receive_response(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    while (strncmp(buffer, ".\r\n", 4) != 0) {
        if (buffer[0] != '-') {
            printf("Messages:\n%s", buffer);
        }
        receive_response(sockfd, buffer, BUFFER_SIZE);
    }
}

void retrieve_message(int sockfd, int message_number) {
    char buffer[BUFFER_SIZE];
    char cmd[BUFFER_SIZE];

    snprintf(cmd, sizeof(cmd), "RETR %d", message_number);
    send_command(sockfd, cmd);
    receive_response(sockfd, buffer, BUFFER_SIZE);

    printf("Server: %s", buffer);
    while (strncmp(buffer, ".\r\n", 4) != 0) {
        printf("%s", buffer);
        receive_response(sockfd, buffer, BUFFER_SIZE);
    }
}

void disconnect(int sockfd) {
    send_command(sockfd, "QUIT");
    close(sockfd);
    printf("Disconnected from the server.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    
    int sockfd = connect_to_server(hostname);
    char buffer[BUFFER_SIZE];

    // Authenticate
    authenticate(sockfd, username, password);

    // List messages
    list_messages(sockfd);

    // Retrieve a specific message (e.g., message 1)
    retrieve_message(sockfd, 1);

    // Disconnect
    disconnect(sockfd);
    
    return 0;
}