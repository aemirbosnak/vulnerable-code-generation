//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int create_socket(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host;
    int sockfd;

    host = gethostbyname(hostname);
    if (host == NULL) {
        error("Error: no such host");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(IMAP_PORT);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    return sockfd;
}

void send_command(int sockfd, const char *cmd) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s\r\n", cmd);
    send(sockfd, buffer, strlen(buffer), 0);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") || strstr(buffer, "NO")) {
            break;
        }
    }
}

void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A1 LOGIN %s %s", username, password);
    send_command(sockfd, command);
    read_response(sockfd);
}

void fetch_email(int sockfd, const char *email_id) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A2 FETCH %s BODY[]", email_id);
    send_command(sockfd, command);
    read_response(sockfd);
}

void logout(int sockfd) {
    send_command(sockfd, "A3 LOGOUT");
    read_response(sockfd);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = create_socket(hostname);

    read_response(sockfd); // Read greeting
    login(sockfd, username, password);
    fetch_email(sockfd, "1"); // Fetch email with ID 1
    logout(sockfd);

    return 0;
}