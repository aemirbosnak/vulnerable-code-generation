//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: recursive
// This is a POP3 client program written recursively in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

void error(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void receive_data(int socket, char *buffer, int buffer_size) {
    ssize_t received_bytes = recv(socket, buffer, buffer_size, 0);
    if (received_bytes < 0) {
        error("Error receiving data");
    }
    buffer[received_bytes] = '\0';
    printf("%s", buffer);
}

void send_data(int socket, char *message) {
    if (send(socket, message, strlen(message), 0) < 0) {
        error("Error sending data");
    }
}

void read_response(int socket, char *buffer, int buffer_size) {
    receive_data(socket, buffer, buffer_size);
    if (strncmp(buffer, "+OK", 3) != 0) {
        error("Error receiving response");
    }
}

void get_message(int socket, int message_number) {
    char buffer[MAX_BUFFER_SIZE];
    sprintf(buffer, "RETR %d\r\n", message_number);
    send_data(socket, buffer);
    read_response(socket, buffer, MAX_BUFFER_SIZE);
    receive_data(socket, buffer, MAX_BUFFER_SIZE);
    printf("Message %d:\n%s\n", message_number, buffer);
}

void delete_message(int socket, int message_number) {
    char buffer[MAX_BUFFER_SIZE];
    sprintf(buffer, "DELE %d\r\n", message_number);
    send_data(socket, buffer);
    read_response(socket, buffer, MAX_BUFFER_SIZE);
    printf("Deleted message %d\n", message_number);
}

void fetch_messages(int socket, int message_number) {
    char buffer[MAX_BUFFER_SIZE];
    sprintf(buffer, "STAT\r\n");
    send_data(socket, buffer);
    read_response(socket, buffer, MAX_BUFFER_SIZE);
    int msg_count, size;
    sscanf(buffer, "+OK %d %d", &msg_count, &size);
    printf("Number of messages: %d\n", msg_count);
    if (msg_count == 0) {
        return;
    }
    get_message(socket, message_number);
    delete_message(socket, message_number);
    fetch_messages(socket, message_number);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server_ip> <port_number> <user>\n", argv[0]);
        return 0;
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("Error creating socket");
    }
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));
    if (connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        error("Error connecting to server");
    }
    char buffer[MAX_BUFFER_SIZE];
    receive_data(sock, buffer, MAX_BUFFER_SIZE);
    send_data(sock, "USER ");
    send_data(sock, argv[3]);
    send_data(sock, "\r\n");
    read_response(sock, buffer, MAX_BUFFER_SIZE);
    send_data(sock, "PASS ******\r\n"); // Enter your password instead of ******
    read_response(sock, buffer, MAX_BUFFER_SIZE);
    fetch_messages(sock, 1);
    send_data(sock, "QUIT\r\n");
    read_response(sock, buffer, MAX_BUFFER_SIZE);
    close(sock);
    return 0;
}