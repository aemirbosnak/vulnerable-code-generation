//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define DEFAULT_PORT "21"
#define MAX_CONNECTIONS 5

// Function prototypes
void handle_ftp_command(int client_sock, const char *command);
void parse_response(int sock, char *buffer);
void list_files(int control_sock);
void download_file(int control_sock, const char *filename);
void upload_file(int control_sock, const char *filename);
int establish_connection(const char *hostname, const char *port);
void set_nonblocking(int sock);

// Asynchronous FTP Client Example
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <command> [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *command = argv[2];
    const char *filename = (argc > 3) ? argv[3] : NULL;

    int control_sock = establish_connection(hostname, DEFAULT_PORT);
    if (control_sock < 0) {
        perror("Failed to connect to FTP server");
        exit(EXIT_FAILURE);
    }

    // Set non-blocking socket
    set_nonblocking(control_sock);

    // Handle FTP commands
    if (strcmp(command, "LIST") == 0) {
        list_files(control_sock);
    } else if (strcmp(command, "GET") == 0 && filename) {
        download_file(control_sock, filename);
    } else if (strcmp(command, "PUT") == 0 && filename) {
        upload_file(control_sock, filename);
    } else {
        fprintf(stderr, "Invalid command or missing filename\n");
    }

    close(control_sock);
    return 0;
}

int establish_connection(const char *hostname, const char *port) {
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;

    int status;
    if ((status = getaddrinfo(hostname, port, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return -1;
    }

    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock < 0) {
        perror("Socket creation failed");
        freeaddrinfo(res);
        return -1;
    }

    if (connect(sock, res->ai_addr, res->ai_addrlen) == -1) {
        close(sock);
        perror("Connection failed");
        freeaddrinfo(res);
        return -1;
    }

    freeaddrinfo(res);
    return sock;
}

void set_nonblocking(int sock) {
    int flags = fcntl(sock, F_GETFL, 0);
    fcntl(sock, F_SETFL, flags | O_NONBLOCK);
}

void parse_response(int sock, char *buffer) {
    int bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to receive data");
        return;
    }
    buffer[bytes_received] = '\0';
    printf("Server response: %s\n", buffer);
}

void list_files(int control_sock) {
    char buffer[BUFFER_SIZE];
    send(control_sock, "PASV\r\n", 7, 0);
    parse_response(control_sock, buffer);
    // Further parsing and implementation would go here for a real PASV mode connection
    // Simulating file listing as an example
    printf("File list:\n");
    printf("file1.txt\nfile2.txt\nfile3.txt\n");
}

void download_file(int control_sock, const char *filename) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "RETR %s\r\n", filename);
    send(control_sock, buffer, strlen(buffer), 0);
    parse_response(control_sock, buffer);
    // Simulating file download
    printf("Downloading file: %s\n", filename);
}

void upload_file(int control_sock, const char *filename) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "STOR %s\r\n", filename);
    send(control_sock, buffer, strlen(buffer), 0);
    parse_response(control_sock, buffer);
    // Simulating file upload
    printf("Uploading file: %s\n", filename);
}