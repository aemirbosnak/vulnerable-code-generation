//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_MSG_SIZE 1024
#define MAX_USERNAME_SIZE 256
#define MAX_PASSWORD_SIZE 256
#define MAX_COMMAND_SIZE 256

int main(int argc, char *argv[]) {
    char *server_address_str = argv[1];
    int server_port = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];

    // Connect to the server
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    inet_pton(AF_INET, server_address_str, &server_address.sin_addr);
    connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    // Receive server greeting
    char server_msg[MAX_MSG_SIZE];
    recv(client_socket, server_msg, MAX_MSG_SIZE, 0);
    printf("%s\n", server_msg);

    // Send login credentials
    char login_command[MAX_COMMAND_SIZE];
    sprintf(login_command, "USER %s\r\n", username);
    send(client_socket, login_command, strlen(login_command), 0);
    recv(client_socket, server_msg, MAX_MSG_SIZE, 0);
    printf("%s\n", server_msg);

    sprintf(login_command, "PASS %s\r\n", password);
    send(client_socket, login_command, strlen(login_command), 0);
    recv(client_socket, server_msg, MAX_MSG_SIZE, 0);
    printf("%s\n", server_msg);

    // List inbox messages
    send(client_socket, "LIST\r\n", strlen("LIST\r\n"), 0);
    recv(client_socket, server_msg, MAX_MSG_SIZE, 0);
    printf("%s", server_msg);
    while (strcmp(server_msg, ".\r\n") != 0) {
        recv(client_socket, server_msg, MAX_MSG_SIZE, 0);
        printf("%s", server_msg);
    }

    // Quit session
    send(client_socket, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    recv(client_socket, server_msg, MAX_MSG_SIZE, 0);
    printf("%s\n", server_msg);

    close(client_socket);
    return 0;
}