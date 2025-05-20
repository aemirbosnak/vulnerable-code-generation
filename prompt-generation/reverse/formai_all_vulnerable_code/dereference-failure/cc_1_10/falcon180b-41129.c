//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    // Check for correct number of arguments
    if (argc!= 3)
    {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Convert IP address from string to binary format
    struct in_addr server_addr;
    if (inet_pton(AF_INET, argv[1], &server_addr) <= 0)
    {
        fprintf(stderr, "Invalid IP address\n");
        exit(EXIT_FAILURE);
    }

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        fprintf(stderr, "Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Connect to server
    struct sockaddr_in server_addr_struct;
    memset(&server_addr_struct, 0, sizeof(server_addr_struct));
    server_addr_struct.sin_family = AF_INET;
    server_addr_struct.sin_addr = server_addr;
    server_addr_struct.sin_port = htons(atoi(argv[2]));

    if (connect(socket_fd, (struct sockaddr *)&server_addr_struct, sizeof(server_addr_struct)) == -1)
    {
        fprintf(stderr, "Error connecting to server\n");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }

    // Send data to server
    char send_buffer[1024];
    strcpy(send_buffer, "Hello, World!");
    send(socket_fd, send_buffer, strlen(send_buffer), 0);

    // Receive data from server
    char recv_buffer[1024];
    memset(recv_buffer, 0, sizeof(recv_buffer));
    int bytes_received = recv(socket_fd, recv_buffer, sizeof(recv_buffer), 0);
    if (bytes_received <= 0)
    {
        fprintf(stderr, "Error receiving data from server\n");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }

    // Print received data
    printf("Received data: %s\n", recv_buffer);

    // Close socket
    close(socket_fd);

    return 0;
}