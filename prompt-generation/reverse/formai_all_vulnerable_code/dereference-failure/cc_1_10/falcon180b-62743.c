//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define MAX_DATA_SIZE 1024
#define TIMEOUT_SEC 5
#define TIMEOUT_USEC 0

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char data[MAX_DATA_SIZE];
    int data_len;
    struct timeval timeout;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s:%d\n", argv[1], atoi(argv[2]));

    memset(data, 'A', MAX_DATA_SIZE);
    data_len = strlen(data);

    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = TIMEOUT_USEC;

    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    if (send(sock, data, data_len, 0) == -1) {
        perror("send");
        exit(1);
    }

    memset(data, 0, MAX_DATA_SIZE);
    data_len = recv(sock, data, MAX_DATA_SIZE, 0);

    if (data_len <= 0) {
        printf("No response from server\n");
    } else {
        printf("Response from server:\n%s\n", data);
    }

    close(sock);
    return 0;
}