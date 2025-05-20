//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 1024

void read_email(int sock_fd, char *email_id) {
    char recvline[MAXLINE];

    // Send command to retrieve email
    sprintf(recvline, "FETCH %s BODY[TEXT]\r\n", email_id);
    send(sock_fd, recvline, strlen(recvline), 0);

    // Receive email data
    int n;
    while ((n = recv(sock_fd, recvline, MAXLINE, 0)) > 0) {
        recvline[n] = '\0';
        printf("%s", recvline);
    }
}

int main(int argc, char **argv) {
    int sock_fd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in serv_addr;
    char username[MAXLINE], password[MAXLINE], mailbox[MAXLINE];

    if (argc != 3) {
        printf("usage: %s <IMAP server IP address> <IMAP server port number>\n", argv[0]);
        exit(1);
    }

    // Create socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    // Configure socket address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(1);
    }

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect error");
        exit(1);
    }

    // Receive greeting message
    if ((n = recv(sock_fd, recvline, MAXLINE, 0)) > 0) {
        recvline[n] = '\0';
        printf("%s", recvline);
    }

    // Send login command
    printf("IMAP username: ");
    fgets(username, MAXLINE, stdin);
    printf("IMAP password: ");
    fgets(password, MAXLINE, stdin);
    sprintf(recvline, "LOGIN %s %s\r\n", username, password);
    send(sock_fd, recvline, strlen(recvline), 0);

    // Receive login response
    if ((n = recv(sock_fd, recvline, MAXLINE, 0)) > 0) {
        recvline[n] = '\0';
        printf("%s", recvline);
        if (strstr(recvline, "OK") == NULL) {
            printf("Authentication failed. Exiting.\n");
            exit(1);
        }
    }

    // Send select mailbox command
    printf("Mailbox name: ");
    fgets(mailbox, MAXLINE, stdin);
    sprintf(recvline, "SELECT %s\r\n", mailbox);
    send(sock_fd, recvline, strlen(recvline), 0);

    // Receive mailbox status response
    if ((n = recv(sock_fd, recvline, MAXLINE, 0)) > 0) {
        recvline[n] = '\0';
        printf("%s", recvline);
        if (strstr(recvline, "OK") == NULL) {
            printf("Failed to select mailbox. Exiting.\n");
            exit(1);
        }
    }

    // Display email list
    printf("Email list:\n");
    sprintf(recvline, "FETCH 1:* RFC822.HEADER\r\n");
    send(sock_fd, recvline, strlen(recvline), 0);
    while ((n = recv(sock_fd, recvline, MAXLINE, 0)) > 0) {
        recvline[n] = '\0';
        if (strstr(recvline, "OK") != NULL) {
            break;
        }
        printf("%s", recvline);
    }

    // Read email
    printf("\nEnter email id to retrieve: ");
    char email_id[MAXLINE];
    fgets(email_id, MAXLINE, stdin);
    read_email(sock_fd, email_id);

    // Logout and close connection
    sprintf(recvline, "LOGOUT\r\n");
    send(sock_fd, recvline, strlen(recvline), 0);

    return 0;
}