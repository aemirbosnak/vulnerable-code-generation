//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    struct hostent *host;
    int sock;
    char buffer[BUFFER_SIZE];

    if ((host = gethostbyname(ip_address)) == NULL) {
        fprintf(stderr, "Error: could not resolve host '%s'.\n", ip_address);
        return 1;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Error: could not create socket.\n");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(7);
    addr.sin_addr.s_addr = *(unsigned long *)host->h_addr;

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        fprintf(stderr, "Error: could not connect to host.\n");
        close(sock);
        return 1;
    }

    send(sock, "PING", strlen("PING"), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);

    close(sock);

    if (strcmp(buffer, "PONG") == 0) {
        printf("Host '%s' is alive!\n", ip_address);
    } else {
        printf("Host '%s' is not responding.\n", ip_address);
    }

    return 0;
}