//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void error_check(int val, char* message) {
    if (val < 0) {
        perror(message);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[]) {
    int client_socket, port, bytes_received;
    char buffer[BUFFER_SIZE], *hostname, *filename;
    struct hostent *server;
    struct sockaddr_in server_addr;

    if (argc != 4) {
        printf("Usage: ./ftp_client <hostname> <port> <filename>\n");
        exit(EXIT_FAILURE);
    }

    hostname = argv[1];
    port = atoi(argv[2]);
    filename = argv[3];

    client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    error_check(client_socket, "Error creating client socket");

    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error: Host not found\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr*) server->h_addr);

    error_check(connect(client_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)), 
        "Error connecting to server");

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", filename, hostname);

    error_check(send(client_socket, buffer, strlen(buffer), 0), "Error sending request");

    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

    if (bytes_received < 0) {
        printf("Error receiving response\n");
        exit(EXIT_FAILURE);
    }

    // Check if file exists
    char* file_not_found_str = "404 Not Found";
    if (strstr(buffer, file_not_found_str) != NULL) {
        printf("Error: File not found on server\n");
        exit(EXIT_FAILURE);
    }

    // Get file size
    char* content_length_str = "Content-Length: ";
    int content_length_index = strstr(buffer, content_length_str) - buffer;
    char* content_length_end = strstr(buffer+content_length_index, "\r\n");
    int content_length = atoi(content_length_str+(strlen(content_length_str)));

    // Write file contents to disk
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Unable to open file for writing\n");
        exit(EXIT_FAILURE);
    }
    fwrite(buffer+(bytes_received-(content_length+4)), sizeof(char), content_length, fp);

    // Check for remaining data in buffer
    int bytes_remaining = bytes_received - (content_length+4);
    if (bytes_remaining > 0) {
        fwrite(buffer, sizeof(char), bytes_remaining, fp);
    }

    // Receive remaining data if file size > buffer size
    while (bytes_remaining < content_length) {
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received < 0) {
            printf("Error receiving response\n");
            exit(EXIT_FAILURE);
        }

        fwrite(buffer, sizeof(char), bytes_received, fp);
        bytes_remaining += bytes_received;
    }

    fclose(fp);
    close(client_socket);
    printf("File received successfully\n");
    return 0;
}