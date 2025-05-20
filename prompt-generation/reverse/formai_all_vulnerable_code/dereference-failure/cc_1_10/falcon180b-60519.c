//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

// Function to print error message and exit
void error(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("socket");
    }

    // Set up address structure
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, ip, &address.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&address, sizeof(address)) == -1) {
        error("connect");
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        // Send data
        if (send(sock, "PING", strlen("PING"), 0) == -1) {
            error("send");
        }

        // Receive data
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            error("recv");
        } else if (bytes_received == 0) {
            printf("Server not responding.\n");
            break;
        } else {
            buffer[bytes_received] = '\0';
            printf("Received: %s\n", buffer);
        }
    }

    // Close socket
    close(sock);

    return 0;
}