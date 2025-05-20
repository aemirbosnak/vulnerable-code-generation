//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int connect_to_server(const char *server_address, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket.\n");
        return -1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed.\n");
        return -1;
    }
    printf("Connected to server.\n");
    return sock;
}

char *read_server(int sock) {
    char *buffer = (char *)calloc(BUF_SIZE, sizeof(char));
    int read_size = recv(sock, buffer, BUF_SIZE, 0);
    if (read_size < 0) {
        printf("Failed to receive from server.\n");
        return NULL;
    }
    return buffer;
}

void send_to_server(int sock, const char *message) {
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Failed to send message to server.\n");
    }
}

int main() {
    const char *server_address = "127.0.0.1";
    int port = 143; // IMAP port
    int sock = connect_to_server(server_address, port);
    if (sock == -1) {
        return 1;
    }

    char *message = read_server(sock);
    printf("%s\n", message); // welcome message from server
    free(message);

    // authenticate with server
    char login_command[BUF_SIZE];
    printf("Username: ");
    fgets(login_command, BUF_SIZE, stdin);
    strtok(login_command, "\n"); // remove newline character
    send_to_server(sock, login_command);
    message = read_server(sock);
    printf("%s\n", message); // imap prompt
    free(message);
    printf("Password: ");
    fgets(login_command, BUF_SIZE, stdin);
    strtok(login_command, "\n"); // remove newline character
    send_to_server(sock, login_command);
    message = read_server(sock);
    printf("%s\n", message); // authentication result
    free(message);

    close(sock);
    return 0;
}