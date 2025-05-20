//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUF_SIZE 1024

int create_socket(const char *ip_address, int port) {
    int sock;
    struct sockaddr_in server_address;

    if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        fprintf(stderr, "Failed to create socket.\n");
        exit(1);
    }

    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if (inet_pton(AF_INET, ip_address, &server_address.sin_addr) == -1) {
        fprintf(stderr, "Invalid IP address.\n");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        fprintf(stderr, "Failed to connect.\n");
        exit(1);
    }

    return sock;
}

void send_data(int sock, const char *data) {
    send(sock, data, strlen(data), 0);
}

int receive_data(int sock, char *buffer) {
    int len;

    len = recv(sock, buffer, MAX_BUF_SIZE, 0);
    buffer[len] = '\0';

    return len;
}

int main(int argc, char *argv[]) {
    int sock, port;
    char ip_address[MAX_BUF_SIZE], file_path[MAX_BUF_SIZE], buffer[MAX_BUF_SIZE], *token;
    FILE *file;
    long file_size;

    if (argc != 4) {
        printf("Usage: ./ftp_client [IP address] [port] [file path]\n");
        return 1;
    }

    strcpy(ip_address, argv[1]);
    port = atoi(argv[2]);
    strcpy(file_path, argv[3]);

    // Open the file to be uploaded.
    file = fopen(file_path, "rb");

    if (!file) {
        fprintf(stderr, "Failed to open file.\n");
        return 1;
    }

    // Get the file size.
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Create a socket and connect to the server.
    sock = create_socket(ip_address, port);

    // Send the file name and size to the server.
    sprintf(buffer, "%ld %s", file_size, strrchr(file_path, '/') + 1);
    send_data(sock, buffer);

    // Wait for the server to respond with "OK".
    receive_data(sock, buffer);

    if (strncmp(buffer, "OK", 2) != 0) {
        fprintf(stderr, "Server did not respond with OK.\n");
        return 1;
    }

    // Upload the file.
    while (!feof(file)) {
        int bytes_read = fread(buffer, 1, MAX_BUF_SIZE, file);
        send(sock, buffer, bytes_read, 0);
    }

    fclose(file);

    // Wait for the server to respond with "OK".
    receive_data(sock, buffer);

    if (strncmp(buffer, "OK", 2) != 0) {
        fprintf(stderr, "Server did not respond with OK.\n");
        return 1;
    }

    // Download a file from the server.
    send_data(sock, "download");

    receive_data(sock, buffer);

    if (strncmp(buffer, "OK", 2) != 0) {
        fprintf(stderr, "Server did not respond with OK.\n");
        return 1;
    }

    // Get the file name from the server's response.
    token = strtok(buffer, " ");
    token = strtok(NULL, " ");

    // Open the file to be downloaded.
    file = fopen(token, "wb");

    if (!file) {
        fprintf(stderr, "Failed to create file.\n");
        return 1;
    }

    // Receive the file.
    while (1) {
        int bytes_received = receive_data(sock, buffer);

        if (bytes_received == 0)
            break;

        fwrite(buffer, 1, bytes_received, file);
    }

    fclose(file);

    // Send "OK" to the server to acknowledge receipt of the file.
    send_data(sock, "OK");

    // Close the socket.
    close(sock);

    return 0;
}