//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_LEN 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s IMAP_SERVER PORT USER_EMAIL\n", argv[0]);
        exit(1);
    }

    // Retrieve command line inputs
    char *server = argv[1];
    int port = atoi(argv[2]);
    char *user = argv[3];

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    // Define server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server);
    server_addr.sin_port = htons(port);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    // Receive server greeting
    char buffer[MAX_BUFFER_LEN];
    if (recv(sock, buffer, MAX_BUFFER_LEN, 0) < 0) {
        perror("Failed to receive server greeting");
        exit(1);
    }
    printf("Server greeting: %s", buffer);

    // Send login command
    char login[MAX_BUFFER_LEN];
    snprintf(login, MAX_BUFFER_LEN, "A001 LOGIN %s PASSWORD\r\n", user);
    if (send(sock, login, strlen(login), 0) < 0) {
        perror("Failed to send login command");
        exit(1);
    }

    // Receive login response
    if (recv(sock, buffer, MAX_BUFFER_LEN, 0) < 0) {
        perror("Failed to receive login response");
        exit(1);
    }
    printf("Login response: %s", buffer);

    // Send list command to retrieve mailbox list
    char list[MAX_BUFFER_LEN] = "A002 LIST \"\" *\r\n";
    if (send(sock, list, strlen(list), 0) < 0) {
        perror("Failed to send list command");
        exit(1);
    }

    // Receive mailbox list response
    if (recv(sock, buffer, MAX_BUFFER_LEN, 0) < 0) {
        perror("Failed to receive mailbox list response");
        exit(1);
    }
    printf("Mailbox list response: %s", buffer);

    // Close connection
    close(sock);

    return 0;
}