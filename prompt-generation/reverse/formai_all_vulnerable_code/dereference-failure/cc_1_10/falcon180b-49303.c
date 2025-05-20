//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    int len;
    int port;
    char *ptr;

    // Check if the correct number of arguments are provided
    if (argc!= 4) {
        printf("Usage:./ping <hostname> <port> <number of packets>\n");
        return 1;
    }

    // Convert hostname to IP address
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: Invalid hostname\n");
        return 1;
    }

    // Store the IP address in the server structure
    memcpy(&server.sin_addr, host->h_addr, host->h_length);

    // Convert port number to network byte order
    port = htons(atoi(argv[2]));

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error: Could not connect to server\n");
        close(sock);
        return 1;
    }

    // Send the specified number of packets
    for (int i = 0; i < atoi(argv[3]); i++) {
        memset(buffer, 0, BUFFER_SIZE);
        sprintf(buffer, "PING %d\n", i);
        send(sock, buffer, strlen(buffer), 0);

        // Receive a response
        len = recv(sock, buffer, BUFFER_SIZE, 0);
        if (len <= 0) {
            printf("Error: Could not receive response\n");
            close(sock);
            return 1;
        }

        // Print the response
        printf("Response %d: %s", i, buffer);
    }

    // Close the socket
    close(sock);

    return 0;
}