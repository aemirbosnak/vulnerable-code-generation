//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server;
    char *username, *password, *server_address;
    int email_count = 0;

    if (argc < 4) {
        printf("Usage: %s <username> <password> <server_address>\n", argv[0]);
        exit(1);
    }

    username = argv[1];
    password = argv[2];
    server_address = argv[3];

    printf("Connecting to server %s ...\n", server_address);

    // Establish connection with server
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error.\n");
        exit(1);
    }

    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_family = AF_INET;
    server.sin_port = htons(110);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Server connection failed.\n");
        exit(1);
    }

    // Get welcome message from server
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Server message: %s\n", buffer);

    // User authentication
    printf("Authenticating user %s ...\n", username);
    send(sock, "USER ", 5, 0);
    send(sock, username, strlen(username), 0);
    send(sock, "\r\n", 2, 0);

    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Server message: %s", buffer);

    if (strncmp(buffer, "+OK", 3) == 0) {
        printf("Sending password for user %s ...\n", username);
        send(sock, "PASS ", 5, 0);
        send(sock, password, strlen(password), 0);
        send(sock, "\r\n", 2, 0);

        memset(buffer, 0, BUFFER_SIZE);
        recv(sock, buffer, BUFFER_SIZE, 0);
        printf("Server message: %s", buffer);

        if (strncmp(buffer, "+OK", 3) == 0) {
            printf("User authentication successful.\n");

            // List emails
            printf("Requesting email list ...\n");
            send(sock, "LIST\r\n", 6, 0);

            memset(buffer, 0, BUFFER_SIZE);
            recv(sock, buffer, BUFFER_SIZE, 0);
            printf("Server message: %s", buffer);

            if (strncmp(buffer, "+OK", 3) == 0) {
                // Extract email count
                char *p = strrchr(buffer, ' ');
                if (p != NULL) {
                    email_count = atoi(p + 1);
                }

                printf("Number of emails: %d\n", email_count);
            } else {
                printf("Listing emails failed.\n");
            }
        } else {
            printf("User authentication failed.\n");
        }
    } 

    // Close connection with server
    close(sock);

    return 0;
}