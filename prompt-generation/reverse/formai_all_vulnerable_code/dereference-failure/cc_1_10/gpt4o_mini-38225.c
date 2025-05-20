//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAXLINE 1024
#define SERVER_PORT 993

// Function prototypes
int connect_to_server(const char *server, int port);
void login_to_server(int sockfd, const char *username, const char *password);
void fetch_email_list(int sockfd);
void logout_from_server(int sockfd);
void send_command(int sockfd, const char *command);
void receive_response(int sockfd, char *buffer, size_t buffer_size);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IMAP server> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = connect_to_server(server, SERVER_PORT);
    if (sockfd < 0) {
        fprintf(stderr, "Could not connect to server: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    login_to_server(sockfd, username, password);
    fetch_email_list(sockfd);
    logout_from_server(sockfd);
    
    close(sockfd);
    return 0;
}

int connect_to_server(const char *server, int port) {
    struct sockaddr_in servaddr;
    struct hostent *he;

    if ((he = gethostbyname(server)) == NULL) {
        perror("gethostbyname");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    memcpy(&servaddr.sin_addr, he->h_addr, he->h_length);
    servaddr.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    char buffer[MAXLINE];
    receive_response(sockfd, buffer, sizeof(buffer));
    printf("Connected to IMAP server: %s\n", buffer);

    return sockfd;
}

void login_to_server(int sockfd, const char *username, const char *password) {
    char command[MAXLINE];
    snprintf(command, sizeof(command), "a1 LOGIN %s %s\r\n", username, password);
    send_command(sockfd, command);

    char response[MAXLINE];
    receive_response(sockfd, response, sizeof(response));
    printf("Login Response: %s\n", response);
}

void fetch_email_list(int sockfd) {
    char command[MAXLINE];
    snprintf(command, sizeof(command), "a2 LIST \"\" \"*\"\r\n");
    send_command(sockfd, command);

    char response[MAXLINE];
    while (1) {
        receive_response(sockfd, response, sizeof(response));
        printf("Email List Response: %s\n", response);
        if (strstr(response, "END")) break; // This is a simplified exit condition
    }
}

void logout_from_server(int sockfd) {
    char command[MAXLINE];
    snprintf(command, sizeof(command), "a3 LOGOUT\r\n");
    send_command(sockfd, command);
    
    char response[MAXLINE];
    receive_response(sockfd, response, sizeof(response));
    printf("Logout Response: %s\n", response);
}

void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("send");
    }
}

void receive_response(int sockfd, char *buffer, size_t buffer_size) {
    ssize_t n = recv(sockfd, buffer, buffer_size - 1, 0);
    if (n < 0) {
        perror("recv");
        return;
    }
    buffer[n] = '\0'; // Null terminate
}