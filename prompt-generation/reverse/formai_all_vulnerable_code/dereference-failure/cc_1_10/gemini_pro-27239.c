//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    struct sockaddr_in addr;
    int sock;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Set the address and port number
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the remote host
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send data to the remote host
    char *data = "Hello, world!";
    if (send(sock, data, strlen(data), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive data from the remote host
    char buffer[1024];
    int len = recv(sock, buffer, sizeof(buffer), 0);
    if (len < 0) {
        perror("recv");
        exit(1);
    }

    // Print the data received from the remote host
    printf("Received: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}