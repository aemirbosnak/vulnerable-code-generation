//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

int main(int argc, char *argv[]) {
    int sock, ret;
    struct sockaddr_in addr;
    char hostname[MAX_HOSTNAME];
    char data[MAX_DATA];

    // Check if the correct number of arguments were provided
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <data>\n", argv[0]);
        return 1;
    }

    // Copy the hostname and data arguments into local variables
    strcpy(hostname, argv[1]);
    strcpy(data, argv[2]);

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // Set up the address structure
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(7);

    // Resolve the hostname
    if (inet_pton(AF_INET, hostname, &addr.sin_addr) <= 0) {
        fprintf(stderr, "Error resolving hostname: %s\n", hostname);
        close(sock);
        return 1;
    }

    // Connect to the server
    ret = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    // Send the data
    ret = send(sock, data, strlen(data), 0);
    if (ret == -1) {
        fprintf(stderr, "Error sending data: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    // Receive the response
    char response[MAX_DATA];
    ret = recv(sock, response, sizeof(response), 0);
    if (ret == -1) {
        fprintf(stderr, "Error receiving response: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    // Print the response
    printf("Response: %s\n", response);

    // Close the socket
    close(sock);

    return 0;
}