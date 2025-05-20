//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 1024

struct hostent *gethostbyname(const char *name);

int main(int argc, char *argv[]) {
    int sock = 0;
    struct hostent *host = NULL;
    char hostname[MAX_HOST_NAME];
    char data[MAX_DATA_SIZE];
    int port = 80; // default HTTP port

    if (argc < 2) {
        printf("Usage: %s <hostname/IP>\n", argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);
    host = gethostbyname(hostname);

    if (host == NULL) {
        printf("Error: Host not found.\n");
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error: Failed to create socket.\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)host->h_addr, host->h_length) == -1) {
        printf("Error: Failed to connect.\n");
        close(sock);
        return 1;
    }

    send(sock, "GET / HTTP/1.1\r\nHost: ", strlen("GET / HTTP/1.1\r\nHost: "), 0);
    send(sock, argv[1], strlen(argv[1]), 0);
    send(sock, "\r\n", strlen("\r\n"), 0);

    memset(data, 0, MAX_DATA_SIZE);
    int len = recv(sock, data, MAX_DATA_SIZE, 0);

    if (len > 0) {
        printf("Response:\n%s", data);
    } else {
        printf("Error: No response received.\n");
    }

    close(sock);
    return 0;
}

struct hostent *gethostbyname(const char *name) {
    struct hostent *host = gethostbyname2(name, AF_INET);

    if (host == NULL) {
        printf("Error: Failed to resolve host.\n");
        errno = EHOSTUNREACH;
        return NULL;
    }

    return host;
}