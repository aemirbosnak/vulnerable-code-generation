//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char *argv[])
{
    // Check if the user has provided enough arguments.
    if (argc != 4)
    {
        printf("Usage: %s <ip address> <port> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the IP address and port number from the user.
    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    // Get the filename from the user.
    char *filename = argv[3];

    // Create a socket.
    int socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_descriptor == -1)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the FTP server.
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    server_address.sin_addr.s_addr = inet_addr(ip_address);
    if (connect(socket_descriptor, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the RETR command to the FTP server.
    char retr_command[100];
    sprintf(retr_command, "RETR %s\r\n", filename);
    if (send(socket_descriptor, retr_command, strlen(retr_command), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the file from the FTP server.
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char buffer[1024];
    int bytes_received;
    while ((bytes_received = recv(socket_descriptor, buffer, sizeof(buffer), 0)) > 0)
    {
        fwrite(buffer, 1, bytes_received, file);
    }

    if (bytes_received == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Close the file.
    fclose(file);

    // Close the socket.
    close(socket_descriptor);

    return EXIT_SUCCESS;
}