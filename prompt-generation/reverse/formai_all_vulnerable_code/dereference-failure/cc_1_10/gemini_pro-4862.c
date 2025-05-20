//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORT_NUMBER 65535

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    int port_number = atoi(argv[2]);

    if (port_number < 0 || port_number > MAX_PORT_NUMBER) {
        fprintf(stderr, "Invalid port number: %d\n", port_number);
        return EXIT_FAILURE;
    }

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error resolving hostname: %s\n", hostname);
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    memcpy(&server_address.sin_addr, host->h_addr, host->h_length);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        close(socket_fd);
        return EXIT_FAILURE;
    }

    printf("Port %d on host %s is open!\n", port_number, hostname);
    close(socket_fd);
    return EXIT_SUCCESS;
}