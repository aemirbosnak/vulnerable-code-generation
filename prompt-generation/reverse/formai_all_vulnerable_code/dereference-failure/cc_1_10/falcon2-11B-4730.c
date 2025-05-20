//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to connect to POP3 server
int connect_to_server(const char* host, int port) {
    int socket_fd;
    struct sockaddr_in server;
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host);

    if (connect(socket_fd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    return socket_fd;
}

// Function to send POP3 command and get response
int send_recv(int socket_fd, char* command) {
    int bytes_sent = send(socket_fd, command, strlen(command), 0);
    if (bytes_sent < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    int bytes_recv = recv(socket_fd, command, sizeof(command), 0);
    if (bytes_recv < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    return bytes_recv;
}

// Function to log in to POP3 server
int login(int socket_fd, const char* username, const char* password) {
    char command[100];
    snprintf(command, sizeof(command), "USER %s", username);
    int bytes_sent = send_recv(socket_fd, command);

    if (strcmp(command, "+OK")!= 0) {
        printf("Error: %s\n", command);
        return -1;
    }

    snprintf(command, sizeof(command), "PASS %s", password);
    bytes_sent = send_recv(socket_fd, command);

    if (strcmp(command, "+OK")!= 0) {
        printf("Error: %s\n", command);
        return -1;
    }

    return 0;
}

// Function to retrieve email headers
int get_email_headers(int socket_fd, int message_number, char** headers, int* num_headers) {
    char command[100];
    snprintf(command, sizeof(command), "RETR %d", message_number);
    int bytes_sent = send_recv(socket_fd, command);

    if (strcmp(command, "-ERR") == 0) {
        printf("Error: %s\n", command);
        return -1;
    }

    *num_headers = atoi(command);
    headers = (char**)malloc(*num_headers * sizeof(char*));
    int i = 0;
    while (i < *num_headers) {
        snprintf(command, sizeof(command), "TOP %d", i);
        int bytes_recv = send_recv(socket_fd, command);
        headers[i] = (char*)malloc(strlen(command) + 1);
        strcpy(headers[i], command);
        i++;
    }

    return 0;
}

// Function to retrieve email body
int get_email_body(int socket_fd, int message_number, char** body, int* num_bytes) {
    char command[100];
    snprintf(command, sizeof(command), "UIDL");
    int bytes_sent = send_recv(socket_fd, command);

    if (strcmp(command, "-ERR") == 0) {
        printf("Error: %s\n", command);
        return -1;
    }

    *num_bytes = atoi(command);
    body = (char**)malloc(*num_bytes * sizeof(char*));
    int i = 0;
    while (i < *num_bytes) {
        snprintf(command, sizeof(command), "RETR %d", i);
        int bytes_recv = send_recv(socket_fd, command);
        body[i] = (char*)malloc(strlen(command) + 1);
        strcpy(body[i], command);
        i++;
    }

    return 0;
}

// Function to logout from POP3 server
int logout(int socket_fd) {
    char command[100];
    snprintf(command, sizeof(command), "QUIT");
    int bytes_sent = send_recv(socket_fd, command);

    if (strcmp(command, "+OK")!= 0) {
        printf("Error: %s\n", command);
        return -1;
    }

    return 0;
}

// Main function
int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    int socket_fd = connect_to_server(argv[1], atoi(argv[2]));
    if (socket_fd < 0) {
        return 1;
    }

    int status = login(socket_fd, "user", "password");
    if (status < 0) {
        return 1;
    }

    // Get email headers
    char* headers[10];
    int num_headers = 0;
    status = get_email_headers(socket_fd, 1, headers, &num_headers);
    if (status < 0) {
        return 1;
    }

    // Print email headers
    printf("Email headers:\n");
    for (int i = 0; i < num_headers; i++) {
        printf("%s\n", headers[i]);
    }

    // Get email body
    char* body[10];
    int num_bytes = 0;
    status = get_email_body(socket_fd, 1, body, &num_bytes);
    if (status < 0) {
        return 1;
    }

    // Print email body
    printf("Email body:\n");
    for (int i = 0; i < num_bytes; i++) {
        printf("%s\n", body[i]);
    }

    // Logout from POP3 server
    status = logout(socket_fd);
    if (status < 0) {
        return 1;
    }

    close(socket_fd);
    return 0;
}