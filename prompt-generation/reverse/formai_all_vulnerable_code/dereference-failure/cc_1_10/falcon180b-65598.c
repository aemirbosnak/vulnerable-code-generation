//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOST_LEN 256
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    char hostname[MAX_HOST_LEN];
    char data[MAX_DATA_LEN];
    int port;
    int sock;
    struct hostent *host;
    struct sockaddr_in server_addr;

    // Check if the correct number of arguments were provided
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Copy hostname and port from command line arguments
    strncpy(hostname, argv[1], MAX_HOST_LEN);
    port = atoi(argv[2]);

    // Resolve the hostname
    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error resolving hostname: %s\n", strerror(errno));
        return 1;
    }

    // Create the socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    // Send a ping request
    strcpy(data, "PING");
    if (send(sock, data, strlen(data), 0) == -1) {
        fprintf(stderr, "Error sending data: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    // Receive a response
    if (recv(sock, data, MAX_DATA_LEN, 0) == -1) {
        fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    // Print the response
    printf("Response from %s:%d: %s\n", hostname, port, data);

    // Close the socket
    close(sock);

    return 0;
}