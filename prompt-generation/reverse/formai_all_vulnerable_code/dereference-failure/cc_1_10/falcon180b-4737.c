//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define TIMEOUT_SEC 5
#define TIMEOUT_USEC 0

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char data[MAX_DATA_SIZE];
    int data_size;
    int timeout;
    int ret;
    char *ip = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Failed to create socket.\n");
        exit(1);
    }

    // Set socket options
    timeout = TIMEOUT_SEC * 1000 + TIMEOUT_USEC;
    ret = setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    if (ret == -1) {
        printf("Error: Failed to set receive timeout.\n");
        exit(1);
    }

    ret = setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));
    if (ret == -1) {
        printf("Error: Failed to set send timeout.\n");
        exit(1);
    }

    // Connect to server
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    ret = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (ret == -1) {
        printf("Error: Failed to connect to server.\n");
        exit(1);
    }

    // Send data
    data_size = strlen(argv[3]);
    ret = send(sock, argv[3], data_size, 0);
    if (ret == -1) {
        printf("Error: Failed to send data.\n");
        exit(1);
    }

    // Receive data
    memset(data, 0, MAX_DATA_SIZE);
    data_size = recv(sock, data, MAX_DATA_SIZE, 0);
    if (data_size == -1) {
        printf("Error: Failed to receive data.\n");
        exit(1);
    }
    printf("Received data: %s\n", data);

    close(sock);
    return 0;
}