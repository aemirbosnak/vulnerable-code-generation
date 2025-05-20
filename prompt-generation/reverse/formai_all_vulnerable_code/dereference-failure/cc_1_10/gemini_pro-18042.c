//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define MAX_MSG_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_aton(hostname, &server_addr.sin_addr);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char *username = "your_username";
    char *password = "your_password";

    char buf[MAX_MSG_SIZE];

    // Login
    snprintf(buf, MAX_MSG_SIZE, "A001 LOGIN %s %s\r\n", username, password);
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, MAX_MSG_SIZE, 0);

    // Select mailbox
    snprintf(buf, MAX_MSG_SIZE, "A002 SELECT INBOX\r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, MAX_MSG_SIZE, 0);

    // Fetch message
    snprintf(buf, MAX_MSG_SIZE, "A003 FETCH 1 (UID BODY[TEXT])\r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, MAX_MSG_SIZE, 0);

    // Parse and print message
    char *start = strstr(buf, "\r\nBODY[TEXT]\r\n");
    if (start == NULL) {
        fprintf(stderr, "Error parsing message\n");
        return EXIT_FAILURE;
    }

    char *end = strstr(start, "\r\n");
    if (end == NULL) {
        fprintf(stderr, "Error parsing message\n");
        return EXIT_FAILURE;
    }

    *end = '\0';

    printf("%s\n", start + 15);

    // Logout
    snprintf(buf, MAX_MSG_SIZE, "A004 LOGOUT\r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, MAX_MSG_SIZE, 0);

    close(sock);

    return EXIT_SUCCESS;
}