//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX 65535
#define PORT_START 1
#define PORT_END 65535
#define BUFFER_SIZE 1024
#define IP_ADDRESS "127.0.0.1"

int main(int argc, char **argv) {
    int sock;
    struct sockaddr_in server;
    int port;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    char *message;

    if (argc!= 3) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);
    while (port <= atoi(argv[2])) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Socket creation failed: %s\n", strerror(errno));
            exit(1);
        }

        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr(IP_ADDRESS);
        server.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
            printf("Connection failed: %s\n", strerror(errno));
            close(sock);
            continue;
        }

        printf("Port %d is open\n", port);
        close(sock);
        port++;
    }

    return 0;
}