//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: protected
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
    char *hostname;
    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        printf("Usage:./ping hostname\n");
        return 1;
    }

    hostname = argv[1];
    host = gethostbyname(hostname);

    if (host == NULL) {
        printf("Host not found\n");
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *) host->h_addr, host->h_length) == -1) {
        printf("Error connecting to host\n");
        close(sock);
        return 1;
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        send(sock, "PING", strlen("PING"), 0);
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Connection lost\n");
            close(sock);
            return 1;
        }

        printf("Received: %s\n", buffer);
        if (strcmp(buffer, "PONG") == 0) {
            printf("Host is alive\n");
            break;
        }
    }

    close(sock);
    return 0;
}