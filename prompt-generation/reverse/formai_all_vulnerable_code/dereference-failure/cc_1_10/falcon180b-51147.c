//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sock = 0;
    struct addrinfo hints, *servinfo = NULL;
    char s[NI_MAXSERV];
    int rv;

    // Set up hints for getaddrinfo()
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get address information for server
    rv = getaddrinfo("www.example.com", "http", &hints, &servinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    // Create socket
    sock = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to server
    rv = connect(sock, servinfo->ai_addr, servinfo->ai_addrlen);
    if (rv == -1) {
        perror("connect");
        exit(1);
    }

    // Send HTTP request
    char request[1024];
    sprintf(request, "GET / HTTP/1.0\r\nHost: www.example.com\r\nConnection: close\r\n\r\n");
    send(sock, request, strlen(request), 0);

    // Receive response
    char response[1024];
    memset(response, 0, sizeof(response));
    while (recv(sock, response, sizeof(response), 0) > 0) {
        printf("%s", response);
    }

    // Close socket
    close(sock);

    return 0;
}