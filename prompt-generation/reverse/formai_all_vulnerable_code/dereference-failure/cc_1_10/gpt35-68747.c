//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: interoperable
// A simple FTP Client using C programming language for downloading files from the server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock_fd;
    struct sockaddr_in server_address;
    char filename[BUFFER_SIZE];

    if(argc != 3) {
        printf("Usage: %s <Server IP> <Server Port>\n", argv[0]);
        return -1;
    }

    // Create socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation error");
        return -1;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connect to the Server
    if(connect(sock_fd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Connection error");
        close(sock_fd);
        return -1;
    }

    printf("Enter the filename to download from Server: ");
    scanf("%s", filename);

    // Send command to server
    if(send(sock_fd, filename, strlen(filename), 0) == -1) {
        perror("Send command error");
        close(sock_fd);
        return -1;
    }

    // Open file for writing
    FILE* file = fopen(filename, "wb");
    if(file == NULL) {
        perror("Cannot create file");
        close(sock_fd);
        return -1;
    }

    // Download file contents
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    while ((bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
    }

    // Close file and socket
    fclose(file);
    close(sock_fd);

    printf("File download complete.\n");

    return 0;
}