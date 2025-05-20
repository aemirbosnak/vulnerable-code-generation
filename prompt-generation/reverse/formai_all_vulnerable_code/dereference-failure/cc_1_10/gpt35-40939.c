//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server IP> <server port> <file name>\n", argv[0]);
        return 0;
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);
    char *file_name = argv[3];

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(server_port);

    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Error: Failed to connect to the server\n");
        return 0;
    }

    printf("Connected to the server\n");

    char buffer[MAX_BUFFER];
    memset(buffer, 0, MAX_BUFFER);

    int bytes_sent = send(client_socket, file_name, strlen(file_name), 0);
    if (bytes_sent < 0) {
        printf("Error: Failed to send the file name\n");
        return 0;
    }

    printf("File name sent to the server\n");

    int bytes_received = recv(client_socket, buffer, MAX_BUFFER, 0);
    if (bytes_received < 0) {
        printf("Error: Failed to receive file contents length from the server\n");
        return 0;
    }

    int file_contents_length = atoi(buffer);
    printf("File contents length received from the server: %d bytes\n", file_contents_length);

    if (file_contents_length <= 0) {
        printf("Error: File contents length is invalid\n");
        return 0;
    }

    FILE *file = fopen(file_name, "wb");
    if (file == NULL) {
        printf("Error: Failed to create the file\n");
        return 0;
    }

    int total_bytes_received = 0;
    while (total_bytes_received < file_contents_length) {
        bytes_received = recv(client_socket, buffer, MAX_BUFFER, 0);
        if (bytes_received < 0) {
            printf("Error: Failed to receive file contents from the server\n");
            fclose(file);
            return 0;
        }

        fwrite(buffer, sizeof(char), bytes_received, file);
        total_bytes_received += bytes_received;

        float progress = (float) total_bytes_received / file_contents_length * 100;
        printf("Progress: %.2f%%\n", progress);
    }

    fclose(file);
    printf("File transfer completed\n");

    return 0;
}