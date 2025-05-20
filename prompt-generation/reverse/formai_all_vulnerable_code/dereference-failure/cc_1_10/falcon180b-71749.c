//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define DEFAULT_PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <server_address> <username> <password>\n", argv[0]);
        return 1;
    }

    char *server_address = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(DEFAULT_PORT);
    if (inet_pton(AF_INET, server_address, &server_addr.sin_addr) <= 0) {
        printf("Invalid server address\n");
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    char login_command[MAX_COMMAND_LENGTH] = "USER ";
    strcat(login_command, username);
    strcat(login_command, "\r\n");

    send(sock, login_command, strlen(login_command), 0);

    char password_command[MAX_COMMAND_LENGTH] = "PASS ";
    strcat(password_command, password);
    strcat(password_command, "\r\n");

    send(sock, password_command, strlen(password_command), 0);

    char welcome_message[BUFFER_SIZE];
    memset(welcome_message, 0, BUFFER_SIZE);
    int bytes_received = recv(sock, welcome_message, BUFFER_SIZE - 1, 0);
    welcome_message[bytes_received] = '\0';

    printf("Server response: %s\n", welcome_message);

    close(sock);
    return 0;
}