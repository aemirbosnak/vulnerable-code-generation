//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_PORT_NUMBER_LEN 6
#define MAX_IP_ADDRESS_LEN 46
#define MAX_MESSAGE_LEN 1024

int main(int argc, char *argv[])
{
    if (argc!= 3)
    {
        printf("Usage: %s <hostname or IP address> <port number>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *port_number = argv[2];
    int port;

    // Convert port number string to integer
    if (sscanf(port_number, "%d", &port)!= 1 || port <= 0 || port > 65535)
    {
        printf("Invalid port number.\n");
        return 1;
    }

    // Resolve hostname to IP address
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    struct addrinfo *result = NULL;
    int gai_error = getaddrinfo(hostname, NULL, &hints, &result);
    if (gai_error!= 0)
    {
        printf("Failed to resolve hostname: %s\n", gai_strerror(gai_error));
        return 1;
    }

    // Create socket
    int socket_fd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (socket_fd == -1)
    {
        printf("Failed to create socket: %s\n", strerror(errno));
        return 1;
    }

    // Connect to remote host
    if (connect(socket_fd, result->ai_addr, result->ai_addrlen) == -1)
    {
        printf("Failed to connect: %s\n", strerror(errno));
        close(socket_fd);
        return 1;
    }

    // Send message
    char message[MAX_MESSAGE_LEN];
    sprintf(message, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hostname);
    send(socket_fd, message, strlen(message), 0);

    // Receive response
    char response[MAX_MESSAGE_LEN];
    int bytes_received = recv(socket_fd, response, MAX_MESSAGE_LEN, 0);
    if (bytes_received <= 0)
    {
        printf("Failed to receive response.\n");
        close(socket_fd);
        return 1;
    }

    // Print response
    response[bytes_received] = '\0';
    printf("%s", response);

    // Close socket
    close(socket_fd);

    return 0;
}