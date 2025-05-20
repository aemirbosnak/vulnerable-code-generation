//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    char* server_address;
    char* filename;
    int socket_fd;
    int port;
    struct sockaddr_in remote_addr;
    char buffer[BUFFER_SIZE];

    if (argc != 4) {
        printf("Usage: %s <server address> <port> <filename>\n", argv[0]);
        exit(1);
    }

    server_address = argv[1];
    port = atoi(argv[2]);
    filename = argv[3];

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Could not create socket");
        exit(1);
    }

    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, server_address, &remote_addr.sin_addr) <= 0) {
        printf("Invalid address or address not supported");
        exit(1);
    }

    if (connect(socket_fd, (struct sockaddr *) &remote_addr, sizeof(remote_addr)) < 0) {
        perror("Could not connect to server");
        exit(1);
    }

    printf("Connected to server %s:%d\n", server_address, port);

    sprintf(buffer, "RETR %s\n", filename);

    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Could not send command to server");
        exit(1);
    }

    FILE* local_file = fopen(filename, "wb");

    int bytes_read;

    while ((bytes_read = recv(socket_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, local_file);
    }

    printf("File downloaded successfully\n");

    close(socket_fd);
    fclose(local_file);

    return 0;
}