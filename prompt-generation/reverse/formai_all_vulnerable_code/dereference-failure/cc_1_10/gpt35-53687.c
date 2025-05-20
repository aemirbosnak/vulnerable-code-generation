//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>

#define BYTE_SIZE 8
#define MAX_PACKET_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ftp_client <IP address> <port number> <file name>\n");
        exit(-1);
    }

    char *ip_addr = argv[1];
    int port = atoi(argv[2]);
    char *file_name = argv[3];

    // Create client socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        printf("Error creating client socket\n");
        exit(-1);
    }

    // Connect to server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if (inet_pton(AF_INET, ip_addr, &server_address.sin_addr) < 1) {
        printf("Invalid IP address\n");
        exit(-1);
    }

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error connecting to server\n");
        exit(-1);
    }

    // Send file name to server
    int file_name_len = strlen(file_name);
    if (send(client_socket, file_name, file_name_len, 0) != file_name_len) {
        printf("Error sending file name to server\n");
        exit(-1);
    }

    // Receive file size from server
    unsigned long long file_size;
    if (recv(client_socket, &file_size, sizeof(file_size), 0) < 0) {
        printf("Error receiving file size from server\n");
        exit(-1);
    }

    // Open output file
    int output_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd < 0) {
        printf("Error creating output file\n");
        exit(-1);
    }

    unsigned char buffer[MAX_PACKET_SIZE];
    unsigned long long bytes_received = 0;
    int num_bytes_recv;
    while (bytes_received < file_size) {
        // Receive packet from server
        num_bytes_recv = recv(client_socket, buffer, sizeof(buffer), 0);
        if (num_bytes_recv <= 0) {
            printf("Error receiving data from server\n");
            exit(-1);
        }

        // Write packet to output file
        write(output_fd, buffer, num_bytes_recv);

        bytes_received += num_bytes_recv;
    }

    printf("File transfer complete!\n");

    // Close sockets and file descriptor
    close(output_fd);
    close(client_socket);

    return 0;
}