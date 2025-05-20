//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER "imap.example.com"
#define PORT 993
#define BUFFER_SIZE 2048

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sock, const char *command) {
    if (send(sock, command, strlen(command), 0) < 0) {
        error("Send failed");
    }
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }
    if (bytes_received < 0) {
        error("Receive failed");
    }
}

int connect_to_server(const char *server, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    if ((host = gethostbyname(server)) == NULL) {
        error("Could not resolve host");
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("Socket creation failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Could not connect to server");
    }

    return sock;
}

void login(int sock, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "LOGIN %s %s\r\n", username, password);
    send_command(sock, command);
    receive_response(sock);
}

void list_emails(int sock) {
    send_command(sock, "LIST \"\" \"*\"\r\n");
    receive_response(sock);
}

void read_email(int sock, const char *email_id) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "FETCH %s BODY[]\r\n", email_id);
    send_command(sock, command);
    receive_response(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <username> <password> <command>\n", argv[0]);
        exit(1);
    }

    const char *username = argv[1];
    const char *password = argv[2];
    const char *command = argv[3];

    int sock = connect_to_server(SERVER, PORT);
    receive_response(sock);

    login(sock, username, password);

    if (strcmp(command, "list") == 0) {
        list_emails(sock);
    } else if (strncmp(command, "read ", 5) == 0) {
        read_email(sock, command + 5);
    } else {
        fprintf(stderr, "Unknown command: %s\n", command);
    }

    close(sock);
    return 0;
}