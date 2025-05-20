//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_DATA_SIZE 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char data[MAX_DATA_SIZE];
    int datalen;
    int result;
    int err;
    int timeout;

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <port> <timeout>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (result == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    timeout = atoi(argv[3]);
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    while (1) {
        memset(data, 0, MAX_DATA_SIZE);
        datalen = recv(sock, data, MAX_DATA_SIZE, 0);
        if (datalen <= 0) {
            fprintf(stdout, "No response from server\n");
            break;
        }
        fprintf(stdout, "Received data: %s\n", data);
    }

    close(sock);
    exit(0);
}