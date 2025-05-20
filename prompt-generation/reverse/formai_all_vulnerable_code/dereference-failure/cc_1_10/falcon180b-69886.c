//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define TIMEOUT_MS 5000

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char hostname[NI_MAXHOST];
    char service[NI_MAXSERV];
    int rv;
    fd_set readfds;
    struct timeval tv;
    int max_fd;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);
    if (getaddrinfo(hostname, NULL, NULL, &server_addr)!= 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(errno));
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "socket error: %s\n", strerror(errno));
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "connect error: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);
    max_fd = sock;

    tv.tv_sec = TIMEOUT_MS / 1000;
    tv.tv_usec = (TIMEOUT_MS % 1000) * 1000;

    rv = select(max_fd + 1, &readfds, NULL, NULL, &tv);
    if (rv == -1) {
        fprintf(stderr, "select error: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    if (FD_ISSET(sock, &readfds)) {
        memset(buffer, 0, BUFFER_SIZE);
        rv = recv(sock, buffer, BUFFER_SIZE, 0);
        if (rv == -1) {
            fprintf(stderr, "recv error: %s\n", strerror(errno));
            close(sock);
            return 1;
        }
        buffer[rv] = '\0';
        printf("PONG received: %s\n", buffer);
    } else {
        fprintf(stderr, "No response from server\n");
    }

    close(sock);
    return 0;
}