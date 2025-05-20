//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    struct hostent *host;
    int sock;
    char buffer[BUFFER_SIZE];

    if ((host = gethostbyname(ip_address)) == NULL) {
        printf("Error: %s\n", hstrerror(h_errno));
        return 1;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    if (connect(sock, (struct sockaddr *) host->h_addr, host->h_length) == -1) {
        printf("Error: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    printf("Pinging %s...\n", ip_address);

    while (1) {
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Error: %s\n", strerror(errno));
            close(sock);
            return 1;
        }

        printf("%s", buffer);
    }

    close(sock);
    return 0;
}