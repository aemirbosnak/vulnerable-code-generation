//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUFFER 1024
#define IMAP_PORT 143

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int connect_to_imap_server(const char *hostname, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    
    host = gethostbyname(hostname);
    if (host == NULL) {
        handle_error("gethostbyname");
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("socket");
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr_list[0], host->h_length);
    
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("connect");
    }
    
    return sockfd;
}

void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);  // IMAP commands end with CRLF
}

void read_response(int sockfd) {
    char buffer[MAX_BUFFER];
    int n;

    while ((n = read(sockfd, buffer, sizeof(buffer)-1)) > 0) {
        buffer[n] = '\0'; // Null-terminate the buffer
        printf("%s", buffer);
        if (strstr(buffer, "OK") || strstr(buffer, "NO")) {
            break; // Responds like "OK", "NO" indicate command status
        }
    }

    if (n < 0) {
        handle_error("read");
    }
}

void login(int sockfd, const char *username, const char *password) {
    char command[MAX_BUFFER];
    snprintf(command, sizeof(command), "A001 LOGIN %s %s", username, password);
    send_command(sockfd, command);
    read_response(sockfd);
}

void list_mailboxes(int sockfd) {
    send_command(sockfd, "A002 LIST \"\" \"*\"");
    read_response(sockfd);
}

void fetch_email(int sockfd, const char *mailbox, int msg_num) {
    char command[MAX_BUFFER];
    snprintf(command, sizeof(command), "A003 FETCH %d BODY[]", msg_num);
    send_command(sockfd, command);
    read_response(sockfd);
}

void logout(int sockfd) {
    send_command(sockfd, "A004 LOGOUT");
    read_response(sockfd);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <imap_server> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char *imap_server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    
    int sockfd = connect_to_imap_server(imap_server, IMAP_PORT);
    
    printf("Connected to IMAP server: %s\n", imap_server);
    
    login(sockfd, username, password);
    printf("Logged in as: %s\n", username);
    
    list_mailboxes(sockfd);
    
    fetch_email(sockfd, "INBOX", 1); // Fetch the first email in the Inbox
    
    logout(sockfd);
    printf("Logged out. Connection closed.\n");

    return 0;
}