//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_imap(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *server;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return -1;
    }

    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, 
           (char *)server->h_addr_list[0],
           server->h_length);
    server_addr.sin_port = htons(IMAP_PORT);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(sockfd);
        error("ERROR connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int n = read(sockfd, buffer, BUFFER_SIZE - 1);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        printf("%s", buffer);
        if (strstr(buffer, "OK") || strstr(buffer, "NO")) {
            break;
        }
    }
}

void list_mailboxes(int sockfd) {
    send_command(sockfd, "A001 LIST \"\" \"*\"\r\n");
    read_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IMAP Hostname>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    int sockfd = connect_to_imap(hostname);

    if (sockfd >= 0) {
        read_response(sockfd);

        // LOGIN Command (Replace with real user and password)
        const char *username = "your_email@example.com";
        const char *password = "your_password";
        char login_command[BUFFER_SIZE];

        snprintf(login_command, BUFFER_SIZE, "A0001 LOGIN %s %s\r\n", username, password);
        send_command(sockfd, login_command);
        read_response(sockfd);

        // List Mailboxes
        list_mailboxes(sockfd);

        // LOGOUT Command
        send_command(sockfd, "A0003 LOGOUT\r\n");
        read_response(sockfd);
        
        close(sockfd);
    }

    return 0;
}