//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: scientific
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

int pop3_authenticate(int sockfd, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];

    // Read Server Greeting
    if (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) < 0) {
        error("Failed to read from socket");
    }
    printf("Server: %s", buffer);

    // Send USER command
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error("Failed to send USER command");
    }

    // Read response
    if (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) < 0) {
        error("Failed to read from socket");
    }
    printf("Server: %s", buffer);

    // Send PASS command
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error("Failed to send PASS command");
    }

    // Read response
    if (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) < 0) {
        error("Failed to read from socket");
    }
    printf("Server: %s", buffer);

    // Check if authentication succeeded
    return strncmp(buffer, "+OK", 3) == 0;
}

void pop3_list_messages(int sockfd) {
    char buffer[BUFFER_SIZE];

    // Send LIST command
    if (send(sockfd, "LIST\r\n", 7, 0) < 0) {
        error("Failed to send LIST command");
    }

    // Read response
    while (1) {
        if (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) <= 0) {
            error("Failed to read from socket");
        }
        printf("Server: %s", buffer);
        if (strncmp(buffer, ".\r\n", 3) == 0) {
            break; // End of response
        }
    }
}

void pop3_retrieve_message(int sockfd, int msg_number) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "RETR %d\r\n", msg_number);
    
    // Send RETR command
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error("Failed to send RETR command");
    }

    // Read response
    while (1) {
        if (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) <= 0) {
            error("Failed to read from socket");
        }
        printf("Server: %s", buffer);
        if (strncmp(buffer, ".\r\n", 3) == 0) {
            break; // End of message
        }
    }
}

void pop3_quit(int sockfd) {
    if (send(sockfd, "QUIT\r\n", 7, 0) < 0) {
        error("Failed to send QUIT command");
    }
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
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(POP3_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    if (pop3_authenticate(sockfd, username, password)) {
        printf("Authentication successful!\n");
        pop3_list_messages(sockfd);
        printf("Retrieving message 1...\n");
        pop3_retrieve_message(sockfd, 1);
    } else {
        printf("Authentication failed.\n");
    }

    pop3_quit(sockfd);
    close(sockfd);
    return 0;
}