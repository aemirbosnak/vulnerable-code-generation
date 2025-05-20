//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *host;
    char *port;
    int sock;
    struct sockaddr_in server;
    int opt = 1;
    char buffer[BUFFER_SIZE];
    char *ptr;
    int n;

    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = argv[2];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(port));
    server.sin_addr.s_addr = inet_addr(host);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Connection failed\n");
        close(sock);
        exit(1);
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        n = read(sock, buffer, BUFFER_SIZE);
        if (n == 0) {
            printf("Host is down\n");
            close(sock);
            exit(0);
        }
        if (strstr(buffer, "HTTP/1.1")) {
            printf("Port %s is open\n", port);
            close(sock);
            exit(0);
        }
    }

    close(sock);
    exit(0);
}