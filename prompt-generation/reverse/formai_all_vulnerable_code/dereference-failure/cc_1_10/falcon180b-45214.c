//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int scan_port(int sock, int port) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));

    if (result == 0) {
        printf("Port %d is open\n", port);
    } else if (errno == ECONNREFUSED) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Error: %s\n", strerror(errno));
    }

    close(sock);
    return 0;
}

int main() {
    int sock;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        return 1;
    }

    for (int i = 1; i <= MAX_PORTS; i++) {
        scan_port(sock, i);
    }

    close(sock);
    return 0;
}