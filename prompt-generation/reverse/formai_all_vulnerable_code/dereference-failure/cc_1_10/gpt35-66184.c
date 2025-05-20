//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

void die_with_error(const char *error_message) {
    perror(error_message);
    exit(1);
}

int create_socket(const char *server_ip, const int port) {
    int client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client_socket < 0) {
        die_with_error("Failed to create socket");
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(port);

    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        die_with_error("Failed to connect with server");
    }

    return client_socket;
}

void send_data(int client_socket, const char *data) {
    if (send(client_socket, data, strlen(data), 0) != strlen(data)) {
        die_with_error("Failed to send data");
    }
}

int receive_data(int client_socket, char *buffer) {
    int total_bytes_received = 0;
    while (1) {
        int bytes_received = recv(client_socket, buffer + total_bytes_received, BUF_SIZE, 0);
        if (bytes_received < 0) {
            die_with_error("Failed to receive data");
        } else if (bytes_received == 0) {
            break;
        } else {
            total_bytes_received += bytes_received;
        }
    }
    return total_bytes_received;
}

void read_input(char *buffer) {
    printf("Enter the message to be sent:\n");
    fgets(buffer, BUF_SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
}

int main(int argc, char **argv) {
    if (argc != 3) {
        die_with_error("Usage: smtp_client <server_ip> <port>");
    }

    const char *server_ip = argv[1];
    const int port = atoi(argv[2]);
    int client_socket = create_socket(server_ip, port);

    printf("SMTP Client started to communicate with %s:%d\n", server_ip, port);

    char buffer[BUF_SIZE];
    memset(buffer, 0, BUF_SIZE);

    // SMTP handshake
    receive_data(client_socket, buffer);
    printf("Server: %s\n", buffer);
    snprintf(buffer, BUF_SIZE, "EHLO client\r\n");
    send_data(client_socket, buffer);
    receive_data(client_socket, buffer);
    printf("Server: %s\n", buffer);

    // From email address
    read_input(buffer);
    snprintf(buffer, BUF_SIZE, "MAIL FROM:<%s>\r\n", buffer);
    send_data(client_socket, buffer);
    receive_data(client_socket, buffer);
    printf("Server: %s\n", buffer);

    // To email address
    read_input(buffer);
    snprintf(buffer, BUF_SIZE, "RCPT TO:<%s>\r\n", buffer);
    send_data(client_socket, buffer);
    receive_data(client_socket, buffer);
    printf("Server: %s\n", buffer);

    // Email data
    snprintf(buffer, BUF_SIZE, "DATA\r\n");
    send_data(client_socket, buffer);
    receive_data(client_socket, buffer);
    printf("Server: %s\n", buffer);

    printf("Enter email text. End with a single line containing only a period.\n");
    while (1) {
        read_input(buffer);
        if (strcmp(buffer, ".") == 0) {
            break;
        }
        snprintf(buffer, BUF_SIZE, "%s\r\n", buffer);
        send_data(client_socket, buffer);
    }
    snprintf(buffer, BUF_SIZE, ".\r\n");
    send_data(client_socket, buffer);

    receive_data(client_socket, buffer);
    printf("Server: %s\n", buffer);

    // Quit
    snprintf(buffer, BUF_SIZE, "QUIT\r\n");
    send_data(client_socket, buffer);
    receive_data(client_socket, buffer);
    printf("Server: %s\n", buffer);

    close(client_socket);

    exit(0);
}