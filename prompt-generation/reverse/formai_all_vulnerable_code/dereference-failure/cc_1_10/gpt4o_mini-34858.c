//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: visionary
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

void pop3_send(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        error("Failed to send command");
    }
}

void pop3_receive(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;
    while ((n = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "+OK")) {
            break; // Found the positive response from the server
        }
    }
}

void pop3_login(int sockfd, const char *username, const char *password) {
    char cmd[BUFFER_SIZE];

    snprintf(cmd, sizeof(cmd), "USER %s\r\n", username);
    pop3_send(sockfd, cmd);
    pop3_receive(sockfd);

    snprintf(cmd, sizeof(cmd), "PASS %s\r\n", password);
    pop3_send(sockfd, cmd);
    pop3_receive(sockfd);
}

void pop3_list(int sockfd) {
    pop3_send(sockfd, "LIST\r\n");
    pop3_receive(sockfd);
}

void pop3_retrieve(int sockfd, const char *msg_num) {
    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "RETR %s\r\n", msg_num);
    pop3_send(sockfd, cmd);
    pop3_receive(sockfd);
}

void pop3_quit(int sockfd) {
    pop3_send(sockfd, "QUIT\r\n");
    pop3_receive(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    struct sockaddr_in server_addr;
    struct hostent *host;

    // Resolve the hostname
    if ((host = gethostbyname(hostname)) == NULL) {
        error("Could not resolve hostname");
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Could not open socket");
    }

    // Setup server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to the POP3 server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    // Receive the server's greeting
    pop3_receive(sockfd);

    // Login to the POP3 server
    pop3_login(sockfd, username, password);

    // List messages
    printf("Listing messages:\n");
    pop3_list(sockfd);

    // Retrieve the first message for simplicity
    printf("Retrieving first message:\n");
    pop3_retrieve(sockfd, "1");  // Message number is "1" for simplicity

    // Quit cleanly
    pop3_quit(sockfd);

    close(sockfd);
    return 0;
}