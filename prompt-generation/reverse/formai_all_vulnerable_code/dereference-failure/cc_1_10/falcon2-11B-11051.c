//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/types.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    // Check the number of arguments
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Get the hostname and port from the command line arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a TCP socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("socket");
        return 1;
    }

    // Create an INADDR_ANY address for the socket
    struct sockaddr_in server_address;
    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the socket to the INADDR_ANY address
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        return 1;
    }

    // Connect to the SMTP server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect");
        return 1;
    }

    // Send a SMTP HELO command
    char helo_command[] = "HELO localhost\r\n";
    if (write(socket_fd, helo_command, strlen(helo_command)) < 0) {
        perror("write");
        return 1;
    }

    // Read the SMTP response
    char response[BUFFER_SIZE];
    if (read(socket_fd, response, sizeof(response)) < 0) {
        perror("read");
        return 1;
    }

    // Print the SMTP response
    printf("%s\n", response);

    // Close the socket
    close(socket_fd);

    return 0;
}