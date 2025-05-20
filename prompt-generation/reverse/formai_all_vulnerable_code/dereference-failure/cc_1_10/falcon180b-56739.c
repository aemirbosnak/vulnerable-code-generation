//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_DATA_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

void print_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        print_error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        print_error("connect");
    }

    char buffer[MAX_DATA_SIZE];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(sock, buffer, MAX_DATA_SIZE, 0);
        if (bytes_received == 0) {
            printf("Connection closed by server.\n");
            break;
        } else if (bytes_received == -1) {
            print_error("recv");
            break;
        }

        printf("Received: %s", buffer);
    }

    close(sock);
    return 0;
}