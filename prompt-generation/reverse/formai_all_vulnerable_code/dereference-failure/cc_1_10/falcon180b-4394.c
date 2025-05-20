//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];

    printf("Enter username: ");
    fgets(username, BUFFER_SIZE, stdin);
    username[strcspn(username, "\r\n")] = '\0';

    printf("Enter password: ");
    fgets(password, BUFFER_SIZE, stdin);
    password[strcspn(password, "\r\n")] = '\0';

    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);

    char response[BUFFER_SIZE];
    int bytes_received = recv(sock, response, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving server response\n");
        close(sock);
        return 1;
    }

    printf("Server response: %s", response);

    snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);

    bytes_received = recv(sock, response, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving server response\n");
        close(sock);
        return 1;
    }

    printf("Server response: %s", response);

    close(sock);
    return 0;
}