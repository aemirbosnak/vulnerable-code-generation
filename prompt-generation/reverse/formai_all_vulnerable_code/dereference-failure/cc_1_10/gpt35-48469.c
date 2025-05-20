//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define HOSTNAME_LEN 256
#define PATH_LEN 1024
#define RESPONSE_LEN 2048

int main(int argc, char *argv[]) {
    char hostname[HOSTNAME_LEN];
    char path[PATH_LEN];
    int port = 80;

    // Parse command line arguments
    if (argc < 3) {
        printf("Usage: %s <hostname> <path> [port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strncpy(hostname, argv[1], HOSTNAME_LEN);
    strncpy(path, argv[2], PATH_LEN);

    if (argc == 4) {
        port = atoi(argv[3]);
    }

    struct sockaddr_in server_address;
    struct hostent *server_host;

    // Resolve hostname to IP address
    server_host = gethostbyname(hostname);
    if (server_host == NULL) {
        printf("Failed to resolve hostname\n");
        exit(EXIT_FAILURE);
    }

    // Create socket
    int Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (Socket < 0) {
        printf("Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    // Fill server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = *(unsigned long *)server_host->h_addr;
    server_address.sin_port = htons(port);

    // Connect to server
    if (connect(Socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    // Construct HTTP request
    char request[1024];
    snprintf(request, 1024, "GET %s HTTP/1.1\r\n"
                            "Host: %s\r\n"
                            "Connection: close\r\n\r\n",
                            path, hostname);

    // Send request
    int sent = send(Socket, request, strlen(request), 0);
    if (sent < 0) {
        printf("Failed to send request\n");
        exit(EXIT_FAILURE);
    }

    // Receive response
    char response[RESPONSE_LEN];
    char buffer[1024];
    int received = 1;

    while (received > 0) {
        received = recv(Socket, buffer, 1024, 0);
        if (received < 0) {
            printf("Failed to receive response\n");
            exit(EXIT_FAILURE);
        }
        strncat(response, buffer, received);
    }

    // Print response
    printf("%s\n", response);

    close(Socket);
    exit(EXIT_SUCCESS);
}