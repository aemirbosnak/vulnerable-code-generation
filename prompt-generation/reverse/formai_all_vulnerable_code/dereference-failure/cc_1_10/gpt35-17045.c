//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: random
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define BUFF_SIZE 1024

int open_socket(const char* server, const int port) {
    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        perror("Error: invalid server\n");
        return -1;
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("Error: Failed to create socket\n");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr*) host->h_addr);
    memset(&(server_addr.sin_zero), '\0', 8);

    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error: Connection failed\n");
        return -1;
    }

    return sock_fd;
}

int login(int sock_fd, const char* username, const char* password) {
    char buffer[BUFF_SIZE] = {0};
    sprintf(buffer, "LOGIN %s %s\n", username, password);
    if (send(sock_fd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: Failed to send data\n");
        return -1;
    }

    if (recv(sock_fd, buffer, BUFF_SIZE, 0) == -1) {
        perror("Error: Failed to receive data\n");
        return -1;
    }

    if (strstr(buffer, "OK")) {
        printf("Login successful\n");
        return 0;
    } else {
        printf("Login failed: %s\n", buffer);
        return -1;
    }
}

void fetch_emails(int sock_fd) {
    char buffer[BUFF_SIZE] = {0};
    sprintf(buffer, "FETCH 1:* BODY[HEADER.FIELDS (SUBJECT FROM)]\n");
    if (send(sock_fd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: Failed to send data\n");
        return;
    }

    while (1) {
        memset(buffer, 0, BUFF_SIZE);
        ssize_t bytes_received = recv(sock_fd, buffer, BUFF_SIZE, 0);
        if (bytes_received == -1) {
            perror("Error: Failed to receive data\n");
            break;
        }

        if (bytes_received == 0) {
            break;
        }

        printf("%s", buffer);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s [server] [port] [username] [password]\n", argv[0]);
        return 0;
    }

    const char* server = argv[1];
    const int port = atoi(argv[2]);
    const char* username = argv[3];
    const char* password = argv[4];

    int sock_fd = open_socket(server, port);
    if (sock_fd == -1) {
        return 1;
    }

    if (login(sock_fd, username, password) == -1) {
        return 1;
    }

    fetch_emails(sock_fd);

    close(sock_fd);
    return 0;
}