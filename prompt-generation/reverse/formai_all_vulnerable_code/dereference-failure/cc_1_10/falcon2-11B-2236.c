//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <stdbool.h>

#define MAX_EMAIL_LENGTH 1000

int connect_to_server(const char* host, const char* port, const char* username, const char* password) {
    int sockfd;
    struct hostent* server;
    struct sockaddr_in server_address;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error opening socket");
        return -1;
    }

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        return -1;
    }

    bzero((char*)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(atoi(port));

    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        return -1;
    }

    if (send(sockfd, username, strlen(username), 0) < 0) {
        perror("Error sending username");
        return -1;
    }

    if (send(sockfd, password, strlen(password), 0) < 0) {
        perror("Error sending password");
        return -1;
    }

    return sockfd;
}

void download_emails(int sockfd, const char* mailbox) {
    char email[MAX_EMAIL_LENGTH];

    while (true) {
        if (recv(sockfd, email, MAX_EMAIL_LENGTH, 0) < 0) {
            perror("Error receiving email");
            return;
        }

        printf("From: %s\nSubject: %s\n\n", email, email);

        if (send(sockfd, "DELE", strlen("DELE"), 0) < 0) {
            perror("Error deleting email");
            return;
        }
    }
}

int main() {
    int sockfd;
    char host[100];
    char port[100];
    char username[100];
    char password[100];
    char mailbox[100];

    printf("Enter hostname: ");
    fgets(host, sizeof(host), stdin);

    printf("Enter port number: ");
    fgets(port, sizeof(port), stdin);

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);

    printf("Enter mailbox name: ");
    fgets(mailbox, sizeof(mailbox), stdin);

    sockfd = connect_to_server(host, port, username, password);

    if (sockfd < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    download_emails(sockfd, mailbox);

    close(sockfd);

    return 0;
}