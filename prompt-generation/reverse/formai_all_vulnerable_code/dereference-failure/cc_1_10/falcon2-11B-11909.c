//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: realistic
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    // Creating a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0)
    {
        perror("socket creation failed");
        return 1;
    }

    // Getting the hostname and port number from the command line arguments
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(atoi(argv[1]));
    address.sin_addr.s_addr = inet_addr(argv[2]);

    // Binding the socket to the address
    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        return 1;
    }

    // Listening to incoming connections
    listen(socket_fd, 5);

    // Accepting a connection
    int client_fd = accept(socket_fd, NULL, NULL);
    if (client_fd < 0)
    {
        perror("accept failed");
        return 1;
    }

    // Sending a response to the client
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    send(client_fd, "Hello, world!", 13, 0);

    // Closing the connection
    close(client_fd);
    close(socket_fd);

    return 0;
}