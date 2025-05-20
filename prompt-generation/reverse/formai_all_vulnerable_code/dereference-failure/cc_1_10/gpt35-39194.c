//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <hostname> <port> <filename>\n", argv[0]);
        return 1;
    }

    // Create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("socket creation failed");
        return 1;
    }

    // Set up server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) != 0) {
        perror("connection failed");
        return 1;
    }

    // Send filename to server
    char filename[BUFFER_SIZE];
    strcpy(filename, argv[3]);
    if (send(client_socket, filename, strlen(filename), 0) == -1) {
        perror("sending filename failed");
        return 1;
    }

    // Receive file size from server
    char size_str[BUFFER_SIZE];
    if (recv(client_socket, size_str, BUFFER_SIZE, 0) == -1) {
        perror("receiving file size failed");
        return 1;
    }
    int size = atoi(size_str);

    // Open file for writing
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("opening file failed");
        return 1;
    }

    // Receive file data from server
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    while (bytes_received < size) {
        int remaining = size - bytes_received;
        int to_receive = remaining > BUFFER_SIZE ? BUFFER_SIZE : remaining;
        int bytes = recv(client_socket, buffer, to_receive, 0);
        if (bytes == -1) {
            perror("receiving file data failed");
            return 1;
        }
        fwrite(buffer, 1, bytes, file);
        bytes_received += bytes;
    }

    // Clean up
    fclose(file);
    close(client_socket);
    printf("File '%s' downloaded successfully.\n", filename);

    return 0;
}