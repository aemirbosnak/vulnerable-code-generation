//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: imaginative
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int connect_to_server(char *server, int port);
void receive_mail(int sockfd, char *username, char *password);
void print_mail(char *buffer);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s server port username\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];

    int sockfd = connect_to_server(server, port);
    if (sockfd == -1) {
        fprintf(stderr, "Error: Could not connect to server.\n");
        exit(EXIT_FAILURE);
    }

    char password[BUFFER_SIZE];
    printf("Enter your password: ");
    fflush(stdout);
    read(STDIN_FILENO, password, BUFFER_SIZE);

    // Replace newline character with null terminator
    char *newline = strchr(password, '\n');
    if (newline) {
        *newline = '\0';
    }

    receive_mail(sockfd, username, password);

    return EXIT_SUCCESS;
}

int connect_to_server(char *server, int port) {
    struct sockaddr_in servaddr;
    struct hostent *host;

    host = gethostbyname(server);
    if (host == NULL) {
        return -1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        return -1;
    }

    return sockfd;
}

void receive_mail(int sockfd, char *username, char *password) {
    char *login_command = "LOGIN %s %s\n";
    char buffer[BUFFER_SIZE];

    // Send login command to server
    sprintf(buffer, login_command, username, password);
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for response from server
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (strncmp(buffer, "OK", 2) == 0) {
        // Login succeeded, fetch mail
        char *fetch_command = "FETCH 1 BODY[TEXT]\n";

        // Send fetch command to server
        send(sockfd, fetch_command, strlen(fetch_command), 0);

        // Wait for response from server
        recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (strncmp(buffer, "OK", 2) == 0) {
            // Print mail to stdout
            print_mail(buffer);
        } else {
            fprintf(stderr, "Error: Could not fetch mail from server.\n");
        }
    } else {
        fprintf(stderr, "Error: Could not log in to server.\n");
    }

    // Close socket
    close(sockfd);
}

void print_mail(char *buffer) {
    // Find start of mail body
    char *body_start = strstr(buffer, "\r\n\r\n");
    if (body_start == NULL) {
        fprintf(stderr, "Error: Could not find start of mail body.\n");
        return;
    }

    // Print mail body to stdout
    printf("%s", body_start + 4);
}